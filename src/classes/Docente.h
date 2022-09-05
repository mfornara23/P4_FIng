#ifndef LAB5_DOCENTE_H
#define LAB5_DOCENTE_H

#include <map>
#include <set>

#include "Usuario.h"
#include "Clase.h"
#include "../enums/enums.h"
#include "../datatypes/DtAsignatura.h"

using namespace std;

class Docente : public Usuario {
private:
    Instituto nombreInst;
    map<Asignatura *, tipoAsignacion> *asignaciones;
    set<Asistencia *> *asistencias;
public:
    Docente(string &nombre, string &email, string &password, string &imagen,
            Instituto nombreInst);
    Instituto getNombreInst();
    void setNombreInst(Instituto nombreInst);
    void asignar(Asignatura *asig, tipoAsignacion rol);
    set<Clase *> *getClasesVivo();
    void eliminarAsignatura(Asignatura *a);
    bool estaAsignado(Asignatura *a);
    set<DtAsignatura *> *getAsignaturas();
    map<DtAsignatura *, tipoAsignacion> *getAsignaciones();
    tipoAsignacion getTipoAsignacion(string codigo);
    ~Docente();
};

#endif //LAB5_DOCENTE_H
