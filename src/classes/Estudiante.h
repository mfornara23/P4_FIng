#ifndef LAB5_ESTUDIANTE_H
#define LAB5_ESTUDIANTE_H

#include <set>

#include "Usuario.h"
#include "Asistencia.h"

class Estudiante : public Usuario {
private:
    int cedula;
    set<Asignatura *> *asignaturas;
    set<Asistencia *> *asistencias;
public:
    Estudiante(string &nombre, string &email, string &password, string &imagen, int cedula);
    int getCedula();
    void setCedula(int cedula);
    void setAsistencias(set<Asistencia *> *asis);
    void setAsignaturas(set<Asignatura *> *asig);
    void addAsistencia(Asistencia *asis);
    void addAsignatura(Asignatura *asig);
    set<Asistencia *> *getAsistencias();
    set<Asignatura *> *getAsignaturas();
    bool cursaAsignatura(Asignatura *asig);
    void eliminarAsignatura(Asignatura *a);
    ~Estudiante();
};

#endif //LAB5_ESTUDIANTE_H
