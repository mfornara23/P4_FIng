#ifndef LAB5_PRACTICO_H
#define LAB5_PRACTICO_H

#include "Clase.h"

class Practico : public Clase {
public:
    Practico(string &nombre, DtFecha *inicio, DtFecha *fin,
             string &urlVideo, string &iniciadaPor, Asignatura *asignatura);

    virtual ~Practico();
};

#endif //LAB5_PRACTICO_H
