#ifndef COMPRA_H
#define COMPRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "DTFecha.h"
#include "DTCliente.h"
#include "DTProducto.h"

class Compra {
    private:
        DTFecha fecha;
        int monto;
        DTCliente *cliente;
    public:
        Compra();
        void subirMonto(int precio);
        void agregarProdCompra(Producto *prod);
        ~Compra();
};

#endif