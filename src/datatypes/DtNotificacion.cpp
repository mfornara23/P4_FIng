#include "DtNotificacion.h"

DtNotificacion::DtNotificacion(string &contenidoMensaje, string &codigoAsignatura, int codigoClase, DtFecha* horaMensaje, string autor){
    this->contenidoMensaje = contenidoMensaje;
    this->codigoAsignatura = codigoAsignatura;
    this->codigoClase = codigoClase;
    this->horaMensaje = horaMensaje;
    this->autor = autor;
}

string &DtNotificacion::getAutor()  {
    return autor;
}

void DtNotificacion::setAutor(string &autor) {
    this->autor = autor;
}

string &DtNotificacion::getCodigoAsignatura()  {
    return codigoAsignatura;
}

void DtNotificacion::setCodigoAsignatura(string &codigoAsignatura) {
    this->codigoAsignatura = codigoAsignatura;
}

int DtNotificacion::getCodigoClase()  {
    return codigoClase;
}

void DtNotificacion::setCodigoClase(int codigoClase) {
    this->codigoClase = codigoClase;
}

string &DtNotificacion::getContenidoMensaje()  {
    return contenidoMensaje;
}

void DtNotificacion::setContenidoMensaje(string &contenidoMensaje) {
    this->contenidoMensaje = contenidoMensaje;
}

DtFecha* DtNotificacion::getHoraMensaje() {
    return horaMensaje;
}

void DtNotificacion::setHoraMensaje(DtFecha* horaMensaje) {
    this->horaMensaje = horaMensaje;
}

DtNotificacion::~DtNotificacion()
{
}

