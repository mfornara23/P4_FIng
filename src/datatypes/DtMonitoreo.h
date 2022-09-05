#ifndef LAB5_DTMONITOREO_H
#define LAB5_DTMONITOREO_H

#include "DtClase.h"
#include "DtEstudiante.h"

class DtMonitoreo : public DtClase{
private:
    set<DtEstudiante*>* habilitados;
     int maxHabilitados = 15;
public:
    DtMonitoreo( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura);
    set<DtEstudiante *> *getHabilitados() ;
    void setHabilitados(set<DtEstudiante *> *habilitados);
    ~DtMonitoreo();
};

#endif //LAB5_DTMONITOREO_H
