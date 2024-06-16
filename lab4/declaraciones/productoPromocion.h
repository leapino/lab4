#ifndef PRODUCTOPROMOCION_H
#define PRODUCTOPROMOCION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "producto.h"

class ProductoPromocion {
    private:
        int descuento;
        int cantMin;
        Producto *producto;
    public:
        //Creadores
        ProductoPromocion();
        ProductoPromocion(int,int);
        //Getters
        int getDescuento();
        int getCantMin();
        Producto* getProducto();
        //Setters
        void setDescuento(int);
        void setCantMin(int);
        void setProducto(Producto*);
        //Destructor
        ~ProductoPromocion();
};

#endif