
#ifndef DTPROMOCION_CPP
#define DTPROMOCION_CPP

#include <iostream>

#include "../declaraciones/DTPromocion.h"

std::ostream &operator<<(std::ostream &salida, DTPromocion *prom){
    salida << "\nNombre: " << prom->getNombre() << "\n Descripción: " << prom->getDesc()<<"\n Fecha Vencimiento:"<<&prom->getFecha()<< "\n";
    return salida;
}

DTPromocion::DTPromocion(){
}

DTPromocion::DTPromocion(std::string nombre, std::string desc, DTFecha fecha){
    this->nombre=nombre;
    this->descripcion=desc;
    this->fecha=fecha;
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
DTPromocion::~DTPromocion(){
}
#endif