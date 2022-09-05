#include "Docente.h"
#include "Asistencia.h"
#include "Asignatura.h"
#include "AsistenciaEnDiferido.h"
#include "../exceptions/AsignacionNotFound.h"
#include "AsistenciaEnVivo.h"

Instituto Docente::getNombreInst() {
    return nombreInst;
}

void Docente::setNombreInst(Instituto nombreInst) {
    this->nombreInst = nombreInst;
}

tipoAsignacion Docente::getTipoAsignacion(string codigo) {
    tipoAsignacion asignacion;
    bool found = false;
    for(map<Asignatura*,tipoAsignacion >::iterator it = asignaciones->begin(); it != asignaciones->end(); ++it) {
        if(it->first->getCodigo() == codigo) {
            asignacion = it->second;
            found = true;
        }
    }
    if (!found) {
        throw AsignacionNotFound();
    }
    return asignacion;
}

set<DtAsignatura *> *Docente::getAsignaturas() {
    set<DtAsignatura *> *asignaturas = new set<DtAsignatura *>();
    for (map<Asignatura *, tipoAsignacion>::iterator it = asignaciones->begin(); it != asignaciones->end(); ++it) {
        asignaturas->insert(
                new DtAsignatura(it->first->getCodigo(), it->first->getNombre(), it->first->getTieneTeorico(),
                                 it->first->getTienePractico(), it->first->getTieneMonitoreo()));
    }
    return asignaturas;
}

void Docente::asignar(Asignatura *asig, tipoAsignacion rol) {
    this->asignaciones->insert(pair<Asignatura*,tipoAsignacion>(asig,rol));
}

set<Clase*> *Docente::getClasesVivo() {
    set<Clase *> *clases = new set<Clase *>();
    set<Clase *> *clasesVivo = new set<Clase *>();
    for (map<Asignatura *, tipoAsignacion>::iterator it = asignaciones->begin(); it != asignaciones->end(); ++it) {
        clases = (it->first->getClases());
        for (set<Clase *>::iterator i = clases->begin(); i != clases->end(); ++i) {
            if (!(*i)->esClaseEnDiferido() && (*i)->getIniciadaPor()==this->getEmail() ) {
                clasesVivo->insert(*i);
            }
        }
    }
    
    return clasesVivo;
}

void Docente::eliminarAsignatura(Asignatura *a) {
    asistencias->clear();
    asignaciones->erase(a);
}

bool Docente::estaAsignado(Asignatura *a) {
    return this->asignaciones->find(a) != this->asignaciones->end();
}

map<DtAsignatura *, tipoAsignacion> *Docente::getAsignaciones() {
    map<DtAsignatura *, tipoAsignacion> *asignacionesMap = new map<DtAsignatura *, tipoAsignacion>();
    for (map<Asignatura *, tipoAsignacion>::iterator it = asignaciones->begin(); it != asignaciones->end(); ++it) {
        asignacionesMap->insert(pair<DtAsignatura *, tipoAsignacion>(
                new DtAsignatura(it->first->getCodigo(), it->first->getNombre(), it->first->getTieneTeorico(),
                                 it->first->getTienePractico(), it->first->getTieneMonitoreo()), it->second));
    }
    return asignacionesMap;
}

Docente::~Docente() {
    for(map<Asignatura*, tipoAsignacion>::iterator it = this->asignaciones->begin(); it!=this->asignaciones->end(); ++it){
        Asignatura * a = it->first;
        delete a;
    }
    for(set<Asistencia*>::iterator iterator = this->asistencias->begin(); iterator != this->asistencias->end(); ++iterator) {
        Asistencia * asistencia = (*iterator);
        delete asistencia;
    }
    this->asignaciones->clear();
    this->asistencias->clear();
    delete this->asignaciones;
    delete this->asistencias;
}

Docente::Docente(string &nombre, string &email, string &password, string &imagen,
                 Instituto nombreInst) : Usuario(nombre, email, password, imagen) {
    this->nombreInst = nombreInst;
    this->asignaciones = new map<Asignatura *, tipoAsignacion>();
    this->asistencias = new set<Asistencia *>();
}



