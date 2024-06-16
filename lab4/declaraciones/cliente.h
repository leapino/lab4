#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>

#include "usuario.h"
#include "vendedor.h"
#include "compra.h"
#include "DTNotificacion.h"

class Cliente: public Usuario {
    private:
        std::string direccion;
        std::string ciudad;
        std::list <Vendedor *> Vendedores;
        std::list <Compra *> Compras;
        std::list <DTNotificacion *> Notificaciones;
    public:
        Cliente();
        Cliente(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciud);
        void crearLinkV(Vendedor *);
        std::list <DTNotificacion *> mostrarNotificaciones();
        void eliminarVendedores();
        void notificar();
        ~Cliente();
};

#endif