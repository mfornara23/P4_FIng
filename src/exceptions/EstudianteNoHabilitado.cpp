#include "EstudianteNoHabilitado.h"

EstudianteNoHabilitado::EstudianteNoHabilitado(){
}

const char* EstudianteNoHabilitado::what()const throw(){
    return "El estudiante no esta habilitado para asistir al monitoreo.";
}
