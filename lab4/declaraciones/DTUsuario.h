#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include "../declaraciones/DTCliente.h"
#include "../declaraciones/DTVendedor.h"
class DTUsuario {
    private:
    bool DTesCliente;
    std::string DTNickname;
    DTFecha DTNacimiento;
    DTCliente * pDTCliente; 
    DTVendedor * pDTVendedor;
};

#endif