#ifndef LAB5_USUARIO_H
#define LAB5_USUARIO_H

#include <string>
#include <set>

#include "Asignatura.h"
#include "Notificacion.h"
#include "Mensaje.h"
#include "../datatypes/DtNotificacion.h"

using namespace std;

class Usuario {
private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<Notificacion *> *notificaciones;
public:
    Usuario(string &nombre, string &email, string &password, string &imagen);
    string &getEmail();
    void setEmail(string &email);
    string &getImagen();
    void setImagen(string &imagen);
    string &getNombre();
    void setNombre(string &nombre);
    set<DtNotificacion *> *getNotificaciones();
    string &getPassword();
    void setPassword(string &password);
    void notify(Notificacion *n);
    virtual void eliminarAsignatura(Asignatura *a);
    void eliminarNotificaciones();
    void eliminarSuscripcion();
    virtual ~Usuario();
};

#endif //USUARIO_H
