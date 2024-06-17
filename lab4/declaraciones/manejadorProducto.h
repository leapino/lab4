#ifndef MANEJADORPRODUCTO_H
#define MANEJADORPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>

#include "producto.h"
#include "DTProducto.h"
#include "DT2Producto.h"

class ManejadorProducto {
    private:
        static ManejadorProducto* instancia;
        ManejadorProducto();
        std::map<int, Producto*> Productos;
    public:
        static ManejadorProducto* getInstancia();
        void agregarProducto(Producto*);
        Producto* getProducto(int);
        std::map<int, DT2Producto*> listarProductos(std::map<int, Producto*>);
        bool checkPromo(int);
};
#endif