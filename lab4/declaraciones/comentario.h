#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "DTFecha.h"

class Comentario {
    private:
        std::string texto;
        DTFecha fecha;
        DTUsuario *user;
        DTProducto *prod;
    public:
        Comentario(DTUsuario *user, std::string comment);
        //DTComentario guardarCom;
        void eliminarLinkUsuario();
        void eliminarLinkProducto();
        ~Comentario();
};

#endif