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
        //Creadores
        Cliente();
        Cliente(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciud);
        //getters
        std::string getDireccion();
        std::string getCiudad();
        std::list <Vendedor *> getVendedores();
        std::list <Compra *> getCompras();
        std::list <DTNotificacion *> getDTNotificaciones();
        //setters
        void setDireccion(std::string dir);
        void setCiudad(std::string city);
        void setUnVendedor(Vendedor *ven);
        void setCompra(Compra *comp);
        void setDTNoti(DTNotificacion *noti);
        //funciones
        void crearLinkV(Vendedor *);
        void eliminarVendedores();
        std::list <DTNotificacion *> mostrarNotificaciones();
        void notificar();
        void agregarCompra(Compra* Compra);
        //destructor
        ~Cliente();
};

#endif