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
#include "compraProducto.h"
#include "DTPromocion.h"
#include "DTFecha.h"

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
        void prodEnCompra(Compra* compra);
        Producto* getProducto(int);
        std::map<int, DT2Producto*> listarProductos(std::map<int, Producto*>);
        //Promociones
        void confirmarAltaPromocion(std::string,std::string,float,DTFecha,std::map<int, int>);
        bool checkPromo(int);
        int cantMinPromo(Producto* prod);//pre: estar en una promo
        float descPromo(Producto* prod);//Pre estar en una promo
        std::set<DTPromocion> ListarPromos(DTFecha fechact);
        DTPromocion getPromo(std::string nombre);
};
#endif