#ifndef COMPRA_H
#define COMPRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <map>
#include <list>

#include "DTFecha.h"
#include "DTCliente.h"
#include "DTProducto.h"
#include "compraProducto.h"

class Cliente;
class CompraProducto;

class Compra {
    private:
        DTFecha fecha;
        int monto;
        Cliente *cliente;
        std::list<CompraProducto *> compraProductos;
    public:
        Compra();
        Compra(DTFecha fecha, int monto, Cliente *cliente, std::list<CompraProducto*> compraPr);
        DTFecha getFecha();
        int getMonto();
        Cliente *getCliente();
        std::list<CompraProducto *> getcompraProductos();
        void setFecha(DTFecha fecha);
        void setMonto(int mont);
        void setCliente(Cliente *client);
        void agregarProdCompra(CompraProducto *comPro);
        void subirMonto(int precio);
        ~Compra();
};

#endif