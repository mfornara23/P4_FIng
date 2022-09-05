#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"

class Administrador : public Usuario{

public:
    Administrador();
    Administrador(string &nombre, string &email, string &password, string &imagen);
    ~Administrador();
};


#endif //ADMINISTRADOR_H
