#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <iostream>
#include "DTFecha.h"
class DTUsuario {
    private:
    std::string DTNickname;
    DTFecha DTNacimiento;
    public:
    //Creadores
    DTUsuario();
    DTUsuario(std::string Nickname, DTFecha fecha);
    //Destructor
    virtual ~DTUsuario();
    //Getters
    std::string getDTNickname();
    DTFecha getDTNacimiento();
    //Setters
    void setDTNickname(std::string nick);
    void setDTNacimiento(DTFecha fecha);
    //Funcion
    friend std::ostream &operator<<(std::ostream &salida, const DTUsuario& user);
};

#endif