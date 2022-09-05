#include "AsistenciaEnVivo.h"

AsistenciaEnVivo::AsistenciaEnVivo(DtFecha* inicio, DtFecha* fin, Clase *clase, Usuario* u):Asistencia(clase,u){
    this->inicio=inicio;
    this->fin=fin;
}

AsistenciaEnVivo::~AsistenciaEnVivo() {

}

DtFecha* AsistenciaEnVivo::getInicio() {
    return inicio;
}

void AsistenciaEnVivo::setInicio(DtFecha* inicio) {
    this->inicio = inicio;
}

DtFecha* AsistenciaEnVivo::getFin() {
    return fin;
}

void AsistenciaEnVivo::setFin(DtFecha* fin) {
    this->fin = fin;
}