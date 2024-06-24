#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "DTFecha.h"
#include "comentario.h"


class Comentario;
class Cliente;

class Usuario {
    private:
        std::string nickname;
        std::string password;
        DTFecha fechaNacimiento;
        std::list<Comentario*> comentarios;
    public:
        //Creadores
        Usuario();
        Usuario(std::string nick, std::string pass, DTFecha fechnaci);
        //Getters
        std::list<Comentario*> getComentarios();
        std::string getNickname();
        std::string getPassword();
        DTFecha getFecha();
        //Setters
        void setComentarios(Comentario*);
        void setNickname(std::string);
        void setPassword(std::string);
        void setFecha(DTFecha);
        //Funciones
        //virtual bool esVendedor()=0;
        //virtual bool esCliente()=0;
        std::list<std::string> listarComentarios();
        void borrarComentario(int id);
        void agregarComentario(Comentario* comm);
        virtual ~Usuario();
};
#endif