#include "ClaseDuplicated.h"

ClaseDuplicated::ClaseDuplicated(){}

const char* ClaseDuplicated::what()const throw(){
    return "La clase ya existe en el sistema";
}
