#include "ClaseNotAvailable.h"

ClaseNotAvailable::ClaseNotAvailable(){}

const char* ClaseNotAvailable::what()const throw(){
    return "La clase requerida no existe en la Asignatura seleccionada";
}
