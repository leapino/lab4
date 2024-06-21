#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "categoria.h"

class DTProducto {
    private:
        int codigo;
        int stock;
        int precio;
        std::string nombre;
        std::string descripcion;
        Categoria categoria;
    public:
        //Creadores
        DTProducto();
        DTProducto(int codigo,int stock,int precio,std::string nombre,std::string descripcion,Categoria categoria);
        //Getters
        int getCodigo();
        int getStock();
        int getPrecio();
        std::string getNombre();
        std::string getDescripcion();
        Categoria getCategoria();
        ~DTProducto();
        friend std::ostream &operator<<(std::ostream &salida,const DTProducto &prod);
};

#endif