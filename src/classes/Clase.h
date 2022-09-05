#ifndef LAB5_CLASE_H
#define LAB5_CLASE_H

#include <string>
#include <set>

#include "../datatypes/DtFecha.h"
#include "Mensaje.h"
#include "Asignatura.h"
#include "../utils/Reloj.h"

using namespace std;

class Asistencia;

class AsistenciaEnDiferido;

class AsistenciaEnVivo;

class Clase {
private:
    static int currentId;
    int codigo;
    string nombre;
    DtFecha *inicio;
    DtFecha *fin;
    string urlVideo;
    string iniciadaPor;
    Asignatura *asignatura;
    set<Mensaje *> *mensajes;
    set<AsistenciaEnDiferido *> *asistenciasEnDiferido;
    set<AsistenciaEnVivo *> *asistenciasEnVivo;
public:
    Clase(string &nombre, DtFecha *inicio, DtFecha *fin, string &urlVideo, string &iniciadaPor, Asignatura *asignatura);
    static int getCurrentId();
    int &getCodigo();
    string &getNombre();
    void setNombre(string &nombre);
    DtFecha *getInicio();
    void setInicio(DtFecha *inicio);
    DtFecha *getFin();
    void setFin(DtFecha *fin);
    string &getUrlVideo();
    void setUrlVideo(string urlVideo);
    string &getIniciadaPor();
    void setIniciadaPor(string &iniciadaPor);
    bool esClaseEnDiferido();
    set<Mensaje *> *listarMensajes();
    void agregarMensaje(Mensaje *msg);
    Asignatura *getAsignatura();
    void setAsignatura(Asignatura *asignatura);
    set<Mensaje *> *getMensajes();
    Mensaje *getMensajeById(int id);
    void setMensajes(set<Mensaje *> *mensajes);
    set<AsistenciaEnDiferido *> *getAsistenciasEnDiferido();
    void setAsistenciasEnDiferido(set<AsistenciaEnDiferido *> *asistenciasEnDiferido);
    set<AsistenciaEnVivo *> *getAsistenciasEnVivo();
    void setAsistenciasEnVivo(set<AsistenciaEnVivo *> *asistenciasEnVivo);
    void addAsistencia(Asistencia* asis);
    virtual ~Clase();
};


#endif //LAB5_CLASE_H
