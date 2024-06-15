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
        std::set<std::string> listarNicknames();
        std::set<int> getListaProductos(std::string nombre);
};
#endif