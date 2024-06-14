#ifndef MANEJADORPRODUCTO_CPP
#define MANEJADORPRODUCTO_CPP

#include "declaraciones/manejadorProducto.h"

ManejadorProducto* ManejadorProducto::instancia = NULL;

ManejadorProducto* ManejadorProducto::getInstancia(){
    if (instancia == NULL){
        instancia = new ManejadorProducto();
    }
        return instancia;
}

void ManejadorProducto::addProducto(Producto* p){
    this->Productos.insert({p->getCodigo(),p});
}

Producto* ManejadorProducto::getProducto(int c){
    std::map<int, Producto*>::iterator it;
    it = this->Productos.find(c);
    return it->second;
}

#endif