#ifndef  USUARIOCONTROLLER_H
#define  USUARIOCONTROLLER_H

#include "../interfaces/IUsuarioController.h"
#include "../datatypes/DtDocente.h"
#include "../datatypes/DtEstudiante.h"
#include "../datatypes/DtAdministrador.h"
#include "../handlers/UsuarioHandler.h"
#include "../controllers/AsignaturaClaseController.h"
#include "../utils/Reloj.h"
#include "../factory/Factory.h"
#include "../classes/Sesion.h"

using namespace std;

class UsuarioController : public IUsuarioController{
private:
    UsuarioHandler* uHandler;
    Reloj* reloj;
    Sesion* sesion;
public:
    UsuarioController();
    virtual ~UsuarioController();
    void altaUsuario(DtUsuario* usuario);
    set<DtNotificacion*>* consultarNotificaciones(string &email);
    void modificarFechaSistema(DtFecha* fecha);
    DtFecha* obtenerFechaSistema();
    void iniciarSesion(string &email, string &password);
    DtUsuario* getUsuarioLoggeado();
    void cerrarSesion();
};

#endif
