#ifndef ASIGNATURAHANDLER_H
#define ASIGNATURAHANDLER_H

#include <map>
#include <string>
#include <set>

#include "../classes/Asignatura.h"
#include "../datatypes/DtAsignatura.h"

using namespace std;

class AsignaturaHandler {
private:
	static AsignaturaHandler* instance;
    map<string,Asignatura*>* asignaturas;
    AsignaturaHandler();
public:
    static AsignaturaHandler* getInstance();
    set<Asignatura*>* getAsignaturas();
    Asignatura* getAsignatura(string &code);
    void addAsignatura(Asignatura* asignatura);
    Asignatura* remove(string &code);
    virtual ~AsignaturaHandler();
};

#endif
