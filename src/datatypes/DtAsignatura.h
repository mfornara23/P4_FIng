#ifndef LAB5_DTASIGNATURA_H
#define LAB5_DTASIGNATURA_H

#include <string>
#include <set>


using namespace std;

class DtClase;

class DtAsignatura {
private:
    string codigo;
    string nombre;
    bool tieneTeorico;
    bool tienePractico;
    bool tieneMonitoreo;
    set<DtClase *> *dtClases;
public:
    DtAsignatura();
    DtAsignatura(string codigo, string nombre, bool teorico, bool practico, bool monitoreo);
    string &getCodigo();
    void setCodigo(string &codigo);
    string &getNombre();
    void setNombre(string &nombre);
    bool isTeorico();
    void setTeorico(bool teorico);
    bool isPractico();
    void setPractico(bool practico);
    bool isMonitoreo();
    void setMonitoreo(bool monitoreo);
    set<DtClase *> *getDtClases();
    void setDtClases(set<DtClase *> *dtClases);
    ~DtAsignatura();
    friend bool operator< (const DtAsignatura& asignatura1, const DtAsignatura& asignatura2);
};

#endif //LAB5_DTASIGNATURA_H
