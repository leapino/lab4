#include "DTUsuario.h"

#include <iostream>

std::ostream &operator<<(std::ostream &salida, DTUsuario* user){
    salida << "Nickname" << user->getDTNickname() << "\n Fecha de Nacimiento: " << &user->getDTNacimiento();
    return salida;
}

DTUsuario::DTUsuario(){
    this->DTNickname="";
    this->DTNacimiento=DTFecha();
}

DTUsuario::DTUsuario(std::string Nickname, DTFecha fecha){
    this->DTNickname=Nickname;
    this->DTNacimiento=fecha;
}

DTUsuario::~DTUsuario(){
}

std::string DTUsuario::getDTNickname(){
    return this->DTNickname;
}

DTFecha DTUsuario::getDTNacimiento(){
    return this->DTNacimiento;
}


void DTUsuario::setDTNickname(std::string nick){
    this->DTNickname=nick;
}

void DTUsuario::setDTNacimiento(DTFecha fecha){
    this->DTNacimiento=fecha;
}

