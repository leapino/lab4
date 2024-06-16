#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>

#include "categoria.h"
#include "vendedor.h"

class Producto {
    private:
        int codigo;
        int stock;
        int precio;
        std::string nombre;
        std::string descripcion;
        Categoria categoria;
        Vendedor *vendedor;
    public:
        //Creadores
        Producto();
        Producto(int,int,int,std::string,std::string,Categoria);
        //Getters
        int getCodigo();
        int getStock();
        int getPrecio();
        std::string getNombre();
        std::string getDescripcion();
        Categoria getCategoria();
        Vendedor *getVendedor();
        //Setters
        void setCodigo(int);
        void setStock(int);
        void setPrecio(int);
        void setNombre(std::string);
        void setDescripcion(std::string);
        void setCategoria(Categoria);
        void setVendedor(Vendedor*);
        //Destructor
        ~Producto();
};
#endif