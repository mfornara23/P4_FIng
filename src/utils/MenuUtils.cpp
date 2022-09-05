#include "MenuUtils.h"

#include <cstdlib>
#include <exception>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int MenuUtils::leerInt(){
	int num;
	string str = "";
	while(true){
		getline(cin, str, '\n');
		stringstream entrada(str);
		if (entrada >> num){
			break;
		}
		cout << "Debe ingresar numeros enteros." << endl;
	}
	return num;
}

string MenuUtils::leerString() {
    string str = "";
//    cin.ignore();
    getline(cin, str);
    return str;
}

void MenuUtils::limpiarConsola() {
	system("clear");
}


DtFecha* MenuUtils::leerFecha(){
	DtFecha* res;
	string vacio = "";
    string dd, mm, aaaa, hh, min;
    bool error = true;
    const char elCero = 0;
    while (error){
        cout << "Ingrese Dia: ";
        dd = MenuUtils::leerString();
        if(dd.at(0)==elCero) dd=dd.replace(0,1,vacio);
        cout << "Ingrese Mes: ";
        mm = MenuUtils::leerString();
        if(mm.at(0)==elCero) mm=mm.replace(0,1,vacio);
        cout << "Ingrese año: ";
        aaaa = MenuUtils::leerString();
        cout << "Ingrese hora: ";
        hh = MenuUtils::leerString();
        if(hh.at(0)==elCero) hh=hh.replace(0,1,vacio);
        cout << "Ingrese minuto: ";
        min = MenuUtils::leerString();
        if(min.at(0)==elCero) min=min.replace(0,1,vacio);
        try{
            res = new DtFecha(stoi(dd),stoi(mm),stoi(aaaa),stoi(hh),stoi(min));
            error = false;
        }catch(exception& e){
            error = true;
            cout << "Error: Fecha ingresada es invalida. " << endl;
        }
    }
    return res;
}


void MenuUtils::esperarInput() {
	cout << "Presione enter para continuar..." << endl;
	string dummy;
	getline(cin,dummy);
}

bool MenuUtils::leerOpcion(const string& msg) {
	bool res = false;
	bool error = false;
	while(true){
		if(error) cout << "[Intente nuevamente] ";
		cout <<  msg << "(S/N):";
		string response = leerString();
		if(response=="S" || response=="s"){
			res = true;
			break;
		}else if(response=="N" || response == "n"){
			res = false;
			break;
		}else{
			error = true;
		}
	}
	return res;
}
