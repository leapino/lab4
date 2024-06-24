#ifndef VENDEDOR_CPP
#define VENDEDOR_CPP

#include "declaraciones/vendedor.h"

Vendedor::Vendedor()
{
}

Vendedor::Vendedor(std::string nick,std::string pass, DTFecha fecha, std::string RUT):Usuario(nick,pass,fecha){
    this->RUT = RUT;
}

Vendedor::~Vendedor(){
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

std::list<DTProducto> Vendedor::getDTProds()
{
    std::list<DTProducto>res;

    for (std::map<int,Producto*>::iterator i = this->Productos.begin();i!=this->Productos.end(); i++)
    {
        DTProducto apushear=i->second->getData();
        res.push_front(apushear);
    }
    
    return res;
}
std::list<DTPromocion> Vendedor::getDTPromocion()
{
    std::list<DTPromocion> res;
    for (std::map<std::string,Promocion*>::iterator i = this->promociones.begin() ; i !=this->promociones.end(); i++)
    {
        DTPromocion apushear=i->second->getData();
        res.push_front(apushear);   
    }
    return res;
    
}
void Vendedor::setPromociones(std::map<std::string, Promocion *> promos)
{
    this->promociones=promos;
}

void Vendedor::setRUT(std::string rut)
{
    this->RUT=rut;
}

void Vendedor::setProductos(int codigo, Producto* prod){   
    this->Productos[codigo]=prod;
}


void Vendedor::setClientes(std::list<Cliente *> client)
{
    this->Clientes=client;
}

void Vendedor::crearLinkC(Cliente *cliente)
{
    this->Clientes.push_front(cliente);
}

void Vendedor::eliminarLinkC(std::string client)
{
    std::list<Cliente*>::iterator Pclient=this->Clientes.begin();
    while ((Pclient!=this->Clientes.end())&&((*Pclient)->getNickname()!=client)){
        Pclient++;
    }
    if((Pclient!=this->Clientes.end())&& ((*Pclient)->getNickname()==client)){
        Pclient=this->Clientes.erase(Pclient);
    }
}

void Vendedor::addPromo(Promocion * promo){
    std::string nomPromo=promo->getNombre();
    this->promociones.insert(std::make_pair(nomPromo,promo));
}

#endif