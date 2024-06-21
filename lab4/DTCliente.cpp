#include <string>
#include <iostream>

#include "declaraciones/DTCliente.h"

std::ostream &operator<<(std::ostream &salida, DTCliente& client){
    salida << "Nickname" << client.getDTNickname() << "\n Fecha de Nacimiento: " << client.getDTNacimiento() << "\n Direccion: " << client.getDTAdress() << "\n Ciudad: " << client.getDTCiudad();
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
