#ifndef COMPRA_CPP
#define COMPRA_CPP

#include "declaraciones/compra.h"

Compra::Compra() {
    this->fecha = NULL;
    this->monto = 0;
    this->cliente = NULL;
}

Compra::Compra(DTFecha *fecha, int monto, Cliente *cliente, CompraProducto * compraPr) {
    this->fecha = fecha;
    this->monto = monto;
    this->cliente = cliente;
    this->compraProductos.push_front(compraPr);
}


 DTFecha *Compra::getFecha() {
    return this->fecha;
 }


int Compra::getMonto() {
    return this->monto;
}


Cliente *Compra::getCliente() {
    return this->cliente;
}


std::list<CompraProducto *> Compra::getcompraProductos() {

}


void Compra::setFecha(DTFecha *fecha) {
    this->fecha = fecha;
}


void Compra::setMonto(int mont) {
    this->monto = mont;
}


void Compra::setCliente(Cliente *client) {
    this->cliente = client;
}


void Compra::subirMonto(int precio) {
    this->monto += precio;
}

void Compra::agregarProdCompra(CompraProducto *comPro) {
    this->compraProductos.push_front(comPro);
}

Compra::~Compra() {
    delete this->fecha;
    delete this->cliente;
    for(CompraProducto *ptr : compraProductos) {
        delete ptr;
    }
}

#endif