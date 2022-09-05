#ifndef USUARIOHANDLER_H
#define USUARIOHANDLER_H

#include <map>
#include <string>
#include <set>

#include "../classes/Administrador.h"
#include "../classes/Docente.h"
#include "../classes/Estudiante.h"
#include "../classes/Usuario.h"
#include "../datatypes/DtAdministrador.h"
#include "../datatypes/DtDocente.h"
#include "../datatypes/DtEstudiante.h"

using namespace std;

class UsuarioHandler {
private:
	static UsuarioHandler* instance;
    map<string,Administrador*>* administradores;
    map<string,Docente*>* docentes;
    map<int,Estudiante*>* estudiantes;
    UsuarioHandler();
public:
    static UsuarioHandler* getInstance();
    void addAdministrador(DtAdministrador* admin);
    void addDocente(DtDocente* docente);
    void addEstudiante(DtEstudiante* estudiante);
    Administrador* getAdministrador(string &email);
    Docente* getDocente(string &email);
    Estudiante* getEstudiante(int ci);
    Estudiante* getEstudianteByEmail(string &email);
    Usuario* getUsuario(string &email);
    set<Estudiante*>* getEstudiantesByAsignatura(Asignatura* asig);
    set<DtDocente*>* getDocentesNoAsignados(Asignatura* asig);
    virtual ~UsuarioHandler ();
};

#endif
