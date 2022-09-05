#include "AsignacionNotFound.h"

AsignacionNotFound::AsignacionNotFound(){
}

const char* AsignacionNotFound::what()const throw(){
    return "La asignacion solicitada no se encuentra en el sistema";
}
