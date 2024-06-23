#ifndef DTVENDEDOR_CPP
#define DTVENDEDOR_CPP

#include "declaraciones/DTVendedor.h"


std::ostream &operator<<(std::ostream &salida, DTVendedor  vend){
    salida << "\nNickname: " << vend.getDTNickname() << "\nFecha de Nacimiento: " << vend.getDTNacimiento() << "\nRUT: " << vend.getDTRUT();
    return salida;
}

DTVendedor::DTVendedor()
{
}

DTVendedor::DTVendedor(std::string Nickname, DTFecha fecha, std::string rut):DTUsuario(Nickname, fecha){
    this->DTRUT=rut;
}

DTVendedor::~DTVendedor(){
}

std::string DTVendedor::getDTRUT(){
    return this->DTRUT;
}

void DTVendedor::setDTRUT(std::string rut){
    this->DTRUT=rut;
}

#endif