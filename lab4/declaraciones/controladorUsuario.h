#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include "manejadorUsuario.h"
#include "manejadorProducto.h"

class ControladorUsuario {
    private:
        static ControladorUsuario *instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario *getInstancia();
        std::list< std::string *> getVendedores();
        virtual  void altaDeUsuario();
        bool estaVacio();
        bool estaUsuario(std::string nombre);
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