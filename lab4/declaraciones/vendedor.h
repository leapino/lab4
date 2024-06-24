#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <list>

#include "usuario.h"
#include "promocion.h"
#include "cliente.h"

class Producto;
class Promocion;


class Vendedor: public Usuario {
    private:
        std::string RUT;
        std::map<int, Producto*> Productos;
        std::list<Cliente *> Clientes;
        std::map <std::string,Promocion*> promociones;
    public:
        //Creadores
        Vendedor();
        Vendedor(std::string nombre, std::string contra,DTFecha fechaNac,std::string RUT);
        ~Vendedor();
        //Getters
        std::string getRUT();
        std::map<int, Producto*> getProductos();
        std::list<Cliente *> getClientes();
        std::map<std::string,Promocion*> getPromociones();
        std::list<DTProducto> getDTProds();
        std::list<DTPromocion> getDTPromocion();
        //Setters
        void setRUT(std::string);
        void setProductos(std::map<int, Producto*>);
        void setClientes(std::list<Cliente *>);
        void setPromociones(std::map<std::string,Promocion*> promos);
        void addPromo(Promocion*);
        //Funciones
        void crearLinkC(Cliente * cliente);
        void eliminarLinkC(std::string client); 
        void setProductos(int, Producto*);
        //bool esVendedor() override { return true; }
       // bool esCliente() override { return false; }
        
};
#endif