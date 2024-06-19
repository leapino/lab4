#ifndef CONTROLADORFECHA_H
#define CONTROLADORFECHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <ctime>

#include "DTFecha.h"

class ControladorFecha {
    private:
        static ControladorFecha *instancia;
        ControladorFecha();
        DTFecha fecha;
    public:
        static ControladorFecha *getInstancia();
        void setFecha(DTFecha);
        DTFecha getFecha();
        DTFecha getFechaActual();
        bool esVigente(DTFecha);
};

#endif