#include "DtEstudiante.h"

DtEstudiante::~DtEstudiante() {
    for(set<DtAsignatura*>::iterator it = this->dtAsignaturas->begin(); it!=this->dtAsignaturas->end(); ++it){
        DtAsignatura * a = (*it);
        delete a;
    }
    for(set<DtAsistencia*>::iterator iterator = this->dtAsistencias->begin(); iterator != this->dtAsistencias->end(); ++iterator) {
        DtAsistencia * asistencia = (*iterator);
        delete asistencia;
    }
    this->dtAsignaturas->clear();
    this->dtAsistencias->clear();
    delete this->dtAsignaturas;
    delete this->dtAsistencias;
}

int DtEstudiante::getCedula() {
    return cedula;
}

void DtEstudiante::setCedula(int cedula) {
    DtEstudiante::cedula = cedula;
}

set<DtAsignatura *> *DtEstudiante::getDtAsignaturas() {
    return dtAsignaturas;
}

void DtEstudiante::setDtAsignaturas(set<DtAsignatura *> *dtAsignaturas) {
    DtEstudiante::dtAsignaturas = dtAsignaturas;
}

set<DtAsistencia *> *DtEstudiante::getDtAsistencias() {
    return dtAsistencias;
}

void DtEstudiante::setDtAsistencias(set<DtAsistencia *> *dtAsistencias) {
    DtEstudiante::dtAsistencias = dtAsistencias;
}

DtEstudiante::DtEstudiante() {

}

DtEstudiante::DtEstudiante(string nombre, string email, string password, string imagen, int cedula) : DtUsuario(nombre,
                                                                                                                email,
                                                                                                                password,
                                                                                                                imagen) {
    this->cedula = cedula;
    this->dtAsignaturas = new set<DtAsignatura *>();
    this->dtAsistencias = new set<DtAsistencia *>();
}
