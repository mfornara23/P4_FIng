#include "DtAsistenciaEnDiferido.h"

DtAsistenciaEnDiferido::DtAsistenciaEnDiferido(int id, DtFecha *fechaRep, DtClase *dtClase, DtUsuario *dtUsuario)
        : DtAsistencia(dtClase, dtUsuario) {
    this->id = id;
    this->fechaRep = fechaRep;
}

DtAsistenciaEnDiferido::~DtAsistenciaEnDiferido() {

}

int DtAsistenciaEnDiferido::getId() {
    return id;
}

void DtAsistenciaEnDiferido::setId(int id) {
    this->id = id;
}

DtFecha *DtAsistenciaEnDiferido::getFechaRep() {
    return fechaRep;
}

void DtAsistenciaEnDiferido::setFechaRep(DtFecha *fechaRep) {
    this->fechaRep = fechaRep;
}

DtClase *DtAsistenciaEnDiferido::getDtClase() {
    return dtClase;
}

void DtAsistenciaEnDiferido::setDtClase(DtClase *dtClase) {
    this->dtClase = dtClase;
}

