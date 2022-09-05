#ifndef FINALIZARNOTALLOWED_H
#define FINALIZARNOTALLOWED_H

#include<exception>
#include<iostream>

using namespace std;

class FinalizarNotAllowed : public exception {
public:
    FinalizarNotAllowed();
    virtual const char* what() const throw();
};


#endif
