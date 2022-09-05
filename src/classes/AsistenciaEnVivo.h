#ifndef LAB5_ASISTENCIAENVIVO_H
#define LAB5_ASISTENCIAENVIVO_H

#include "Asistencia.h"
#include "../datatypes/DtFecha.h"

class AsistenciaEnVivo : public Asistencia{
private:
    DtFecha* inicio;
    DtFecha* fin;
public:
    AsistenciaEnVivo(DtFecha* inicio, DtFecha* fin, Clase *clase, Usuario* u);
    DtFecha* getInicio();
    void setInicio(DtFecha* inicio);
    DtFecha* getFin();
    void setFin(DtFecha* fin);
    virtual ~AsistenciaEnVivo();
};

#endif //LAB5_ASISTENCIAENVIVO_H
