#ifndef CLASENOTFOUND_H
#define	CLASENOTFOUND_H

#include<exception>
#include<iostream>

using namespace std;

class ClaseNotFound : public exception{
public:
    ClaseNotFound();
    virtual const char* what() const throw();
};


#endif	/* CLASEONOTFOUND_H */