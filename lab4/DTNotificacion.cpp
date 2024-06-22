#ifndef DTNOTIFICACION_CPP
#define DTNOTIFICACION_CPP

#include "declaraciones/DTNotificacion.h"

DTNotificacion::DTNotificacion()
{
}

std::ostream &operator<<(std::ostream &salida, const DTNotificacion  &   noti){
    salida << "Nombre Promocion"<<noti.nombreprom<<"\n Nombre Vendedor"<<noti.nombrevendedor<<"\n Productos";
    for (const auto& i : noti.productos) {
        salida << "- " << i << "\n";
    }
    return salida;
}

DTNotificacion::DTNotificacion(std::string nombreP, std::string nombreV, std::list<DTProducto*> prods){
    this->nombreprom=nombreP;
    this->nombrevendedor=nombreV;
    this->productos=prods;
}

std::string DTNotificacion::getNombreProm()
{
    return this->nombreprom;
}

std::string DTNotificacion::getNombreVendedor()
{
    return this->nombrevendedor;
}

std::list<DTProducto*> DTNotificacion::getProductos()
{
    return this->productos;
}

void DTNotificacion::setNombrePromo(std::string nombre)
{
    this->nombreprom=nombre;
}

void DTNotificacion::setNombreVendedor(std::string nombre)
{
    this->nombrevendedor=nombre;
}

void DTNotificacion::setProductos(std::list<DTProducto *> productos)
{
    this->productos=productos;
}

DTNotificacion::~DTNotificacion()
{
}

#endif