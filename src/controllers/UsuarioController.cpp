#include "UsuarioController.h"

#include "../exceptions/UsuarioNotFound.h"
#include "../exceptions/UsuarioDuplicated.h"
#include "../exceptions/WrongPassword.h"
#include "../exceptions/FechaAnterior.h"


UsuarioController::UsuarioController(){
    this->uHandler = UsuarioHandler::getInstance();
    this->reloj = Reloj::getInstance();
    this->sesion = Sesion::getInstance();
}

UsuarioController::~UsuarioController(){

}

void UsuarioController::altaUsuario(DtUsuario* usuario){
    DtEstudiante* dtEstudiante = dynamic_cast<DtEstudiante*>(usuario);
    DtDocente* dtDocente = dynamic_cast<DtDocente*>(usuario);
    DtAdministrador* DtAdmin = dynamic_cast<DtAdministrador*>(usuario);

    try{
        if((dtEstudiante!=NULL && uHandler->getEstudiante(dtEstudiante->getCedula())) ||
            (dtDocente!=NULL && uHandler->getDocente(dtDocente->getEmail())) ||
                (DtAdmin!=NULL && uHandler->getAdministrador(DtAdmin->getEmail()))){
                    throw UsuarioDuplicated();
                }
    }catch(UsuarioNotFound& e){
        if(dtEstudiante!=NULL){
            uHandler->addEstudiante(dtEstudiante);
        }else if(dtDocente!=NULL){
            uHandler->addDocente(dtDocente);
        }else{
            uHandler->addAdministrador(DtAdmin);
        }
    }
}

set<DtNotificacion*>* UsuarioController::consultarNotificaciones(string &email){
    Usuario* usuario = uHandler->getUsuario(email);
    set<DtNotificacion*>* dtnotificaciones = usuario->getNotificaciones();
    usuario->eliminarNotificaciones();
    return dtnotificaciones;
}

void UsuarioController::modificarFechaSistema(DtFecha* nuevaFecha){
    this->reloj->setTimer(nuevaFecha);
}

DtFecha* UsuarioController::obtenerFechaSistema(){
    return this->reloj->getTimer();
}

void UsuarioController::iniciarSesion(string &email, string &password){
    Usuario* usuario = uHandler->getUsuario(email);
    if (usuario->getPassword() != password){
        throw WrongPassword();
    }

    sesion->iniciarSesion(usuario);

}

DtUsuario* UsuarioController::getUsuarioLoggeado(){
    if (sesion->getUsuario() == NULL) {
        return NULL;
    } else if (Docente* docente = dynamic_cast<Docente*>(sesion->getUsuario())) {
        DtDocente* dtDocente = new DtDocente(docente->getNombre(),
                                             docente->getEmail(),
                                             docente->getPassword(),
                                             docente->getImagen(),
                                             docente->getNombreInst());
        dtDocente->setAsignaciones(docente->getAsignaciones());
        return dtDocente;
    } else if (Estudiante* estudiante = dynamic_cast<Estudiante*>(sesion->getUsuario())) {
        return new DtEstudiante(estudiante->getNombre(),
                                estudiante->getEmail(),
                                estudiante->getPassword(),
                                estudiante->getImagen(),
                                   estudiante->getCedula());
    } else {
        return new DtAdministrador(sesion->getUsuario()->getNombre(),
                                   sesion->getUsuario()->getEmail(),
                                   sesion->getUsuario()->getPassword(),
                                   sesion->getUsuario()->getImagen());
    }
}

void UsuarioController::cerrarSesion(){
    sesion->cerrarSesion();
}