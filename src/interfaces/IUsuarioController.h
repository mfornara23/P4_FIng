#ifndef  IUSUARIOCONTROLLER_H
#define  IUSUARIOCONTROLLER_H

#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtNotificacion.h"
#include "../datatypes/DtFecha.h"

using namespace std;

class IUsuarioController{

public:
      IUsuarioController();
      virtual ~IUsuarioController();
      virtual void altaUsuario(DtUsuario* usuario) = 0;
      virtual set<DtNotificacion*>* consultarNotificaciones(string &email) = 0;
      virtual void modificarFechaSistema(DtFecha* fecha)=0;
      virtual DtFecha* obtenerFechaSistema()=0;
      virtual void iniciarSesion(string &email, string &password) = 0;
      virtual DtUsuario* getUsuarioLoggeado() = 0;
      virtual void cerrarSesion() = 0;
};

#endif
