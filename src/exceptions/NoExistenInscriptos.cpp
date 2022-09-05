#include "NoExistenInscriptos.h"

NoExistenInscriptos::NoExistenInscriptos(){
}

const char* NoExistenInscriptos::what()const throw(){
    return "No existen Estudiantes inscriptos a la Asignatura.";
}
