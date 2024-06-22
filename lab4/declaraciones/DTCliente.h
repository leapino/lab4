#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include "DTUsuario.h"
#include "DTFecha.h"

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
    //funcion
    friend std::ostream &operator<<(std::ostream &salida, DTCliente  client);
};

#endif