#ifndef USUARIO_CPP
#define USUARIO_CPP

#include "declaraciones/usuario.h"

// Usuario::Usuario(){
//     this->nickname = "";
//     this->password = "";
//     this->fechaNacimiento = NULL;
// }

Usuario::Usuario(std::string nick,std::string pass, DTFecha fecha){
    this->nickname = nick;
    this->password = pass;
    this->fechaNacimiento = fecha;
}

std::string Usuario::getNickname(){
    return this->nickname;
}

std::string Usuario::getPassword(){
    return this->password;
}

DTFecha Usuario::getFecha(){
    return this->fechaNacimiento;
}

void Usuario::setNickname(std::string nick){
    this->nickname = nick;
}

void Usuario::setPassword(std::string pass){
    this->password = pass;
}

void Usuario::setFecha(DTFecha fecha){
    this->fechaNacimiento = fecha;
}

bool Usuario::esVendedor(){
    Vendedor* pVendedor;
    pVendedor=dynamic_cast<Vendedor*> (this);
    return pVendedor!=nullptr;
}

bool Usuario::esCliente(){
    Cliente* pCliente;
    pCliente=dynamic_cast<Cliente*> (this);
    return pCliente!=nullptr;
}

std::map<int, std::string> Usuario::listarComentarios(){
    std::map<int, Comentario*>::iterator it;
    std::map<int ,std::string> coments;
    for (it = this->comentarios.begin(); it != this->comentarios.end(); it++){
        coments.insert({it->first, it->second->getTexto()});
    }
    return coments;
}    

#endif