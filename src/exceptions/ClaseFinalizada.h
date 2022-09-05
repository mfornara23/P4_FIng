#ifndef CLASEFINALIZADA_H
#define CLASEFINALIZADA_H

#include<exception>
#include<iostream>

using namespace std;

class ClaseFinalizada : public exception {
public:
    ClaseFinalizada();
    virtual const char* what() const throw();
};


#endif
