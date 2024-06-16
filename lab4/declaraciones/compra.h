#ifndef COMPRA_H
#define COMPRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <list>

#include "DTFecha.h"
#include "DTCliente.h"
#include "DTProducto.h"
#include "compraProducto.h"
#include "cliente.h"

class Compra {
    private:
        DTFecha *fecha;
        int monto;
        Cliente *cliente;
        std::list<CompraProducto *> compraProductos;
    public:
        Compra();
        Compra(DTFecha *fecha, int monto, Cliente *cliente, CompraProducto *compraPr);
        void subirMonto(int precio);
        void agregarProdCompra(Producto *prod);
        ~Compra();
};

#endif