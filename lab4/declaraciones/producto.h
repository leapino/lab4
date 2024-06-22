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

class Producto {
    private:
        int codigo;
        int stock;
        double precio;
        std::string nombre;
        std::string descripcion;
        Categoria categoria;
        Vendedor *vendedor;
        std::map<int,Comentario*> comentarios;
        ProductoPromocion* promo;
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
        std::map<int,Comentario*> getComentarios();
        ProductoPromocion* getPromo();
        //Setters
        void setCodigo(int);
        void setStock(int);
        void setPrecio(double);
        void setNombre(std::string);
        void setDescripcion(std::string);
        void setCategoria(Categoria);
        void setVendedor(Vendedor *);
        void setComentarios(std::map<int,Comentario*>);
        void setPromo(ProductoPromocion*);
        void bajarStock(int cantidad);
        //Destructor
        ~Producto();
        //funcion
        void agregarComentario(Comentario* comment);
        Producto(int,int,std::string,std::string,Categoria);
};
#endif