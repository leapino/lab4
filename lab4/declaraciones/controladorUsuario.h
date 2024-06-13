#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

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
        //listarClientes
        void selectCliente(/*cliente*/);
        //mostrarProductos
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