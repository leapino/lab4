#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

class DTVendedor: public DTUsuario {
    private:
    std::string DTRUT;
    public:
    //Creadores
    DTVendedor();
    DTVendedor(std::string rut);
    //Destructor
    ~DTVendedor();
    //Getter
    std::string getDTRUT();
    //Setter
    void setDTRUT(std::string rut);
};

#endif