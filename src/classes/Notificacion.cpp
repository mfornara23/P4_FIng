#include "Notificacion.h"

Notificacion::Notificacion(string &contenidoMensaje, string &codigoAsignatura, int codigoClase, DtFecha *horaMensaje,
                           string &autor) {
    this->contenidoMensaje = contenidoMensaje;
    this->codigoAsignatura = codigoAsignatura;
    this->codigoClase = codigoClase;
    this->horaMensaje = horaMensaje;
    this->autor = autor;
}

string &Notificacion::getAutor() {
    return autor;
}

void Notificacion::setAutor(string &autor) {
    this->autor = autor;
}

string &Notificacion::getCodigoAsignatura() {
    return codigoAsignatura;
}

void Notificacion::setCodigoAsignatura(string &codigoAsignatura) {
    this->codigoAsignatura = codigoAsignatura;
}

int Notificacion::getCodigoClase() {
    return codigoClase;
}

void Notificacion::setCodigoClase(int codigoClase) {
    this->codigoClase = codigoClase;
}

string &Notificacion::getContenidoMensaje() {
    return contenidoMensaje;
}

void Notificacion::setContenidoMensaje(string &contenidoMensaje) {
    this->contenidoMensaje = contenidoMensaje;
}

DtFecha *Notificacion::getHoraMensaje() {
    return horaMensaje;
}

void Notificacion::setHoraMensaje(DtFecha *horaMensaje) {
    this->horaMensaje = horaMensaje;
}


Notificacion::~Notificacion() {
}
