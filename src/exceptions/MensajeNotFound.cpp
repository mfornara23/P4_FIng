#include "MensajeNotFound.h"

MensajeNotFound::MensajeNotFound(){
}

const char* MensajeNotFound::what()const throw(){
    return "El mensaje solicitado no se encuentra en el sistema";
}
