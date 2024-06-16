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

std::list<DTNotificacion *> Cliente::getDTNotificaciones() {

}


std::string Cliente::getDireccion() {
    return this->direccion;
}


std::string Cliente::getCiudad() {
    return this->ciudad;
}


std::list <Vendedor *> Cliente::getVendedores() {

}


std::list <Compra *> Cliente::getCompras() {

}


void Cliente::setDireccion(std::string dir) {
    this->direccion = dir;
}


void Cliente::setCiudad(std::string city) {
    this->ciudad = city;
}


void Cliente::setUnVendedor(Vendedor *ven) {
    this->Vendedores.push_front(ven);
}


void Cliente::setCompra(Compra *comp) {
    this->Compras.push_front(comp);
}


void Cliente::setDTNoti(DTNotificacion *noti) {
    this->Notificaciones.push_front(noti);
}


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