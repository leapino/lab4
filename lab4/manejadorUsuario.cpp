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

std::set<std::string> ManejadorUsuario::listarNicknames(){
    std::map<std::string, Usuario*>::iterator it;
    std::set<std::string> nicknames;
    Vendedor* vendedor;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
        vendedor = dynamic_cast<Vendedor*>(it->second);
        if (vendedor != NULL){
            nicknames.insert(it->first);
        }
    }
    return nicknames;
}

std::set<int> ManejadorUsuario::getListaProductos(std::string nombre){
    Vendedor* vendedor = dynamic_cast<Vendedor*>(this->Usuarios.find(nombre)->second);
    return vendedor->getProductos();
}

#endif