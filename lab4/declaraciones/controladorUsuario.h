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
        void altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciudad);
        void altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string RUT);
        bool estaVacio();
        bool estaUsuario(std::string nombre);
        std::map<int, std::string> listarNickUsuarios();
        std::map<int, std::string> listarComentario(std::string nombreU);
        void eliminarComentario(int id,std::string nombreU);
        std::set <std::string> listarClientes();
        void selectCliente(/*cliente*/);
        std::set <DTProducto>mostrarProductos();
        void agregarProductoCompra(int codigo, int cantidad);
        void confirmarCompra(std::map <int,int> datos,Cliente *cliente,DTFecha *fechaActual);
        Usuario * getUsuario(std::string Usuario);
        //ingresarNickname
        //suscribirVendedores
        //consultarNotificaciones
        //getVendedoresSuscrito
        //seleccionarVendedores
        //eliminarSusVendedores
};

#endif