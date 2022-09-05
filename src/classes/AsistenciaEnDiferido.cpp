#include "AsistenciaEnDiferido.h"

AsistenciaEnDiferido::AsistenciaEnDiferido(int id, DtFecha *fechaRep, Clase *clase, Usuario *u) : Asistencia(clase, u) {
    this->id = id;
    this->fechaRep = fechaRep;
}

int AsistenciaEnDiferido::getId() {
    return id;
}

void AsistenciaEnDiferido::setId(int id) {
    this->id = id;
}

DtFecha *AsistenciaEnDiferido::getFechaRep() {
    return fechaRep;
}

void AsistenciaEnDiferido::setFechaRep(DtFecha *fechaRep) {
    this->fechaRep = fechaRep;
}

AsistenciaEnDiferido::~AsistenciaEnDiferido() {

}
