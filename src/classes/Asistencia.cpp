#include "Asistencia.h"

Asistencia::Asistencia(Clase *clase, Usuario *usuario) {
    this->clase = clase;
    this->usuario = usuario;
}

Clase *Asistencia::getClase() {
    return clase;
}

void Asistencia::setClase(Clase *clase) {
    this->clase = clase;
}

Asistencia::~Asistencia() {
}

Usuario *Asistencia::getUsuario() {
    return usuario;
}

void Asistencia::setUsuario(Usuario *usuario) {
    Asistencia::usuario = usuario;
}
