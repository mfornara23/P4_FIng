#include "DtDocente.h"
#include "DtClase.h"

DtDocente::~DtDocente() {
    for(map<DtAsignatura*, tipoAsignacion>::iterator it = this->asignaciones->begin(); it!=this->asignaciones->end(); ++it){
        DtAsignatura * a = it->first;
        delete a;
    }
    for(set<DtAsistencia*>::iterator iterator = this->asistencias->begin(); iterator != this->asistencias->end(); ++iterator) {
        DtAsistencia * asistencia = (*iterator);
        delete asistencia;
    }
    this->asignaciones->clear();
    this->asistencias->clear();
    delete this->asignaciones;
    delete this->asistencias;
}

Instituto DtDocente::getNombreInst()  {
    return nombreInst;
}

void DtDocente::setNombreInst(Instituto nombreInst) {
    DtDocente::nombreInst = nombreInst;
}

DtDocente::DtDocente(){}

DtDocente::DtDocente( string nombre,  string email,  string password,  string imagen, Instituto nombreInst) : DtUsuario(nombre, email, password, imagen){
    this->nombreInst = nombreInst;
    this->asignaciones = new map<DtAsignatura *, tipoAsignacion>();
}

map<DtAsignatura *, tipoAsignacion> *DtDocente::getAsignaciones()  {
    return asignaciones;
}

void DtDocente::setAsignaciones(map<DtAsignatura *, tipoAsignacion> *asignaciones) {
    DtDocente::asignaciones = asignaciones;
}

set<DtAsistencia *> *DtDocente::getAsistencias()  {
    return asistencias;
}

void DtDocente::setAsistencias(set<DtAsistencia *> *asistencias) {
    DtDocente::asistencias = asistencias;
}

