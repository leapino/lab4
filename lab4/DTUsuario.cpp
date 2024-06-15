#include "DTUsuario.h"

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

