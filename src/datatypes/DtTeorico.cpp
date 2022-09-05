#include "DtTeorico.h"

DtTeorico::~DtTeorico() {

}

DtTeorico::DtTeorico( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura,
                     int cantAsistentes) : DtClase(codigo, nombre, inicio, fin, urlVideo, iniciadaPor, dtAsignatura){
    this->cantAsistentes = cantAsistentes;
}

int DtTeorico::getCantAsistentes()  {
    return this->cantAsistentes;
}

void DtTeorico::setCantAsistentes(int cantAsistentes) {
    this->cantAsistentes = cantAsistentes;
}



