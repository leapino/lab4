#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTProducto.h"

class DTPromocion {
    private:
       std::string nombre;
       std::string descripcion;
       DTFecha fecha;
       std::set<DTProducto> productos;
       int descuento;
    public:
       DTPromocion();
       DTPromocion(std::string nombre,std::string desc,DTFecha fecha, int descuento);
       std::string getNombre();
       std::string getDesc();
       DTFecha getFecha();
       int getDescuento();
       ~DTPromocion();
       void addProducto(DTProducto);
       std::set<DTProducto> getProductos();
       friend std::ostream &operator<<(std::ostream &salida,const DTPromocion&prom);
};

#endif