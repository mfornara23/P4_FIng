#ifndef FACTORY_H
#define FACTORY_H

#include <string>

#include "../interfaces/IUsuarioController.h"
#include "../interfaces/IAsignaturaClaseController.h"
#include "../utils/Reloj.h"


using namespace std;

class Factory {
private:
    static Factory* instance;
    Factory();
public:
    ~Factory();
    static Factory* getInstance();
    static IUsuarioController* getIUsuarioController();
    static IAsignaturaClaseController* getIAsignaturaClaseController();
};

#endif
