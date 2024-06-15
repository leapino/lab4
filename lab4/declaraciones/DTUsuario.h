#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include "../declaraciones/DTCliente.h"
#include "../declaraciones/DTVendedor.h"
#include "../declaraciones/DTFecha.h"
class DTUsuario {
    private:
    std::string DTNickname;
    DTFecha DTNacimiento;
    public:
    //Creadores
    DTUsuario();
    DTUsuario(std::string Nickname, DTFecha fecha);
    //Destructor
    ~DTUsuario();
    //Getters
    std::string getDTNickname();
    DTFecha getDTNacimiento();
    //Setters
    void setDTesCliente(bool check);
    void setDTNickname(std::string nick);
    void setDTNacimiento(DTFecha fecha);
};

#endif