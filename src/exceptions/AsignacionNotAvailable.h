#ifndef LABORATORIO05_ASIGNACIONNOTAVAILABLE_H
#define LABORATORIO05_ASIGNACIONNOTAVAILABLE_H

#include<exception>
#include<iostream>

using namespace std;

class AsignacionNotAvailable : public exception{
public:
    AsignacionNotAvailable();
    virtual const char* what() const throw();
};

#endif //LABORATORIO05_ASIGNACIONNOTAVAILABLE_H
