#ifndef ASITENCIANDUPLICATED_H
#define	ASITENCIANDUPLICATED_H

#include<exception>
#include<iostream>

using namespace std;

class AsistenciaDuplicated : public exception{
public:
    AsistenciaDuplicated();
    virtual const char* what() const throw();
};


#endif	/* ASITENCIANDUPLICATED_H */