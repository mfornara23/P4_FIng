#ifndef LAB5_DTREPORTETIEMPODICTADO_H
#define LAB5_DTREPORTETIEMPODICTADO_H

#include <math.h>
#include <iostream>
#include <string>

#include "DtAsignatura.h"
#include "DtFecha.h"

class DtReporteTiempoDictado {
private:
    DtAsignatura* dtAsignatura;
    int tiempoDictadoEnSegundos;
public:
    DtAsignatura* getDtAsignatura();
    void setDtAsignatura(DtAsignatura* dtAsignatura);
    DtReporteTiempoDictado(DtAsignatura* dtAsignatura, int tiempoEnSegundos);
    int getTiempoDictado();
    void setTiempoDictado(int tiempoEnSegundos);
    void addTiempo(int tiempoEnSegundos);
    string toString();
    ~DtReporteTiempoDictado();
};

#endif //LAB5_DTREPORTETIEMPODICTADO_H
