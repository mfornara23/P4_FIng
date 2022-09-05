#ifndef LAB5_DTASISTENCIAENDIFERIDO_H
#define LAB5_DTASISTENCIAENDIFERIDO_H

#include "DtFecha.h"
#include "DtAsistencia.h"


class DtAsistenciaEnDiferido : public DtAsistencia {
private:
    int id;
    DtFecha* fechaRep;
    DtClase* dtClase;
public:
    DtAsistenciaEnDiferido(int id, DtFecha* fechaRep, DtClase* dtClase, DtUsuario* dtUsuario);
    int getId() ;
    void setId(int id);
    DtFecha* getFechaRep();
    void setFechaRep(DtFecha* fechaRep);
    DtClase* getDtClase();
    void setDtClase(DtClase *dtClase);
    virtual ~DtAsistenciaEnDiferido();
};

#endif //LAB5_DTASISTENCIAENDIFERIDO_H
