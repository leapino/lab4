#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class Cliente: public Usuario {
    private:
        std::string direccion;
        std::string ciudad;
        //notificaciones
        //set de vendedores
        //set de compra
    public:
        Cliente();
        Cliente(std::string dir, std::string ciud, /*notis*/);
        void crearLinkV(/* puntero a vendedor*/);
        //mostrarNotificaciones()
        void eliminarVendedores();
        void notificar();
        ~Cliente();
};

#endif