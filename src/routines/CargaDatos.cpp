#include "CargaDatos.h"

void CargaDatos::cargarDatos() {
    Factory *factory = Factory::getInstance();
    IUsuarioController *uc = factory->getIUsuarioController();
    IAsignaturaClaseController *acc = factory->getIAsignaturaClaseController();
    this->cHandler = ClaseHandler::getInstance();

    //Admin
    DtUsuario *dtUsuarioA1 = new DtAdministrador("Adminis Trador", "admin@admin.com", "admin", "imagen_admin");
    uc->altaUsuario(dtUsuarioA1);

    //Docentes
    DtUsuario *dtUsuarioD1 = new DtDocente("Juan Perez", "juan@mail.com", "123", "imagen_juan", INCO);
    uc->altaUsuario(dtUsuarioD1);

    DtUsuario *dtUsuarioD2 = new DtDocente("Maria Pires", "maria@mail.com", "123", "imagen_maria", INCO);
    uc->altaUsuario(dtUsuarioD2);

    DtUsuario *dtUsuarioD3 = new DtDocente("Jorge Chacho", "jorge@mail.com", "123", "imagen_jorge", INCO);
    uc->altaUsuario(dtUsuarioD3);

    //Estudiantes
    DtUsuario *dtUsuarioE1 = new DtEstudiante("Roberto Parra", "roberto@mail.com", "123", "imagen_roberto", 12345678);
    uc->altaUsuario(dtUsuarioE1);

    DtUsuario *dtUsuarioE2 = new DtEstudiante("Ana Rodriguez", "ana@mail.com", "123", "imagen_ana", 23456789);
    uc->altaUsuario(dtUsuarioE2);

    DtUsuario *dtUsuarioE3 = new DtEstudiante("Ramon Valdez ", "ramon@mail.com", "123", "imagen_ramon", 34567890);
    uc->altaUsuario(dtUsuarioE3);

    //Asignaturas
    DtAsignatura *dtAsignaturaA1 = new DtAsignatura("P1", "Programacion 1", true, true, true);
    acc->altaAsignatura(dtAsignaturaA1);

    DtAsignatura *dtAsignaturaA2 = new DtAsignatura("P2", "Programacion 2", true, true, true);
    acc->altaAsignatura(dtAsignaturaA2);

    DtAsignatura *dtAsignaturaA3 = new DtAsignatura("P3", "Programacion 3", true, true, false);
    acc->altaAsignatura(dtAsignaturaA3);

    //Asignacion de docentes a asignaturas (Docente Asignatura Rol)
    //D1 A1 Teórico:
    DtDocente *dtDocenteD1 = dynamic_cast<DtDocente *>(dtUsuarioD1);
    acc->asignarDocente(dtAsignaturaA1->getCodigo(), dtDocenteD1->getEmail(), tipoTeorico);
    //D2 A1 Práctico:
    DtDocente *dtDocenteD2 = dynamic_cast<DtDocente *>(dtUsuarioD2);
    acc->asignarDocente(dtAsignaturaA1->getCodigo(), dtDocenteD2->getEmail(), tipoPractico);
    //D3 A1 Monitoreo:
    DtDocente *dtDocenteD3 = dynamic_cast<DtDocente *>(dtUsuarioD3);
    acc->asignarDocente(dtAsignaturaA1->getCodigo(), dtDocenteD3->getEmail(), tipoMonitoreo);

    //Inscripicion de estudiantes a asignaturas (Estudiante Asignaturas)
    //E1 A1:
    DtEstudiante *dtEstudianteE1 = dynamic_cast<DtEstudiante *>(dtUsuarioE1);
    acc->inscribirseAsignatura(dtAsignaturaA1->getCodigo(), dtEstudianteE1);
    //E2 A1,A2
    DtEstudiante *dtEstudianteE2 = dynamic_cast<DtEstudiante *>(dtUsuarioE2);
    acc->inscribirseAsignatura(dtAsignaturaA1->getCodigo(), dtEstudianteE2);
    acc->inscribirseAsignatura(dtAsignaturaA2->getCodigo(), dtEstudianteE2);
    //E3 A1
    DtEstudiante *dtEstudianteE3 = dynamic_cast<DtEstudiante *>(dtUsuarioE3);
    acc->inscribirseAsignatura(dtAsignaturaA1->getCodigo(), dtEstudianteE3);
    //Clases (Ref Asignatura Nombre Tipo Inicio Fin Dictada por docente)
    //C1 A1 Intro Teórico 01/05/20 - 9am 01/05/20 - 10am D1:
    string nombreC1 = "Intro";
    int id_c1 = acc->confirmarClase(dtUsuarioD1->getEmail(), dtAsignaturaA1->getCodigo(), nombreC1, new DtFecha(1, 5, 2020, 9, 0), NULL);
    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 10, 0));
    acc->finalizarClase(id_c1, dtUsuarioD1->getEmail());

    //C2 A1 Tema 1 Teórico 03/05/20 - 9am 03/05/20 - 10am D1:
    string nombreC2 = "Tema 1";
    int id_c2 = acc->confirmarClase(dtUsuarioD1->getEmail(), dtAsignaturaA1->getCodigo(),  nombreC2, new DtFecha(3, 5, 2020, 9, 0), NULL);
    uc->modificarFechaSistema(new DtFecha(3, 5, 2020, 10, 0));
    acc->finalizarClase(id_c2, dtUsuarioD1->getEmail());

    //C3 A1 Tema 2 Teórico 08/05/20 - 9am 08/05/20 - 10am D1:
    string nombreC3 = "Tema 2";
    int id_c3 = acc->confirmarClase(dtUsuarioD1->getEmail(), dtAsignaturaA1->getCodigo(), nombreC3, new DtFecha(8, 5, 2020, 9, 0), NULL);
    uc->modificarFechaSistema(new DtFecha(8, 5, 2020, 10, 0));
    acc->finalizarClase(id_c3, dtUsuarioD1->getEmail());

    //C4 A1 Pra 1 Práctico 02/05/20 - 4pm 02/05/20 - 5pm D2:
    string nombreC4 = "Pra 1";
    int id_c4 = acc->confirmarClase(dtUsuarioD2->getEmail(), dtAsignaturaA1->getCodigo(), nombreC4, new DtFecha(2, 5, 2020, 16, 0), NULL);
    uc->modificarFechaSistema(new DtFecha(2, 5, 2020, 17, 0));
    acc->finalizarClase(id_c4, dtUsuarioD2->getEmail());

    //C5 A1 Pra 2 Práctico 03/05/20 - 4pm 03/05/20 - 5pm D2:
    string nombreC5 = "Pra 2";
    int id_c5 = acc->confirmarClase(dtUsuarioD2->getEmail(), dtAsignaturaA1->getCodigo(), nombreC5, new DtFecha(3, 5, 2020, 16, 0), NULL);
    uc->modificarFechaSistema(new DtFecha(3, 5, 2020, 17, 0));
    acc->finalizarClase(id_c5, dtUsuarioD2->getEmail());

    //C6 A1 06/01/20 Monitoreo 04/05/20 - 4pm 04/05/20 - 5pm D3:
    //Estudiantes habilitados
    //E2 C6
    //E3 C6
    set<DtEstudiante*>* dtEstudiantes = new set<DtEstudiante*>();
    dtEstudiantes->insert(dtEstudianteE2);
    dtEstudiantes->insert(dtEstudianteE3);
    string nombreC6 = "06/01/20";
    int id_c6 = acc->confirmarClase(dtUsuarioD3->getEmail(), dtAsignaturaA1->getCodigo(),nombreC6,  new DtFecha(4, 5, 2020, 16, 0), dtEstudiantes);
    uc->modificarFechaSistema(new DtFecha(4, 5, 2020, 17, 0));
    acc->finalizarClase(id_c6, dtUsuarioD3->getEmail());

    //Asistencia a clases (Estudiante Clase Inicio Fin)
    //E1 C1 01/05/20 - 09:01am 01/05/20 - 09:21am:    
    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 9, 1));

    Clase* clase1 = cHandler->getClase(id_c1);
    DtAsignatura* dtAsignaturaClase1 = new DtAsignatura(clase1->getAsignatura()->getCodigo(), clase1->getAsignatura()->getNombre(),
                                    clase1->getAsignatura()->getTieneTeorico(), clase1->getAsignatura()->getTienePractico(), 
                                    clase1->getAsignatura()->getTieneMonitoreo());
    DtClase* dtClase1 = new DtClase(clase1->getCodigo(), clase1->getNombre(), clase1->getInicio(), clase1->getFin(),
                            clase1->getUrlVideo(), clase1->getIniciadaPor(), dtAsignaturaClase1);
    acc->registrarAsistencia(dtClase1->getCodigo(), dtAsignaturaClase1->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE1));

    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 9, 21));
    
    acc->confirmarFinalizacionAsistenciaVivo(dtClase1->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE1));

    //E2 C1 01/05/20 - 09:02am 01/05/20 - 09:32am:
    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 9, 2));
    
    acc->registrarAsistencia(dtClase1->getCodigo(), dtAsignaturaClase1->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE2));
    
    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 9, 32));
    
    acc->confirmarFinalizacionAsistenciaVivo(dtClase1->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE2));

    //E3 C1 01/05/20 - 09:03am 01/05/20 - 09:43am:
    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 9, 3));
    
    acc->registrarAsistencia(dtClase1->getCodigo(), dtAsignaturaClase1->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE3));
    
    uc->modificarFechaSistema(new DtFecha(1, 5, 2020, 9, 43));
    
    acc->confirmarFinalizacionAsistenciaVivo(dtClase1->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE3));

    //E3 C6 04/05/20 – 4:00pm 04/05/20 – 5:00pm:
    uc->modificarFechaSistema(new DtFecha(4, 5, 2020, 16, 0));

    Clase* clase6 = cHandler->getClase(id_c6);
    DtAsignatura* dtAsignaturaClase6 = new DtAsignatura(clase6->getAsignatura()->getCodigo(), clase6->getAsignatura()->getNombre(),
                                                  clase6->getAsignatura()->getTieneTeorico(), clase6->getAsignatura()->getTienePractico(),
                                                  clase6->getAsignatura()->getTieneMonitoreo());
    DtClase* dtClase6 = new DtClase(clase6->getCodigo(), clase6->getNombre(), clase6->getInicio(), clase6->getFin(),
                                    clase6->getUrlVideo(), clase6->getIniciadaPor(), dtAsignaturaClase6);
    acc->registrarAsistencia(dtClase6->getCodigo(), dtAsignaturaClase6->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE3));
    
    uc->modificarFechaSistema(new DtFecha(4, 5, 2020, 17, 0));
    
    acc->confirmarFinalizacionAsistenciaVivo(dtClase6->getCodigo(), dynamic_cast<DtEstudiante *>(dtUsuarioE3));

    //Mensajes (Ref Usuario Clase Fecha - Hora Mensaje Respuesta)
    //M1 D1 C1 01/05/20 - 09:01am Bienvenidos! -
    DtFecha* dtFechaMensaje = new DtFecha(1, 5, 2020, 9, 1);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m1 = "Bienvenidos!";
    int id_m1 = acc->altaMensaje(dtUsuarioD1->getEmail(), id_c1, m1, 0);

    //M2 D1 C1 01/05/20 - 09:02 am Confirmen materiales por favor. -
    dtFechaMensaje = new DtFecha(1, 5, 2020, 9, 2);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m2 = "Confirmen materiales por favor.";
    int id_m2 = acc->altaMensaje(dtUsuarioD1->getEmail(), id_c1, m2 , 0);

    //M3 D3 C6 04/05/20 - 04:01pm Comparto pantalla. -
    dtFechaMensaje = new DtFecha(4, 5, 2020, 4, 1);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m3 = "Comparto pantalla.";
    int id_m3 = acc->altaMensaje(dtUsuarioD3->getEmail(), id_c6, m3, 0);

    //M4 E1 C1 01/05/20 - 09:05am Listo para aprender M1
    dtFechaMensaje = new DtFecha(1, 5, 2020, 9, 5);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m4 = "Listo para aprender";
    int id_m4 = acc->altaMensaje(dtUsuarioE1->getEmail(), id_c1, m4, id_m1);

    //M5 D1 C1 01/05/20 - 09:06am Me alegro M4
    dtFechaMensaje = new DtFecha(1, 5, 2020, 9, 6);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m5 = "Me alegro";
    acc->altaMensaje(dtUsuarioD1->getEmail(), id_c1, m5, id_m4);

    //M6 E2 C1 01/05/20 - 09:06am Todo listo M2
    dtFechaMensaje = new DtFecha(1, 5, 2020, 9, 6);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m6 = "Todo listo";
    acc->altaMensaje(dtUsuarioE2->getEmail(), id_c1, m6, id_m2);

    //M7 E3 C6 04/05/20 - 04:05pm Ya la vemos M3
    dtFechaMensaje = new DtFecha(4, 5, 2020, 4, 5);
    uc->modificarFechaSistema(dtFechaMensaje);
    string m7 = "Ya la vemos";
    acc->altaMensaje(dtUsuarioE3->getEmail(), id_c6,  m7, id_m3);

}