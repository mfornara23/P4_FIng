#include "DtMonitoreo.h"

DtMonitoreo::DtMonitoreo( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura)
                         : DtClase(codigo, nombre, inicio, fin, urlVideo,iniciadaPor, dtAsignatura){
    this->habilitados = new set<DtEstudiante*>();
}

DtMonitoreo::~DtMonitoreo() {

}

set<DtEstudiante *> *DtMonitoreo::getHabilitados()  {
    return this->habilitados;
}

void DtMonitoreo::setHabilitados(set<DtEstudiante *> *habilitados) {
    this->habilitados = habilitados;
}

