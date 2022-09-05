#include "UsuarioDuplicated.h"

UsuarioDuplicated::UsuarioDuplicated(){
}

const char* UsuarioDuplicated::what()const throw(){
    return "El usuario ingresado ya existe en el sistema";
}
