#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "DTFecha.h"

class Comentario;
class Cliente;
class Vendedor;

class Usuario {
    private:
        std::string nickname;
        std::string password;
        DTFecha fechaNacimiento;
        std::map<std::string,Comentario*> comentarios;
    public:
        //Creadores
        Usuario();
        Usuario(std::string nick, std::string pass, DTFecha fechnaci);
        //Getters
        std::map<std::string,Comentario*> getComentarios();
        std::string getNickname();
        std::string getPassword();
        DTFecha getFecha();
        Cliente* getCliente();
        Vendedor* getVend();
        //Setters
        void setComentarios(std::map<std::string,Comentario*>);
        void setNickname(std::string);
        void setPassword(std::string);
        void setFecha(DTFecha);
        //Funciones
        virtual bool esVendedor();
        virtual bool esCliente();
        std::map<std::string, std::string> listarComentarios();
        void borrarComentario(std::string id);
};
#endif