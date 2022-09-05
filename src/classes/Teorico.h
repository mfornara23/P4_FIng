#ifndef LAB5_TEORICO_H
#define LAB5_TEORICO_H

#include "Clase.h"

class Teorico : public Clase {
private:
    int cantAsistentes;
public:
    Teorico(string &nombre, DtFecha *inicio, DtFecha *fin,
            string &urlVideo, string &iniciadaPor, Asignatura *asignatura);
    int getCantAsistentes();
    void setCantAsistentes(int cantAsistentes);
    virtual ~Teorico();
};

#endif //LAB5_TEORICO_H
