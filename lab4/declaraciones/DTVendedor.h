#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include <iostream>
#include <string>

#include "DTUsuario.h"

class DTVendedor: public DTUsuario {
    private:
    std::string DTRUT;
    public:
    //Creadores
    DTVendedor();
    DTVendedor(std::string Nickname, DTFecha fecha,std::string rut);
    //Destructor
    ~DTVendedor();
    //Getter
    std::string getDTRUT();
    //Setter
    void setDTRUT(std::string rut);
    friend std::ostream &operator<<(std::ostream &salida, const DTVendedor& vend);
};

#endif