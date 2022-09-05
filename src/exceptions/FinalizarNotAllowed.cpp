#include "FinalizarNotAllowed.h"

FinalizarNotAllowed::FinalizarNotAllowed(){
}

const char* FinalizarNotAllowed::what()const throw(){
    return "El Docente no tiene permiso para finalizar la Clase.";
}
