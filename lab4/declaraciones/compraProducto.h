#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>

#include "producto.h"

class Producto;

class CompraProducto {
    private:
        bool enviado;
        int cantidad;
        Producto *producto;
    public:
        CompraProducto();
        CompraProducto(Producto *, int cantidad);
        bool getEnviado();
        int getCantidad();
        Producto *getProd();
        void setEnviado(bool b);
        void setCantidad(int cant);
        void setProd(Producto *prod);
        ~CompraProducto();
};

#endif