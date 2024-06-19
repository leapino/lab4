#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include <string>
#include "DTFecha.h"

struct DTPromocion {
    private:
       std::string nombre;
       std::string descripcion;
       DTFecha fecha;
    public:
       DTPromocion();
       DTPromocion(std::string nombre,std::string desc,DTFecha fecha);
       std::string getNombre();
       std::string getDesc();
       DTFecha getFecha();
       ~DTPromocion();
};

#endif