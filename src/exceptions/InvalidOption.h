#ifndef LABORATORIO05_INVALIDOPTION_H
#define LABORATORIO05_INVALIDOPTION_H

#include<exception>
#include<iostream>

using namespace std;

class InvalidOption : public exception{
public:
    InvalidOption();
    virtual const char* what() const throw();
};

#endif //LABORATORIO05_INVALIDOPTION_H
