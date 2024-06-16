#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <set>

#include "manejadorUsuario.h"
#include "manejadorProducto.h"

class ControladorProducto {
    private: 
        static ControladorProducto *instancia;
        ControladorProducto();
    public:
        static ControladorProducto *getInstancia();
        void ingrDatosPromocion(std::string nombreP,std::string descripcionP,float descuentoP,DTFecha fechaP);
        std::set<std::string> listarNicknames(); //Devuelve un set<std::string> con los nicknames de los vendedores
        std::set<DT2Producto*> listarProductos(std::string RUTVendedor); //Devuelve un set de DT2Producto con codigo y nombre asociado a los productos del vendedor
        void agregarProducto(int codigo,int cantMin);
        void confirmarAltaPromocion();//poner parametros
        std::set<Producto*> getProductosDisp();
        bool hayStock(int codigoP,int cantidad); 
        bool prodEnCompra();
};

#endif