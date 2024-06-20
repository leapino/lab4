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
        std::string idcom;
        std::map<std::string,Comentario*> respuestas;
    public:
        Comentario();
        Comentario(Usuario *miUsuario, DTFecha *fecha, Producto *prodCom , std::string comment);
        std::map<std::string,Comentario*> getRespuestas();
        std::string getTexto();
        DTFecha *getFecha();
        Producto *getProdCom();
        Usuario *getUsuario();
        std::string getIdcom();
        void setRespuestas(std::map<std::string,Comentario*> respuesta);
        void setTexto(std::string text);
        void setFecha(DTFecha *fecha);
        void setProdComentado(Producto *prod);
        void setMiUsuario(Usuario *miUser);
        void setIdCom(std::string id);
        void borrarRespuestas();
        void agregarRespuesta(Comentario comm);
        ~Comentario();
};

#endif