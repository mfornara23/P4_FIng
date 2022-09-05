#include "UsuarioHandler.h"

#include "../exceptions/UsuarioNotFound.h"

UsuarioHandler* UsuarioHandler::instance = NULL;

UsuarioHandler::UsuarioHandler(){
    administradores = new map<string,Administrador*>();
    docentes = new map<string,Docente*>();
    estudiantes = new map<int,Estudiante*>();
}

UsuarioHandler* UsuarioHandler::getInstance(){
    if(instance == NULL){
        instance =  new UsuarioHandler();
    }

    return instance;
}

void UsuarioHandler::addAdministrador(DtAdministrador* admin){
    Administrador* administrador = new Administrador(admin->getNombre(), admin->getEmail(), admin->getPassword(), admin->getImagen());
    administradores->insert(pair<string,Administrador*>(admin->getEmail(),administrador));
}

void UsuarioHandler::addDocente(DtDocente* docente){
    Docente* doc = new Docente(docente->getNombre(), docente->getEmail(), docente->getPassword(), docente->getImagen(), docente->getNombreInst());
    docentes->insert(pair<string,Docente*>(docente->getEmail(),doc));
}

void UsuarioHandler::addEstudiante(DtEstudiante* estudiante){
    Estudiante* est = new Estudiante(estudiante->getNombre(), estudiante->getEmail(), estudiante->getPassword(), estudiante->getImagen(), estudiante->getCedula());
    estudiantes->insert(pair<int,Estudiante*>(estudiante->getCedula(),est));
}

Administrador* UsuarioHandler::getAdministrador(string &email){
    map<string,Administrador*>::iterator it;
	it = administradores->find(email);
	if(it != administradores->end()){
		return it->second;
	}else{
		throw UsuarioNotFound();
	}
}

Docente* UsuarioHandler::getDocente(string &email){
    map<string,Docente*>::iterator it;
	it = docentes->find(email);
	if(it != docentes->end()){
		return it->second;
	}else{
		throw UsuarioNotFound();
	}
}

Estudiante* UsuarioHandler::getEstudiante(int ci){
    map<int,Estudiante*>::iterator it;
	it = estudiantes->find(ci);
	if(it != estudiantes->end()){
		return it->second;
	}else{
		throw UsuarioNotFound();
	}
}

Usuario* UsuarioHandler::getUsuario(string &email) {
    Usuario* usuario = NULL;
    try {
        usuario = this->getEstudianteByEmail(email);
    } catch (const UsuarioNotFound &e) {
        try {
            usuario = this->getDocente(email);
        } catch (const UsuarioNotFound &e) {
            usuario = this->getAdministrador(email);
        }
    }
    return usuario;
}

Estudiante* UsuarioHandler::getEstudianteByEmail(string &email){
    Estudiante* estudiante = NULL;
    for (map<int,Estudiante*>::iterator it = estudiantes->begin(); it != estudiantes->end() ; ++it){
        if (it->second->getEmail() == email){
            estudiante = it->second;
        }
    }
    if (estudiante == NULL) {
        throw UsuarioNotFound();
    } else {
        return estudiante;
    }
}

set<Estudiante*>* UsuarioHandler::getEstudiantesByAsignatura(Asignatura* asig){
    set<Estudiante*>* matches = new set<Estudiante*>();
    for (map<int,Estudiante*>::iterator it = estudiantes->begin(); it != estudiantes->end() ; ++it) {
        if(it->second->cursaAsignatura(asig)){
            matches->insert(it->second);
        }       
    }
    return matches;
}

set<DtDocente*>* UsuarioHandler::getDocentesNoAsignados(Asignatura* asig){
    set<DtDocente*>* matches = new set<DtDocente*>();
    for (map<string,Docente*>::iterator it = docentes->begin(); it != docentes->end() ; ++it) {
        if(!it->second->estaAsignado(asig)){
            matches->insert(new DtDocente(it->second->getNombre(), it->second->getEmail(),
                 it->second->getPassword(), it->second->getImagen(), it->second->getNombreInst()));
        }       
    }
    return matches; 
}
 
UsuarioHandler::~UsuarioHandler (){
    for(map<string,Administrador*>::iterator it = this->administradores->begin(); it!=this->administradores->end(); ++it){
        Administrador* a = it->second;
        delete a;
    }
    this->administradores->clear();
    delete administradores;

    for(map<string,Docente*>::iterator it = this->docentes->begin(); it!=this->docentes->end(); ++it){
        Docente* d = it->second;
        delete d;
    }
    this->docentes->clear();
    delete docentes;

    for(map<int,Estudiante*>::iterator it = this->estudiantes->begin(); it!=this->estudiantes->end(); ++it){
        Estudiante* e = it->second;
        delete e;
    }
    this->estudiantes->clear();
    delete estudiantes;

    UsuarioHandler::instance = NULL;
}
