#include "AsignaturaClaseController.h"

#include "../exceptions/AsignaturaDuplicated.h"
#include "../exceptions/AsignaturaNotFound.h"
#include "../exceptions/AsignacionDuplicated.h"
#include "../exceptions/EstudianteNoHabilitado.h"
#include "../exceptions/MensajeNotFound.h"
#include "../exceptions/AsignacionNotAvailable.h"
#include "../exceptions/FechaAnterior.h"
#include "../exceptions/AsistenciaDuplicated.h"
#include "../exceptions/ClaseNotAvailable.h"
#include "../exceptions/ClaseNotFound.h"
#include "../exceptions/ClaseFinalizada.h"
#include "../exceptions/FinalizarNotAllowed.h"


AsignaturaClaseController::AsignaturaClaseController(){
    this->aHandler = AsignaturaHandler::getInstance();
    this->uHandler = UsuarioHandler::getInstance();
    this->cHandler = ClaseHandler::getInstance();
    this->reloj = Reloj::getInstance();
    this->suscriptores = new set<Usuario*>();
}

AsignaturaClaseController::~AsignaturaClaseController(){

}

set<Usuario*>* AsignaturaClaseController::getSuscriptores() {
    return suscriptores;
}

void AsignaturaClaseController::suscribirseNotificaciones(string &email) {
    Usuario* usuario = uHandler->getUsuario(email);
    this->addSuscriptor(usuario);
}

void AsignaturaClaseController::addSuscriptor(Usuario *usuario) {
    suscriptores->insert(usuario);
}

set<DtAsignatura *> * AsignaturaClaseController::listarAsignaturasNoInscripto(int cedula) {
    set<Asignatura *> * asignaturas = aHandler->getAsignaturas();
    Estudiante* estudiante = uHandler->getEstudiante(cedula);
    set<DtAsignatura *> *dtAsignaturas = new set<DtAsignatura *>();
    for(set<Asignatura*>::iterator it = asignaturas->begin(); it!=asignaturas->end(); ++it) {
        if ((*it)->getEstudiantes()->find(estudiante) == (*it)->getEstudiantes()->end()) {
            dtAsignaturas->insert(new DtAsignatura((*it)->getCodigo(), (*it)->getNombre(), (*it)->getTieneTeorico(), (*it)->getTienePractico(), (*it)->getTieneMonitoreo()));
        }
    }
    return dtAsignaturas;
}

set<DtAsignatura *>* AsignaturaClaseController::listarAsignaturas(int cedula) {
    Estudiante* estudiante = uHandler->getEstudiante(cedula);
    set<DtAsignatura *> *dtAsignaturas = new set<DtAsignatura *>();
    for(set<Asignatura*>::iterator it = estudiante->getAsignaturas()->begin(); it!=estudiante->getAsignaturas()->end(); ++it) {
        dtAsignaturas->insert(new DtAsignatura((*it)->getCodigo(), (*it)->getNombre(), (*it)->getTieneTeorico(), (*it)->getTienePractico(), (*it)->getTieneMonitoreo()));
    }
    return dtAsignaturas;
}

set<DtClase *> * AsignaturaClaseController::listarClasesDisponibles(int cedula) {
    Estudiante* estudiante = uHandler->getEstudiante(cedula);
    set<DtClase *> *dtClases = new set<DtClase *>();
    for(set<Asignatura*>::iterator itAsignatura = estudiante->getAsignaturas()->begin(); itAsignatura!=estudiante->getAsignaturas()->end(); ++itAsignatura) {
        for(set<Clase*>::iterator itClase = (*itAsignatura)->getClases()->begin(); itClase!=(*itAsignatura)->getClases()->end(); ++itClase) {
            if (!(*itClase)->esClaseEnDiferido()) {
                Clase * clase = (*itClase);
                Asignatura* asignatura = clase->getAsignatura();
                DtAsignatura * dtAsignatura = new DtAsignatura(asignatura->getCodigo(), asignatura->getNombre(), asignatura->getTieneTeorico(), asignatura->getTienePractico(), asignatura->getTieneMonitoreo());
                dtClases->insert(new DtClase(clase->getCodigo(), clase->getNombre(), clase->getInicio(), clase->getFin(), clase->getUrlVideo(), clase->getIniciadaPor(), dtAsignatura));
            }
        }
    }
    return dtClases;
}

set<DtClase *> * AsignaturaClaseController::listarClasesVivo(int cedula) {
    Estudiante* estudiante = uHandler->getEstudiante(cedula);
    set<DtClase *> *dtClases = new set<DtClase *>();
    for(set<Asistencia*>::iterator itAsistencia = estudiante->getAsistencias()->begin(); itAsistencia!=estudiante->getAsistencias()->end(); ++itAsistencia) {
        AsistenciaEnVivo* asistenciaEnVivo = dynamic_cast<AsistenciaEnVivo*>((*itAsistencia));
        if (asistenciaEnVivo != NULL && (asistenciaEnVivo->getFin() == NULL)) {
            Clase * clase = (*itAsistencia)->getClase();
            Asignatura* asignatura = clase->getAsignatura();
            DtAsignatura * dtAsignatura = new DtAsignatura(asignatura->getCodigo(), asignatura->getNombre(), asignatura->getTieneTeorico(), asignatura->getTienePractico(), asignatura->getTieneMonitoreo());
            dtClases->insert(new DtClase(clase->getCodigo(), clase->getNombre(), clase->getInicio(), clase->getFin(), clase->getUrlVideo(), clase->getIniciadaPor(), dtAsignatura));
        }
    }
    return dtClases;
}

void AsignaturaClaseController::registrarAsistencia(int id, string codigoAsignatura, DtEstudiante* dtEstudiante) {
    Estudiante* estudiante = uHandler->getEstudiante(dtEstudiante->getCedula());
    Clase* clase = cHandler->getClase(id);

    if(clase->getAsignatura()->getCodigo()!=codigoAsignatura){
        throw  ClaseNotAvailable();
    }else if(DtFecha::esAnterior(clase->getFin(),this->reloj->getTimer())){
        throw ClaseFinalizada();
    }

    
    Teorico* teorico = dynamic_cast<Teorico*>(clase);
    if (teorico != NULL) {
        int asistentes = teorico->getCantAsistentes();
        teorico->setCantAsistentes(++asistentes);
    }


    Monitoreo* monitoreo = dynamic_cast<Monitoreo*>(clase);
    if(monitoreo != NULL) {
        set<Estudiante*> *habilitados = monitoreo->getHabilitados();
        if (habilitados->find(estudiante) == habilitados->end()) {
            throw EstudianteNoHabilitado();
        }
    }


    set<Asistencia*>* asistencias = estudiante->getAsistencias();


    for(set<Asistencia*>::iterator it = asistencias->begin(); it!=asistencias->end(); ++it){
        if((*it)->getClase()->getCodigo()==id && dynamic_cast<AsistenciaEnVivo*>((*it))->getFin()==NULL){
            throw AsistenciaDuplicated();
        }
    }

    AsistenciaEnVivo* asistenciaEnVivo = new AsistenciaEnVivo(reloj->getTimer(), NULL, clase, estudiante);
    estudiante->addAsistencia(asistenciaEnVivo);
    clase->addAsistencia(asistenciaEnVivo);
}

void AsignaturaClaseController::confirmarFinalizacionAsistenciaVivo(int id, DtEstudiante *dtEstudiante) {
    Estudiante* estudiante = uHandler->getEstudiante(dtEstudiante->getCedula());

    set<Asistencia*>* asistencias = estudiante->getAsistencias();

    bool noExisteClase = true;

    for(set<Asistencia*>::iterator it = asistencias->begin(); it!=asistencias->end(); ++it){
        if((*it)->getClase()->getCodigo()==id){
            noExisteClase = false;
        }
    }

    if(noExisteClase) throw ClaseNotFound();

    for(set<Asistencia*>::iterator itAsistencia = estudiante->getAsistencias()->begin(); itAsistencia != estudiante->getAsistencias()->end(); ++itAsistencia) {
        AsistenciaEnVivo* asistenciaEnVivo = dynamic_cast<AsistenciaEnVivo*>((*itAsistencia));
        if (asistenciaEnVivo != NULL && asistenciaEnVivo->getClase()->getCodigo() == id) {
            if (DtFecha::esAnterior(asistenciaEnVivo->getInicio(), reloj->getTimer())) {
                asistenciaEnVivo->setFin(reloj->getTimer());
            } else {
                throw FechaAnterior("La fecha de finalización es anterior a la de inicio.");
            }
        }
    }
}

void AsignaturaClaseController::inscribirseAsignatura(string &codigo, DtEstudiante* dtEstudiante) {
    Estudiante* estudiante = uHandler->getEstudiante(dtEstudiante->getCedula());
    Asignatura* asignatura = aHandler->getAsignatura(codigo);
    asignatura->addEstudiante(estudiante);
    estudiante->addAsignatura(asignatura);
}

void AsignaturaClaseController::altaAsignatura(DtAsignatura* asignatura){
    try{
        aHandler->getAsignatura(asignatura->getCodigo());
        throw AsignaturaDuplicated();
    }catch(const AsignaturaNotFound &e){
        aHandler->addAsignatura(new Asignatura(asignatura->getCodigo(), asignatura->getNombre(),
                                     asignatura->isTeorico(), asignatura->isPractico(), asignatura->isMonitoreo()));
    }
}

set<DtAsignatura*>* AsignaturaClaseController::listarAsignaturas(){
    set<DtAsignatura*>* list = new set<DtAsignatura*>();
    set<Asignatura*>* asignaturas = aHandler->getAsignaturas();
    for(set<Asignatura*>::iterator it = asignaturas->begin(); it!=asignaturas->end(); ++it){
        list->insert(new DtAsignatura((*it)->getCodigo(), (*it)->getNombre(),(*it)->getTieneTeorico(),
                         (*it)->getTienePractico(), (*it)->getTieneMonitoreo()));
    }
    return list;
}

set<DtDocente*>* AsignaturaClaseController::listarDocentesNoAsignados(string &codigo){
    return uHandler->getDocentesNoAsignados(aHandler->getAsignatura(codigo));
}

void AsignaturaClaseController::asignarDocente(string &codigo, string &email, tipoAsignacion rol){
    Docente* d = uHandler->getDocente(email);
    Asignatura * asignatura = aHandler->getAsignatura(codigo);
    DtAsignatura * dtAsignatura = new DtAsignatura(asignatura->getCodigo(), asignatura->getNombre(),
                                                   asignatura->getTieneTeorico(), asignatura->getTienePractico(), asignatura->getTieneMonitoreo());
    map<DtAsignatura*, tipoAsignacion>* coleccion = d->getAsignaciones();

    if((rol==tipoTeorico && !asignatura->getTieneTeorico()) || (rol==tipoPractico && !asignatura->getTienePractico())
       || (rol==tipoMonitoreo && !asignatura->getTieneMonitoreo())) {
        throw AsignacionNotAvailable();
    }
    if (coleccion->find(dtAsignatura) == coleccion->end() || coleccion->find(dtAsignatura)->second!=rol){
        d->asignar(asignatura, rol);
        asignatura->addDocente(d);
    }else{
        delete dtAsignatura;
        throw AsignacionDuplicated();
    }
    delete dtAsignatura;
}

 DtReporteTiempoDictado* AsignaturaClaseController::obtenerTiempoDictado(string &codigoAsignatura){
     Asignatura* a = aHandler->getAsignatura(codigoAsignatura);
     DtReporteTiempoDictado* reporte = new DtReporteTiempoDictado(new DtAsignatura(a->getCodigo(), a->getNombre(),a->getTieneTeorico(),
                                                a->getTienePractico(), a->getTieneMonitoreo()),0);

     for(set<Clase*>::iterator it = a->getClases()->begin(); it!=a->getClases()->end(); ++it){
         if((*it)->getFin()!=NULL){
             reporte->addTiempo((((*it)->getFin()->getHora()*3600 + (*it)->getFin()->getMinuto()*60)) -
                                    ((*it)->getInicio()->getHora()*3600 + (*it)->getInicio()->getMinuto()*60));
         }else{
            reporte->addTiempo(((reloj->getTimer()->getHora()*3600 + reloj->getTimer()->getMinuto()*60)) -
                                    ((*it)->getInicio()->getHora()*3600 + (*it)->getInicio()->getMinuto()*60)); 
         }
     }

     return reporte;
 }

 void AsignaturaClaseController::eliminarAsignatura(string &codigoAsignatura){
     Asignatura* a = aHandler->remove(codigoAsignatura);

     for(set<Clase*>::iterator it = a->getClases()->begin(); it!=a->getClases()->end(); ++it){
         Clase* c = cHandler->remove((*it)->getCodigo());
         delete c;
     }

     for(set<Estudiante*>::iterator it = a->getEstudiantes()->begin(); it!=a->getEstudiantes()->end(); ++it){
         (*it)->eliminarAsignatura(a);
     }

     for(set<Docente*>::iterator it = a->getDocentes()->begin(); it!=a->getDocentes()->end(); ++it){
         (*it)->eliminarAsignatura(a);
     }
     delete a;
 }


set<DtAsignatura*>* AsignaturaClaseController::listarAsignaturas(string &email){
    return uHandler->getDocente(email)->getAsignaturas();
}

set<DtEstudiante*>* AsignaturaClaseController::listarEstudiantes(string &codigo){
    set<Estudiante*>* estudiantes = uHandler->getEstudiantesByAsignatura(aHandler->getAsignatura(codigo));
    set<DtEstudiante*>* dtEstudiantes = new set<DtEstudiante*>();
    for (set<Estudiante*>::iterator it = estudiantes->begin(); it != estudiantes->end(); ++it){
        dtEstudiantes->insert(new DtEstudiante((*it)->getNombre(),(*it)->getEmail(),(*it)->getPassword(),(*it)->getImagen(),(*it)->getCedula()));
    }
    return dtEstudiantes;
}

int AsignaturaClaseController::confirmarClase(string &email, string &codigo, string &nombre, DtFecha *inicio, set<DtEstudiante*>* estudiantes){
    Docente* docente = uHandler->getDocente(email);
    Asignatura* asignatura = aHandler->getAsignatura(codigo);
    Clase* clase = NULL;
    string url = "";
    if (docente->getTipoAsignacion(codigo) == tipoTeorico){
        clase = new Teorico(nombre, inicio, NULL, url, email, asignatura);
        asignatura->addClase(clase);
        cHandler->addClase(clase);
    }else if (docente->getTipoAsignacion(codigo) == tipoPractico){
        clase = new Practico(nombre, inicio, NULL, url, email, asignatura);
        asignatura->addClase(clase);
        cHandler->addClase(clase);
    }else{
        clase = new Monitoreo(nombre, inicio, NULL, url, email, asignatura);
        Monitoreo* monitoreo = dynamic_cast<Monitoreo*>(clase);
        for (set<DtEstudiante*>::iterator i = estudiantes->begin(); i != estudiantes->end(); ++i){
            Estudiante* estudiante = uHandler->getEstudiante((*i)->getCedula());
            monitoreo->setHabilitado(estudiante);
        }
        cHandler->addClase(clase);
        asignatura->addClase(monitoreo);
    }
    return clase->getCodigo();

}

set<DtClase*>* AsignaturaClaseController::listarClasesVivo(string &email){
    set<Clase*>* clasesVivo = uHandler->getDocente(email)->getClasesVivo();
    set<DtClase*>* dtClasesVivo = new set<DtClase*>();
    for (set<Clase*>::iterator it = clasesVivo->begin(); it != clasesVivo->end(); ++it){
        DtAsignatura* dtAsignatura = new DtAsignatura((*it)->getAsignatura()->getCodigo(),(*it)->getAsignatura()->getNombre(),(*it)->getAsignatura()->getTieneTeorico(),
                                                            (*it)->getAsignatura()->getTienePractico(),(*it)->getAsignatura()->getTieneMonitoreo());
        dtClasesVivo->insert(new DtClase((*it)->getCodigo(),(*it)->getNombre(),(*it)->getInicio(),(*it)->getFin(),(*it)->getUrlVideo(),(*it)->getIniciadaPor(),dtAsignatura));
    }
    return dtClasesVivo;
}

void AsignaturaClaseController::finalizarClase(int id, string emailFinalizar){
    Clase* clase = cHandler->getClase(id);

    if(clase->getIniciadaPor()!=emailFinalizar) throw FinalizarNotAllowed();

    bool esAnterior = DtFecha::esAnterior(clase->getInicio(), reloj->getTimer());
    if (esAnterior) {
        if(clase->getFin()==NULL){
            clase->setFin(reloj->getTimer());
            clase->setUrlVideo("www.fingclass.com/" + to_string(id));
            set<AsistenciaEnVivo*>* asistenciasEnVivo = clase->getAsistenciasEnVivo();
            for (set<AsistenciaEnVivo*>::iterator it = asistenciasEnVivo->begin(); it != asistenciasEnVivo->end(); ++it){
                (*it)->setFin(reloj->getTimer());
            }
        }else{
            throw ClaseFinalizada();
        }
        
    } else {
        throw FechaAnterior("La fecha de finalización es anterior a la de inicio.");
    }
}

set<DtReporteTiempoAsistencia*>* AsignaturaClaseController::obtenerTiempoAsistenciaClase(string &email, string &codigo){
    Docente* docente = uHandler->getDocente(email);
    Asignatura* asignatura = aHandler->getAsignatura(codigo);
    set<DtReporteTiempoAsistencia*>* reportes = new set<DtReporteTiempoAsistencia*>();
    set<Clase*>* clases = asignatura->getClases();
    DtAsignatura* dtAsignatura = new DtAsignatura(asignatura->getCodigo(),asignatura->getNombre(),asignatura->getTieneTeorico(),asignatura->getTienePractico(),asignatura->getTieneMonitoreo());
    for(set<Clase*>::iterator it = clases->begin(); it!=clases->end(); ++it){
        if (docente->getEmail() == (*it)->getIniciadaPor()) {
            DtClase* dtClase = new DtClase((*it)->getCodigo(),(*it)->getNombre(),(*it)->getInicio(),(*it)->getFin(),(*it)->getUrlVideo(),(*it)->getIniciadaPor(),dtAsignatura);
            set<AsistenciaEnVivo*>* asistencias = (*it)->getAsistenciasEnVivo();
            int tiempoTotal = 0;
            int cantidadAsistentes = 0;
            for(set<AsistenciaEnVivo*>::iterator i = asistencias->begin(); i != asistencias->end(); ++i){
                if (dynamic_cast<Estudiante*>((*i)->getUsuario()) != NULL) {
                    if ((*i)->getFin() != NULL) {
                        tiempoTotal += (((*i)->getFin()->getHora() * 3600 + (*i)->getFin()->getMinuto() * 60)
                                        - ((*i)->getInicio()->getHora() * 3600 + (*i)->getInicio()->getMinuto() * 60));
                    } else {
                        tiempoTotal += (reloj->getTimer()->getHora() * 3600 + reloj->getTimer()->getMinuto() * 60)
                                        - ((*i)->getInicio()->getHora() * 3600 + (*i)->getInicio()->getMinuto() * 60);
                    }
                    cantidadAsistentes++;
                }
            }
            int promedio;
            if (cantidadAsistentes != 0) {
                promedio = static_cast<int>(tiempoTotal / cantidadAsistentes);
            } else {
                promedio = 0;
            }
            reportes->insert(new DtReporteTiempoAsistencia(dtClase, promedio));
        }
    }
    return reportes;
}

set<DtMensaje*>* AsignaturaClaseController::listarMensajes(int id){
    set<Mensaje*>* mensajes = cHandler->getClase(id)->getMensajes();
    set<DtMensaje*>* dtmensajes = new set<DtMensaje*>();
    for (set<Mensaje*>::iterator it = mensajes->begin(); it != mensajes->end(); ++it){
        dtmensajes->insert(new DtMensaje((*it)->getId(),(*it)->getAutor(),(*it)->getContenido(),(*it)->getFechaEnvio(),(*it)->getRespondeA()));
    }
    return dtmensajes;
}

int AsignaturaClaseController::altaMensaje(string &email, int id, string &texto, int respondeA){
    Usuario* usuario = uHandler->getUsuario(email);
    Clase* clase = cHandler->getClase(id);
    if ((respondeA != 0) && clase->getMensajeById(respondeA) == NULL){
        throw MensajeNotFound();
    }
    Mensaje* mensaje = new Mensaje(usuario->getNombre(), texto, reloj->getTimer(), respondeA);
    mensaje->setClase(clase);
    clase->agregarMensaje(mensaje);
    for (set<Usuario*>::iterator it = getSuscriptores()->begin(); it != getSuscriptores()->end(); ++it){
        Mensaje* mensajeRespondido = clase->getMensajeById(respondeA);
        if (mensajeRespondido != NULL && (mensajeRespondido->getAutor() == (*it)->getNombre())){
            (*it)->notify(new Notificacion(texto, clase->getAsignatura()->getCodigo(), id, reloj->getTimer(), usuario->getNombre()));
        }
    }
    return mensaje->getId();
}

set<DtClase*>* AsignaturaClaseController::listarClasesEnVivoPorAsignatura(string codigo){
    Asignatura* asignatura = aHandler->getAsignatura(codigo);
    set<Clase*>* clases = asignatura->getClases();
    DtAsignatura* dtAsignatura = new DtAsignatura(asignatura->getCodigo(),asignatura->getNombre(),asignatura->getTieneTeorico(),
                                                  asignatura->getTienePractico(),asignatura->getTieneMonitoreo());
    set<DtClase*>* dtClasesVivo = new set<DtClase*>();
    for (set<Clase*>::iterator it = clases->begin(); it != clases->end(); ++it){
        if (!(*it)->esClaseEnDiferido()){
            dtClasesVivo->insert(new DtClase((*it)->getCodigo(),(*it)->getNombre(),(*it)->getInicio(),(*it)->getFin(),(*it)->getUrlVideo(),(*it)->getIniciadaPor(),dtAsignatura));
        }
    }
    return dtClasesVivo;
}