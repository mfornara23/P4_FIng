#include "DtReporteTiempoDictado.h"

DtReporteTiempoDictado::DtReporteTiempoDictado(DtAsignatura *dtAsignatura, int tiempoEnSegundos) {
    this->dtAsignatura = dtAsignatura;
    this->tiempoDictadoEnSegundos = tiempoEnSegundos;
}

DtReporteTiempoDictado::~DtReporteTiempoDictado() {

}

DtAsignatura *DtReporteTiempoDictado::getDtAsignatura() {
    return dtAsignatura;
}

void DtReporteTiempoDictado::setDtAsignatura(DtAsignatura *dtAsignatura) {
    this->dtAsignatura = dtAsignatura;
}

int DtReporteTiempoDictado::getTiempoDictado() {
    return this->tiempoDictadoEnSegundos;
}

void DtReporteTiempoDictado::setTiempoDictado(int tiempoEnSegundos) {
    this->tiempoDictadoEnSegundos = tiempoEnSegundos;
}

void DtReporteTiempoDictado::addTiempo(int tiempoEnSegundos) {
    this->tiempoDictadoEnSegundos += tiempoEnSegundos;
}

string DtReporteTiempoDictado::toString() {
    string horas = to_string(static_cast<int>(this->tiempoDictadoEnSegundos / 3600));
    if (static_cast<int>(this->tiempoDictadoEnSegundos / 3600) < 10) horas = "0"+ horas;
    string minutos = to_string(static_cast<int>((this->tiempoDictadoEnSegundos % 3600) / 60));
    if (static_cast<int>((this->tiempoDictadoEnSegundos % 3600) / 60) < 10) minutos = "0" + minutos;
    string retorno =
            "    - Asignatura: " + this->dtAsignatura->getNombre() + " - " + this->dtAsignatura->getCodigo() + "\n" +
            "    - Tiempo dictado: " + horas + ":" + minutos;

    return retorno;
}