#ifndef PRODUCTOPROMOCION_H
#define PRODUCTOPROMOCION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

class ProductoPromocion {
    private:
        int descuento;
        int cantMin;
    public:
        //Creadores
        ProductoPromocion();
        ProductoPromocion(int,int);
        //Getters
        int getDescuento();
        int getCantMin();
        //Setters
        void setDescuento(int);
        void setCantMin(int);
};

#endif