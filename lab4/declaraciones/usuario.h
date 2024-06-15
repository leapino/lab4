#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

#include "DTFecha.h"


class Usuario {
    private:
        std::string nickname;
        std::string password;
        DTFecha fechaNacimiento;
    public:
        //Creadores
        Usuario();
        Usuario(std::string nick, std::string pass, DTFecha fechnaci);
        //Getters
        std::string getNickname();
        std::string getPassword();
        DTFecha getFecha();
        //Setters
        void setNickname(std::string);
        void setPassword(std::string);
        void setFecha(DTFecha);
        //Funciones
        bool esVendedor(Usuario);
        bool esUsuario(Usuario);
        bool esCliente(Usuario);

};
#endif