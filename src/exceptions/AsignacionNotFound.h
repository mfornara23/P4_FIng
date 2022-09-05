#ifndef ASIGNACIONNOTFOUND_H
#define ASIGNACIONNOTFOUND_H


#include<exception>
#include<iostream>

using namespace std;

class AsignacionNotFound : public exception{
public:
    AsignacionNotFound();
    virtual const char* what() const throw();
};


#endif
