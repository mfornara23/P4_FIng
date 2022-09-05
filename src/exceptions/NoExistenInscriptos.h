#ifndef NOINSCRIPTOS_H
#define	NOINSCRIPTOS_H

#include<exception>
#include<iostream>

using namespace std;

class NoExistenInscriptos : public exception{
public:
    NoExistenInscriptos();
    virtual const char* what() const throw();
};


#endif	/* NOINSCRIPTOS_H */