#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "usuario.h"

class ManejadorUsuario {
    private:
        static ManejadorUsuario* instancia;
        ManejadorUsuario();
        std::map<std::string, Usuario*> Usuarios;
    public:
        static ManejadorUsuario* getInstancia();
};
#endif