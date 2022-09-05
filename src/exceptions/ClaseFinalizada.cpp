#include "ClaseFinalizada.h"

ClaseFinalizada::ClaseFinalizada(){}

const char* ClaseFinalizada::what()const throw(){
    return "La clase seleccionada ya ha finalizado";
}
