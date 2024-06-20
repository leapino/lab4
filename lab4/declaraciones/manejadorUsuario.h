#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "usuario.h"
#include "vendedor.h"
#include "DTCompra.h"
#include "DTCompraProducto.h"
#include "DTPromocion.h"
#include "DTCliente.h"
#include "DTVendedor.h"

class ManejadorUsuario {
    private:
        static ManejadorUsuario* instancia;
        ManejadorUsuario();
        std::map<std::string, Usuario*> Usuarios;
    public:
        static ManejadorUsuario* getInstancia();
        void addUsuario(Usuario*);
        Usuario* getUsuario(std::string);
        std::map<int, std::string> listarNicknamesV();
        std::map<int, std::string> listarNickUsuarios();
        std::set<std::string> getClientes();
        std::map<int, Producto*> getListaProductos(std::string nombre);
        bool estaUsuario(std::string nombre);
        void agregarCompraCliente(Cliente *cliente,Compra* compra);
        void escribirCom(std::string comentario,DTFecha fecha,Producto* codProd,std::string usuario);
        void escribirCom(std::string comentario,DTFecha fecha,Producto* codProd,std::string idCom,std::string usuario);
        Vendedor* getVendedor(std::string v);
        Usuario * getUsuario(std::string Usuario);
        DTUsuario getInfoUsuario(Usuario* usuario);
        DTCliente getInfoCliente(Cliente* usuario);
        DTVendedor getInfoVendedor(Vendedor* usuario);
        std::list <DTCompra*> getInfoComprasCliente(Cliente *cliente);
        std::list<DTProducto*> getProdEnVenta(Vendedor* vendedor);
        std::list<std::string> getVendedoresNoSuscrito(std::string cliente);
        void suscribirVendedores(std::list<std::string> Vendedores,std::string cliente);
        std::list <DTNotificacion*> consultarNotificaciones(std::string cliente);
        std::list<std::string*> getVendedoresSuscrito(std::string cliente);
        std::list<Usuario*> ListarUsuarios();
        void eliminarSusVendedores(std::string cliente, std::string vendedor);
        
        std::map<int, DT2Producto*> getProductosNoEnv(std::string nomVend);
};
#endif
