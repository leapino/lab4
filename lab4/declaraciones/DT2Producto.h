#ifndef DT2PRODUCTO_H
#define DT2PRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class DT2Producto {
    private:
        int codigo;
        std::string nombre;
    public:
        //Creadores
        DT2Producto(int,std::string);
        //Getters
        int getCodigo();
        std::string getNombre();
        //Destructor
        ~DT2Producto();
        friend std::ostream &operator<<(std::ostream &salida, DT2Producto const &prod);
};

#endif