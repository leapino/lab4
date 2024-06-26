#ifndef DTCOMPRA_H
#define DTCOMPRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <list>
#include <iostream>

#include "DTFecha.h"
#include "DTCompraProducto.h"

class DTCompra{
    private:
        DTFecha fecha;
        double monto;
        std::list <DTCompraProducto> Prods;
        int IDcompra;
    public:
        //Creadores
        DTCompra();
        DTCompra(DTFecha fecha, double monto, std::list <DTCompraProducto> prods,int id);
        //Getters
        DTFecha getFecha();
        double getMonto();
        int getCantidad();
        //Setters
        void setFecha(DTFecha fecha);
        void setMonto(double mont);
        void setProds(std::list<DTCompraProducto> prods);
        //funcion
        void agregarProds(DTCompraProducto prod);
        //Destructor
        ~DTCompra();
        //funcion
        friend std::ostream& operator<<(std::ostream& os, const DTCompra& compra);

};
#endif