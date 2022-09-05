#include "UsuarioNotFound.h"

UsuarioNotFound::UsuarioNotFound(){
}

const char* UsuarioNotFound::what()const throw(){
    return "El usuario solicitado no se encuentra en el sistema";
}
