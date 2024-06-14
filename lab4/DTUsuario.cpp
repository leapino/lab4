#include "DTUsuario.h"

DTUsuario::DTUsuario(){
    this->DTesCliente=false;
    this->DTNickname="";
    this->DTNacimiento=DTFecha();
    this->pDTCliente=nullptr;
    this->pDTVendedor=nullptr;
}

DTUsuario::DTUsuario(bool esCliente, std::string Nickname, DTFecha fecha, DTCliente *cliente, DTVendedor *vendedor){
    this->DTesCliente=esCliente;
    this->DTNickname=Nickname;
    this->DTNacimiento=fecha;
    this->pDTCliente=cliente;
    this->pDTVendedor=vendedor;
}

DTUsuario::~DTUsuario(){
}

bool DTUsuario::getDTesCliente(){
    return this->DTesCliente;
}

std::string DTUsuario::getDTNickname(){
    return this->DTNickname;
}

DTFecha DTUsuario::getDTNacimiento(){
    return this->DTNacimiento;
}

DTCliente *DTUsuario::getpDTCliente(){
    return this->pDTCliente;
}

DTVendedor *DTUsuario::getpDTVendedor(){
    return this->pDTVendedor;
}

void DTUsuario::setDTesCliente(bool check){
    this->DTesCliente=check;
}

void DTUsuario::setDTNickname(std::string nick){
    this->DTNickname=nick;
}

void DTUsuario::setDTNacimiento(DTFecha fecha){
    this->DTNacimiento=fecha;
}

void DTUsuario::setpDTCliente(DTCliente * cliente){
    this->pDTCliente=cliente;
}

void DTUsuario::setpDTVendedor(DTVendedor * vendedor){
    this->pDTVendedor=vendedor;
}
