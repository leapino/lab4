#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "usuario.h"
#include "cliente.h"

class Vendedor: public Usuario {
    private:
        std::string RUT;
    public:
        //Creadores
        Vendedor();
        Vendedor(std::string, std::string, DTFecha,std::string);
        ~Vendedor();
        //Getters
        std::string getRUT();
        //Setters
        void setRUT(std::string);
        //Funciones
        bool estaSuscripto(std::string);
        //void crearLink()
        void desuscribirse(Cliente);

};
#endif