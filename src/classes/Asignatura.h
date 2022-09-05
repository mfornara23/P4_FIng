#ifndef LAB5_ASIGNATURA_H
#define LAB5_ASIGNATURA_H

#include <string>
#include <set>


using namespace std;

class Clase;

class Estudiante;

class Docente;

class Asignatura {
private:
    string codigo;
    string nombre;
    bool tieneTeorico;
    bool tienePractico;
    bool tieneMonitoreo;
    set<Clase *> *clases;
    set<Docente *> *docentes;
    set<Estudiante *> *estudiantes;
public:
    Asignatura(string &codigo, string &nombre, bool tieneTeorico, bool tienePractico, bool tieneMonitoreo);
    virtual ~Asignatura();
    string &getCodigo();
    void setCodigo(string &codigo);
    string &getNombre();
    void setNombre(string &nombre);
    void setClases(set<Clase *> *clases);
    void setTieneTeorico(bool tieneTeorico);
    void setTienePractico(bool tienePractico);
    void setTieneMonitoreo(bool tieneMonitoreo);
    bool getTieneTeorico();
    bool getTienePractico();
    bool getTieneMonitoreo();
    set<Clase *> *getClases();
    void addEstudiante(Estudiante *estudiante);
    set<Estudiante *> *getEstudiantes();
    void removeEstudiante(Estudiante *estudiante);
    void removeAllEstudiantes();
    void addDocente(Docente *docente);
    set<Docente *> *getDocentes();
    void removeAllDocentes();
    void removeDocente(Docente *docente);
    void addClase(Clase *clase);
};

#endif //LAB5_ASIGNATURA_H
