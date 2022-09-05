#include "Factory.h"
#include "../controllers/UsuarioController.h"
#include "../controllers/AsignaturaClaseController.h"

Factory* Factory::instance = NULL;

Factory::Factory() {}

Factory::~Factory() {}

Factory* Factory::getInstance() {
    if (instance == NULL)
        instance = new Factory();
    return instance;
}

IUsuarioController* Factory::getIUsuarioController() {
    return new UsuarioController();
}

IAsignaturaClaseController* Factory::getIAsignaturaClaseController() {
    return new AsignaturaClaseController();
}