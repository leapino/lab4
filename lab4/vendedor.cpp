#ifndef VENDEDOR_CPP
#define VENDEDOR_CPP

#include "declaraciones/vendedor.h"

Vendedor::Vendedor(std::string nick,std::string pass, DTFecha fecha, std::string RUT):Usuario(nick,pass,fecha){
    this->RUT = RUT;
}

std::string Vendedor::getRUT(){
     return this->RUT;
}

std::map<int, Producto*> Vendedor::getProductos(){
    return this->Productos;
}

std::list<Cliente *> Vendedor::getClientes(){
    return this->Clientes;
}
#endif