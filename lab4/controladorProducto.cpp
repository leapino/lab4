#ifndef CONTROLADORPRODUCTO_CPP
#define CONTROLADORPRODUCTO_CPP

#include "declaraciones/controladorProducto.h"


ControladorProducto* ControladorProducto::instancia = NULL;

ControladorProducto* ControladorProducto::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorProducto();
    }
        return instancia;
}

std::map<int ,std::string> ControladorProducto::listarNicknamesV(){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->listarNicknamesV();
}

std::map<int , DT2Producto> ControladorProducto::listarProductos(std::string nombre){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    std::map<int, Producto*> lista = mu->getListaProductos(nombre);
    return mp->listarProductos(lista);
}

std::set<DTProducto> ControladorProducto::getProductosDisp(){
    ManejadorProducto *mP;
    mP=ManejadorProducto::getInstancia();
    std::set<DTProducto>listaProductosDisp=mP->getProductosDisp();
    return listaProductosDisp;
}


std::map<std::string, DTProducto> ControladorProducto::getInfoProd(std::string producto){
    ManejadorProducto *mP=ManejadorProducto::getInstancia();
    return mP->getInfoProd(producto);
}
std::map<int, std::string> ControladorProducto::getProds(){
    ManejadorProducto *mP=ManejadorProducto::getInstancia();
    return mP->getProds();
}

bool ControladorProducto::hayStock(int codigoP, int cantidad){
    ManejadorProducto *mP;
    mP=ManejadorProducto::getInstancia();
    bool res=mP->hayStock(codigoP,cantidad);
    return ;
}

void ControladorProducto::prodEnCompra(std::map<int,int> prods){
    ManejadorProducto*mP=ManejadorProducto::getInstancia();
    for (auto i = prods.begin(); i!=prods.end(); i++){
        Producto* prod=mP->getProducto(i->first);
        mP->prodEnCompra(prod,i->second);       
    }
}

bool ControladorProducto::checkPromo(int codigo){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->checkPromo(codigo);
}

void confirmarAltaPromocion(std::string nombreP,std::string descriP,float descuento,DTFecha fecha,std::map<int, int> infoProd){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    mp->confirmarAltaPromocion(nombreP, descriP, descuento, fecha, infoProd);
}

std::map<std::string, DTPromocion> ControladorProducto::getPromos(){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    ControladorFecha* cf;
    cf = ControladorFecha::getInstancia();
    std::map<std::string, Promocion*>::iterator it;
    std::map<std::string, DTPromocion> dtpromociones;
    for (it = mp->getPromos().begin(); it != mp->getPromos().end(); it++){
        if (cf->esVigente(it->second->getFecha())){
            DTPromocion dtpromo = DTPromocion(it->second->getNombre(), it->second->getDescripcion(), it->second->getFecha());
            dtpromociones.insert({it->second->getNombre(), dtpromo});
        }
    }
    return dtpromociones;
}

std::set<DTProducto> ControladorProducto::getProductoPromo(std::string nombrePromo){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    mp->getProductoPromo(nombrePromo);
}

DTVendedor ControladorProducto::vendedorPromo(DTProducto producto){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->vendedorPromo(producto);
}

void ControladorProducto::escribirCom(std::string comment,DTFecha fecha,int codProd,std::string usuario,int idCom){
    ManejadorProducto * mP=ManejadorProducto::getInstancia();
    ManejadorUsuario * mU=ManejadorUsuario::getInstancia();
    Usuario* user=mU->getUsuario(usuario);
    mP->escribirCom(comment,fecha,codProd,user,idCom);    
}

#endif