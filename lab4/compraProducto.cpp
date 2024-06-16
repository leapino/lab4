#ifndef COMPRAPRODUCTO_CPP
#define COMPRAPRODUCTO_CPP

#include "declaraciones/compraProducto.h"

CompraProducto::CompraProducto() {
    this->enviado = false;
    this->cantidad = 0;
    this->prod = NULL;
}

CompraProducto::CompraProducto(Producto *prod, int cantidad) {
    this->enviado = false;
    this->cantidad = cantidad;
    this->prod = prod;
}

void CompraProducto::enviar() {
    this->enviado = true;
}

bool CompraProducto::fueEnviado() {
    return this->enviado;
}

CompraProducto::~CompraProducto() {
    delete this->prod;
}


#endif