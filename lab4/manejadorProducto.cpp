#ifndef MANEJADORPRODUCTO_CPP
#define MANEJADORPRODUCTO_CPP

#include "declaraciones/manejadorProducto.h"
#include "manejadorProducto.h"

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

std::set<DTProducto> ManejadorProducto::getProductosDisp(){
    std::set<DTProducto> res;
    for (std::map<int, Producto*>::iterator it = this->Productos.begin(); it!=this->Productos.end(); ++it){
        if(it->second->getStock()!=0){
            res.insert(it->second->getData());
        }
    return res;
    }
}
bool ManejadorProducto::hayStock(int codigo, int cantidad){
    std::map<int,Producto*>::iterator it=this->Productos.find(codigo);
    bool res=it->second->getStock()>=cantidad;
    if (res){
        //recordarProd(codigoP,cantidad);
    }
    return res;
}
void ManejadorProducto::prodEnCompra(){
    /*
    std::map<int,Producto*>::iterator it=this->Productos.find(codigoP);
    it->second->bajarStock(cantidad);
    int Preciocompra=(it->second->getPrecio())*cantidad;*/
}
Producto *ManejadorProducto::getProducto(int c)
{
    std::map<int, Producto*>::iterator it;
    it = this->Productos.find(c);
    return it->second;
}

std::map<int, DT2Producto*> ManejadorProducto::listarProductos(std::map<int, Producto*> lista){
    std::map<int, Producto*>::iterator it;
    std::map<int, DT2Producto*> dataProductos;
    int num = 1;
    for (it = lista.begin(); it != lista.end(); it++){
        DT2Producto* dProducto = new DT2Producto(it->second->getCodigo(), it->second->getNombre());
        dataProductos.insert({num, dProducto});
        num++;
    }
    return dataProductos;
}

bool ManejadorProducto::checkPromo(int codigo){
    Producto* prod = this->Productos.find(codigo)->second;
    if (prod->getPromo() == NULL){
        return false;
    }
    else{
        return true;
    }
}

#endif