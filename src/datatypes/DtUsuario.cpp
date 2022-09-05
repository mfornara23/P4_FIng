#include "DtUsuario.h"

DtUsuario::DtUsuario() {
}

DtUsuario::DtUsuario(string &nombre, string &email, string &password, string &imagen) {
    this->nombre = nombre;
    this->email = email;
    this->password = password;
    this->imagen = imagen;
    this->dtNotificaciones = new set<DtNotificacion *>();
}

DtUsuario::~DtUsuario() {

}

string &DtUsuario::getNombre() {
    return nombre;
}

void DtUsuario::setNombre(string &nombre) {
    DtUsuario::nombre = nombre;
}

string &DtUsuario::getEmail() {
    return email;
}

void DtUsuario::setEmail(string &email) {
    DtUsuario::email = email;
}

string &DtUsuario::getPassword() {
    return password;
}

void DtUsuario::setPassword(string &password) {
    DtUsuario::password = password;
}

string &DtUsuario::getImagen() {
    return imagen;
}

void DtUsuario::setImagen(string &imagen) {
    DtUsuario::imagen = imagen;
}

set<DtNotificacion *> *DtUsuario::getDtNotificaciones() {
    return dtNotificaciones;
}

void DtUsuario::setDtNotificaciones(set<DtNotificacion *> *dtNotificaciones) {
    DtUsuario::dtNotificaciones = dtNotificaciones;
}