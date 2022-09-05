#ifndef LAB5_NOTIFICACION_H
#define LAB5_NOTIFICACION_H

#include <string>
#include "../datatypes/DtFecha.h"

using namespace std;

class Notificacion {
private:
    string contenidoMensaje;
    string codigoAsignatura;
    int codigoClase;
    DtFecha *horaMensaje;
    string autor;
public:
    Notificacion(string &contenidoMensaje, string &codigoAsignatura, int codigoClase, DtFecha *horaMensaje, string &autor);
    string& getAutor();
    void setAutor(string &autor);
    string& getCodigoAsignatura();
    void setCodigoAsignatura(string &codigoAsignatura);
    int getCodigoClase();
    void setCodigoClase(int codigoClase);
    string& getContenidoMensaje();
    void setContenidoMensaje(string &contenidoMensaje);
    DtFecha *getHoraMensaje();
    void setHoraMensaje(DtFecha *horaMensaje);
    ~Notificacion();
};

#endif //LAB5_NOTIFICACION_H
