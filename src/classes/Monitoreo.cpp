#include "Monitoreo.h"

#include "../exceptions/MaxHabilitados.h"


Monitoreo::Monitoreo(string &nombre, DtFecha *inicio, DtFecha *fin,
                     string &urlVideo, string &iniciadaPor, Asignatura *asignatura) : Clase(nombre, inicio, fin,
                                                                                            urlVideo, iniciadaPor,
                                                                                            asignatura) {
    this->habilitados = new set<Estudiante*>();
}

void Monitoreo::setHabilitado(Estudiante *e) {
    if ((int) this->habilitados->size() >= this->maxHabilitados) {
        throw MaxHabilitados();
    } else {
        this->habilitados->insert(e);
    }
}

set<Estudiante *> *Monitoreo::getHabilitados() {
    return this->habilitados;
}

Monitoreo::~Monitoreo() {

}
