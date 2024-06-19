#ifndef DTVENDEDOR_CPP
#define DTVENDEDOR_CPP

#include "DTVendedor.h"
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &salida, DTVendedor* vend){
    salida << "Nickname: " << vend->getDTNickname() << "\nRUT: " << vend->getDTRUT() << "\n";
    return salida;
}

DTVendedor::DTVendedor(std::string Nickname, DTFecha fecha,std::string rut){
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