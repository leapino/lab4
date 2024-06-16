#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>

#include "DTFecha.h"
#include "DTUsuario.h"
#include "DTProducto.h"
#include "producto.h"
#include "usuario.h"

class Comentario {
    private:
        std::string texto;
        DTFecha *fecha;
        Producto *prodCom;
        Usuario *miUsuario;
    public:
        Comentario();
        Comentario(Usuario *miUsuario, DTFecha *fecha, Producto *prodCom , std::string comment);
        Comentario guardarCom (Comentario);
        void eliminarLinkUsuaProd();
        
        ~Comentario();
};

#endif