#ifndef LAB5_DTFECHA_H
#define LAB5_DTFECHA_H

#include <iostream>
#include <string>

using namespace std;

class DtFecha
{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
public:
    DtFecha();
    DtFecha(int dia, int mes, int anio, int hora, int minuto);
    void setAnio(int anio);
    int getAnio() ;
    void setDia(int dia);
    int getDia() ;
    void setHora(int hora);
    int getHora() ;
    void setMes(int mes);
    int getMes() ;
    void setMinuto(int minuto);
    int getMinuto() ;
    ~DtFecha();
    static bool esAnterior(DtFecha* fechaActual, DtFecha* nuevaFecha);
    string toString();
};

#endif //LAB5_DTFECHA_H
