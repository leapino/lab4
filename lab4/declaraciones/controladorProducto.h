#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class ControladorProducto {
    private:
        bool enviado;
        int cantidad;
        static ControladorProducto *instancia;
        ControladorProducto();
    public:
        static ControladorProducto *getInstancia();
        void ingrDatosPromocion(/*cosas*/);
        //listarNicknames
        //listarProductos
        void agregarProducto(/*producto*/);
        void confirmarAltaPromocion();
        //getProductosDisp
        bool hayStock(); //capas mejor hacer cantStock?
        bool prodEnCompra();
};

#endif