#ifndef VENDEDOR_CPP
#define VENDEDOR_CPP

#include "declaraciones/vendedor.h"

Vendedor::Vendedor(std::string nick,std::string pass, DTFecha fecha, std::string RUT):Usuario(nick,pass,fecha){
    this->RUT = RUT;
}

#endif