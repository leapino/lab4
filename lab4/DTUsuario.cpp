#ifndef DTUSUARIO_CPP
#define DTUSUARIO_CPP

#include "declaraciones/DTUsuario.h"



std::ostream &operator<<(std::ostream &salida, const DTUsuario& user){
    salida << "Nickname" << user.DTNickname << "\n Fecha de Nacimiento: " << user.DTNacimiento;
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

#endif
