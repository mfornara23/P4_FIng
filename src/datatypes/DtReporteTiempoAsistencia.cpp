#include "DtReporteTiempoAsistencia.h"

DtReporteTiempoAsistencia::DtReporteTiempoAsistencia(DtClase* dtClase, int tiempoAsistenciaEnSegundos){
    this->dtClase = dtClase;
    this->tiempoAsistenciaEnSegundos = tiempoAsistenciaEnSegundos;
}

DtReporteTiempoAsistencia::~DtReporteTiempoAsistencia() {

}

DtClase* DtReporteTiempoAsistencia::getDtClase()  {
    return dtClase;
}

void DtReporteTiempoAsistencia::setDtClase(DtClase* dtClase) {
    this->dtClase = dtClase;
}

int DtReporteTiempoAsistencia::getTiempoAsistencia()  {
    return tiempoAsistenciaEnSegundos;
}

void DtReporteTiempoAsistencia::setTiempoAsistencia(int tiempoAsistenciaEnSegundos){
    this->tiempoAsistenciaEnSegundos = tiempoAsistenciaEnSegundos;
}

string DtReporteTiempoAsistencia::toString() {
    string horas = to_string(static_cast<int>(this->tiempoAsistenciaEnSegundos / 3600));
    if (static_cast<int>(this->tiempoAsistenciaEnSegundos / 3600) < 10) horas = "0"+ horas;
    string minutos = to_string(static_cast<int>((this->tiempoAsistenciaEnSegundos % 3600) / 60));
    if (static_cast<int>((this->tiempoAsistenciaEnSegundos % 3600) / 60) < 10) minutos = "0" + minutos;
    return
            "    - Clase: " + this->dtClase->getNombre() +  " - " + "\n" +
            "    - Tiempo asistencia: " + horas + ":" + minutos + "\n";
}