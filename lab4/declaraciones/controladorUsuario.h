#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include "manejadorUsuario.h"
#include "manejadorProducto.h"
#include "DTCompra.h"

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
        std::map<std::string, std::string> listarComentario(std::string nombreU);
        void escribirCom(std::string comentario,DTFecha fecha,Producto* codProd,std::string usuario);
        //void escribirCom(std::string comentario,DTFecha fecha,Producto* codProd,std::string idCom,std::string usuario);
        void eliminarComentario(std::string id,std::string nombreU);
        std::set <std::string> listarClientes();
        void selectCliente(/*cliente*/);
        std::set <DTProducto>mostrarProductos();
        std::map<int, DT2Producto> getProductosNoEnv(std::string nomVend);
        void agregarProductoCompra(int codigo, int cantidad);
        void confirmarCompra(std::map <int,int > productos,int &monto,std::string cliente,DTFecha fechaActual);
        Usuario * getUsuario(std::string Usuario);
        DTUsuario getInfoUsuario(Usuario* usuario);
        DTCliente getInfoCliente(Usuario* usuario);
        DTVendedor getInfoVendedor(Usuario* usuario);
        std::list<DTCompra> getInfoComprasCliente(Cliente* cliente);
        std::list<DTProducto> getProdEnVenta(Vendedor* vendedor);
        std::list<std::string> getVendedoresNoSuscrito(std::string cliente);
        //ingresarNickname
        void suscribirVendedores(std::list<std::string> Vendedores,std::string cliente);
        std::list<DTNotificacion> consultarNotificaciones(std::string cliente);
        std::list<std::string> getVendedoresSuscrito(std::string cliente);
        std::list<DTUsuario> ListaUsuarios();
        std::list<DTPromocion> getPromoVigente(std::string vendedor,DTFecha fechaActual);
        //seleccionarVendedores
        void eliminarSusVendedores(std::string cliente, std::string vendedor);
        Vendedor* getVendedor(std::string v);
};

#endif
