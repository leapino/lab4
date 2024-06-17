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
        void eliminarVendedores();
        std::list <DTNotificacion *> mostrarNotificaciones();
        void notificar();
        std::string getDireccion();
        std::string getCiudad();
        std::list <Vendedor *> getVendedores();
        std::list <Compra *> getCompras();
        std::list <DTNotificacion *> getDTNotificaciones();
        void setDireccion(std::string dir);
        void setCiudad(std::string city);
        void setUnVendedor(Vendedor *ven);
        void setCompra(Compra *comp);
        void setDTNoti(DTNotificacion *noti);
        void altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciud);
        ~Cliente();
};

#endif