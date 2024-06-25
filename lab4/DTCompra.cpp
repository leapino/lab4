#ifndef DTCOMPRA_CPP
#define DTCOMPRA_CPP
#include "declaraciones/DTCompra.h"

DTCompra::DTCompra(){}

DTCompra::DTCompra(DTFecha fecha, double monto, std::list<DTCompraProducto> prods,int id){
    this->fecha=fecha;
    this->monto=monto;
    this->Prods=prods;
    this->IDcompra=id;
}


DTFecha DTCompra::getFecha() {
    return this->fecha;
}

double DTCompra::getMonto() {
    return this->monto;
}

int DTCompra::getCantidad() {
    return this->Prods.size();  // Devuelve la cantidad de productos en la lista Prods
}

// Setters
void DTCompra::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void DTCompra::setMonto(double monto) {
    this->monto = monto;
}

void DTCompra::setProds(std::list<DTCompraProducto>prods){
    this->Prods=prods;
}

std::ostream& operator<<(std::ostream& salida, const DTCompra& compra) {
    salida <<"\nIdCompra: " <<compra.IDcompra;
    salida << "\nFecha de compra: " << compra.fecha ; 
    salida << "\nMonto: $" << compra.monto<<"\n" ;
    salida << "Productos:" << "\n";
    for (const auto& prod : compra.Prods) {
        salida << "- " << prod << "\n";
    }
    return salida;
}

void DTCompra::agregarProds(DTCompraProducto prod){
    this->Prods.push_back(prod);
}

DTCompra::~DTCompra(){
    this->Prods.clear();
}
#endif

