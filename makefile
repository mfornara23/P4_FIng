#main
all: FingClass.o

FingClass.o: Datatypes Exceptions Factory Interfaces Routines Utils
	g++ -o ./bin/FingClass -Wall ./src/main.cpp ./lib/libLab05.lib


#exceptions
AsignacionDuplicated:
	g++ -Wall -Werror -o ./obj/AsignacionDuplicated.o -c ./src/exceptions/AsignacionDuplicated.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsignacionDuplicated.o
AsignaturaDuplicated:
	g++ -Wall -Werror -o ./obj/AsignaturaDuplicated.o -c ./src/exceptions/AsignaturaDuplicated.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsignaturaDuplicated.o
AsignaturaNotFound:
	g++ -Wall -Werror -o ./obj/AsignaturaNotFound.o -c ./src/exceptions/AsignaturaNotFound.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsignaturaNotFound.o
ClaseNotFound:
	g++ -Wall -Werror -o ./obj/ClaseNotFound.o -c ./src/exceptions/ClaseNotFound.cpp
	ar rvs ./lib/libLab05.lib ./obj/ClaseNotFound.o
MaxHabilitados:
	g++ -Wall -Werror -o ./obj/MaxHabilitados.o -c ./src/exceptions/MaxHabilitados.cpp
	ar rvs ./lib/libLab05.lib ./obj/MaxHabilitados.o
UsuarioDuplicated:
	g++ -Wall -Werror -o ./obj/UsuarioDuplicated.o -c ./src/exceptions/UsuarioDuplicated.cpp
	ar rvs ./lib/libLab05.lib ./obj/UsuarioDuplicated.o
UsuarioNotFound:
	g++ -Wall -Werror -o ./obj/UsuarioNotFound.o -c ./src/exceptions/UsuarioNotFound.cpp
	ar rvs ./lib/libLab05.lib ./obj/UsuarioNotFound.o
WrongPassword:
	g++ -Wall -Werror -o ./obj/WrongPassword.o -c ./src/exceptions/WrongPassword.cpp
	ar rvs ./lib/libLab05.lib ./obj/WrongPassword.o
InvalidOption:
	g++ -Wall -Werror -o ./obj/InvalidOption.o -c ./src/exceptions/InvalidOption.cpp
	ar rvs ./lib/libLab05.lib ./obj/InvalidOption.o
AsignacionNotFound:
	g++ -Wall -Werror -o ./obj/AsignacionNotFound.o -c ./src/exceptions/AsignacionNotFound.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsignacionNotFound.o
ClaseDuplicated:
	g++ -Wall -Werror -o ./obj/ClaseDuplicated.o -c ./src/exceptions/ClaseDuplicated.cpp
	ar rvs ./lib/libLab05.lib ./obj/ClaseDuplicated.o
MensajeNotFound:
	g++ -Wall -Werror -o ./obj/MensajeNotFound.o -c ./src/exceptions/MensajeNotFound.cpp
	ar rvs ./lib/libLab05.lib ./obj/MensajeNotFound.o
AsignacionNotAvailable:
	g++ -Wall -Werror -o ./obj/AsignacionNotAvailable.o -c ./src/exceptions/AsignacionNotAvailable.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsignacionNotAvailable.o
FechaAnterior:
	g++ -Wall -Werror -o ./obj/FechaAnterior.o -c ./src/exceptions/FechaAnterior.cpp
	ar rvs ./lib/libLab05.lib ./obj/FechaAnterior.o
EstudianteNoHabilitado:
	g++ -Wall -Werror -o ./obj/EstudianteNoHabilitado.o -c ./src/exceptions/EstudianteNoHabilitado.cpp
	ar rvs ./lib/libLab05.lib ./obj/EstudianteNoHabilitado.o
AsistenciaDuplicated:
	g++ -Wall -Werror -o ./obj/AsistenciaDuplicated.o -c ./src/exceptions/AsistenciaDuplicated.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsistenciaDuplicated.o
ClaseNotAvailable:
	g++ -Wall -Werror -o ./obj/ClaseNotAvailable.o -c ./src/exceptions/ClaseNotAvailable.cpp
	ar rvs ./lib/libLab05.lib ./obj/ClaseNotAvailable.o
ClaseFinalizada:
	g++ -Wall -Werror -o ./obj/ClaseFinalizada.o -c ./src/exceptions/ClaseFinalizada.cpp
	ar rvs ./lib/libLab05.lib ./obj/ClaseFinalizada.o
FinalizarNotAllowed:
	g++ -Wall -Werror -o ./obj/FinalizarNotAllowed.o -c ./src/exceptions/FinalizarNotAllowed.cpp
	ar rvs ./lib/libLab05.lib ./obj/FinalizarNotAllowed.o
NoExistenInscriptos:
	g++ -Wall -Werror -o ./obj/NoExistenInscriptos.o -c ./src/exceptions/NoExistenInscriptos.cpp
	ar rvs ./lib/libLab05.lib ./obj/NoExistenInscriptos.o

Exceptions: AsignacionDuplicated AsignaturaDuplicated AsignaturaNotFound ClaseNotFound MaxHabilitados UsuarioDuplicated UsuarioNotFound WrongPassword InvalidOption AsignacionNotFound ClaseDuplicated MensajeNotFound AsignacionNotAvailable FechaAnterior EstudianteNoHabilitado AsistenciaDuplicated ClaseNotAvailable ClaseFinalizada FinalizarNotAllowed NoExistenInscriptos


#datatypes
DtFecha:
	g++ -Wall -Werror -o ./obj/DtFecha.o -c ./src/datatypes/DtFecha.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtFecha.o
DtAsignatura:
	g++ -Wall -Werror -o ./obj/DtAsignatura.o -c ./src/datatypes/DtAsignatura.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtAsignatura.o
DtMensaje: DtFecha
	g++ -Wall -Werror -o ./obj/DtMensaje.o -c ./src/datatypes/DtMensaje.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtMensaje.o
DtNotificacion: DtFecha
	g++ -Wall -Werror -o ./obj/DtNotificacion.o -c ./src/datatypes/DtNotificacion.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtNotificacion.o
DtUsuario: DtNotificacion
	g++ -Wall -Werror -o ./obj/DtUsuario.o -c ./src/datatypes/DtUsuario.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtUsuario.o
DtAdministrador:
	g++ -Wall -Werror -o ./obj/DtAdministrador.o -c ./src/datatypes/DtAdministrador.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtAdministrador.o
DtEstudiante: DtAsignatura DtAsistencia
	g++ -Wall -Werror -o ./obj/DtEstudiante.o -c ./src/datatypes/DtEstudiante.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtEstudiante.o
DtDocente: DtAsignatura DtAsistencia
	g++ -Wall -Werror -o ./obj/DtDocente.o -c ./src/datatypes/DtDocente.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtDocente.o
DtClase:
	g++ -Wall -Werror -o ./obj/DtClase.o -c ./src/datatypes/DtClase.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtClase.o
DtTeorico:
	g++ -Wall -Werror -o ./obj/DtTeorico.o -c ./src/datatypes/DtTeorico.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtTeorico.o
DtPractico:
	g++ -Wall -Werror -o ./obj/DtPractico.o -c ./src/datatypes/DtPractico.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtPractico.o
DtMonitoreo: DtEstudiante
	g++ -Wall -Werror -o ./obj/DtMonitoreo.o -c ./src/datatypes/DtMonitoreo.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtMonitoreo.o
DtAsistencia: DtClase DtUsuario
	g++ -Wall -Werror -o ./obj/DtAsistencia.o -c ./src/datatypes/DtAsistencia.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtAsistencia.o
DtAsistenciaEnDiferido: DtFecha
	g++ -Wall -Werror -o ./obj/DtAsistenciaEnDiferido.o -c ./src/datatypes/DtAsistenciaEnDiferido.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtAsistenciaEnDiferido.o
DtAsistenciaEnVivo: DtFecha
	g++ -Wall -Werror -o ./obj/DtAsistenciaEnVivo.o -c ./src/datatypes/DtAsistenciaEnVivo.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtAsistenciaEnVivo.o
DtReporteTiempoAsistencia: DtClase
	g++ -Wall -Werror -o ./obj/DtReporteTiempoAsistencia.o -c ./src/datatypes/DtReporteTiempoAsistencia.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtReporteTiempoAsistencia.o
DtReporteTiempoDictado: DtAsignatura DtFecha
	g++ -Wall -Werror -o ./obj/DtReporteTiempoDictado.o -c ./src/datatypes/DtReporteTiempoDictado.cpp
	ar rvs ./lib/libLab05.lib ./obj/DtReporteTiempoDictado.o


Datatypes: DtFecha DtMensaje DtNotificacion DtUsuario DtAdministrador DtEstudiante DtDocente DtClase DtTeorico DtPractico DtMonitoreo DtAsistencia DtAsistenciaEnDiferido DtAsistenciaEnVivo DtAsignatura DtReporteTiempoAsistencia DtReporteTiempoDictado



#classes 
Asignatura:
	g++ -Wall -Werror -o ./obj/Asignatura.o -c ./src/classes/Asignatura.cpp
	ar rvs ./lib/libLab05.lib ./obj/Asignatura.o
Mensaje: DtFecha
	g++ -Wall -Werror -o ./obj/Mensaje.o -c ./src/classes/Mensaje.cpp
	ar rvs ./lib/libLab05.lib ./obj/Mensaje.o
Notificacion: DtFecha
	g++ -Wall -Werror -o ./obj/Notificacion.o -c ./src/classes/Notificacion.cpp
	ar rvs ./lib/libLab05.lib ./obj/Notificacion.o
Usuario: Notificacion DtNotificacion Mensaje Asignatura
	g++ -Wall -Werror -o ./obj/Usuario.o -c ./src/classes/Usuario.cpp
	ar rvs ./lib/libLab05.lib ./obj/Usuario.o
Administrador:
	g++ -Wall -Werror -o ./obj/Administrador.o -c ./src/classes/Administrador.cpp
	ar rvs ./lib/libLab05.lib ./obj/Administrador.o
Estudiante: Asistencia
	g++ -Wall -Werror -o ./obj/Estudiante.o -c ./src/classes/Estudiante.cpp
	ar rvs ./lib/libLab05.lib ./obj/Estudiante.o
Docente: DtAsignatura Clase AsignacionNotFound
	g++ -Wall -Werror -o ./obj/Docente.o -c ./src/classes/Docente.cpp
	ar rvs ./lib/libLab05.lib ./obj/Docente.o
Clase: Asignatura Mensaje DtFecha
	g++ -Wall -Werror -o ./obj/Clase.o -c ./src/classes/Clase.cpp
	ar rvs ./lib/libLab05.lib ./obj/Clase.o
Teorico:
	g++ -Wall -Werror -o ./obj/Teorico.o -c ./src/classes/Teorico.cpp
	ar rvs ./lib/libLab05.lib ./obj/Teorico.o
Practico:
	g++ -Wall -Werror -o ./obj/Practico.o -c ./src/classes/Practico.cpp
	ar rvs ./lib/libLab05.lib ./obj/Practico.o
Monitoreo: Estudiante MaxHabilitados
	g++ -Wall -Werror -o ./obj/Monitoreo.o -c ./src/classes/Monitoreo.cpp
	ar rvs ./lib/libLab05.lib ./obj/Monitoreo.o
Asistencia: Clase Usuario
	g++ -Wall -Werror -o ./obj/Asistencia.o -c ./src/classes/Asistencia.cpp
	ar rvs ./lib/libLab05.lib ./obj/Asistencia.o
AsistenciaEnDiferido: DtFecha
	g++ -Wall -Werror -o ./obj/AsistenciaEnDiferido.o -c ./src/classes/AsistenciaEnDiferido.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsistenciaEnDiferido.o
AsistenciaEnVivo: DtFecha
	g++ -Wall -Werror -o ./obj/AsistenciaEnVivo.o -c ./src/classes/AsistenciaEnVivo.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsistenciaEnVivo.o
Sesion: Usuario
	g++ -Wall -Werror -o ./obj/Sesion.o -c ./src/classes/Sesion.cpp
	ar rvs ./lib/libLab05.lib ./obj/Sesion.o
Reloj: 
	g++ -Wall -Werror -o ./obj/Reloj.o -c ./src/utils/Reloj.cpp
	ar rvs ./lib/libLab05.lib ./obj/Reloj.o

Classes: Asignatura Mensaje Notificacion Usuario Administrador Estudiante Docente Clase Teorico Practico Monitoreo Asistencia AsistenciaEnDiferido AsistenciaEnVivo Sesion

#handlers
AsignaturaHandler: Asignatura DtAsignatura AsignaturaNotFound AsignacionDuplicated
	g++ -Wall -Werror -o ./obj/AsignaturaHandler.o -c ./src/handlers/AsignaturaHandler.cpp
	ar rvs ./lib/libLab05.lib ./obj/AsignaturaHandler.o
ClaseHandler: Clase ClaseNotFound ClaseDuplicated
	g++ -Wall -Werror -o ./obj/ClaseHandler.o -c ./src/handlers/ClaseHandler.cpp
	ar rvs ./lib/libLab05.lib ./obj/ClaseHandler.o
UsuarioHandler: Usuario Administrador Docente Estudiante DtUsuario DtAdministrador DtEstudiante DtDocente UsuarioNotFound
	g++ -Wall -Werror -o ./obj/UsuarioHandler.o -c ./src/handlers/UsuarioHandler.cpp
	ar rvs ./lib/libLab05.lib ./obj/UsuarioHandler.o

Handlers: AsignaturaHandler ClaseHandler UsuarioHandler


#interfaces
IAsignaturaClaseController:
	g++ -Wall -Werror -o ./obj/IAsignaturaClaseController.o -c ./src/interfaces/IAsignaturaClaseController.cpp
	ar rvs ./lib/libLab05.lib ./obj/IAsignaturaClaseController.o
IUsuarioController:
	g++ -Wall -Werror -o ./obj/IUsuarioController.o -c ./src/interfaces/IUsuarioController.cpp
	ar rvs ./lib/libLab05.lib ./obj/IUsuarioController.o

Interfaces: IAsignaturaClaseController IUsuarioController

#controllers
UsuarioController: IUsuarioController Handlers Exceptions Datatypes Classes AsignaturaClaseController Reloj
	g++ -Wall -Werror -o ./obj/UsuarioController.o -c ./src/controllers/UsuarioController.cpp
	ar rvs ./lib/libLab05.lib ./obj/UsuarioController.o
AsignaturaClaseController: IAsignaturaClaseController Handlers Exceptions Datatypes Classes Reloj
	g++ -Wall -Werror -o ./obj/PropiedadController.o -c ./src/controllers/AsignaturaClaseController.cpp
	ar rvs ./lib/libLab05.lib ./obj/PropiedadController.o

Controllers: UsuarioController AsignaturaClaseController



#factory
Factory: Controllers
	g++ -Wall -Werror -o ./obj/Factory.o -c ./src/factory/Factory.cpp
	ar rvs ./lib/libLab05.lib ./obj/Factory.o

#routines
CargaDatos: Interfaces Datatypes Classes ClaseHandler Exceptions
	g++ -Wall -Werror -o ./obj/CargaDatos.o -c ./src/routines/CargaDatos.cpp
	ar rvs ./lib/libLab05.lib ./obj/CargaDatos.o

Routines : CargaDatos 

#utils
Utils: DtFecha
	g++ -Wall -Werror -o ./obj/MenuUtils.o -c ./src/utils/MenuUtils.cpp
	ar rvs ./lib/libLab05.lib ./obj/MenuUtils.o

clean:
	rm ./obj/*.o
	rm ./bin/FingClass
