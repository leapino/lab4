#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>

#include "categoria.h"
#include "productoPromocion.h"
#include "DT2Producto.h"
#include "DTProducto.h"
#include "comentario.h"

class Vendedor;
class ProductoPromocion;
class Comentario;
class CompraProducto;

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
        void agregarComentario(Comentario* comment);
};
#endif