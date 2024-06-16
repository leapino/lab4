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

void ManejadorProducto::agregarProducto(Producto* p){
    this->Productos.insert({p->getCodigo(),p});
}

Producto* ManejadorProducto::getProducto(int c){
    std::map<int, Producto*>::iterator it;
    it = this->Productos.find(c);
    return it->second;
}

std::set<DT2Producto*> ManejadorProducto::listarProductos(std::map<int, Producto*> lista){
    std::map<int, Producto*>::iterator it;
    std::set<DT2Producto*> dataProductos;
    for (it = lista.begin(); it != lista.end(); it++){
        DT2Producto* dProducto = new DT2Producto(it->second->getCodigo(), it->second->getNombre());
        dataProductos.insert(dProducto);
    }
    return dataProductos;
}

#endif