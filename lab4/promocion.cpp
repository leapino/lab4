#ifndef PROMOCION_CPP
#define PROMOCION_CPP

#include "declaraciones/promocion.h"

// Promocion::Promocion(){
//    this->nombre = "";
//    this->descripcion = "";
//  //  this->fecha = ???;
// }

Promocion::Promocion(std::string nombre,std::string desc,DTFecha fecha){
   this->nombre = nombre;
   this->descripcion = desc;
   this->fecha = fecha;
}

std::string Promocion::getNombre(){
   return this->nombre;
}

std::string Promocion::getDescripcion(){
   return this->descripcion;
}

DTFecha Promocion::getFecha(){
   return this->fecha;
}

void Promocion::setNombre(std::string nombre){
   this->nombre = nombre;
}

void Promocion::setDescripcion(std::string desc){
   this->descripcion = desc;
}

void Promocion::setFecha(DTFecha fecha){
   this->fecha = fecha;
}

void Promocion::agregarProdProm(ProductoPromocion* pp){
   this->prodProm.insert(pp);
}



#endif