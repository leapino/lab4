#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <set>

#include "DTFecha.h"
#include "manejadorUsuario.h"
#include "manejadorProducto.h"
#include "controladorFecha.h"

class ControladorProducto {
    private: 
        static ControladorProducto *instancia;
        ControladorProducto();
    public:
        static ControladorProducto *getInstancia();
        //void ingrDatosPromocion(std::string nombreP,std::string descripcionP,float descuentoP,DTFecha fechaP);
        std::map<int ,std::string> listarNicknamesV(); //Devuelve un map<int, std::string> con los nicknames de los vendedores
        std::map<int, DT2Producto> listarProductos(std::string RUTVendedor); //Devuelve un set de DT2Producto con codigo y nombre asociado a los productos del vendedor
        void confirmarAltaPromocion(std::string,std::string,float,DTFecha,std::map<int, int>);
        std::set<DTProducto> getProductosDisp();
        std::map<std::string,DTProducto> getInfoProd(std::string producto);//Devuelve un DT del producto y en la casilla de string el nickname del vendedor
        std::map<int,std::string> getProds();//Retorna el codigo y el nombre de todos los productos
        bool hayStock(int codigoP,int cantidad);
        std::list <DTComentario> listarComProd(int codProd);
        void prodEnCompra(std::map<int,int> prods);
        std::list<DTComentario> listarComProd(int codProd);
        //std::list<CompraProducto*> confirmarCompra(std::map<int, int> datos, int &monto); se paso esta funcion al controlador Usuario
        bool checkPromo(int);
        std::map<std::string, DTPromocion> getPromos();
        std::set<DTProducto> getProductoPromo(std::string);
        DTVendedor vendedorPromo(DTProducto);
        void escribirCom(std::string comment,DTFecha fecha,int codProd,std::string usuario,int idCom);
        std::list<DTPromocion*> getPromoVigente(std::string vendedor,DTFecha fechaActual);
        void agregarPromoVendedor(std::string,std::string);
        void altaDeProducto(std::string nombre,int precio,int stock,std::string desc,Categoria categoria);
        void linkVendProd(std::string nombV);
};

#endif