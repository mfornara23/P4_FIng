#include "DtAsistencia.h"

DtAsistencia::DtAsistencia() {}

DtAsistencia::~DtAsistencia() {

}

DtClase *DtAsistencia::getDtClase()  {
    return dtClase;
}

void DtAsistencia::setDtClase(DtClase *dtClase) {
    DtAsistencia::dtClase = dtClase;
}

DtAsistencia::DtAsistencia(DtClase *dtClase, DtUsuario *dtUsuario){
    this->dtClase=dtClase;
    this->dtUsuario=dtUsuario;
}

DtUsuario *DtAsistencia::getDtUsuario()  {
    return dtUsuario;
}

void DtAsistencia::setDtUsuario(DtUsuario *dtUsuario) {
    DtAsistencia::dtUsuario = dtUsuario;
}
