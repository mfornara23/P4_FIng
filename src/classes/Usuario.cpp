#include "Usuario.h"

Usuario::Usuario(string &nombre, string &email, string &password, string &imagen) {
    this->nombre = nombre;
    this->email = email;
    this->password = password;
    this->imagen = imagen;
    notificaciones = new set<Notificacion *>();
}

string &Usuario::getEmail() {
    return email;
}

void Usuario::setEmail(string &email) {
    this->email = email;
}

string &Usuario::getImagen()  {
    return imagen;
}

void Usuario::setImagen(string &imagen) {
    this->imagen = imagen;
}

string &Usuario::getNombre()  {
    return nombre;
}

void Usuario::setNombre(string &nombre) {
    this->nombre = nombre;
}

set<DtNotificacion *> *Usuario::getNotificaciones() {
    set<DtNotificacion *> *dtnotificaciones = new set<DtNotificacion *>();
    for (set<Notificacion *>::iterator it = notificaciones->begin(); it != notificaciones->end(); it++) {
        dtnotificaciones->insert(
                new DtNotificacion((*it)->getContenidoMensaje(), (*it)->getCodigoAsignatura(), (*it)->getCodigoClase(),
                                   (*it)->getHoraMensaje(), (*it)->getAutor()));
    };
    return dtnotificaciones;
}

string &Usuario::getPassword()  {
    return password;
}

void Usuario::setPassword(string &password) {
    this->password = password;
}

void Usuario::notify(Notificacion *n) {
    notificaciones->insert(n);
}

void Usuario::eliminarAsignatura(Asignatura *a) {

}
void Usuario::eliminarNotificaciones() {
    for (set<Notificacion *>::iterator it = notificaciones->begin(); it != notificaciones->end(); it++) {
        Notificacion *n = (*it);
        delete n;
    };
    notificaciones->clear();
}

void Usuario::eliminarSuscripcion() {

}

Usuario::~Usuario() {
    this->eliminarNotificaciones();
    delete notificaciones;
}
