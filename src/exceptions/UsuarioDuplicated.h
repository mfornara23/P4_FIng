#ifndef USUARIODUPLICATED_H
#define	USUARIODUPLICATED_H

#include<exception>
#include<iostream>

using namespace std;

class UsuarioDuplicated : public exception{
public:
    UsuarioDuplicated();
    virtual const char* what() const throw();
};


#endif	/* USUARIODUPLICATED_H */