#ifndef DTPRODUCTO_CPP
#define DTPRODUCTO_CPP

#include "declaraciones/DTProducto.h"

DTProducto::DTProducto(int codigo, int stock, int precio, std::string nombre, std::string descripcion, Categoria categoria){
    this->codigo = codigo;
    this->stock = stock;
    this->precio = precio;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->categoria = categoria;
}

#endif