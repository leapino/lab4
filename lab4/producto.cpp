#ifndef PRODUCTO_CPP
#define PRODUCTO_CPP

#include "declaraciones/producto.h"
#include "declaraciones/DT2Producto.h"


Producto::Producto(){
//     this->codigo = 0;
//     this->stock = 0;
//     this->precio = 0;
//     this->nombre = "";
//     this->descripcion = "";
// //  this->categoria = ???;
};   

Producto::Producto(int stock,int precio,std::string nombre,std::string desc,Categoria categoria){
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

DTProducto Producto::getData()
{
    DTProducto nuevo = DTProducto(this->codigo, this->stock, this->precio, this->nombre, this->descripcion, this->categoria);
    return nuevo;
}

DT2Producto Producto::getData2()
{   DT2Producto nosequequerianhaceraca=DT2Producto(this->codigo,this->nombre);
    return nosequequerianhaceraca;
}

std::map<int, Comentario*> Producto::getComentarios()
{
    return this->comentarios;
}

Vendedor *Producto::getVendedor()
{
    return this->vendedor;
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

    void Producto::setVendedor(Vendedor * vendedor)
    {
        this->vendedor=vendedor;
    }

    void Producto::setComentarios(std::map<int, Comentario *> comments)
    {
        this->comentarios=comments;
    }

void Producto::setPromo(ProductoPromocion* promocion){
    this->promo = promocion;
}

ProductoPromocion* Producto::getPromo(){
    return this->promo;
}

void Producto::bajarStock(int cantidad){
    this->stock=this->stock-cantidad;
}

Producto::~Producto()
{
}

void Producto::agregarComentario(int id, Comentario *comment){
    /*auto it=this->comentarios.find(id);
    if(it!=nullptr)
        it->second->(std::make_pair(id,comment));
*/}
#endif 