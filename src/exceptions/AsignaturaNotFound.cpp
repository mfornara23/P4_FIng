#include "AsignaturaNotFound.h"

AsignaturaNotFound::AsignaturaNotFound(){
}

const char* AsignaturaNotFound::what()const throw(){
    return "La asignatura solicitada no se encuentra en el sistema";
}
