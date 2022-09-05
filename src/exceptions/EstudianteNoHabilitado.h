#ifndef ESTUDIANTENOHABILITADO_H
#define ESTUDIANTENOHABILITADO_H


#include<exception>
#include<iostream>

using namespace std;

class EstudianteNoHabilitado : public exception {
public:
    EstudianteNoHabilitado();
    virtual const char* what() const throw();
};


#endif
