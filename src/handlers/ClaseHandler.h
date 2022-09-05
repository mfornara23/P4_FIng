#ifndef CLASEHANDLER_H
#define CLASEHANDLER_H

#include <map>
#include <string>
#include <set>

#include "../classes/Clase.h"

using namespace std;

class ClaseHandler {
private:
	static ClaseHandler* instance;
    map<int,Clase*>* clases;
    ClaseHandler();
public:
    static ClaseHandler* getInstance();
    Clase* getClase(int code);
	void addClase(Clase* clase);
	Clase* remove(int codigo);
    virtual ~ClaseHandler();
};

#endif
