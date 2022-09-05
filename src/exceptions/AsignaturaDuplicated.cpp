#include "AsignaturaDuplicated.h"

AsignaturaDuplicated::AsignaturaDuplicated(){
}

const char* AsignaturaDuplicated::what()const throw(){
    return "La asignatura ya existe en el sistema";
}
