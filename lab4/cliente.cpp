#ifndef CLIENTE_CPP
#define CLIENTE_CPP

#include "declaraciones/cliente.h"

Cliente::Cliente() {
    this->direccion = "";
    this->ciudad = "";
    this->Vendedores = {nullptr};
    this->Compras = {nullptr};
    this->Notificaciones;
}

Cliente::Cliente(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciud):Usuario(nick, pass, fechnaci) {
    this->direccion = dir;
    this->ciudad = ciud;
}

void Cliente::crearLinkV(Vendedor * vend) {
    this->Vendedores.push_front(vend);
}

std::list<DTNotificacion > Cliente::getDTNotificaciones() {
    return this->Notificaciones;
}


std::string Cliente::getDireccion() {
    return this->direccion;
}


std::string Cliente::getCiudad() {
    return this->ciudad;
}


std::list <Vendedor *> Cliente::getVendedores() {
    return this->Vendedores;
}


std::list <Compra *> Cliente::getCompras() {
    return this->Compras;
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


void Cliente::setDTNoti(std::list<DTNotificacion> noti) {
    this->Notificaciones=noti;
}


void Cliente::eliminarVendedores() {
    for (std::list<Vendedor*>::iterator it = this->Vendedores.begin();it != this->Vendedores.end(); ++it){
        this->Vendedores.erase(it);
    }
}

void Cliente::limpiarNotificaciones(){
    this->Notificaciones.clear();
}
void Cliente::notificar() {

}

void Cliente::agregarCompra(Compra* Compra){
    this->Compras.push_front(Compra);
}

Cliente::~Cliente() {
    for (std::list<Vendedor*>::iterator it = this->Vendedores.begin();it != this->Vendedores.end(); ++it){
        this->Vendedores.erase(it);
    }
    for (std::list<DTNotificacion>::iterator it = this->Notificaciones.begin();it != this->Notificaciones.end(); ++it){
        this->Notificaciones.erase(it);
    }
    for (std::list<Compra*>::iterator it = this->Compras.begin();it != this->Compras.end(); ++it){
        this->Compras.erase(it);
    }
}

#endif