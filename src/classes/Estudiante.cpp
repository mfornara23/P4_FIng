#include "Estudiante.h"

Estudiante::Estudiante(string &nombre, string &email, string &password, string &imagen, int cedula) : Usuario(nombre,
                                                                                                              email,
                                                                                                              password,
                                                                                                              imagen) {
    this->cedula = cedula;
    this->asignaturas = new set<Asignatura *>();
    this->asistencias = new set<Asistencia *>();
}

void Estudiante::setCedula(int cedula) {
    this->cedula = cedula;
}

void Estudiante::addAsistencia(Asistencia *asis) {
    this->asistencias->insert(asis);
}

void Estudiante::addAsignatura(Asignatura *asig) {
    this->asignaturas->insert(asig);
}

set<Asignatura *> *Estudiante::getAsignaturas() {
    return asignaturas;
}

int Estudiante::getCedula() {
    return cedula;
}

set<Asistencia *> *Estudiante::getAsistencias() {
    return asistencias;
}

bool Estudiante::cursaAsignatura(Asignatura *asig) {
    return this->asignaturas->find(asig) != this->asignaturas->end();
}

void Estudiante::eliminarAsignatura(Asignatura *a) {
    this->asistencias->clear();
    this->asignaturas->erase(a);
}

Estudiante::~Estudiante() {
    for(set<Asignatura*>::iterator it = this->asignaturas->begin(); it!=this->asignaturas->end(); ++it){
        Asignatura * a = (*it);
        delete a;
    }
    for(set<Asistencia*>::iterator iterator = this->asistencias->begin(); iterator != this->asistencias->end(); ++iterator) {
        Asistencia * asistencia = (*iterator);
        delete asistencia;
    }
    this->asignaturas->clear();
    this->asistencias->clear();
    delete this->asignaturas;
    delete this->asistencias;
}