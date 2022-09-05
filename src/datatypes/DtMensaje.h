#ifndef LAB5_DTMENSAJE_H
#define LAB5_DTMENSAJE_H

#include <string>
#include "DtFecha.h"

using namespace std;

class DtClase;

class DtMensaje {
private:
    int id;
    string autor;
    string contenido;
    DtFecha* fechaEnvio;
    int respondeA;
    DtClase* dtClase;
public:
    DtMensaje(int id,  string &autor,  string &contenido, DtFecha* fechaEnvio, int respondeA);
    int getId() ;
    void setId(int id);
     string &getAutor() ;
    void setAutor( string &autor);
     string &getContenido() ;
    void setContenido( string &contenido);
    DtFecha* getFechaEnvio();
    void setFechaEnvio(DtFecha* fechaEnvio);
    int getRespondeA() ;
    void setRespondeA(int respondeA);
    DtClase* getDtClase() ;
    void setDtClase(DtClase *dtClase);
    virtual ~DtMensaje();
};

#endif //LAB5_DTMENSAJE_H
