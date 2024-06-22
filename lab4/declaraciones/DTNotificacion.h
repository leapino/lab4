#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <list>
#include <iostream>

#include "DTProducto.h"

class DTNotificacion {
    private:
       std::string nombreprom;
       std::string nombrevendedor;
       std::list <DTProducto*> productos;
    public:
       DTNotificacion();
       DTNotificacion(std::string nombreP,std::string nombreV,std::list <DTProducto*> prods);
       std::string getNombreProm();
       std::string getNombreVendedor();
       std::list <DTProducto*> getProductos(); 
       void setNombrePromo(std::string nombre);
       void setNombreVendedor(std::string nombre);
       void setProductos(std::list<DTProducto*> productos);
       ~DTNotificacion();  
       friend std::ostream &operator<<(std::ostream &salida, const DTNotificacion  &   noti);   
};

#endif