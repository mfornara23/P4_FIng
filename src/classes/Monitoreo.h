#ifndef LAB5_MONITOREO_H
#define LAB5_MONITOREO_H

#include <set>

#include "Clase.h"
#include "Estudiante.h"

class Monitoreo : public Clase {
private:
    set<Estudiante *> *habilitados;
    int maxHabilitados = 15;
public:
    Monitoreo(string &nombre, DtFecha *inicio, DtFecha *fin,
              string &urlVideo, string &iniciadaPor, Asignatura *asignatura);
    void setHabilitado(Estudiante *e);
    set<Estudiante *> *getHabilitados();
    virtual ~Monitoreo();
};

#endif //LAB5_MONITOREO_H
