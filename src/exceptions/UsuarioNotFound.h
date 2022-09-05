#ifndef USUARIONOTFOUND_H
#define	USUARIONOTFOUND_H

#include<exception>
#include<iostream>

using namespace std;

class UsuarioNotFound : public exception{
public:
    UsuarioNotFound();
    virtual const char* what() const throw();
};


#endif	/* USUARIONOTFOUND_H */