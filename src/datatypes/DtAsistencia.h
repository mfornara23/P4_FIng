#ifndef LAB5_DTASISTENCIA_H
#define LAB5_DTASISTENCIA_H

#include "DtClase.h"
#include "DtUsuario.h"

class DtAsistencia {
private:
    DtClase *dtClase;
    DtUsuario *dtUsuario;
public:
    DtAsistencia();
    DtAsistencia(DtClase *dtClase, DtUsuario *dtUsuario);
    DtClase *getDtClase();
    void setDtClase(DtClase *dtClase);
    DtUsuario *getDtUsuario() ;
    void setDtUsuario(DtUsuario *dtUsuario);
    ~DtAsistencia();
};

#endif //LAB5_DTASISTENCIA_H
