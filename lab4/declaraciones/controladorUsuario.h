#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include "manejadorUsuario.h"

class ControladorUsuario {
    private:
        static ControladorUsuario *instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario *getInstancia();
        //getVendedores
        bool altaDeUsuario();
        //listarUsuarios
        //listarComentario
        void eliminarComentario(/*wea*/);
        std::set <std::string> listarClientes();
        void selectCliente(/*cliente*/);
        std::set <DTProducto>mostrarProductos();
        void agregarProductoCompra(/*prod*/);
        void confirmarCompra();
        //ingresarNickname
        //suscribirVendedores
        //consultarNotificaciones
        //getVendedoresSuscrito
        //seleccionarVendedores
        //eliminarSusVendedores
};

#endif