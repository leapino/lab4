#ifndef CONTROLADORUSUARIO_CPP
#define CONTROLADORUSUARIO_CPP

#include "declaraciones/controladorUsuario.h"

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

void ControladorUsuario::altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciudad){
       Cliente* nuevoCliente =new  Cliente(nick,pass,fechnaci,dir,ciudad);       
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       mu->addUsuario(nuevoCliente);
}

void ControladorUsuario::altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string RUT){
       Vendedor* nuevoVendedor =new  Vendedor(nick,pass,fechnaci,RUT);       
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       mu->addUsuario(nuevoVendedor);
}

bool ControladorUsuario::estaVacio(){
        bool estaV = true;
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        std::map<int ,std::string> nombres = mu->listarNicknames();
        if (nombres.empty() == false)
          estaV = false;
    }

#endif