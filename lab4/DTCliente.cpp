#include <string>
#include <iostream>

#include "declaraciones/DTCliente.h"

std::ostream &operator<<(std::ostream &salida, DTCliente const& client){
    salida << " Direccion: " << client.DTAdress << "\n Ciudad: " << client.DTCiudad;
    return salida;
}

DTCliente::DTCliente(){
}

DTCliente::DTCliente(std::string Nickname, DTFecha fecha,std::string direc, std::string Ciudad){
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
