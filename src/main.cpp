#include <iostream>

#include "factory/Factory.h"
#include "interfaces/IUsuarioController.h"
#include "interfaces/IAsignaturaClaseController.h"

#include "datatypes/DtUsuario.h"
#include "datatypes/DtAsignatura.h"
#include "datatypes/DtDocente.h"
#include "datatypes/DtAdministrador.h"
#include "datatypes/DtEstudiante.h"
#include "datatypes/DtReporteTiempoDictado.h"
#include "datatypes/DtReporteTiempoAsistencia.h"
#include "datatypes/DtFecha.h"

#include "routines/CargaDatos.h"

#include "utils/MenuUtils.h"

#include "exceptions/InvalidOption.h"
#include "exceptions/NoExistenInscriptos.h"
#include "exceptions/UsuarioNotFound.h"

#include "enums/enums.h"

#include <string>
#include <set>

using namespace std;

bool menu(void);
bool cargaD = false;

void iniciarSesion();
void altaAsignatura();
void asignacionDeDocentesAAsignatura();
void tiempoDeDictadoDeClases();
void eliminacionDeAsignatura();
void altaUsuario();
void envioMensaje();
void suscribirseANotificaciones();
void consultaDeNotificaciones();
void consultarReloj();
void modificarReloj();
void cerrarSesion();
void inicioDeClase();
void finalizacionDeClase();
void tiempoDeAsistenciaAClase();
void inscripcionAAsignaturas();
void asistenciaAClaseEnVivo();
void finalizacionDeAsistenciaAClaseEnVivo();
bool listarNotificaciones(string &email);
bool listarDocentesNoAsignados(string &codigo);
bool listarClasesEnVivo(string &email);
bool listarClasesEnVivo(int cedula);
bool listarAsignaturas();
bool listarAsignaturas(string &email);
bool listarAsignaturas(int cedula);
bool listarAsignaturasNoInscripto(int ci);
bool listarMensajes(int id);
bool listarClasesEnVivoPorAsignatura(string codigo);
set<DtEstudiante*>* listarEstudiantes(string &codigo);


Factory* factory = Factory::getInstance();
IAsignaturaClaseController *acc = factory->getIAsignaturaClaseController();
IUsuarioController *uc = factory->getIUsuarioController();

int main() {

    bool seguir;
    do {
        try {
            seguir = menu();
        }
        catch (std::out_of_range& e) {
            cout << "Ocurrio un error: " << e.what() << endl<<endl;
            seguir = true;
        }
        catch (std::invalid_argument& e) {
            cout << "Ocurrio un error: " << e.what() << endl<<endl;
            seguir = true;
        }
        catch (exception& e) {
            cout << "Ocurrio un error: " << e.what() << endl<<endl;
            seguir = true;
        }
    } while (seguir);

    return 1;
}

bool menu() {
    int opcion;
    if (uc->getUsuarioLoggeado() == NULL) {
        int opcion = 0;
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
        cout << "Bienvenido. Elija la opcion.\n";
        cout << "    1) Cargar datos de prueba\n";
        cout << "    2) Iniciar sesion\n";
        cout << "    3) Salir\n";
        cout << "    Opcion:";
        opcion = MenuUtils::leerInt();
        switch (opcion) {
            case 1:
                try{
                    if(!cargaD){
                        CargaDatos* cargaDat = new CargaDatos();
                        cargaDat->cargarDatos();
                        cargaD = true;
                        cout << "Los datos se han cargado satisfactoriamente.\n";
                    }else {
                            cout << "Los datos ya han sido cargados.\n";
                    }
                }catch(const exception &e) {
                    cout << e.what()<<endl;
                }
                return true;
                break;
            case 2: iniciarSesion();
                return true;
                break;
            case 3: 
                MenuUtils::limpiarConsola();
                cout << "Desea salir del sistema (se perderan los datos cargados hasta el momento)? (1 = SI/ 2 = NO)" << endl;
                int respuesta;
                respuesta = MenuUtils::leerInt();
                if(respuesta==1){
                    return false;
                }else if(respuesta==2){
                    return true;        
                }else{
                    throw InvalidOption();
                }
            default:
                throw InvalidOption();
        }
        return true;
    } else if (dynamic_cast<DtAdministrador *>(uc->getUsuarioLoggeado()) != NULL) {
        cout << "Bienvenido Administrador: "<<uc->getUsuarioLoggeado()->getNombre()<<". Elija una opcion.\n";
        cout << "    1) Alta de usuario\n";
        cout << "    2) Alta de asignatura\n";
        cout << "    3) Asignacion de docentes a una asignatura\n";
        cout << "    4) Tiempo de dictado de clases\n";
        cout << "    5) Eliminacion de asignatura\n";
        cout << "    6) Consultar Reloj\n";
        cout << "    7) Modificar Reloj\n";
        cout << "    8) Cerrar sesion\n";
        cout << "    9) Salir\n";
        cout << "    Opcion:";
        opcion = MenuUtils::leerInt();
        switch (opcion) {
            case 1:
                MenuUtils::limpiarConsola();
                altaUsuario();
                return true;
            case 2:
                MenuUtils::limpiarConsola();
                altaAsignatura();
                return true;
            case 3:
                MenuUtils::limpiarConsola();
                asignacionDeDocentesAAsignatura();
                return true;
            case 4:
                MenuUtils::limpiarConsola();
                tiempoDeDictadoDeClases();
                return true;
            case 5:
                MenuUtils::limpiarConsola();
                eliminacionDeAsignatura();
                return true;
            case 6:
                MenuUtils::limpiarConsola();
                consultarReloj();
                return true;
            case 7:
                MenuUtils::limpiarConsola();
                modificarReloj();
                return true;
            case 8:
                MenuUtils::limpiarConsola();
                cerrarSesion();
                return true;
            case 9:
                MenuUtils::limpiarConsola();
                cout << "Desea salir del sistema (se perderan los datos cargados hasta el momento)? (1 = SI/ 2 = NO)" << endl;
                int respuesta;
                respuesta = MenuUtils::leerInt();
                if(respuesta==1){
                    return false;
                }else if(respuesta==2){
                    return true;        
                }else{
                    throw InvalidOption();
                }
            default:
                throw InvalidOption();
        }
    } else if (dynamic_cast<DtDocente *>(uc->getUsuarioLoggeado()) != NULL){
        cout << "Bienvenido Docente: "<<uc->getUsuarioLoggeado()->getNombre()<<". Elija una opcion.\n";
        cout << "    1) Inicio de clase\n";
        cout << "    2) Finalizacion de clase\n";
        cout << "    3) Tiempo de asistencia a clase\n";
        cout << "    4) Envio de mensaje\n";
        cout << "    5) Suscribirse a notificaciones\n";
        cout << "    6) Consulta de notificaciones\n";
        cout << "    7) Cerrar sesion\n";
        cout << "    8) Salir\n";
        cout << "    Opcion:";
        opcion = MenuUtils::leerInt();
        switch (opcion) {
            case 1:
                MenuUtils::limpiarConsola();
                inicioDeClase();
                return true;
            case 2:
                MenuUtils::limpiarConsola();
                finalizacionDeClase();
                return true;
            case 3:
                MenuUtils::limpiarConsola();
                tiempoDeAsistenciaAClase();
                return true;
            case 4:
                MenuUtils::limpiarConsola();
                envioMensaje();
                return true;
            case 5:
                MenuUtils::limpiarConsola();
                suscribirseANotificaciones();
                return true;
            case 6:
                MenuUtils::limpiarConsola();
                consultaDeNotificaciones();
                return true;
            case 7:
                MenuUtils::limpiarConsola();
                cerrarSesion();
                return true;
            case 8:
                MenuUtils::limpiarConsola();
                cout << "Desea salir del sistema (se perderan los datos cargados hasta el momento)? (1 = SI/ 2 = NO)" << endl;
                int respuesta;
                respuesta = MenuUtils::leerInt();
                if(respuesta==1){
                    return false;
                }else if(respuesta==2){
                    return true;        
                }else{
                    throw InvalidOption();
                }
            default:
                throw InvalidOption();
        }
    } else if (dynamic_cast<DtEstudiante *>(uc->getUsuarioLoggeado()) != NULL) {
        cout << "Bienvenido Estudiante: "<<uc->getUsuarioLoggeado()->getNombre()<<". Elija una opcion.\n";
        cout << "    1) Inscripcion a asignaturas\n";
        cout << "    2) Asistencia a clase en vivo\n";
        cout << "    3) Finalizacion de asistencia a clase en vivo\n";
        cout << "    4) Envio de mensaje\n";
        cout << "    5) Suscribirse a notificaciones\n";
        cout << "    6) Consulta de notificaciones\n";
        cout << "    7) Cerrar sesion\n";
        cout << "    8) Salir\n";
        cout << "    Opcion:";
        opcion = MenuUtils::leerInt();
        switch (opcion) {
            case 1:
                MenuUtils::limpiarConsola();
                inscripcionAAsignaturas();
                return true;
            case 2:
                MenuUtils::limpiarConsola();
                asistenciaAClaseEnVivo();
                return true;
            case 3:
                MenuUtils::limpiarConsola();
                finalizacionDeAsistenciaAClaseEnVivo();
                return true;
            case 4:
                MenuUtils::limpiarConsola();
                envioMensaje();
                return true;
            case 5:
                MenuUtils::limpiarConsola();
                suscribirseANotificaciones();
                return true;
            case 6:
                MenuUtils::limpiarConsola();
                consultaDeNotificaciones();
                return true;
            case 7:
                MenuUtils::limpiarConsola();
                cerrarSesion();
                return true;
            case 8:
                MenuUtils::limpiarConsola();
                cout << "Desea salir del sistema (se perderan los datos cargados hasta el momento)? (1 = SI/ 2 = NO)" << endl;
                int respuesta;
                respuesta = MenuUtils::leerInt();
                if(respuesta==1){
                    return false;
                }else if(respuesta==2){
                    return true;        
                }else{
                    throw InvalidOption();
                }                
            default:
                throw InvalidOption();
        }
    }
    return 0;
}

void consultaDeNotificaciones() {
    try{
        listarNotificaciones(uc->getUsuarioLoggeado()->getEmail());
    }
    catch (const exception &e) {
        cout << e.what()<<endl;
    }
}

void suscribirseANotificaciones() {
    cout << "Desea confirmar suscribirse a notificaciones? (1 = SI/ 2 = NO)" << endl;
    int respuesta;
    respuesta = MenuUtils::leerInt();
    switch (respuesta) {
        case 1:try{
                acc->suscribirseNotificaciones(uc->getUsuarioLoggeado()->getEmail());
                cout << "Suscripcion realizada correctamente." << endl;
            }
            catch (const exception &e) {
                cout << e.what()<<endl;
            }
            break;
        case 2:
            break;
        default:
            throw InvalidOption();
            break;
    }
}

void envioMensaje() {
    DtUsuario* dtUsuario = uc->getUsuarioLoggeado();
    if (dynamic_cast<DtDocente *>(uc->getUsuarioLoggeado()) != NULL){
        if(listarClasesEnVivo(dtUsuario->getEmail())){
            cout << "Seleccione id de clase: " << endl;
            int id_clase = MenuUtils::leerInt();
            int respuesta;
            int id_responde = 0;

            if(listarMensajes(id_clase)){
                cout << "El mensaje a enviar es en respuesta a uno ya existente? (1 = SI/ 2 = NO)" << endl;
                respuesta = MenuUtils::leerInt();
                if (respuesta == 1) {
                    cout << "Ingrese ID mensaje a responder: " << endl;
                    id_responde = MenuUtils::leerInt();
                }else if (respuesta ==2 ){
                    id_responde = 0;
                } else {
                    throw InvalidOption();
                }
            }
            
            cout << "Ingrese texto del mensaje a enviar: " << endl;
            string texto = MenuUtils::leerString();
            cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
            respuesta = MenuUtils::leerInt();
            switch (respuesta) {
                case 1:try{
                        acc->altaMensaje(uc->getUsuarioLoggeado()->getEmail(), id_clase, texto, id_responde);
                        cout << "Mensaje enviado correctamente." << endl;
                    }
                    catch (const exception &e) {
                        cout << e.what()<<endl;
                    }
                    break;
                case 2:
                    break;
                default:
                    throw InvalidOption();
                    break;
            }
        }
    }else {
        DtEstudiante* dtEstudiante = dynamic_cast<DtEstudiante *>(uc->getUsuarioLoggeado());
        if(listarClasesEnVivo(dtEstudiante->getCedula())){
            cout << "Seleccione id de clase: " << endl;
            int id_clase = MenuUtils::leerInt();
            int respuesta;
            int id_responde = 0;

            if(listarMensajes(id_clase)){
                cout << "El mensaje a enviar es en respuesta a uno ya existente? (1 = SI/ 2 = NO)" << endl;
                respuesta = MenuUtils::leerInt();
                if (respuesta == 1) {
                    cout << "Ingrese ID mensaje a responder: " << endl;
                    id_responde = MenuUtils::leerInt();
                }else if (respuesta ==2 ){
                    id_responde = 0;
                } else {
                    throw InvalidOption();
                }
            }
            
            cout << "Ingrese texto del mensaje a enviar: " << endl;
            string texto = MenuUtils::leerString();
            cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
            respuesta = MenuUtils::leerInt();
            switch (respuesta) {
                case 1:try{
                        acc->altaMensaje(uc->getUsuarioLoggeado()->getEmail(), id_clase, texto, id_responde);
                        cout << "Mensaje enviado correctamente." << endl;
                    }
                    catch (const exception &e) {
                        cout << e.what()<<endl;
                    }
                    break;
                case 2:
                    break;
                default:
                    throw InvalidOption();
                    break;
            }
        }
    }
    
}

void iniciarSesion() {
    
    cout << "Ingrese su email: " << endl;
    string email = MenuUtils::leerString();
    cout << "Ingrese su contrasenia: " << endl;
    string password = MenuUtils::leerString();
    try {
        uc->iniciarSesion(email,password);
        cout << "Sesion iniciada correctamente" << endl;
    } catch (const exception &e) {
        cout << e.what()<<endl;
    }
}

void cerrarSesion() {
    
    try {
        uc->cerrarSesion();
        cout << "Sesion cerrada correctamente" << endl;
    } catch (const exception &e) {
        cout << e.what()<<endl;
    }
}

void altaUsuario() {
    cout << "Ingrese nombre: " << endl;
    string nombre = MenuUtils::leerString();
    cout << "Ingrese email: " << endl;
    string email = MenuUtils::leerString();
    cout << "Ingrese password: " << endl;
    string password = MenuUtils::leerString();
    cout << "Ingrese imagen: " << endl;
    string imagen = MenuUtils::leerString();;
    cout << "Seleccione tipo de usuario a dar de alta: " << endl;
    cout << "    1) Docente\n";
    cout << "    2) Estudiante\n";
    int opcion;
    opcion = MenuUtils::leerInt();
    switch (opcion) {
        case 1:
            cout << "Ingrese Instituto: " << endl;
            cout << "    1) InCo\n";
            cout << "    2) Imerl\n";
            cout << "    3) If\n";
            int opcionInstituto;
            Instituto instituto;
            opcionInstituto = MenuUtils::leerInt();
            switch (opcionInstituto) {
                case 1:
                    instituto = INCO;
                    break;
                case 2:
                    instituto = imerl;
                    break;
                case 3:
                    instituto = ifisica;
                    break;
                default:
                    throw InvalidOption();
            }
            cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
            int respuesta;
            respuesta = MenuUtils::leerInt();
            if (respuesta == 1 ) {
                try {
                    DtDocente* dtDocente = new DtDocente();
                    dtDocente->setNombre(nombre);
                    dtDocente->setEmail(email);
                    dtDocente->setPassword(password);
                    dtDocente->setImagen(imagen);
                    dtDocente->setNombreInst(instituto);
                    uc->altaUsuario(dtDocente);
                    cout << "Docente agregado correctamente" << endl;
                } catch (const exception &e) {
                    cout << e.what()<<endl;
                }
            }else {
                cout << "Proceso cancelado." << endl;
            }
            break;
        case 2:
            cout << "Ingrese cedula: " << endl;
            int cedula ;
            cedula = MenuUtils::leerInt();;
            cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
            int respuesta2;
            respuesta2 = MenuUtils::leerInt();
            if (respuesta2 == 1 ) {
                try {
                    DtEstudiante* dtEstudiante = new DtEstudiante();
                    dtEstudiante->setNombre(nombre);
                    dtEstudiante->setEmail(email);
                    dtEstudiante->setPassword(password);
                    dtEstudiante->setImagen(imagen);
                    dtEstudiante->setCedula(cedula);
                    uc->altaUsuario(dtEstudiante);
                    cout << "Estudiante agregado correctamente" << endl;
                } catch (const exception &e) {
                    cout << e.what()<<endl;
                }
            }else {
                cout << "Proceso cancelado." << endl;
            }
            break;
        default:
            throw InvalidOption();
            break;
    }
}

void altaAsignatura() {
    cout << "Ingrese codigo: " << endl;
    string codigo;
    codigo = MenuUtils::leerString();
    cout << "Ingrese nombre: " << endl;
    string nombre;
    nombre = MenuUtils::leerString();
    int respuesta = 2;
    bool teorico = false;
    cout << "Aplica teorico? (1 = SI/ 2 = NO)" << endl;
    respuesta = MenuUtils::leerInt();
    switch (respuesta) {
        case 1: teorico = true;
            break;
        case 2:
            break;
        default:
            throw InvalidOption();
    }
    bool practico = false;
    cout << "Aplica practico? (1 = SI/ 2 = NO)" << endl;
    respuesta = MenuUtils::leerInt();
    switch (respuesta) {
        case 1: practico = true;
            break;
        case 2:
            break;
        default:
            throw InvalidOption();
    }
    bool monitoreo = false;
    cout << "Aplica monitoreo? (1 = SI/ 2 = NO)" << endl;
    respuesta = MenuUtils::leerInt();
    switch (respuesta) {
        case 1: monitoreo = true;
            break;
        case 2:
            break;
        default:
            throw InvalidOption();
    }
    cout << "Los datos ingresados son: " << endl;
    cout << "   Codigo: " << codigo << endl;
    cout << "   Nombre: " << nombre << endl;
    if (teorico) {
        cout << "   Teorico: aplica" << endl;
    }else {
        cout << "   Teorico: no aplica" << endl;
    }
    if (practico) {
        cout << "   Practico: aplica" << endl;
    }else {
        cout << "   Practico: no aplica" << endl;
    }
    if (monitoreo) {
        cout << "   Monitoreo: aplica" << endl;
    }else {
        cout << "   Monitoreo: no aplica" << endl;
    }
    cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
    respuesta = MenuUtils::leerInt();
    switch (respuesta) {
        case 1:
            try {
                acc->altaAsignatura(new DtAsignatura(codigo, nombre, teorico, practico, monitoreo));
                cout << "Se agrego asignatura satisfactoriamente" << endl;
            } catch (const exception &e) {
                cout << e.what()<<endl;
            }
            break;
        case 2:
            cout << "Se cancela alta de asignatua." << endl;
            break;
        default:
            throw InvalidOption();
    }
}

void asignacionDeDocentesAAsignatura() {
    if (listarAsignaturas()) {
        cout << "Ingrese codigo asignatura: " << endl;
        string codigo = MenuUtils::leerString();
        string email;
        tipoAsignacion rol;
        int opcionAsignacion;
        int respuesta;
        int seguirAgregandoDocentes = 1;
        while (seguirAgregandoDocentes == 1) {
            if (listarDocentesNoAsignados(codigo)) {
                cout << "Ingrese email docente a asignar: " << endl;
                email = MenuUtils::leerString();
                cout << "Ingrese rol de docente: " << endl;
                cout << "    1) Teorico\n";
                cout << "    2) Practico\n";
                cout << "    3) Monitoreo\n";
                opcionAsignacion = MenuUtils::leerInt();
                switch (opcionAsignacion) {
                    case 1:
                        rol = tipoTeorico;
                        break;
                    case 2:
                        rol = tipoPractico;
                        break;
                    case 3:
                        rol = tipoMonitoreo;
                        break;
                    default:
                        throw InvalidOption();
                }
                cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
                respuesta = MenuUtils::leerInt();
                if (respuesta == 1) {
                    try {
                        acc->asignarDocente(codigo, email, rol);
                        cout << "Docente asignado correctamente." << endl;
                        cout << "Desea asignar otro docente? (1 = SI/ 2 = NO)" << endl;
                        seguirAgregandoDocentes = MenuUtils::leerInt();
                    } catch (const exception &e) {
                        cout << e.what() << endl;
                        cout << "Desea asignar otro docente? (1 = SI/ 2 = NO)" << endl;
                        seguirAgregandoDocentes = MenuUtils::leerInt();
                        if(seguirAgregandoDocentes!=1 && seguirAgregandoDocentes!=2) throw InvalidOption();
                    }
                } else if (respuesta == 2) {
                    cout << "Asignacion Cancelada." << endl;
                    cout << "Desea asignar otro docente? (1 = SI/ 2 = NO)" << endl;
                    seguirAgregandoDocentes = MenuUtils::leerInt();
                    if(seguirAgregandoDocentes!=1 && seguirAgregandoDocentes!=2) throw InvalidOption();
                } else {
                    throw InvalidOption();
                }
            } else {
                seguirAgregandoDocentes = 2;
            }
        }
    }
}

void tiempoDeDictadoDeClases(){
    
    set<DtAsignatura*>* dtAsignaturas = acc->listarAsignaturas();
    cout << "Tiempo de dictado de clases: " << endl;
    for (set<DtAsignatura*>::iterator it = dtAsignaturas->begin(); it != dtAsignaturas->end(); ++it){
        DtReporteTiempoDictado* dtReporteTiempoDict = (acc->obtenerTiempoDictado((*it)->getCodigo()));
        cout<< dtReporteTiempoDict->toString() << endl;
        cout<<"_____________________________________________________"<<endl;
    }
}

void eliminacionDeAsignatura(){
    if (listarAsignaturas()) {
        cout << "Seleccione codigo de asignatura a eliminar: " << endl;
        string codigo = MenuUtils::leerString();
        cout << "Desea confirmar eliminacion? (1 = SI/ 2 = NO)" << endl;
        int respuesta;
        respuesta = MenuUtils::leerInt();
        if (respuesta == 1) {
            try {
                acc->eliminarAsignatura(codigo);
                cout << "Se elimino asignatura correctamente" << endl;
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        } else if (respuesta == 2) {
            cout << "Se cancela eliminacion de asignatura" << endl;
        } else {
            throw InvalidOption();
        }
    }
}

void consultarReloj(){
    
    DtFecha* dtFecha = uc->obtenerFechaSistema();
    cout<<"La fecha y hora actuales son: "<<dtFecha->getDia()<<"/"<<dtFecha->getMes()<<"/"<<dtFecha->getAnio()<<" "
                    <<dtFecha->toString()<<endl;
}

void modificarReloj(){
    consultarReloj();
    cout << "Desea modificar el Reloj? (1 = SI/ 2 = NO)" << endl;
    int respuesta;
    respuesta = MenuUtils::leerInt();
    if (respuesta == 1) {
        DtFecha *fecha = MenuUtils::leerFecha();
        uc->modificarFechaSistema(fecha);
        cout << "Se ingreso fecha y hora correctamente." << endl;
        consultarReloj();
    } else if (respuesta == 2) {
        cout << "Modificacion Cancelada." << endl;
    } else {
        throw InvalidOption();
    }
}

void inicioDeClase(){
    if (listarAsignaturas(uc->getUsuarioLoggeado()->getEmail())) {
        cout << "Ingrese codigo de asignatura:" << endl;
        string codigo = MenuUtils::leerString();
        cout << "Ingrese nombre de la clase:" << endl;
        string nombre = MenuUtils::leerString();
        int respuesta;
        DtDocente *docente = dynamic_cast<DtDocente *>(uc->getUsuarioLoggeado());
        set<DtEstudiante *> *estudiantesAIngresar = new set<DtEstudiante *>;
        string tipo = "";

        for (map<DtAsignatura *, tipoAsignacion>::iterator it = docente->getAsignaciones()->begin();
             it != docente->getAsignaciones()->end(); ++it) {

            if (it->first->getCodigo() == codigo && it->second == tipoMonitoreo) {
                int cedula;
                int seguirAgregandoEstudiantes = 1;
                set<DtEstudiante*>* estudiantes = listarEstudiantes(codigo);
                if(!estudiantes->empty()){
                    while (seguirAgregandoEstudiantes == 1) {
                        cout << "Ingrese cedula de estudiante a asignar: " << endl;
                        cedula = MenuUtils::leerInt();
                        bool found = false;
                        for (set<DtEstudiante *>::iterator itEstudiante = estudiantes->begin();
                            itEstudiante != estudiantes->end(); ++itEstudiante) {
                            if ((*itEstudiante)->getCedula() == cedula) {
                                estudiantesAIngresar->insert(*itEstudiante);
                                found = true;
                            }
                        }
                        if(!found) throw UsuarioNotFound();
                        cout << "Desea asignar otro estudiante? (1 = SI/ 2 = NO)" << endl;
                        respuesta = MenuUtils::leerInt();
                        if (respuesta == 2) {
                            seguirAgregandoEstudiantes = 0;
                        }else if(respuesta !=1){
                            throw InvalidOption();
                        }
                    }
                }else{
                    throw NoExistenInscriptos();
                }
                
            }

            if(it->second == tipoMonitoreo){
                tipo = "Monitoreo";
            }else if(it->second == tipoTeorico){
                tipo = "Teorico";
            }else{
                tipo = "Practico";
            }
        }
        
        cout << "Datos ingresados. " << endl;
        cout << "     Nombre: " << nombre << std::endl;
        cout << "     Tipo: " << tipo << std::endl;
        cout << "     ID (autogenerado): " << Clase::getCurrentId() + 1 << endl;
        cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
        respuesta = MenuUtils::leerInt();
        DtFecha *fecha = uc->obtenerFechaSistema();
        if (respuesta == 1) {
            try {
                acc->confirmarClase(uc->getUsuarioLoggeado()->getEmail(), codigo, nombre, fecha, estudiantesAIngresar);
                cout << "Se agrego correctamente la clase" << endl;
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
    }
}

void finalizacionDeClase(){
    if (listarClasesEnVivo(uc->getUsuarioLoggeado()->getEmail())){
        cout << "Seleccione id de clase a finalizar: " << endl;
        int id;
        id = MenuUtils::leerInt();
        cout << "Desea confirmar finalizacion de clase? (1 = SI/ 2 = NO)" << endl;
        int respuesta;
        respuesta = MenuUtils::leerInt();
        if (respuesta == 1) {
            try{
                acc->finalizarClase(id, uc->getUsuarioLoggeado()->getEmail());
                cout << "Clase finalizada correctamente." << endl;
            }
            catch (const exception &e) {
                cout << e.what()<<endl;
            }
        }
    }
}

void tiempoDeAsistenciaAClase(){ 
    set<DtReporteTiempoAsistencia*>* reportes = NULL;
    if(listarAsignaturas(uc->getUsuarioLoggeado()->getEmail())) {
        cout << "Ingrese codigo asignatura: " << endl;
        string codigo = MenuUtils::leerString();
        try {
            reportes = acc->obtenerTiempoAsistenciaClase(uc->getUsuarioLoggeado()->getEmail(), codigo);
            cout << "Tiempo promedio de asistencias de los estudiantes:" << endl;
            for (set<DtReporteTiempoAsistencia *>::iterator it = reportes->begin(); it != reportes->end(); ++it) {
                cout << (*it)->toString() << endl;
                cout << "______________________________________________"<<endl;
            }
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
    }
}

void inscripcionAAsignaturas(){
    DtEstudiante* dtEstudiante = dynamic_cast<DtEstudiante*> (uc->getUsuarioLoggeado());
    string codigo;
    int respuesta = 1;
    int seguirInscribiendose = 1;
    while (seguirInscribiendose == 1) {
        if (listarAsignaturasNoInscripto(dtEstudiante->getCedula())) {
            cout << "Ingrese el codigo de la asignatura: " << endl;
            codigo = MenuUtils::leerString();
            cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
            respuesta = MenuUtils::leerInt();
            if (respuesta == 1) {
                acc->inscribirseAsignatura(codigo, dtEstudiante);
                cout << "Desea inscribirse a otra asignatura? (1 = SI/ 2 = NO)" << endl;
                seguirInscribiendose = MenuUtils::leerInt();
            } else if (respuesta == 2) {
                cout << "Desea inscribirse a otra asignatura? (1 = SI/ 2 = NO)" << endl;
                seguirInscribiendose = MenuUtils::leerInt();
            } else {
                throw InvalidOption();
            }
        } else {
            seguirInscribiendose = 0;
        }
    }
}

void asistenciaAClaseEnVivo(){
    DtEstudiante* dtEstudiante = dynamic_cast<DtEstudiante*>(uc->getUsuarioLoggeado());
    if (listarAsignaturas(dtEstudiante->getCedula())) {
        cout << "Ingrese codigo asignatura: " << endl;
        string codigo = MenuUtils::leerString();
        if (listarClasesEnVivoPorAsignatura(codigo)) {
            cout << "Ingrese id de clase: " << endl;
            int id;
            id = MenuUtils::leerInt();
            cout << "Datos ingresados" << endl;
            cout << "     Codigo asignatura: " << codigo << std::endl;
            cout << "     Id clase: " << id << std::endl;
            cout << "Desea confirmar? (1 = SI/ 2 = NO)" << endl;
            int respuesta;
            respuesta = MenuUtils::leerInt();
            if (respuesta == 1) {
                try {
                    acc->registrarAsistencia(id, codigo, dtEstudiante);
                    cout << "Se confirmo asistencia correctamente" << endl;
                } catch (const exception &e) {
                    cout << e.what() << endl;
                }
            }
        }
    }
}

void finalizacionDeAsistenciaAClaseEnVivo() {
    DtEstudiante* dtEstudiante = dynamic_cast<DtEstudiante*>(uc->getUsuarioLoggeado());
    if (listarClasesEnVivo(dtEstudiante->getCedula())){
        cout << "Ingrese id de clase: " << endl;
        int id;
        id = MenuUtils::leerInt();
        cout << "Desea confirmar finalizacion de asistencia en vivo? (1 = SI/ 2 = NO)" << endl;
        int respuesta;
        respuesta = MenuUtils::leerInt();
        if (respuesta == 1) {
            try {
                acc->confirmarFinalizacionAsistenciaVivo(id, dtEstudiante);
                cout << "Se finalizo correctamente la clase" << endl;
            } catch (const exception &e) {
                cout << e.what()<<endl;
            }
        }
    }
}

/* * * * * * *
 * LISTADOS  *
 * * * * * * */

bool listarClasesEnVivo(string &email) {

    set<DtClase*>* dtClases = acc->listarClasesVivo(email);
    if (!dtClases->empty()) {
        cout << "Sus clases en vivo son: " << endl;
        for (set<DtClase *>::iterator it = dtClases->begin(); it != dtClases->end(); ++it)
            cout << ((*it)->getNombre()) << "  - " << ((*it)->getCodigo()) << endl;
    }else {
        cout << "No hay clases en vivo para mostrar." << endl;
    }
    return (!dtClases->empty());
}

bool listarClasesEnVivo(int cedula) {
    
    set<DtClase*>* dtClases = acc->listarClasesVivo(cedula);
    if (!dtClases->empty()) {
        cout << "Las clases en vivo son: " << endl;
        for (set<DtClase*>::iterator it = dtClases->begin(); it != dtClases->end(); ++it)
            cout <<((*it)->getNombre()) << "  - " << ((*it)->getCodigo()) << endl;
    }else {
        cout << "No hay clases en vivo para mostrar." << endl;
    }
    return (!dtClases->empty());
}

bool listarClasesEnVivoPorAsignatura(string codigo) {

    set<DtClase*>* dtClases = acc->listarClasesEnVivoPorAsignatura(codigo);
    if (!dtClases->empty()) {
        cout << "Las clases en vivo son: " << endl;
        for (set<DtClase *>::iterator it = dtClases->begin(); it != dtClases->end(); ++it)
            cout << ((*it)->getNombre()) << "  - " << ((*it)->getCodigo()) << endl;
    }else {
        cout << "No hay clases en vivo para mostrar." << endl;
    }

    return !dtClases->empty();
}

set<DtEstudiante*>* listarEstudiantes(string &codigo){
    
    set<DtEstudiante*>* dtEstudiantes = acc->listarEstudiantes(codigo);
    if(!dtEstudiantes->empty()){
        cout << "Los estudiantes habilitados a la asignatura son: " << endl;
    for (set<DtEstudiante*>::iterator it = dtEstudiantes->begin(); it != dtEstudiantes->end(); ++it) {
        cout << "Nombre:" << (*it)->getNombre() << "  - ci: " << (*it)->getCedula() << endl;
    }
    }
    return dtEstudiantes;
}



bool listarDocentesNoAsignados(string &codigo) {
    
    set<DtDocente*>* dtDocentes = acc->listarDocentesNoAsignados(codigo);

    if (!dtDocentes->empty()){
        cout << "Los docentes son: " << endl;
        for (set<DtDocente*>::iterator it = dtDocentes->begin(); it != dtDocentes->end(); ++it) {
            cout << "  - " << ((*it)->getEmail()) << endl;
        }
    }else{
        cout << "No hay docentes no asignados a la asignatura." << endl;
    }
    return !dtDocentes->empty();
}

bool listarAsignaturas() { //Muestra todas las asignaturas del sistema
    
    set<DtAsignatura*>* dtAsignaturas = acc->listarAsignaturas();
    if (!dtAsignaturas->empty()) {
        cout << "Las asignaturas son: " << endl;
        for (set<DtAsignatura *>::iterator it = dtAsignaturas->begin(); it != dtAsignaturas->end(); ++it)
            cout << "  - " << ((*it)->getCodigo()) << endl;
    } else {
        cout << "No hay asignaturas para mostrar." << endl;
    }
    return (!dtAsignaturas->empty());
}

bool listarAsignaturas(string &email) { //Muestra las asignaturas del docente
    
    set<DtAsignatura*>* dtAsignaturas = acc->listarAsignaturas(email);
    if (!dtAsignaturas->empty()) {
        cout << "Sus asignaturas son: " << endl;
        for (set<DtAsignatura*>::iterator it = dtAsignaturas->begin(); it != dtAsignaturas->end(); ++it)
            cout << "  - " << ((*it)->getCodigo()) << endl;
    } else {
        cout << "No hay asignaturas para mostrar." << endl;
    }
    return (!dtAsignaturas->empty());
}

bool listarAsignaturas(int cedula) { //Muestra las asignaturas del estudiante

    set<DtAsignatura*>* dtAsignaturas = acc->listarAsignaturas(cedula);
    if (!dtAsignaturas->empty()) {
        cout << "Sus asignaturas son: " << endl;
        for (set<DtAsignatura *>::iterator it = dtAsignaturas->begin(); it != dtAsignaturas->end(); ++it)
            cout << "  - " << ((*it)->getCodigo()) << endl;
    } else {
        cout << "No hay asignaturas para mostrar." << endl;
    }
    return (!dtAsignaturas->empty());
}

bool listarAsignaturasNoInscripto(int cedula) { //Muestra las asignaturas del estudiante
    
    set<DtAsignatura*>* dtAsignaturas = acc->listarAsignaturasNoInscripto(cedula);
    if (!dtAsignaturas->empty()) {
        cout << "Las asignaturas habilitadas para usted son: " << endl;
        for (set<DtAsignatura *>::iterator it = dtAsignaturas->begin(); it != dtAsignaturas->end(); ++it)
            cout << "  - " << ((*it)->getCodigo()) << endl;
    } else {
        cout << "No hay asignaturas para mostrar." << endl;
    }
    return (!dtAsignaturas->empty());

}

bool listarMensajes(int id){
    
    set<DtMensaje*>* dtMensajes = acc->listarMensajes(id);
    if(!dtMensajes->empty()){
        cout << "Los mensajes son: " << endl;
        for (set<DtMensaje*>::iterator it = dtMensajes->begin(); it != dtMensajes->end(); ++it){
            cout << " - ID: " << ((*it)->getId()) << "          - Autor: " << ((*it)->getAutor())<< endl;
            if ((*it)->getRespondeA() != 0 ) cout << " - Responde a: " << ((*it)->getRespondeA())<< endl;
            cout << " - Contenido: " << ((*it)->getContenido())<< endl;
            cout << " - Fecha: " <<(*it)->getFechaEnvio()->getDia()<<"/"<<(*it)->getFechaEnvio()->getMes()<<"/"
                                <<(*it)->getFechaEnvio()->getAnio()<<" "<<(*it)->getFechaEnvio()->toString()<<endl;
            cout << "__________________________________________________ " << endl;
        }
    }

    return !dtMensajes->empty();
};

bool listarNotificaciones(string &email) {
    
    set<DtNotificacion*>* dtNotificaciones = uc->consultarNotificaciones(email);

    if(!dtNotificaciones->empty()){
        cout << "Las notificaciones son: " << endl;
        for (set<DtNotificacion*>::iterator it = dtNotificaciones->begin(); it != dtNotificaciones->end(); ++it){
            cout << " - Clase codigo: " << ((*it)->getCodigoClase()) << " - Autor: " << ((*it)->getAutor())<< endl;
            cout << " - Contenido: " << ((*it)->getContenidoMensaje())<< endl;
            cout << " - Fecha: " <<(*it)->getHoraMensaje()->getDia()<<"/"<<(*it)->getHoraMensaje()->getMes()<<"/"
                 <<(*it)->getHoraMensaje()->getAnio()<<" "<<(*it)->getHoraMensaje()->toString()<<endl;
            cout << "__________________________________________________ " << endl;
        }
    }else{
        cout << "No hay Notificaciones para mostrar." << endl;
    }
    
    return !dtNotificaciones->empty();
};