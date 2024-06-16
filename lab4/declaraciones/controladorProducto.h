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
        //bool enviado; 
        //int cantidad; 
        static ControladorProducto *instancia;
        ControladorProducto();
    public:
        static ControladorProducto *getInstancia();
        void ingrDatosPromocion(/*cosas*/);
        std::set<std::string> listarNicknames(); //Devuelve un set<std::string> con los nicknames de los vendedores
        std::set<DT2Producto*> listarProductos(std::string); //Devuelve un set de DT2Producto con codigo y nombre asociado a los productos del vendedor
        void agregarProducto(/*producto*/);
        void confirmarAltaPromocion();
        //getProductosDisp
        bool hayStock(); //capas mejor hacer cantStock?
        bool prodEnCompra();
};

#endif