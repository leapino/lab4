#ifndef PRODUCTO_CPP
#define PRODUCTO_CPP

#include "declaraciones/producto.h"
#include "producto.h"

// Producto::Producto(){
//     this->codigo = 0;
//     this->stock = 0;
//     this->precio = 0;
//     this->nombre = "";
//     this->descripcion = "";
// //  this->categoria = ???;
//     };   

Producto::Producto(int codigo,int stock,int precio,std::string nombre,std::string desc,Categoria categoria){
    this->codigo = codigo;
    this->stock = stock;
    this->precio = precio;
    this->nombre = nombre;
    this->descripcion = desc;
    this->categoria = categoria;
    this->promo = NULL;
    }

int Producto::getCodigo(){
   return this->codigo;
    }

int Producto::getStock(){
   return this->stock;
    }

int Producto::getPrecio(){
   return this->precio;
    }   

std::string Producto::getNombre(){
   return this->nombre;
    }

std::string Producto::getDescripcion(){
   return this->descripcion;
    }

Categoria Producto::getCategoria(){
   return this->categoria;
    }

DTProducto Producto::getData(){
    return DTProducto(this->codigo,this->stock,this->precio,this->nombre,this->descripcion,this->categoria);
}

void Producto::setCodigo(int codigo){
   this->codigo = codigo;
    }

void Producto::setStock(int stock){
   this->stock = stock;
    }

void Producto::setPrecio(int precio){
   this->precio = precio;
    }

void Producto::setNombre(std::string nombre){   
   this->nombre = nombre;
    }

void Producto::setDescripcion(std::string desc){   
   this->descripcion = desc;
    }

void Producto::setCategoria(Categoria categoria){   
   this->categoria = categoria;
    }

void Producto::setPromo(ProductoPromocion* promocion){
    this->promo = promocion;
}

ProductoPromocion* Producto::getPromo(){
    return this->promo;
}
#endif 