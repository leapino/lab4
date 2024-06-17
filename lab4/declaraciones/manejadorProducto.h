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
#include "productoPromocion.h"
#include "promocion.h"

class ManejadorProducto {
    private:
        static ManejadorProducto* instancia;
        ManejadorProducto();
        std::map<int, Producto*> Productos;
        std::map<std::string, Promocion*> Promociones;
    public:
        static ManejadorProducto* getInstancia();
        void agregarProducto(Producto*);
        std::set<DTProducto> getProductosDisp();
        bool hayStock(int codigo, int cantidad);
        void prodEnCompra();
        Producto* getProducto(int);
        std::map<int, DT2Producto*> listarProductos(std::map<int, Producto*>);
        void confirmarAltaPromocion(std::string,std::string,float,DTFecha,std::map<int, int>);
        bool checkPromo(int);
};
#endif