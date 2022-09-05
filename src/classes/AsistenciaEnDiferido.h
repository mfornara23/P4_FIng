#ifndef LAB5_ASISTENCIAENDIFERIDO_H
#define LAB5_ASISTENCIAENDIFERIDO_H

#include "Asistencia.h"
#include "../datatypes/DtFecha.h"

class Clase;

class AsistenciaEnDiferido :
        public Asistencia {
private:
    int id;
    DtFecha *fechaRep;
public:
    AsistenciaEnDiferido(int id, DtFecha *fechaRep, Clase *clase, Usuario *u);
    int getId();
    void setId(int id);
    DtFecha *getFechaRep();
    void setFechaRep(DtFecha *fechaRep);
    ~AsistenciaEnDiferido();
};

#endif //LAB5_ASISTENCIAENDIFERIDO_H
