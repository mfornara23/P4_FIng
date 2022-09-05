#include "DtMensaje.h"

DtMensaje::DtMensaje(int id,  string &autor,  string &contenido, DtFecha* fechaEnvio, int respondeA){
    this->id = id;
    this->autor = autor;
    this->contenido = contenido;
    this->fechaEnvio = fechaEnvio;
    this->respondeA = respondeA;
}

int DtMensaje::getId()  {
    return id;
}

void DtMensaje::setId(int id) {
    DtMensaje::id = id;
}

 string &DtMensaje::getAutor()  {
    return autor;
}

void DtMensaje::setAutor( string &autor) {
    DtMensaje::autor = autor;
}

 string &DtMensaje::getContenido()  {
    return contenido;
}

void DtMensaje::setContenido( string &contenido) {
    DtMensaje::contenido = contenido;
}

DtFecha* DtMensaje::getFechaEnvio() {
    return fechaEnvio;
}

void DtMensaje::setFechaEnvio(DtFecha* fechaEnvio) {
    DtMensaje::fechaEnvio = fechaEnvio;
}

int DtMensaje::getRespondeA()  {
    return respondeA;
}

void DtMensaje::setRespondeA(int respondeA) {
    DtMensaje::respondeA = respondeA;
}

DtClase *DtMensaje::getDtClase()  {
    return dtClase;
}

void DtMensaje::setDtClase(DtClase *dtClase) {
    DtMensaje::dtClase = dtClase;
}

DtMensaje::~DtMensaje() {

}

