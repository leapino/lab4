#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <string>
#include "DTFecha.h"

struct DTPromocion {
    private:
       std::string nombre;
       std::string descripcion;
       DTFecha fecha;
    public:
       DTPromocion();
       DTPromocion(std::string,std::string,DTFecha);
       std::string getNombre();
       std::string getDesc();
       DTFecha getFecha();
       ~DTPromocion();
};

#endif