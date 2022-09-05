#include "AsignacionDuplicated.h"

AsignacionDuplicated::AsignacionDuplicated(){
}

const char* AsignacionDuplicated::what()const throw(){
    return "La asignatura ya se encuentra asignada al docente con ese rol";
}
