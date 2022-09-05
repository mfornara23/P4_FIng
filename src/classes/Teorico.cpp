#include "Teorico.h"

Teorico::Teorico(string &nombre, DtFecha *inicio, DtFecha *fin,
                 string &urlVideo, string &iniciadaPor, Asignatura *asignatura) : Clase(nombre, inicio, fin, urlVideo,
                                                                                        iniciadaPor, asignatura) {}

Teorico::~Teorico() {

}

int Teorico::getCantAsistentes() {
    return cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes) {
    this->cantAsistentes = cantAsistentes;
}
