#include "AsignacionNotAvailable.h"

AsignacionNotAvailable::AsignacionNotAvailable(){
}

const char* AsignacionNotAvailable::what()const throw(){
    return "La asignatura no cuenta con el tipo de asignacion especificado.";
}
