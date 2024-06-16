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