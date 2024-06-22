#ifndef DTVENDEDOR_CPP
#define DTVENDEDOR_CPP

#include "declaraciones/DTVendedor.h"


std::ostream &operator<<(std::ostream &salida, const DTVendedor & vend){
    salida << "RUT" << vend.DTRUT;
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