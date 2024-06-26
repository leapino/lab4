#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>

#include "categoria.h"
#include "productoPromocion.h"
#include "DT2Producto.h"
#include "DTProducto.h"
#include "comentario.h"

class Vendedor;
class ProductoPromocion;
class CompraProducto;
class Comentario;

class Producto {
    private:
        int codigo;
        int stock;
        double precio;
        std::string nombre;
        std::string descripcion;
        Categoria categoria;
        Vendedor *vendedor;
        std::list<Comentario*> comentarios;
        ProductoPromocion* promo;
        std::set<CompraProducto*> compraProductos;
    public:
        //Creadores
        Producto();
        Producto(int,double,std::string,std::string,Categoria);
        //Getters
        int getCodigo();
        int getStock();
        double getPrecio();
        std::string getNombre();
        std::string getDescripcion();
        Categoria getCategoria();
        Vendedor *getVendedor();
        DTProducto getData();
        DT2Producto getData2();
        std::list<Comentario*> getComentarios();
        ProductoPromocion* getPromo();
        std::set<CompraProducto*> getCompraProductos();
        //Setters
        void setCodigo(int);
        void setStock(int);
        void setPrecio(double);
        void setNombre(std::string);
        void setDescripcion(std::string);
        void setCategoria(Categoria);
        void setVendedor(Vendedor *);
        void setComentarios(std::list<Comentario*>);
        void setPromo(ProductoPromocion*);
        void bajarStock(int cantidad);
        void addCompraProducto(CompraProducto*);
        //Destructor
        ~Producto();
        //funcion
        void borrarComment(int id);
        void borrarRespCometario(Comentario* comm);
        void agregarComentario(Comentario* comment);
        void agregarComentario(int id,Comentario* comm,std::list<Comentario*> buscar);
};      
#endif