#include "Mensaje.h"

int Mensaje::currentId = 0;

Mensaje::Mensaje(string &autor, string &contenido, DtFecha *fechaEnvio, int respondeA) {
    this->id = ++this->currentId;;
    this->autor = autor;
    this->contenido = contenido;
    this->fechaEnvio = fechaEnvio;
    this->respondeA = respondeA;
}

string &Mensaje::getAutor() {
    return autor;
}

void Mensaje::setAutor(string &autor) {
    this->autor = autor;
}

string &Mensaje::getContenido() {
    return contenido;
}

void Mensaje::setContenido(string &contenido) {
    this->contenido = contenido;
}

DtFecha *Mensaje::getFechaEnvio() {
    return fechaEnvio;
}

void Mensaje::setFechaEnvio(DtFecha *fechaEnvio) {
    this->fechaEnvio = fechaEnvio;
}

int Mensaje::getId() {
    return id;
}

int Mensaje::getRespondeA() {
    return respondeA;
}

void Mensaje::setRespondeA(int respondeA) {
    this->respondeA = respondeA;
}

Mensaje::~Mensaje() {
}

Clase *Mensaje::getClase() {
    return clase;
}

void Mensaje::setClase(Clase *clase) {
    this->clase = clase;
}

