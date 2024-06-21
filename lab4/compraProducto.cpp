#ifndef COMPRAPRODUCTO_CPP
#define COMPRAPRODUCTO_CPP

#include "declaraciones/compraProducto.h"

CompraProducto::CompraProducto() {
    this->enviado = false;
    this->cantidad = 0;
    this->producto = NULL;
}

CompraProducto::CompraProducto(Producto *prod, int cantidad) {
    this->enviado = false;
    this->cantidad = cantidad;
    this->producto = prod;
}


int CompraProducto::getCantidad() {
    return this->cantidad;
}


Producto *CompraProducto::getProd() {
    return this->producto;
}


bool CompraProducto::getEnviado() {
    return this->enviado;
}

void CompraProducto::setEnviado(bool b) {
    this->enviado = b;
}


void CompraProducto::setCantidad(int cant) {
    this->cantidad = cant;
}


void CompraProducto::setProd(Producto *prod) {
    this->producto = prod;
}



CompraProducto::~CompraProducto() {
    //delete this->producto;
}


#endif