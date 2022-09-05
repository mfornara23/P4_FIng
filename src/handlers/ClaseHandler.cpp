#include "ClaseHandler.h"

#include "../exceptions/ClaseNotFound.h"
#include "../exceptions/ClaseDuplicated.h"

ClaseHandler* ClaseHandler::instance = NULL;

ClaseHandler* ClaseHandler::getInstance(){
    if(instance == NULL){
        instance =  new ClaseHandler();
    }

    return instance;
}

ClaseHandler::ClaseHandler() {
    clases = new map<int, Clase*>();
}

void ClaseHandler::addClase(Clase *clase) {
    if(this->clases->find(clase->getCodigo())!=this->clases->end()){
        throw ClaseDuplicated();
    }else{
        this->clases->insert(pair<int,Clase*>(clase->getCodigo(), clase));
    }
}

Clase* ClaseHandler::remove(int codigo){
    if(this->clases->find(codigo)==this->clases->end()){
        throw ClaseNotFound();
    }else{
        Clase* c = this->clases->find(codigo)->second;
        clases->erase(codigo);
        return c;
    }
}

Clase* ClaseHandler::getClase(int code){
    if(this->clases->find(code)==this->clases->end()){
		throw ClaseNotFound();
	}else{
        return this->clases->find(code)->second;
	}
}

ClaseHandler::~ClaseHandler() {
    for(map<int,Clase*>::iterator it = this->clases->begin(); it!=this->clases->end(); ++it){
        Clase * c = it->second;
        delete c;
    }
    this->clases->clear();
    delete this->clases;
    ClaseHandler::instance = NULL;
}