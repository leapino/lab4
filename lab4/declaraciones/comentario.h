#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <list>
#include <map>
#include <vector>

#include "DTFecha.h"
#include "DTUsuario.h"
#include "DTProducto.h"
#include "producto.h"
#include "DTComentario.h"

class Producto;
class Usuario;

class Comentario {
    private:
        std::string texto;
        DTFecha fecha;
        Producto *prodComentado;
        Usuario *miUsuario;
        int idcom;
        std::list<Comentario*> respuestas;
    public:
        Comentario();
        Comentario(Usuario *miUsuario, DTFecha fecha, Producto *prodCom , std::string comment,int idcom);
        std::list<Comentario*> getRespuestas();
        std::string getTexto();
        DTFecha getFecha();
        Producto *getProdCom();
        Usuario *getUsuario();
        std::list<DTComentario> getDTRespuestas();
        int getIdcom();
        void setRespuestas(std::list<Comentario*> respuesta);
        void setTexto(std::string text);
        void setFecha(DTFecha fecha);
        void setProdComentado(Producto *prod);
        void setMiUsuario(Usuario *miUser);
        void setIdCom(int id);
        void borrarRespuestas();
        void agregarRespuesta(Comentario* comm);
        ~Comentario();
};

#endif