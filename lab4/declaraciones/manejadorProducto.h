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
#include "DTPromocion.h"
#include "DTFecha.h"
#include "DTVendedor.h"
#include "DTComentario.h"
#include "compraProducto.h"
#include "vendedor.h"


class Producto;
class Promocion;
class Comentario;


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
        std::map<int,std::string> getProds();
        bool hayStock(int codigo, int cantidad);
        void prodEnCompra(Producto* prod,int cantidad);
        Producto* getProducto(int);
        std::map<std::string, DTProducto > getInfoProd(std::string producto);
        std::map<int, DT2Producto> listarProductos(std::map<int, Producto*>);
        std::list <DTComentario> listarComProd(std::map<int,Comentario*> comm);
        //Promociones
        void confirmarAltaPromocion(std::string,std::string,float,DTFecha,std::map<int, int>);
        bool checkPromo(int);
        int cantMinPromo(Producto* prod);//pre: estar en una promo
        float descPromo(Producto* prod);//Pre estar en una promo
        std::map<std::string, Promocion*> getPromos();
        DTVendedor vendedorPromo(DTProducto);
        std::list<DTPromocion> getPromoVigente(std::string vendedor,DTFecha fechaActual);
        std::list<CompraProducto*> confirmarCompra(std::map<int,int> datos, double monto);
        Producto* finalProd();
        void addProducto(Producto*);
};      
#endif