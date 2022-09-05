#ifndef LAB5_DTPRACTICO_H
#define LAB5_DTPRACTICO_H

#include "DtClase.h"

class DtPractico : public DtClase{
public:
    DtPractico( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura);

    virtual ~DtPractico();
};

#endif //LAB5_DTPRACTICO_H
