#ifndef CONTROLADORFECHA_H
#define CONTROLADORFECHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class ControladorFecha {
    private:
        static ControladorFecha *instancia;
        ControladorFecha();
    public:
        static ControladorFecha *getInstancia();
};

#endif