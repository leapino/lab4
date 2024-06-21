#ifndef DTPRODUCTO_CPP
#define DTPRODUCTO_CPP

#include <iostream>

#include "declaraciones/DTProducto.h"



std::ostream &operator<<(std::ostream &salida, DTProducto &prod){
    salida << "Código: " << prod.getCodigo() << "\n Stock: " << prod.getStock()<<"\n Precio:"<<prod.getPrecio()<<"\n Nombre:"<<prod.getNombre()<<"\n Descripción:"<<prod.getDescripcion()<<"\n Categoria:"<<prod.getCategoria();
    return salida;
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