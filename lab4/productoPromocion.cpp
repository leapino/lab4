#ifndef PRODUCTOPROMOCION_CPP
#define PRODUCTOPROMOCION_CPP

#include "declaraciones/productoPromocion.h"
#include "productoPromocion.h"

ProductoPromocion::ProductoPromocion(){
      this->descuento = 0;
      this->cantMin = 0;
}

ProductoPromocion::ProductoPromocion(int desc,int cantMin){
      this->descuento = desc;
      this->cantMin = cantMin;
}

int ProductoPromocion::getDescuento(){
      return this->descuento;
}

int ProductoPromocion::getCantMin(){
      return this->cantMin;
}

Producto *ProductoPromocion::getProducto(){
    return this->producto;
}
void ProductoPromocion::setDescuento(int desc){
       this->descuento = desc;
}

void ProductoPromocion::setCantMin(int cantMin){
       this->descuento = cantMin;
}

void ProductoPromocion::setProducto(Producto *p){
      this->producto=p;
}

ProductoPromocion::~ProductoPromocion(){
      this->producto=nullptr;
}

#endif