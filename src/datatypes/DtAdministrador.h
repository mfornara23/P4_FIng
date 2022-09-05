#ifndef LAB5_DTADMINISTRADOR_H
#define LAB5_DTADMINISTRADOR_H

#include "DtUsuario.h"

class DtAdministrador : public DtUsuario {
public:
    DtAdministrador();
    DtAdministrador(string nombre, string email, string password, string imagen);
    ~DtAdministrador();
};

#endif //LAB5_DTADMINISTRADOR_H
