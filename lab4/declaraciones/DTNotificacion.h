#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <list>

#include "DTProducto.h"

struct DTNotificacion {
    private:
       std::string nombreprom;
       std::string nombrevendedor;
       std::list <DTProducto> productos;
    public:
       DTNotificacion();
       DTNotificacion(std::string,std::string,std::list <DTProducto>);
       std::string getNombreProm();
       std::string getNombreVendedor();
       std::list <DTProducto> getProductos(); 
       ~DTNotificacion();     
};

#endif