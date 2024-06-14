#ifndef PROMOCION_H
#define PROMOCION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "DTFecha.h"
#include "DTProducto.h"

class Promocion {
    private:
        std::string nombre;
        std::string descripcion;
        DTFecha fecha;
    public:
    //Creadores
    Promocion();
    Promocion(std::string,std::string,DTFecha);
    //Getters
    std::string getNombre();
    std::string getDescripcion();
    std::string getFecha();
    //Setters
    void setNombre(std::string);
    void setDescripcion(std::string);
    void setFecha(DTFecha);
    void agregarProdProm(DTProducto,int);
};

#endif