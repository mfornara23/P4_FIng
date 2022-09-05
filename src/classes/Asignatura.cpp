#include "Asignatura.h"

bool Asignatura::getTieneTeorico() {
    return tieneTeorico;
}

bool Asignatura::getTienePractico() {
    return tienePractico;
}

bool Asignatura::getTieneMonitoreo() {
    return tieneMonitoreo;
}

void Asignatura::setTieneTeorico(bool tieneTeorico) {
    this->tieneTeorico = tieneTeorico;
}

void Asignatura::setTienePractico(bool tienePractico) {
    this->tienePractico = tienePractico;
}

void Asignatura::setTieneMonitoreo(bool tieneMonitoreo) {
    this->tieneMonitoreo = tieneMonitoreo;
}

string &Asignatura::getCodigo() {
    return codigo;
}

void Asignatura::setCodigo(string &codigo) {
    this->codigo = codigo;
}

string &Asignatura::getNombre() {
    return nombre;
}

void Asignatura::setNombre(string &nombre) {
    Asignatura::nombre = nombre;
}

set<Clase *> *Asignatura::getClases() {
    return clases;
}

void Asignatura::setClases(set<Clase *> *clases) {
    this->clases = clases;
}

void Asignatura::addEstudiante(Estudiante *estudiante) {
    this->estudiantes->insert(estudiante);
}

set<Estudiante *> *Asignatura::getEstudiantes() {
    return this->estudiantes;
}

void Asignatura::removeEstudiante(Estudiante *estudiante) {
    this->estudiantes->erase(estudiante);
}

void Asignatura::removeAllEstudiantes() {
    this->estudiantes->clear();
}

void Asignatura::addDocente(Docente *docente) {
    this->docentes->insert(docente);
}

set<Docente *> *Asignatura::getDocentes() {
    return this->docentes;
}

void Asignatura::removeDocente(Docente *docente) {
    this->docentes->erase(docente);
}

void Asignatura::removeAllDocentes() {
    this->docentes->clear();
}

Asignatura::Asignatura(string &codigo, string &nombre, bool tieneTeorico, bool tienePractico, bool tieneMonitoreo) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->tieneTeorico = tieneTeorico;
    this->tienePractico = tienePractico;
    this->tieneMonitoreo = tieneMonitoreo;
    this->clases = new set<Clase *>();
    this->docentes = new set<Docente *>();
    this->estudiantes = new set<Estudiante *>();
}

Asignatura::~Asignatura() {
    this->docentes->clear();
    delete this->docentes;
    this->estudiantes->clear();
    delete this->estudiantes;
    this->clases->clear();
    delete this->clases;
}

void Asignatura::addClase(Clase *clase) {
    this->clases->insert(clase);
}