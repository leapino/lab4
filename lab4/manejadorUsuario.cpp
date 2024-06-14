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


#endif