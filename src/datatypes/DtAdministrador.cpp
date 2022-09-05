#include "DtAdministrador.h"

DtAdministrador::DtAdministrador() {}

DtAdministrador::~DtAdministrador() {

}

DtAdministrador::DtAdministrador(string nombre, string email, string password,
                                 string imagen) : DtUsuario(nombre, email, password, imagen) {}
