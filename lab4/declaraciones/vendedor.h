#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <set>

#include "usuario.h"
#include "cliente.h"
#include "producto.h"

class Vendedor: public Usuario {
    private:
        std::string RUT;
        std::map<int, Producto*> Productos;
        std::list<Cliente *> Clientes;
    public:
        //Creadores
        Vendedor();
        Vendedor(std::string nombre, std::string contra,DTFecha fechaNac,std::string RUT);
        ~Vendedor();
        //Getters
        std::string getRUT();
        std::map<int, Producto*> getProductos();
        std::list<Cliente *> getClientes();
        //Setters
        void setRUT(std::string);
        void setProductos(std::map<int, Producto*>);
        void setClientes(std::list<Cliente *>);
        //Funciones
        void crearLinkC(Cliente * cliente);
        void desuscribirse(Cliente); 
        
};
#endif