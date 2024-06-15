#include <string>

#include "DTCliente.h"

DTCliente::DTCliente(){
}

DTCliente::DTCliente(std::string direc, std::string Ciudad){
    this->DTAdress=direc;
    this->DTCiudad=Ciudad;
}

DTCliente::~DTCliente(){
}

std::string DTCliente::getDTAdress(){
    return this->DTAdress;
}

std::string DTCliente::getDTCiudad(){
    return this->DTCiudad;
}

void DTCliente::setDTAdress(std::string direc){
    this->DTAdress=direc;
}

void DTCliente::setDTCiudad(std::string ciudad){
    this->DTCiudad=ciudad;
}
