#ifndef DTCOMPRAPRODUCTO_CPP
#define DTCOMPRAPRODUCTO_CPP

#include <iostream>

#include "declaraciones/DTCompraProducto.h"


std::ostream &operator<<(std::ostream &salida, const DTCompraProducto &prod){
    salida << "\nProducto:\n" <<prod.prod<<"\nEnviado: " << prod.enviado<< "\nCantidad: " << prod.cantidad;
    return salida;
}

DTCompraProducto::DTCompraProducto(){
}

DTCompraProducto::DTCompraProducto(bool enviado, int cantidad, DTProducto prod) {
    this->enviado=enviado;
    this->cantidad=cantidad;
    this->prod=prod;
}

// Getters
bool DTCompraProducto::getEnviado() {
    return this->enviado;
}

int DTCompraProducto::getCantidad() {
    return this->cantidad;
}

DTProducto DTCompraProducto::getProd() {
    return this->prod;
}

// Setters
void DTCompraProducto::setEnviado(bool enviado) {
    this->enviado = enviado;
}

void DTCompraProducto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void DTCompraProducto::setProd(DTProducto prod) {
    this->prod = prod;
}

DTCompraProducto::~DTCompraProducto(){
    
}

#endif