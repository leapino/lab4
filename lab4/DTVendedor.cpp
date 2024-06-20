#ifndef DTVENDEDOR_CPP
#define DTVENDEDOR_CPP

#include "../declaraciones/DTVendedor.h"
#include <iostream>
#include <string>
#include <iostream>

std::ostream &operator<<(std::ostream &salida, DTVendedor* vend){
    salida << "Nickname" << vend->getDTNickname() << "\n Fecha de Nacimiento: " << &vend->getDTNacimiento() << "RUT" << vend->getDTRUT();
    return salida;
}

std::ostream &operator<<(std::ostream &salida, DTVendedor* vend){
    salida << "Nickname: " << vend->getDTNickname() << "\nRUT: " << vend->getDTRUT() << "\n";
    return salida;
}

DTVendedor::DTVendedor()
{
}

DTVendedor::DTVendedor(std::string Nickname, DTFecha fecha, std::string rut)
{
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