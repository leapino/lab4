#ifndef CONTROLADORUSUARIO_CPP
#define CONTROLADORUSUARIO_CPP

#include "declaraciones/controladorUsuario.h"
#include "controladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario* ControladorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorUsuario();
    }
        return instancia;
}

std::set<std::string> ControladorUsuario::listarClientes(){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    std::set<std::string> listaClientes=mUsuario->getClientes();
    return listaClientes;
}

void ControladorUsuario::selectCliente(){

}

void ControladorUsuario::confirmarCompra(){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    ManejadorProducto* mProducto;
    mProducto=ManejadorProducto::getInstancia();
    //Compra()
    mProducto->prodEnCompra();
    //Compra->subirMonto(PrecioCompra);
    //agregarProdCompra(codigoP,cantidad)
    //pasarle la compra a el cliente correspondiente

}

#endif