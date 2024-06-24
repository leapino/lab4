#ifndef DTPRODUCTO_CPP
#define DTPRODUCTO_CPP

#include <iostream>

#include "declaraciones/DTProducto.h"

std::ostream &operator<<(std::ostream &salida, Categoria c){
    switch (c)
    {
    case Categoria::electrodomestico:
        salida << "Electrodoméstico";
        break;
    case Categoria::ropa:
        salida << "Ropa";
        break;
    case Categoria::otro:
        salida << "Otro";
        break;
    }
    return salida;
}

std::ostream &operator<<(std::ostream &salida, DTProducto const &prod){
    salida << "Código: " << prod.codigo <<"\nNombre: "<<prod.nombre<<"\nStock: " << prod.stock<<"\nDescripción: "<<prod.descripcion<< "\nPrecio: "<<prod.precio<<"\nCategoria: "<<prod.categoria<<"\n";
    return salida;
}


bool operator<(const DTProducto& prod,const DTProducto otroprod){
    return prod.codigo<otroprod.codigo;
}


DTProducto::DTProducto(){
}

DTProducto::DTProducto(int codigo, int stock, int precio, std::string nombre, std::string descripcion, Categoria categoria){
    this->codigo = codigo;
    this->stock = stock;
    this->precio = precio;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
}

int DTProducto::getCodigo(){
    return this->codigo;
}

int DTProducto::getStock(){
    return this->stock;
}

int DTProducto::getPrecio(){
    return this->precio;
}

std::string DTProducto::getNombre(){
    return this->nombre;
}

std::string DTProducto::getDescripcion(){
    return this->descripcion;
}

Categoria DTProducto::getCategoria(){
    return this->categoria;
}

DTProducto::~DTProducto(){
}

#endif