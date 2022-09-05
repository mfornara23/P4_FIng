#ifndef RELOJ_H
#define RELOJ_H

#include "../datatypes/DtFecha.h"
#include <string>

using namespace std;

class Reloj {
private:
    static Reloj* instance;
    DtFecha* timer;
    Reloj();
public:
    ~Reloj();
    static Reloj* getInstance();
    DtFecha* getTimer();
    void setTimer(DtFecha *timer);
};


#endif
