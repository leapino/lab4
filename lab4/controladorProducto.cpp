#ifndef CONTROLADORPRODUCTO_CPP
#define CONTROLADORPRODUCTO_CPP

#include "declaraciones/controladorProducto.h"

ControladorProducto* ControladorProducto::instancia = NULL;

ControladorProducto* ControladorProducto::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorProducto();
    }
        return instancia;
}

std::map<int ,std::string> ControladorProducto::listarNicknamesV(){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->listarNicknamesV();
}

std::map<int , DT2Producto*> ControladorProducto::listarProductos(std::string nombre){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    std::map<int, Producto*> lista = mu->getListaProductos(nombre);
    return mp->listarProductos(lista);
}

std::set<DTProducto> ControladorProducto::getProductosDisp(){
    ManejadorProducto *mP;
    mP=ManejadorProducto::getInstancia();
    std::set<DTProducto>listaProductosDisp=mP->getProductosDisp();
    return listaProductosDisp;
}

bool ControladorProducto::hayStock(int codigoP, int cantidad){
    ManejadorProducto *mP;
    mP=ManejadorProducto::getInstancia();
    bool res=mP->hayStock(codigoP,cantidad);
    return ;
}

bool ControladorProducto::checkPromo(int codigo){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->checkPromo(codigo);
}

void confirmarAltaPromocion(std::string nombreP,std::string descriP,float descuento,DTFecha fecha,std::map<int, int> infoProd){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    mp->confirmarAltaPromocion(nombreP, descriP, descuento, fecha, infoProd);
}

std::set<DTProducto> ControladorProducto::getProductosDisp(){
    ManejadorProducto *mP;
    mP=ManejadorProducto::getInstancia();
    std::set<DTProducto>listaProductosDisp=mP->getProductosDisp();
    return listaProductosDisp;
}

bool ControladorProducto::hayStock(int codigoP, int cantidad){
    ManejadorProducto *mP;
    mP=ManejadorProducto::getInstancia();
    bool res=mP->hayStock(codigoP,cantidad);
    return ;
}

std::map<std::string, DTPromocion*> ControladorProducto::getPromos(){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    ControladorFecha* cf;
    cf = ControladorFecha::getInstancia();
    std::map<std::string, Promocion*>::iterator it;
    std::map<std::string, DTPromocion*> dtpromociones;
    for (it = mp->getPromos().begin(); it != mp->getPromos().end(); it++){
        if (cf->esVigente(it->second->getFecha())){
            DTPromocion* dtpromo = new DTPromocion(it->second->getNombre(), it->second->getDescripcion(), it->second->getFecha());
            dtpromociones.insert({it->second->getNombre(), dtpromo});
        }
    }
    return dtpromociones;
}
#endif