#ifndef CLASENOTAVAILABLE_H
#define CLASENOTAVAILABLE_H

#include<exception>
#include<iostream>

using namespace std;

class ClaseNotAvailable : public exception {
public:
    ClaseNotAvailable();
    virtual const char* what() const throw();
};


#endif
