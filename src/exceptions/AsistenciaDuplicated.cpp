#include "AsistenciaDuplicated.h"

AsistenciaDuplicated::AsistenciaDuplicated(){
}

const char* AsistenciaDuplicated::what()const throw(){
    return "El estudiante ya se encuentra asistiendo a la clase";
}
