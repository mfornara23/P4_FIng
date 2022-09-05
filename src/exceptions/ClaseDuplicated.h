#ifndef CLASEDUPLICATED_H
#define CLASEDUPLICATED_H

#include<exception>
#include<iostream>

using namespace std;

class ClaseDuplicated : public exception {
public:
    ClaseDuplicated();
    virtual const char* what() const throw();
};


#endif
