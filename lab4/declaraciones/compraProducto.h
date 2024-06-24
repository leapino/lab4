#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>
#include "DTCompraProducto.h"
#include "producto.h"


class Producto;
class Compra;

class CompraProducto {
    private:
        bool enviado;
        int cantidad;
        Producto *producto;
        Compra *compra;
    public:
        CompraProducto();
        CompraProducto(Producto *, int cantidad);
        bool getEnviado();
        int getCantidad();
        Producto *getProd();
        Compra *getCompra();
        void setEnviado(bool b);
        void setCantidad(int cant);
        void setProd(Producto *prod);
        DTCompraProducto getData();
        void setCompra(Compra * compra);
        ~CompraProducto();
};

#endif