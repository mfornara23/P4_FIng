#include "DtClase.h"

int &DtClase::getCodigo() {
    return codigo;
}

void DtClase::setCodigo(int &codigo) {
    this->codigo = codigo;
}

string &DtClase::getNombre() {
    return nombre;
}

void DtClase::setNombre(string &nombre) {
    this->nombre = nombre;
}

DtFecha *DtClase::getInicio() {
    return inicio;
}

void DtClase::setInicio(DtFecha *inicio) {
    this->inicio = inicio;
}

DtFecha *DtClase::getFin() {
    return fin;
}

void DtClase::setFin(DtFecha *fin) {
    this->fin = fin;
}

string &DtClase::getUrlVideo() {
    return urlVideo;
}

void DtClase::setUrlVideo(string &urlVideo) {
    this->urlVideo = urlVideo;
}

string &DtClase::getIniciadaPor() {
    return iniciadaPor;
}

void DtClase::setIniciadaPor(string &iniciadaPor) {
    this->iniciadaPor = iniciadaPor;
}

DtAsignatura *DtClase::getDtAsignatura() {
    return dtAsignatura;
}

void DtClase::setAsignatura(DtAsignatura *dtAsignatura) {
    this->dtAsignatura = dtAsignatura;
}

DtClase::~DtClase() {

}

set<DtMensaje *> *DtClase::getDtMensajes() {
    return dtMensajes;
}

void DtClase::setDtMensajes(set<DtMensaje *> *dtMensajes) {
    this->dtMensajes = dtMensajes;
}

set<DtAsistenciaEnDiferido *> *DtClase::getDtAsistenciasEnDiferido() {
    return dtAsistenciasEnDiferido;
}

void DtClase::setDtAsistenciasEnDiferido(set<DtAsistenciaEnDiferido *> *dtAsistenciasEnDiferido) {
    this->dtAsistenciasEnDiferido = dtAsistenciasEnDiferido;
}

set<DtAsistenciaEnVivo *> *DtClase::getDtAsistenciasEnVivo() {
    return dtAsistenciasEnVivo;
}

void DtClase::setDtAsistenciasEnVivo(set<DtAsistenciaEnVivo *> *dtAsistenciasEnVivo) {
    this->dtAsistenciasEnVivo = dtAsistenciasEnVivo;
}

DtClase::DtClase(int &codigo, string &nombre, DtFecha *inicio, DtFecha *fin,
                 string &urlVideo, string &iniciadaPor, DtAsignatura *dtAsignatura) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->inicio = inicio;
    this->fin = fin;
    this->urlVideo = urlVideo;
    this->iniciadaPor = iniciadaPor;
    this->dtAsignatura = dtAsignatura;
}

