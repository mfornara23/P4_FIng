#ifndef LABORATORIO05_MENSAJENOTFOUND_H
#define LABORATORIO05_MENSAJENOTFOUND_H

#include<exception>
#include<iostream>

using namespace std;

class MensajeNotFound : public exception{
public:
    MensajeNotFound();
    virtual const char* what() const throw();
};


#endif //LABORATORIO05_MENSAJENOTFOUND_H
