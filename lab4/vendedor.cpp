#ifndef VENDEDOR_CPP
#define VENDEDOR_CPP

#include "declaraciones/vendedor.h"
#include "vendedor.h"

    Vendedor::Vendedor()
    {
    }

Vendedor::Vendedor(std::string nick,std::string pass, DTFecha fecha, std::string RUT):Usuario(nick,pass,fecha){
    this->RUT = RUT;
}

Vendedor::~Vendedor()
{
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

std::map<std::string, Promocion *> Vendedor::getPromociones()
{
    return this->promociones;
}

void Vendedor::setPromociones(std::map<std::string, Promocion *> promos)
{
    this->promociones=promos;
}

void Vendedor::setRUT(std::string rut)
{
    this->RUT=rut;
}

void Vendedor::setProductos(std::map<int, Producto *> prods)
{   
    this->Productos=prods;
}

void Vendedor::setClientes(std::list<Cliente *> client)
{
    this->Clientes=client;
}

void Vendedor::crearLinkC(Cliente *cliente)
{
    this->Clientes.push_front(cliente);
}

void Vendedor::addPromo(Promocion* promo){
    this->promociones.insert({promo->getNombre(),promo});
}

#endif