#ifndef LAB5_DTTEORICO_H
#define LAB5_DTTEORICO_H

#include "DtClase.h"

class DtTeorico : public DtClase {
private:
    int cantAsistentes;
public:
    DtTeorico( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura, int cantAsistentes);
    int getCantAsistentes() ;
    void setCantAsistentes(int cantAsistentes);
    ~DtTeorico();
};

#endif //LAB5_DTTEORICO_H
