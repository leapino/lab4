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
        DTFecha fecha;
        DTUsuario *user;
        DTProducto *prod;
        Producto *prodCom;
        Usuario *miUsuario;
    public:
        Comentario();
        Comentario(DTUsuario *user, std::string comment);
        //DTComentario guardarCom (Qué se supone que hace esto?)
        void eliminarLinkUsuario();
        void eliminarLinkProducto();
        ~Comentario();
};

#endif