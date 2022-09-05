#include "AsignaturaHandler.h"

#include "../exceptions/AsignaturaNotFound.h"
#include "../exceptions/AsignaturaDuplicated.h"

AsignaturaHandler* AsignaturaHandler::instance = NULL;

AsignaturaHandler* AsignaturaHandler::getInstance(){
    if(instance == NULL){
        instance =  new AsignaturaHandler();
    }

    return instance;
}

AsignaturaHandler::AsignaturaHandler() {
    asignaturas = new map<string,Asignatura*>();
}

set<Asignatura*>* AsignaturaHandler::getAsignaturas(){
    set<Asignatura*>* all = new set<Asignatura*>();
    for (map<string,Asignatura*>::iterator it = asignaturas->begin(); it != asignaturas->end() ; ++it) {
        all->insert(it->second);       
    }
    return all;
}

Asignatura* AsignaturaHandler::getAsignatura(string &code){
    if(this->asignaturas->find(code)==this->asignaturas->end()){
		throw AsignaturaNotFound();
	}else{
        return this->asignaturas->find(code)->second;
	}
}

Asignatura* AsignaturaHandler::remove(string &code){
    if(this->asignaturas->find(code)==this->asignaturas->end()){
		throw AsignaturaNotFound();
	}else{
        Asignatura* a = this->asignaturas->find(code)->second;
        asignaturas->erase(code);
        return a;
	}
}

void AsignaturaHandler::addAsignatura(Asignatura* asignatura){
    if(this->asignaturas->find(asignatura->getCodigo())!=this->asignaturas->end()){
        throw AsignaturaDuplicated();
    }else{
       this->asignaturas->insert(pair<string,Asignatura*>(asignatura->getCodigo(),asignatura));
    }
}

AsignaturaHandler::~AsignaturaHandler(){
    for(map<string,Asignatura*>::iterator it = this->asignaturas->begin(); it!=this->asignaturas->end(); ++it){
        Asignatura * a = it->second;
        delete a;
    }
    this->asignaturas->clear();
    delete this->asignaturas;
    AsignaturaHandler::instance = NULL;
}