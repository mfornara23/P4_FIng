#ifndef LAB5_DTREPORTETIEMPOASISTENCIA_H
#define LAB5_DTREPORTETIEMPOASISTENCIA_H

#include <set>
#include <iostream>
#include <string>

#include "DtClase.h"

class DtReporteTiempoAsistencia {
private:
    DtClase* dtClase;
    int tiempoAsistenciaEnSegundos;
public:
    DtReporteTiempoAsistencia(DtClase* dtClase, int tiempoAsistenciaEnSegundos);
    DtClase* getDtClase() ;
    void setDtClase(DtClase* dtClase);
    int getTiempoAsistencia() ;
    void setTiempoAsistencia(int tiempoAsistenciaEnSegundos);
    ~DtReporteTiempoAsistencia();
    string toString();
};

#endif //LAB5_DTREPORTETIEMPOASISTENCIA_H
