#ifndef LAB5_DTNOTIFICACION_H
#define LAB5_DTNOTIFICACION_H

#include <string>
#include "DtFecha.h"

using namespace std;

class DtNotificacion
{
private:
    string contenidoMensaje;
    string codigoAsignatura;
    int codigoClase;
    DtFecha* horaMensaje;
    string autor;
public:
    DtNotificacion(string &contenidoMensaje, string &codigoAsignatura, int codigoClase, DtFecha* horaMensaje, string autor);
    string& getAutor() ;
    void setAutor(string &autor);
    string& getCodigoAsignatura() ;
    void setCodigoAsignatura(string &codigoAsignatura);
    int getCodigoClase() ;
    void setCodigoClase(int codigoClase);
    string& getContenidoMensaje() ;
    void setContenidoMensaje(string &contenidoMensaje);
    DtFecha* getHoraMensaje();
    void setHoraMensaje(DtFecha* horaMensaje);
    ~DtNotificacion();
};

#endif //LAB5_DTNOTIFICACION_H
