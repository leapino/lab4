#include "DTVendedor.h"
#include <string>

DTVendedor::DTVendedor(){
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