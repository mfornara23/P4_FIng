#ifndef ASIGNATURANOTFOUND_H
#define	ASIGNATURANOTFOUND_H

#include<exception>
#include<iostream>

using namespace std;

class AsignaturaNotFound : public exception{
public:
    AsignaturaNotFound();
    virtual const char* what() const throw();
};


#endif	/* ASIGNATURANOTFOUND_H */