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

std::set<DTProducto> ManejadorProducto::getProductosDisp(){
    std::set<DTProducto> res;
    for (std::map<int, Producto*>::iterator it = this->Productos.begin(); it!=this->Productos.end(); ++it){
        if(it->second->getStock()!=0){
            res.insert(it->second->getData());
        }
    }
}
bool ManejadorProducto::hayStock(int codigo, int cantidad){
    std::map<int,Producto*>::iterator it=this->Productos.find(codigo);
    return it->second->getStock()>=cantidad;
}


void ManejadorProducto::prodEnCompra(Compra* Compra){

    for (std::list<CompraProducto*>::iterator it = Compra->getcompraProductos().begin(); it!=Compra->getcompraProductos().end(); ++it){

        CompraProducto* compraProducto=*it;
        Producto* prod=compraProducto->getProd();
        
        prod->bajarStock(compraProducto->getCantidad());//bajar el Stock del Producto
    }
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
int ManejadorProducto::cantMinPromo(Producto* prod){
    return prod->getPromo()->getCantMin();
}
float ManejadorProducto::descPromo(Producto* prod){
    return prod->getPromo()->getDescuento();   
}

void ManejadorProducto::confirmarAltaPromocion(std::string nombreP,std::string descriP,float descuento,DTFecha fecha,std::map<int, int> infoProd){
    std::map<int, int>::iterator it;
    Promocion* promo = new Promocion(nombreP, descriP, fecha);
    this->Promociones.insert({nombreP, promo});
    for (it = infoProd.begin(); it != infoProd.end(); it++){
        Producto* producto = this->Productos.find(it->first)->second;
        ProductoPromocion* productoPromo = new ProductoPromocion(descuento, it->second, producto);
        producto->setPromo(productoPromo);
        promo->agregarProdProm(productoPromo);
    }
}

std::set<DTPromocion> ManejadorProducto::ListarPromos(DTFecha fechact){
    std::set<DTPromocion> res;
    for (std::map<std::string,Promocion*>::iterator it = this->Promociones.begin(); it!=this->Promociones.end();++it){

        if(fechact.EsFechaMayor(it->second->getFecha(),fechact))
            res.insert(DTPromocion(it->first,it->second->getDescripcion(),it->second->getFecha()));
    }
    return res;    
}

DTPromocion ManejadorProducto::getPromo(std::string nombre){
    std::map<std::string,Promocion*>::iterator it=this->Promociones.find(nombre);
    return DTPromocion(it->first,it->second->getDescripcion(),it->second->getFecha());
}

#endif