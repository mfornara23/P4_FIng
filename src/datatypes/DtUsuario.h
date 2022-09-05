#ifndef LAB5_DTUSUARIO_H
#define LAB5_DTUSUARIO_H

#include <set>

#include "DtNotificacion.h"

using namespace std;

class DtUsuario {
private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<DtNotificacion*>* dtNotificaciones;
public:
    DtUsuario();
    DtUsuario( string &nombre,  string &email,  string &password,  string &imagen);
     string &getNombre() ;
    void setNombre( string &nombre);
    string& getEmail();
    void setEmail( string &email);
     string &getPassword() ;
    void setPassword( string &password);
     string &getImagen() ;
    void setImagen( string &imagen);
    set<DtNotificacion*>* getDtNotificaciones() ;
    void setDtNotificaciones(set<DtNotificacion*>* dtNotificaciones);
    int getCantNotificaciones() ;
    void setCantNotificaciones(int cantNotificaciones);
    virtual ~DtUsuario();
};

#endif //LAB5_DTUSUARIO_H
