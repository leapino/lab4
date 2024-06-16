#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>

#include "producto.h"

class CompraProducto {
    private:
        bool enviado;
        int cantidad;
        Producto *prod;
    public:
        CompraProducto();
        CompraProducto(Producto *, int cantidad);
        bool getEnviado();
        int getCantidad();
        Producto *getProd();
        void setEnviado(bool);
        void setCantidad(int);
        void setProd(Producto);
        void enviar();
        bool fueEnviado();
        ~CompraProducto();
};

#endif