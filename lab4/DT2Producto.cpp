#ifndef DT2PRODUCTO_CPP
#define DT2PRODUCTO_CPP

#include <iostream>

#include "declaraciones/DT2Producto.h"


std::ostream &operator<<(std::ostream &salida, DT2Producto const &prod){
    salida << "Nombre: " << prod.nombre << "\nCódigo: " << prod.codigo;
    return salida;
}


DT2Producto::DT2Producto(int codigo, std::string nombre){
    this->codigo = codigo;
    this->nombre = nombre;
}

int DT2Producto::getCodigo(){
    return this->codigo;
}

std::string DT2Producto::getNombre(){
    return this->nombre;
}

DT2Producto::~DT2Producto()
{
}
#endif