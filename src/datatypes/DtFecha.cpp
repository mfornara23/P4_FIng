#include <stdexcept>
#include "DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio, int hora, int minuto) {
    if (dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 1900 || hora >= 24 || hora < 0 || minuto >= 60 ||
        minuto < 0) {
        throw invalid_argument("Formato de fecha incorrecto.");
    } else {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
        this->hora = hora;
        this->minuto = minuto;
    }
}

bool DtFecha::esAnterior(DtFecha *fechaActual, DtFecha *nuevaFecha) {
    if (fechaActual == NULL) return false;
    if (fechaActual->getAnio() == nuevaFecha->getAnio()) {
        if (fechaActual->getMes() == nuevaFecha->getMes()) {
            if (fechaActual->getDia() == nuevaFecha->getDia()) {
                if (fechaActual->getHora() == nuevaFecha->getHora()) {
                    if (fechaActual->getMinuto() <= nuevaFecha->getMinuto()) {
                        return true;
                    }
                } else if (fechaActual->getHora() < nuevaFecha->getHora()){
                    return true;
                }
            } else if (fechaActual->getDia() < nuevaFecha->getDia()) {
                return true;
            }
        } else if (fechaActual->getMes() < nuevaFecha->getMes()) {
            return true;
        }
    } else if (fechaActual->getAnio() < nuevaFecha->getAnio()) {
        return true;
    }
    return false;
}

int DtFecha::getAnio() {
    return anio;
}

void DtFecha::setAnio(int anio) {
    this->anio = anio;
}

void DtFecha::setDia(int dia) {
    this->dia = dia;
}

void DtFecha::setHora(int hora) {
    this->hora = hora;
}

void DtFecha::setMes(int mes) {
    this->mes = mes;
}

void DtFecha::setMinuto(int minuto) {
    this->minuto = minuto;
}

DtFecha::~DtFecha() {
}

int DtFecha::getDia() {
    return dia;
}

int DtFecha::getMes() {
    return mes;
}

int DtFecha::getHora() {
    return hora;
}

int DtFecha::getMinuto() {
    return minuto;
}

DtFecha::DtFecha() {}

string DtFecha::toString() {
    string hora = to_string(this->hora);
    string minutos = to_string(this->minuto);
    if (this->hora < 10) {
        hora = "0" + hora;
    }
    if (this->minuto < 10) {
        minutos = "0" + minutos;
    }
    return hora + ":" + minutos;
}