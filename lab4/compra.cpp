#ifndef COMPRA_CPP
#define COMPRA_CPP

#include "declaraciones/compra.h"

Compra::Compra() {
    this->fecha=DTFecha();
    this->monto = 0;
    this->cliente = NULL;
}

Compra::Compra(DTFecha fecha, double monto, Cliente *cliente,std::list<CompraProducto *> compraPr) {
    this->fecha = fecha;
    this->monto = monto;
    this->cliente = cliente;
    this->compraProductos=compraPr;
    this->IdCompra=cliente->getCompras().size();
}


 DTFecha Compra::getFecha() {
    return this->fecha;
 }


double Compra::getMonto() {
    return this->monto;
}


Cliente *Compra::getCliente() {
    return this->cliente;
}


std::list<CompraProducto *> Compra::getcompraProductos() {
    return this->compraProductos;
}

int Compra::getIdCompra()
{
    return this->IdCompra;
}
void Compra::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}


void Compra::setMonto(double mont) {
    this->monto = mont;
}


void Compra::setCliente(Cliente *client) {
    this->cliente = client;
}


void Compra::subirMonto(double precio) {
    this->monto += precio;
}

void Compra::setIdcompra(int idC)
{
    this->IdCompra = idC;
}

DTCompra Compra::getData()
{
    std::list<DTCompraProducto> compraprods;
    for(std::list<CompraProducto*>::iterator it=this->compraProductos.begin();it!=this->compraProductos.end();it++){
        DTCompraProducto prods=(*it)->getData();
        compraprods.push_front(prods);
    }
    return DTCompra(this->fecha,this->monto,compraprods,this->IdCompra);
}
void Compra::agregarProdCompra(CompraProducto *comPro) {
    this->compraProductos.push_front(comPro);
}

Compra::~Compra() {
    //delete this->cliente;
    for(CompraProducto *ptr : compraProductos) {
        delete ptr;
    }
}

#endif