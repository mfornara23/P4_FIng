#ifndef LABORATORIO05_WRONGPASSWORD_H
#define LABORATORIO05_WRONGPASSWORD_H

#include<exception>
#include<iostream>

using namespace std;

class WrongPassword : public exception{
public:
    WrongPassword();
    virtual const char* what() const throw();
};

#endif