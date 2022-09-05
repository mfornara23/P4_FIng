#ifndef LAB5_MENSAJE_H
#define LAB5_MENSAJE_H

#include <string>

#include "../datatypes/DtFecha.h"

using namespace std;

class Clase;

class Mensaje {
private:
    static int currentId;
    int id;
    string autor;
    string contenido;
    DtFecha *fechaEnvio;
    int respondeA;
    Clase *clase;
public:
    Mensaje(string &autor, string &contenido, DtFecha *fechaEnvio, int respondeA);
    string& getAutor();
    void setAutor(string &autor);
    string& getContenido();
    void setContenido(string &contenido);
    DtFecha *getFechaEnvio();
    void setFechaEnvio(DtFecha *fechaEnvio);
    int getId();
    int getRespondeA();
    void setRespondeA(int respondeA);
    Clase *getClase();
    void setClase(Clase *clase);
    ~Mensaje();
};

#endif //LAB5_MENSAJE_H
