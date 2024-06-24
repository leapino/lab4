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



void Producto::agregarComentario(Comentario * comment){
    this->comentarios.push_back(comment);
}

Producto::Producto(int stock,double precio,std::string nombre,std::string desc,Categoria categoria){
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

double Producto::getPrecio(){
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

std::list< Comentario*> Producto::getComentarios()
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

void Producto::setPrecio(double precio){
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

    void Producto::setComentarios(std::list< Comentario *> comments)
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

Producto::~Producto(){
    for (std::list<Comentario*>::iterator it = this->comentarios.begin();it != this->comentarios.end(); ++it){
        delete (*it);
        this->comentarios.erase(it);
    }
    delete this->promo;
}

std::set<CompraProducto*> Producto::getCompraProductos(){
    return this->compraProductos;
}

void Producto::addCompraProducto(CompraProducto* c){
    this->compraProductos.insert(c);
}

#endif 