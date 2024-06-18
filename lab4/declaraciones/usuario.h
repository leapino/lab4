#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>

#include "DTFecha.h"
#include "producto.h"

class Usuario {
    private:
        std::string nickname;
        std::string password;
        DTFecha fechaNacimiento;
        std::map<int,Comentario> comentarios;
    public:
        //Creadores
        Usuario();
        Usuario(std::string nick, std::string pass, DTFecha fechnaci);
        //Getters
        std::map<int,Comentario> getComentarios();
        std::string getNickname();
        std::string getPassword();
        DTFecha getFecha();
        //Setters
        void setComentarios(int,Comentario);
        void setNickname(std::string);
        void setPassword(std::string);
        void setFecha(DTFecha);
        //Funciones
        virtual bool esVendedor();
        virtual bool esUsuario(Usuario);
        virtual bool esCliente();


};
#endif