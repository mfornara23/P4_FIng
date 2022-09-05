#ifndef LAB5_DTESTUDIANTE_H
#define LAB5_DTESTUDIANTE_H

#include <set>

#include "DtUsuario.h"
#include "DtAsignatura.h"
#include "DtAsistencia.h"

class DtEstudiante : public DtUsuario {
private:
    int cedula;
    set<DtAsignatura *> *dtAsignaturas;
    set<DtAsistencia *> *dtAsistencias;
public:
    DtEstudiante();
    DtEstudiante(string nombre, string email, string password, string imagen, int cedula);
    int getCedula();
    void setCedula(int cedula);
    set<DtAsignatura *> *getDtAsignaturas();
    void setDtAsignaturas(set<DtAsignatura *> *dtAsignaturas);
    set<DtAsistencia *> *getDtAsistencias();
    void setDtAsistencias(set<DtAsistencia *> *dtAsistencias);
    ~DtEstudiante();
};

#endif //LAB5_DTESTUDIANTE_H
