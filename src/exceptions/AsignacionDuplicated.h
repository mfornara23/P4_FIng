#ifndef ASIGNACIONDUPLICATED_H
#define	ASIGNACIONDUPLICATED_H

#include<exception>
#include<iostream>

using namespace std;

class AsignacionDuplicated : public exception{
public:
    AsignacionDuplicated();
    virtual const char* what() const throw();
};


#endif	/* ASIGNACIONDUPLICATED_H */