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
        std::map<int ,std::string> listarNicknamesV(); //Devuelve un map<int, std::string> con los nicknames de los vendedores
        std::map<int, DT2Producto*> listarProductos(std::string RUTVendedor); //Devuelve un set de DT2Producto con codigo y nombre asociado a los productos del vendedor
        void agregarProducto(int codigo,int cantMin);
        void confirmarAltaPromocion(std::string,std::string,float,DTFecha,std::map<int, int>);
        std::set<DTProducto> getProductosDisp();
        bool hayStock(int codigoP,int cantidad); 
        bool prodEnCompra();
        bool checkPromo(int);
        std::set<DTPromocion> ListarPromos(DTFecha fechact);
};

#endif