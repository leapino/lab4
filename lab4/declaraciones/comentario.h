#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>
#include <map>

#include "DTFecha.h"
#include "DTUsuario.h"
#include "DTProducto.h"
#include "producto.h"
#include "usuario.h"

class Comentario {
    private:
        std::string texto;
        DTFecha *fecha;
        Producto *prodComentado;
        Usuario *miUsuario;
        int idcom;
    public:
        Comentario();
        Comentario(Usuario *miUsuario, DTFecha *fecha, Producto *prodCom , std::string comment);
        std::string getTexto();
        DTFecha *getFecha();
        Producto *getProdCom();
        Usuario *getUsuario();
        int getIdcom();
        void setTexto(std::string text);
        void setFecha(DTFecha *fecha);
        void setProdComentado(Producto *prod);
        void setMiUsuario(Usuario *miUser);
        void setIdCom(int id);
        ~Comentario();
};

#endif