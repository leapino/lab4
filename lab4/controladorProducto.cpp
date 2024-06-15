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

std::set<std::string> ControladorProducto::listarNicknames(){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->listarNicknames();
}

#endif