#ifndef DTCOMPRA_CPP
#define DTCOMPRA_CPP
#include "../declaraciones/DTCompra.h"

DTCompra::DTCompra(){}

DTCompra::DTCompra(DTFecha *fecha, int monto, std::list<DTCompraProducto*> prods){
    this->fecha=fecha;
    this->monto=monto;
    this->Prods=prods;
}


DTFecha* DTCompra::getFecha() {
    return this->fecha;
}

int DTCompra::getMonto() {
    return this->monto;
}

int DTCompra::getCantidad() {
    return this->Prods.size();  // Devuelve la cantidad de productos en la lista Prods
}

// Setters
void DTCompra::setFecha(DTFecha* fecha) {
    this->fecha = fecha;
}

void DTCompra::setMonto(int monto) {
    this->monto = monto;
}

void DTCompra::setProds(std::list<DTCompraProducto*>prods){
    this->Prods=prods;
}
#endif
