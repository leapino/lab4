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
#include <utility>

#include "DTFecha.h"
#include "DTCompra.h"
#include "DTCompraProducto.h"
#include "DTPromocion.h"
#include "DTCliente.h"
#include "DTVendedor.h"
#include "DTComentario.h"
#include "DTNotificacion.h"
#include "compra.h"
#include "promocion.h"
#include "DT2Producto.h"
#include "usuario.h"
#include "cliente.h"
#include "vendedor.h"


class Comentario;

class ManejadorUsuario {
    private:
        static ManejadorUsuario* instancia;
        ManejadorUsuario();
        std::map<std::string, Usuario*> Usuarios;
        std::list< Comentario*> Comentarios;
    public:
        static ManejadorUsuario* getInstancia();
        void addUsuario(Usuario*);
        std::map<int, std::string> listarNicknamesV();
        std::map<int, std::string> listarNickUsuarios();
        std::set<std::string> getClientes();
        std::map<int, Producto*> getListaProductos(std::string nombre);
        bool estaUsuario(std::string nombre);
        void agregarCompraCliente(Cliente *cliente,Compra* compra);
        void escribirCom(std::string comentario,DTFecha fecha,Producto* codProd,int id,std::string usuario);
        void escribirCom(int idCom,std::string comentario,DTFecha fecha,Producto* codProd,int id,std::string usuario);
        Vendedor* getVendedor(std::string v);
        Usuario * getUsuario(std::string usuario);
        std::list<Comentario*> getComentarios();
        DTUsuario getInfoUsuario(Usuario* usuario);
        DTCliente getInfoCliente(Cliente* usuario);
        DTVendedor getInfoVendedor(Vendedor* usuario);
        std::list <DTCompra> getInfoComprasCliente(Cliente *cliente);
        std::list<DTProducto> getProdEnVenta(Vendedor* vendedor);
        std::list<std::string> getVendedoresNoSuscrito(std::string cliente);
        void suscribirVendedores(std::list<std::string> Vendedores,std::string cliente);
        std::list <DTNotificacion> consultarNotificaciones(std::string cliente);
        std::list<std::string> getVendedoresSuscrito(std::string cliente);
        std::list<DTVendedor> ListarUsuariosV();
        std::list<DTCliente> ListarUsuariosC();
        void eliminarSusVendedores(std::string cliente, std::string vendedor);
        std::list<DTPromocion> getPromoVigente(std::string vendedor,DTFecha fechaActual);
        void eraseRespuestas(int id);
        std::map<int, DT2Producto> getProductosNoEnv(std::string nomVend);
        std::map<int, std::pair<std::string, DTFecha>> nickYFechaDeProdNoEnviado(std::string v, int codigoProd);
        void setComentarios(std::list<Comentario*> comm);
        std::list< std::string > getVendedores();
        void setProductoEnviado(std::string c, DTFecha f, int id);
        void mandarNotificacion(std::string nombreP, std::string nombreV, std::list<DTProducto> productos);
};
#endif
