#ifndef MANEJADORPRODUCTO_H
#define MANEJADORPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "producto.h"

class ManejadorProducto {
    private:
        static ManejadorProducto* instancia;
        ManejadorProducto();
        std::map<int, Producto*> Productos;
    public:
        static ManejadorProducto* getInstancia();
};
#endif