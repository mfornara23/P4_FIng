#include "WrongPassword.h"

WrongPassword::WrongPassword(){
}

const char* WrongPassword::what()const throw(){
    return "Clave incorrecta.";
}
