#ifndef  ASIGNATURACLASECONTROLLER_H
#define  ASIGNATURACLASECONTROLLER_H

#include "../interfaces/IAsignaturaClaseController.h"
#include "../handlers/AsignaturaHandler.h"
#include "../handlers/UsuarioHandler.h"
#include "../handlers/ClaseHandler.h"
#include "../classes/Asignatura.h"
#include "../classes/Clase.h"
#include "../classes/Estudiante.h"
#include "../classes/Docente.h"
#include "../classes/Usuario.h"
#include "../classes/Teorico.h"
#include "../classes/Practico.h"
#include "../classes/Monitoreo.h"
#include "../classes/Asistencia.h"
#include "../classes/AsistenciaEnVivo.h"
#include "../classes/Mensaje.h"
#include "../utils/Reloj.h"

#include <math.h>
#include <string>

using namespace std;

class AsignaturaClaseController : public IAsignaturaClaseController {
private:
      AsignaturaHandler* aHandler;
      UsuarioHandler* uHandler;
      ClaseHandler* cHandler;
      Reloj* reloj;
      set<Usuario*>* suscriptores;
public:
      AsignaturaClaseController();
      virtual ~AsignaturaClaseController();
      void altaAsignatura(DtAsignatura* asignatura);
      set<DtAsignatura*>* listarAsignaturas();
      set<DtDocente*>* listarDocentesNoAsignados(string &codigo);
      void asignarDocente(string &codigo, string &email, tipoAsignacion rol);
      DtReporteTiempoDictado* obtenerTiempoDictado(string &codigoAsignatura);
      void eliminarAsignatura(string &codigoAsignatura);
      set<DtAsignatura*>* listarAsignaturas(string &email);
      set<DtEstudiante*>* listarEstudiantes(string &codigo);
      int confirmarClase(string &email, string &codigo, string &nombre, DtFecha *inicio, set<DtEstudiante*>* estudiantes);
      set<DtClase*>* listarClasesVivo(string &email);
      void finalizarClase(int id, string emailFinalizar);
      set<DtReporteTiempoAsistencia*>* obtenerTiempoAsistenciaClase(string &email, string &codigo);
      set<DtMensaje*>* listarMensajes(int id);
      int altaMensaje(string &email, int id, string &texto, int respondeA);
      void inscribirseAsignatura(string &codigo, DtEstudiante* dtEstudiante);
      set<DtAsignatura *> *listarAsignaturasNoInscripto(int cedula);
      set<DtAsignatura *> *listarAsignaturas(int cedula);
      set<DtClase *> *listarClasesDisponibles(int cedula);
      set<DtClase *> *listarClasesVivo(int cedula);
      set<DtClase*>* listarClasesEnVivoPorAsignatura(string codigo);
      void registrarAsistencia(int id, string codigoAsignatura, DtEstudiante* dtEstudiante);
      void confirmarFinalizacionAsistenciaVivo(int id, DtEstudiante* dtEstudiante);
      set<Usuario*>* getSuscriptores();
      void suscribirseNotificaciones(string &email);
      void addSuscriptor(Usuario* usuario);
};

#endif
