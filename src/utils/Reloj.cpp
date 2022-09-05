#include "Reloj.h"

Reloj* Reloj::instance = NULL;

Reloj::~Reloj() {}

Reloj::Reloj() {}

Reloj* Reloj::getInstance() {
    if (instance == NULL){
        instance = new Reloj();
    }
        
    return instance;
}

DtFecha *Reloj::getTimer() {
    return this->timer;
}

void Reloj::setTimer(DtFecha *timer) {
    this->timer = timer;
}
