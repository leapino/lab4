#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include "manejadorUsuario.h"
#include "manejadorProducto.h"
#include "usuario.h"
#include "cliente.h"
#include "vendedor.h"


class ControladorUsuario {
    private:
        static ControladorUsuario *instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario *getInstancia();
        std::list< std::string > getVendedores();
        void altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciudad);
        void altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string RUT);
        bool estaVacio();
        bool estaUsuario(std::string nombre);
        std::map<int, std::string> listarNickUsuarios();
        std::map<int, std::string> listarComentario(std::string nombreU);
        void escribirCom(int idCom,std::string comentario,DTFecha fecha,int codProd,std::string usuario);
        void escribirCom(std::string comentario,DTFecha fecha,int codProd,std::string usuario);
        //void escribirCom(std::string comentario,DTFecha fecha,Producto* codProd,std::string idCom,std::string usuario);
        void eliminarComentario(int id,std::string nombreU);
        std::set <std::string> listarClientes();
        void selectCliente(/*cliente*/);
        std::set <DTProducto>mostrarProductos();
        bool esCliente(std::string usuario);//retorna true si es cliente
        std::map<int, DT2Producto> getProductosNoEnv(std::string nomVend);
        void agregarProductoCompra(int codigo, int cantidad);
        void confirmarCompra(std::map <int,int > productos, double monto,std::string cliente,DTFecha fechaActual);
        DTUsuario getInfoUsuario(std::string usuario);
        DTCliente getInfoCliente(std::string usuario);
        DTVendedor getInfoVendedor(std::string usuario);
        std::list<DTCompra> getInfoComprasCliente(std::string cliente);
        std::list<DTProducto> getProdEnVenta(std::string vendedor);
        std::list<std::string> getVendedoresNoSuscrito(std::string cliente);
        //ingresarNickname
        void suscribirVendedores(std::list<std::string> Vendedores,std::string cliente);
        std::list<DTNotificacion> consultarNotificaciones(std::string cliente);
        std::list<std::string> getVendedoresSuscrito(std::string cliente);
        std::list<DTVendedor> ListaUsuariosV();
        std::list<DTCliente> ListaUsuariosC();
        std::list<DTPromocion> getPromoVigente(std::string vendedor,DTFecha fechaActual);
        //seleccionarVendedores
        void eliminarSusVendedores(std::string cliente, std::string vendedor);
        Vendedor* getVendedor(std::string v);
        std::map<int, std::pair<std::string, DTFecha>> nickYFechaDeProdNoEnviado(std::string v, int codigoProd);
        void setProductoEnviado(std::string c, DTFecha f, int id);
        void limpiarNotificaciones(std::string cliente);
};

#endif
