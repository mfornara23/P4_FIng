#include "DtPractico.h"

DtPractico::~DtPractico() {

}

DtPractico::DtPractico( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura) : DtClase(
        codigo, nombre, inicio, fin, urlVideo, iniciadaPor, dtAsignatura) {}
