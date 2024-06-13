#ifndef COMPRAPRODUCTO_H
#define COMPRAPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class CompraProducto {
    private:
        bool enviado;
        int cantidad;
    public:
        CompraProducto();
        ~CompraProducto();
};

#endif