#ifndef LAB5_DTASISTENCIAENVIVO_H
#define LAB5_DTASISTENCIAENVIVO_H

#include "DtFecha.h"
#include "DtAsistencia.h"


class DtAsistenciaEnVivo : public DtAsistencia {
private:
    DtFecha* inicio;
    DtFecha* fin;
    DtClase* dtClase;
public:
    DtAsistenciaEnVivo(DtFecha* inicio, DtFecha* fin, DtClase *dtClase, DtUsuario* dtUsuario);
     DtFecha* getInicio();
    void setInicio(DtFecha* inicio);
     DtFecha* getFin();
    void setFin(DtFecha* fin);
    DtClase *getDtClase();
    void setDtClase(DtClase *dtClase);
    ~DtAsistenciaEnVivo();
};

#endif //LAB5_DTASISTENCIAENVIVO_H
