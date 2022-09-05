#ifndef LAB5_DTCLASE_H
#define LAB5_DTCLASE_H

#include <string>

#include "DtFecha.h"
#include "DtAsignatura.h"
#include "DtMensaje.h"

using namespace std;

class DtAsistencia;
class DtAsistenciaEnDiferido;
class DtAsistenciaEnVivo;

class DtClase {
private:
    int codigo;
    string nombre;
    DtFecha* inicio;
    DtFecha* fin;
    string urlVideo;
    string iniciadaPor;
    DtAsignatura* dtAsignatura;
    set<DtMensaje*>* dtMensajes;
    set<DtAsistenciaEnDiferido*>* dtAsistenciasEnDiferido;
    set<DtAsistenciaEnVivo*>* dtAsistenciasEnVivo;
public:
    DtClase( int &codigo,  string &nombre, DtFecha* inicio, DtFecha* fin,
             string &urlVideo,  string &iniciadaPor, DtAsignatura* dtAsignatura);
     int &getCodigo() ;
    void setCodigo( int &codigo);
     string &getNombre() ;
    void setNombre( string &nombre);
    DtFecha* getInicio();
    void setInicio(DtFecha* inicio);
    DtFecha* getFin();
    void setFin(DtFecha* fin);
     string &getUrlVideo() ;
    void setUrlVideo( string &urlVideo);
     string &getIniciadaPor() ;
    void setIniciadaPor( string &iniciadaPor);
     DtAsignatura* getDtAsignatura();
    void setAsignatura(DtAsignatura* dtAsignatura);
    set<DtMensaje*> *getDtMensajes() ;
    void setDtMensajes(set<DtMensaje *> *dtMensajes);
    set<DtAsistenciaEnDiferido *> *getDtAsistenciasEnDiferido() ;
    void setDtAsistenciasEnDiferido(set<DtAsistenciaEnDiferido *> *dtAsistenciasEnDiferido);
    set<DtAsistenciaEnVivo *> *getDtAsistenciasEnVivo() ;
    void setDtAsistenciasEnVivo(set<DtAsistenciaEnVivo *> *dtAsistenciasEnVivo);
    virtual ~DtClase();
};

#endif //LAB5_DTCLASE_H
