#ifndef LAB5_DTDOCENTE_H
#define LAB5_DTDOCENTE_H

#include <map>
#include <set>

#include "../enums/enums.h"
#include "DtUsuario.h"
#include "DtAsignatura.h"
#include "DtAsistencia.h"

using namespace std;

class DtDocente : public DtUsuario {
private:
    Instituto nombreInst;
    map<DtAsignatura *, tipoAsignacion> *asignaciones;
    set<DtAsistencia *> *asistencias;
public:
    DtDocente();
    DtDocente(string nombre, string email, string password, string imagen, Instituto nombreInst);
    Instituto getNombreInst();
    void setNombreInst(Instituto nombreInst);
    map<DtAsignatura *, tipoAsignacion> *getAsignaciones();
    void setAsignaciones(map<DtAsignatura *, tipoAsignacion> *asignaciones);
    set<DtAsistencia *> *getAsistencias();
    void setAsistencias(set<DtAsistencia *> *asistencias);
    ~DtDocente();
};

#endif //LAB5_DTDOCENTE_H
