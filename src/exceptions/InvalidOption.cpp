#include "InvalidOption.h"

InvalidOption::InvalidOption(){
}

const char* InvalidOption::what()const throw(){
    return "La opcion ingresada no es valida.";
}

