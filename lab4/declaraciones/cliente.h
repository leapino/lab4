#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>

#include "DTNotificacion.h"
#include "compra.h"
#include "usuario.h"
#include "DTCompra.h"
#include "vendedor.h"

class Compra;
class Usuario;

class Cliente: public Usuario {
    private:
        std::string direccion;
        std::string ciudad;
        std::list <Vendedor *> Vendedores;
        std::list <Compra *> Compras;
        std::list <DTNotificacion > Notificaciones;
    public:
        //Creadores
        Cliente();
        Cliente(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciud);
        //getters
        std::string getDireccion();
        std::string getCiudad();
        std::list <Vendedor *> getVendedores();
        std::list <Compra *> getCompras();
        std::list <DTNotificacion > getDTNotificaciones();
        //setters
        void setDireccion(std::string dir);
        void setCiudad(std::string city);
        void setUnVendedor(Vendedor *ven);
        void setCompra(Compra *comp);
        void setDTNoti(std::list<DTNotificacion> noti);
        //funciones
        void crearLinkV(Vendedor * Vendedor);
        void eliminarLinkV(std::string vend);
        void eliminarVendedores();
        void limpiarNotificaciones();
        void notificar();
        void agregarCompra(Compra* Compra);
        std::list <DTCompra> getDTCompras();
        //destructor
        ~Cliente();
       // bool esVendedor() override { return false; };
       // bool esCliente() override { return true; };
};

#endif