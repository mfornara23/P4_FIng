#ifndef MAXHABILITADOSNOTFOUND_H
#define	MAXHABILITADOSNOTFOUND_H

#include<exception>
#include<iostream>

using namespace std;

class MaxHabilitados : public exception{
public:
    MaxHabilitados();
    virtual const char* what() const throw();
};


#endif	/* MAXHABILITADOSNOTFOUND_H */