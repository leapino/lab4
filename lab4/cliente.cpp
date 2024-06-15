#ifndef CLIENTE_CPP
#define CLIENTE_CPP

#include "declaraciones/cliente.h"

Cliente::Cliente() {
    this->direccion = "";
    this->ciudad = "";
    this->Vendedores = {nullptr};
    this->Compras = {nullptr};
    this->Notificaciones = {nullptr};
}

Cliente::Cliente(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciud):Usuario(nick, pass, fechnaci) {
    this->direccion = dir;
    this->ciudad = ciud;
}

void Cliente::crearLinkV(Vendedor * vend) {
    this->Vendedores.push_front(vend);
}

//getNotificaciones

void Cliente::eliminarVendedores() {

}

void Cliente::notificar() {

}

//Ni idea si esto funciona
Cliente::~Cliente() {
    for(Vendedor *ptr : Vendedores) {
        delete ptr;
    }
    for(Compra *ptr : Compras) {
        delete ptr;
    }
    for(DTNotificacion *ptr : Notificaciones) {
        delete ptr;
    }
}

#endif