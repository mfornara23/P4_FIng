#ifndef LABORATORIO05_CARGADATOS_H
#define LABORATORIO05_CARGADATOS_H

#include "../factory/Factory.h"

#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtDocente.h"
#include "../datatypes/DtEstudiante.h"
#include "../datatypes/DtAdministrador.h"
#include "../datatypes/DtAsignatura.h"
#include "../datatypes/DtFecha.h"
#include "../handlers/ClaseHandler.h"

class CargaDatos {
private:
    ClaseHandler* cHandler;
public:
    void cargarDatos();
};

#endif //LABORATORIO05_CARGADATOS_H
