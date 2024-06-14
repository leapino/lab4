#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "usuario.h"

class Cliente: public Usuario {
    private:
        std::string direccion;
        std::string ciudad;
        //set de vendedores
        //set de compra
    public:
        Cliente();
        Cliente(std::string dir, std::string ciud);
        void crearLinkV(/* puntero a vendedor*/);
        //mostrarNotificaciones()
        void eliminarVendedores();
        void notificar();
        ~Cliente();
};

#endif