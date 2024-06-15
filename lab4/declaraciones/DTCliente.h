#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include "DTUsuario.h"

class DTCliente: public DTUsuario {
    private:
    std::string DTAdress;
    std::string DTCiudad;
    public:
    //Creadores
    DTCliente();
    DTCliente(std::string Nickname, DTFecha fecha,std::string direc,std::string Ciudad);
    //Destructor
    ~DTCliente();
    //Getters
    std::string getDTAdress();
    std::string getDTCiudad();
    //Setters
    void setDTAdress(std::string direc);
    void setDTCiudad(std::string ciudad);
};

#endif