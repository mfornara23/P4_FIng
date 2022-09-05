#ifndef ASIGNATURADUPLICATED_H
#define	ASIGNATURADUPLICATED_H

#include<exception>
#include<iostream>

using namespace std;

class AsignaturaDuplicated : public exception{
public:
    AsignaturaDuplicated();
    virtual const char* what() const throw();
};


#endif	/* ASIGNATURADUPLICATED_H */