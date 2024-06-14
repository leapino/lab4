#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include "../declaraciones/DTCliente.h"
#include "../declaraciones/DTVendedor.h"
#include "../declaraciones/DTFecha.h"
class DTUsuario {
    private:
    bool DTesCliente;
    std::string DTNickname;
    DTFecha DTNacimiento;
    DTCliente * pDTCliente; 
    DTVendedor * pDTVendedor;
    public:
    //Creadores
    DTUsuario();
    DTUsuario(bool esCliente, std::string Nickname, DTFecha fecha, DTCliente *cliente, DTVendedor *vendedor);
    //Destructor
    ~DTUsuario();
    //Getters
    bool getDTesCliente();
    std::string getDTNickname();
    DTFecha getDTNacimiento();
    DTCliente * getpDTCliente();
    DTVendedor * getpDTVendedor();
    //Setters
    void setDTesCliente(bool check);
    void setDTNickname(std::string nick);
    void setDTNacimiento(DTFecha fecha);
    void setpDTCliente(DTCliente* cliente);
    void setpDTVendedor(DTVendedor* vendedor);
};

#endif