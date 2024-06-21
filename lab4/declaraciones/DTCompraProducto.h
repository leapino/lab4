#ifndef DTCOMPRAPRODUCTO_H
#define DTCOMPRAPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <list>


#include "DTFecha.h"
#include "DTProducto.h"

class DTCompraProducto{
    private:
        bool enviado;
        int cantidad;
        DTProducto prod;
    public:
        //Creadores
        DTCompraProducto();
        DTCompraProducto(bool enviado, int cantidad, DTProducto prods);
        //Getters
        bool getEnviado();
        int getCantidad();
        DTProducto getProd();
        //Setters
        void setEnviado(bool enviado);
        void setCantidad(int cantidad);
        void setProd(DTProducto prod);
        friend std::ostream &operator<<(std::ostream &salida, const DTCompraProducto& prod);
};
#endif