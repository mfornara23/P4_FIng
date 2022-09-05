#include "ClaseNotFound.h"

ClaseNotFound::ClaseNotFound(){
}

const char* ClaseNotFound::what()const throw(){
    return "La clase solicitada no fue encontrada";
}
