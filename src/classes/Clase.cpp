#include "Clase.h"
#include "Asistencia.h"
#include "AsistenciaEnDiferido.h"
#include "AsistenciaEnVivo.h"

int Clase::currentId = 0;

Clase::Clase(string &nombre, DtFecha *inicio, DtFecha *fin,
             string &urlVideo, string &iniciadaPor, Asignatura *asignatura) {
    this->codigo = ++this->currentId;
    this->nombre = nombre;
    this->inicio = inicio;
    this->fin = fin;
    this->urlVideo = urlVideo;
    this->iniciadaPor = iniciadaPor;
    this->asignatura = asignatura;
    this->mensajes = new set<Mensaje*>();
    this->asistenciasEnVivo = new set<AsistenciaEnVivo*>();
    this->asistenciasEnDiferido = new set<AsistenciaEnDiferido*>();
}

int &Clase::getCodigo() {
    return codigo;
}

int Clase::getCurrentId() {
    return currentId;
}

string &Clase::getNombre() {
    return nombre;
}

void Clase::setNombre(string &nombre) {
    this->nombre = nombre;
}

DtFecha *Clase::getInicio() {
    return inicio;
}

void Clase::setInicio(DtFecha *inicio) {
    this->inicio = inicio;
}

DtFecha *Clase::getFin() {
    return fin;
}

void Clase::setFin(DtFecha *fin) {
    this->fin = fin;
}

string &Clase::getUrlVideo() {
    return urlVideo;
}

void Clase::setUrlVideo(string urlVideo) {
    this->urlVideo = urlVideo;
}

string &Clase::getIniciadaPor() {
    return iniciadaPor;
}

void Clase::setIniciadaPor(string &iniciadaPor) {
    this->iniciadaPor = iniciadaPor;
}

bool Clase::esClaseEnDiferido() {
    return (this->urlVideo != "");
}
set<Mensaje *> *Clase::listarMensajes() {
    return this->mensajes;
}

void Clase::agregarMensaje(Mensaje *msg) {
    mensajes->insert(msg);
}

Asignatura *Clase::getAsignatura() {
    return this->asignatura;
}

void Clase::setAsignatura(Asignatura *asignatura) {
    this->asignatura = asignatura;
}

Clase::~Clase() {
    for (set<Mensaje *>::iterator it = this->mensajes->begin(); it != this->mensajes->end(); ++it) {
        Mensaje *m = (*it);
        delete m;
    }
    this->mensajes->clear();
    delete this->mensajes;

    for (set<AsistenciaEnDiferido *>::iterator it = this->asistenciasEnDiferido->begin();
        it != this->asistenciasEnDiferido->end(); ++it) {
        AsistenciaEnDiferido *ad = (*it);
        delete ad;
    }
    this->asistenciasEnDiferido->clear();
    delete this->asistenciasEnDiferido;

    for (set<AsistenciaEnVivo *>::iterator it = this->asistenciasEnVivo->begin();
         it != this->asistenciasEnVivo->end(); ++it) {
        AsistenciaEnVivo *av = (*it);
        delete av;
    }
    this->asistenciasEnVivo->clear();
    delete this->asistenciasEnVivo;

}

set<Mensaje *> *Clase::getMensajes() {
    return mensajes;
}

void Clase::setMensajes(set<Mensaje *> *mensajes) {
    this->mensajes = mensajes;
}

set<AsistenciaEnDiferido *> *Clase::getAsistenciasEnDiferido() {
    return asistenciasEnDiferido;
}

void Clase::setAsistenciasEnDiferido(set<AsistenciaEnDiferido *> *asistenciasEnDiferido) {
    this->asistenciasEnDiferido = asistenciasEnDiferido;
}

set<AsistenciaEnVivo *> *Clase::getAsistenciasEnVivo() {
    return asistenciasEnVivo;
}

void Clase::setAsistenciasEnVivo(set<AsistenciaEnVivo *> *asistenciasEnVivo) {
    this->asistenciasEnVivo = asistenciasEnVivo;
}

Mensaje *Clase::getMensajeById(int id) {
    Mensaje *m = NULL;
    for (set<Mensaje *>::iterator it = this->mensajes->begin(); it != this->mensajes->end(); ++it) {
        if ((*it)->getId() == id) {
            m = (*it);
        }
    }

    return m;
}

void Clase::addAsistencia(Asistencia* asis){
    if(dynamic_cast<AsistenciaEnDiferido*> (asis)){
        this->asistenciasEnDiferido->insert(dynamic_cast<AsistenciaEnDiferido*> (asis));
    }else{
        this->asistenciasEnVivo->insert(dynamic_cast<AsistenciaEnVivo*> (asis));
    }
}
