#ifndef DTCOMPRA_H
#define DTCOMPRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <list>

#include "DTFecha.h"
#include "DTCompraProducto.h"

class DTCompra{
    private:
        DTFecha* fecha;
        int monto;
        std::list <DTCompraProducto*> Prods;
    public:
        //Creadores
        DTCompra();
        DTCompra(DTFecha *fecha, int monto, std::list <DTCompraProducto> prods);
        //Getters
        DTFecha* getFecha();
        int getMonto();
        int getCantidad();
        //Setters
        void setFecha(DTFecha *fecha);
        void setMonto(int mont);
        void setCantidad(int cantidad);
};
#endif