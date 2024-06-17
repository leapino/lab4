#ifndef PROMOCION_H
#define PROMOCION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>

#include "DTFecha.h"
#include "DTProducto.h"
#include "productoPromocion.h"


class Promocion {
    private:
        std::string nombre;
        std::string descripcion;
        DTFecha fecha;
        std::set < ProductoPromocion *> prodProm;
    public:
    //Creadores
    Promocion();
    Promocion(std::string,std::string,DTFecha);
    //Getters
    std::string getNombre();
    std::string getDescripcion();
    DTFecha getFecha();
    std::list < ProductoPromocion *> getProdProm();
    //Setters
    void setNombre(std::string);
    void setDescripcion(std::string);
    void setFecha(DTFecha);
    void agregarProdProm(ProductoPromocion*);
};

#endif