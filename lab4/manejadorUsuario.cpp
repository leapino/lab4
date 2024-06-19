#ifndef MANEJADORUSUARIO_CPP
#define MANEJADORUSUARIO_CPP

#include "declaraciones/manejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ManejadorUsuario();
    }
        return instancia;
}

void ManejadorUsuario::addUsuario(Usuario* u){
    this->Usuarios.insert({u->getNickname(),u});
}

Usuario* ManejadorUsuario::getUsuario(std::string n){
    std::map<std::string, Usuario*>::iterator it;
    it = this->Usuarios.find(n);
    return it->second;
}

DTUsuario ManejadorUsuario::getInfoUsuario(Usuario *usuario){
    return DTUsuario(usuario->getNickname(),usuario->getFecha());
}

DTCliente ManejadorUsuario::getInfoCliente(Cliente *usuario){
    return DTCliente(usuario->getNickname(),usuario->getFecha(),usuario->getDireccion(),usuario->getCiudad());
}
DTVendedor ManejadorUsuario::getInfoVendedor(Vendedor *usuario){
    return DTVendedor(usuario->getNickname(),usuario->getFecha(),usuario->getRUT());
}
std::list<DTCompra> ManejadorUsuario::getInfoComprasCliente(Cliente *cliente){

    /*std::list<DTCompra> res;

    for (std::list<Compra*>::iterator it = cliente->getCompras().begin(); it!=cliente->getCompras().end(); ++it){
        std::list<DTCompraProducto> prods;
        std::list<CompraProducto*>::iterator it2=it;
        for(=it->getCompraProductos().begin();it2!=it->getCompraProductos().end();++it2){

        }
        DTCompra compraactual=DTCompra(it->getFecha(),it->getMonto(),prods);
    }  
*/
}
std::set<std::string> ManejadorUsuario::getClientes(){

    std::set<std::string> listaClientes;
    for (std::map<std::string, Usuario*>::iterator it = this->Usuarios.begin(); it!=this->Usuarios.end(); ++it){
        if (it->second->esCliente()){
            listaClientes.insert(it->first);
        }
    }
    return listaClientes;
}

std::map<int ,std::string> ManejadorUsuario::listarNicknamesV(){
    std::map<std::string, Usuario*>::iterator it;
    std::map<int ,std::string> nicknames;
    Vendedor* vendedor;
    int num = 1;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
        vendedor = dynamic_cast<Vendedor*>(it->second);
        if (vendedor != NULL){
            nicknames.insert({num, it->first});
            num++;
        }
    }
    return nicknames;
}

std::map<int, Producto*> ManejadorUsuario::getListaProductos(std::string nombre){
    Vendedor* vendedor = dynamic_cast<Vendedor*>(this->Usuarios.find(nombre)->second);
    return vendedor->getProductos();
}

bool ManejadorUsuario::estaUsuario(std::string nombre) {   
       bool estaN = false;
       std::map<std::string, Usuario*>::iterator it;
       it = this->Usuarios.find(nombre);
       if (it != this->Usuarios.end())
          estaN = true;
       return estaN;
}

std::map<int ,std::string> ManejadorUsuario::listarNickUsuarios(){
    std::map<std::string, Usuario*>::iterator it;
    std::map<int ,std::string> nicknames;
    int num = 1;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
        nicknames.insert({num, it->first});
        num++;
    }
    return nicknames;
}

void ManejadorUsuario::agregarCompraCliente(Cliente *cliente,Compra* compra){
    cliente->agregarCompra(compra);
}

#endif