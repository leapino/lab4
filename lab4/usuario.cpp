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

#endif