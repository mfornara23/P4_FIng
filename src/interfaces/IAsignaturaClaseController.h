#ifndef  IASIGNATURACLASECONTROLLER_H
#define  IASIGNATURACLASECONTROLLER_H


#include <set>

#include "../datatypes/DtAsignatura.h"
#include "../datatypes/DtClase.h"
#include "../datatypes/DtEstudiante.h"
#include "../datatypes/DtDocente.h"
#include "../datatypes/DtReporteTiempoAsistencia.h"
#include "../datatypes/DtFecha.h"
#include "../datatypes/DtReporteTiempoDictado.h"
#include "../datatypes/DtMensaje.h"
#include "../enums/enums.h"
#include "../classes/Usuario.h"

using namespace std;

class IAsignaturaClaseController{
public:
      IAsignaturaClaseController();
      virtual ~IAsignaturaClaseController();
      virtual void altaAsignatura(DtAsignatura* asignatura)=0;
      virtual set<DtDocente*>* listarDocentesNoAsignados(string &codigo)=0;
      virtual void asignarDocente(string &codigo, string &email, tipoAsignacion rol)=0;
      virtual DtReporteTiempoDictado* obtenerTiempoDictado(string &codigoAsignatura)=0;
      virtual void eliminarAsignatura(string &codigoAsignatura)=0;
      virtual set<DtAsignatura*>* listarAsignaturas(string &email) = 0;
      virtual set<DtEstudiante*>* listarEstudiantes(string &codigo) = 0;
      virtual int confirmarClase(string &email, string &codigo, string &nombre, DtFecha *inicio, set<DtEstudiante*>* estudiantes) = 0;
      virtual set<DtClase*>* listarClasesVivo(string &email) = 0;
      virtual void finalizarClase(int id, string emailFinalizar) = 0;
      virtual set<DtReporteTiempoAsistencia*>* obtenerTiempoAsistenciaClase(string &email, string &codigo) = 0;
      virtual set<DtMensaje*>* listarMensajes(int id) = 0;
      virtual int altaMensaje(string &email, int id, string &texto, int respondeA) = 0;
      virtual void inscribirseAsignatura(string &codigo, DtEstudiante *dtEstudiante) = 0;
      virtual set<DtAsignatura*>* listarAsignaturasNoInscripto(int cedula) = 0;
      virtual set<DtAsignatura*>* listarAsignaturas(int cedula) = 0;
      virtual set<DtClase*>* listarClasesDisponibles(int cedula) = 0;
      virtual set<DtClase*>* listarClasesVivo(int cedula) = 0;
      virtual set<DtClase*>* listarClasesEnVivoPorAsignatura(string codigo) = 0;
      virtual set<DtAsignatura*>* listarAsignaturas() = 0;
      virtual void registrarAsistencia(int id, string codigoAsignatura, DtEstudiante *dtEstudiante) = 0;
      virtual void confirmarFinalizacionAsistenciaVivo(int id, DtEstudiante *dtEstudiante) = 0;
      virtual set<Usuario*>* getSuscriptores() = 0;
      virtual void suscribirseNotificaciones(string &email) = 0;
      virtual void addSuscriptor(Usuario* usuario) = 0;
};

#endif
