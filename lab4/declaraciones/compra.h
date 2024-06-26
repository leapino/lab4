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
#include "DTCompraProducto.h"
#include "DTCompra.h"
#include "cliente.h"

class CompraProducto;
class Cliente;

class Compra {
    private:
        DTFecha fecha;
        double monto;
        Cliente *cliente;
        std::list<CompraProducto *> compraProductos;
        int IdCompra;
    public:
        Compra();
        Compra(DTFecha fecha, double monto, Cliente *cliente, std::list<CompraProducto*> compraPr);
        DTFecha getFecha();
        double getMonto();
        Cliente *getCliente();
        std::list<CompraProducto *> getcompraProductos();
        int getIdCompra();
        void setFecha(DTFecha fecha);
        void setMonto(double mont);
        void setCliente(Cliente *client);
        void agregarProdCompra(CompraProducto *comPro);
        void subirMonto(double precio);
        void setIdcompra(int idC);
        DTCompra getData();
        ~Compra();
};


#endif