
#ifndef DTPROMOCION_CPP
#define DTPROMOCION_CPP

#include <iostream>

#include "declaraciones/DTPromocion.h"

std::ostream &operator<<(std::ostream &salida, const DTPromocion&prom){
    salida << "\nNombre: " << prom.nombre << "\nDescripción: " << prom.descripcion<<"\nFecha Vencimiento:"<<prom.fecha<< "\n";
    return salida;
}

DTPromocion::DTPromocion(){
}

DTPromocion::DTPromocion(std::string nombre, std::string desc, DTFecha fecha, int descuento){
    this->nombre=nombre;
    this->descripcion=desc;
    this->fecha=fecha;
    this->descuento = descuento;
}

void DTPromocion::addProducto(DTProducto p){
    this->productos.insert(p);
}

std::set<DTProducto> DTPromocion::getProductos(){
    return this->productos;
}

std::string DTPromocion::getNombre(){
    return this->nombre;
}
std::string DTPromocion::getDesc(){
    return this->descripcion;
}
DTFecha DTPromocion::getFecha(){
    return this->fecha;
}

int DTPromocion::getDescuento(){
    return this->descuento;
}

DTPromocion::~DTPromocion(){
}
#endif