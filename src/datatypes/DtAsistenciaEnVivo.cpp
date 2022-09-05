#include "DtAsistenciaEnVivo.h"

DtAsistenciaEnVivo::DtAsistenciaEnVivo(DtFecha* inicio, DtFecha* fin, DtClase *dtClase, DtUsuario* dtUsuario):DtAsistencia(dtClase, dtUsuario){
    this->inicio = inicio;
    this->fin = fin;
}

DtAsistenciaEnVivo::~DtAsistenciaEnVivo() {

}

 DtFecha* DtAsistenciaEnVivo::getInicio() {
    return inicio;
}

void DtAsistenciaEnVivo::setInicio(DtFecha* inicio) {
    this->inicio = inicio;
}

 DtFecha* DtAsistenciaEnVivo::getFin() {
    return fin;
}

void DtAsistenciaEnVivo::setFin(DtFecha* fin) {
    this->fin = fin;
}

DtClase *DtAsistenciaEnVivo::getDtClase() {
    return dtClase;
}

void DtAsistenciaEnVivo::setDtClase(DtClase *dtClase) {
    this->dtClase = dtClase;
}