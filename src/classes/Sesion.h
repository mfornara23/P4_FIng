
#ifndef SESION_H
#define	SESION_H

#include "Usuario.h"


class Sesion {
private:
    static Sesion* instance;
    Sesion();
    Usuario* usuario;
public:
    static Sesion* getInstance();
    void iniciarSesion(Usuario* user);
    void cerrarSesion();
    Usuario* getUsuario();
    virtual ~Sesion();

};

#endif	/* SESION_H */

