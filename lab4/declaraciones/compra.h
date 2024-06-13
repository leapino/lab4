#ifndef COMPRA_H
#define COMPRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "DTFecha.h"

class Compra {
    private:
        DTFecha fecha;
        int monto;
        DTCliente *cliente;
    public:
        Compra(/*idk*/)
        void subirMonto(int precio);
        void agregarProdCompra(DTProducto *prod);
        ~Compra();
};

#endif