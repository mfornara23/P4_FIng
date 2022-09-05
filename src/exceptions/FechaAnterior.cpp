#include "FechaAnterior.h"

FechaAnterior::FechaAnterior(string mensaje){
    this->message = mensaje;
}

const char* FechaAnterior::what()const throw(){
    return this->message.c_str();
}
