#include "Sesion.h"

Sesion* Sesion::instance=NULL;

Sesion::Sesion() {
    this->usuario=NULL;
}

void Sesion::cerrarSesion() {
    this->usuario=NULL;
}

Sesion* Sesion::getInstance() {
    if(instance==NULL){
        instance = new Sesion();
    }
    return instance;
}

Usuario* Sesion::getUsuario() {
    return this->usuario;
}

void Sesion::iniciarSesion(Usuario* user) {
    this->usuario=user;
}

Sesion::~Sesion() {

}
