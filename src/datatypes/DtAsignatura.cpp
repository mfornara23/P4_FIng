#include "DtAsignatura.h"

DtAsignatura::DtAsignatura(string codigo, string nombre, bool teorico, bool practico, bool monitoreo) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->tieneTeorico = teorico;
    this->tienePractico = practico;
    this->tieneMonitoreo = monitoreo;
}

DtAsignatura::~DtAsignatura() {

}

bool operator< (const DtAsignatura& asignatura1, const DtAsignatura& asignatura2) {
    return asignatura1.codigo < asignatura2.codigo;
}

string &DtAsignatura::getCodigo() {
    return this->codigo;
}

void DtAsignatura::setCodigo(string &codigo) {
    this->codigo = codigo;
}

string &DtAsignatura::getNombre() {
    return this->nombre;
}

void DtAsignatura::setNombre(string &nombre) {
    this->nombre = nombre;
}

bool DtAsignatura::isTeorico() {
    return this->tieneTeorico;
}

void DtAsignatura::setTeorico(bool teorico) {
    this->tieneTeorico = teorico;
}

bool DtAsignatura::isPractico() {
    return this->tienePractico;
}

void DtAsignatura::setPractico(bool practico) {
    this->tienePractico = practico;
}

bool DtAsignatura::isMonitoreo() {
    return this->tieneMonitoreo;
}

void DtAsignatura::setMonitoreo(bool monitoreo) {
    this->tieneMonitoreo = monitoreo;
}

DtAsignatura::DtAsignatura() {}

set<DtClase *> *DtAsignatura::getDtClases() {
    return this->dtClases;
}

void DtAsignatura::setDtClases(set<DtClase *> *dtClases) {
    this->dtClases = dtClases;
}
