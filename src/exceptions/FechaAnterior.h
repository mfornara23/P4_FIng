#ifndef FECHAANTERIOR_H
#define FECHAANTERIOR_H


#include<exception>
#include<iostream>
#include<string>

using namespace std;

class FechaAnterior : public exception{
private:
    string message;
public:
    FechaAnterior(string mensaje);
    virtual const char* what() const throw();
};


#endif
