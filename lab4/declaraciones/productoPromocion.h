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
        float descuento;
        int cantMin;
        Producto *producto;
    public:
        //Creadores
        ProductoPromocion();
        ProductoPromocion(float,int,Producto*);
        //Getters
        float getDescuento();
        int getCantMin();
        Producto* getProducto();
        //Setters
        void setDescuento(float);
        void setCantMin(int);
        void setProducto(Producto *p);
        //Destructor
        ~ProductoPromocion();
};

#endif