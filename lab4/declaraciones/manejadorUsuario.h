#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>

#include "usuario.h"
#include "vendedor.h"

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
};
#endif
