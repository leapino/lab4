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

std::map<int ,std::string> ControladorProducto::listarNicknames(){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->listarNicknames();
}

std::map<int , DT2Producto*> ControladorProducto::listarProductos(std::string nombre){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    std::map<int, Producto*> lista = mu->getListaProductos(nombre);
    return mp->listarProductos(lista);
}

bool ControladorProducto::checkPromo(int codigo){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->checkPromo(codigo);
}

void confirmarAltaPromocion(std::string nombreP,std::string descriP,float descuento,DTFecha fecha,std::map<int, int> infoProd){

}

#endif