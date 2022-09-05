#ifndef LAB5_ASISTENCIA_H
#define LAB5_ASISTENCIA_H

#include "Clase.h"
#include "Usuario.h"

class Asistencia {
private:
    Clase *clase;
    Usuario *usuario;
public:
    Asistencia(Clase *clase, Usuario *usuario);
    Clase *getClase();
    void setClase(Clase *clase);
    Usuario *getUsuario();
    void setUsuario(Usuario *usuario);
    virtual ~Asistencia();
};

#endif //LAB5_ASISTENCIA_H
