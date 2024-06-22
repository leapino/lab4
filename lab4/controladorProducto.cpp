#ifndef CONTROLADORPRODUCTO_CPP
#define CONTROLADORPRODUCTO_CPP

#include "declaraciones/controladorProducto.h"



ControladorProducto* ControladorProducto::instancia = NULL;

ControladorProducto::ControladorProducto() {};

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


std::list<DTComentario> ControladorProducto::listarComProd(int codProd)
{
    ManejadorProducto* mP=ManejadorProducto::getInstancia();
    Producto* prod=mP->getProducto(codProd);
    return mP->listarComProd(prod->getComentarios());
}


std::map<int , DT2Producto> ControladorProducto::listarProductos(std::string nombre){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    std::map<int, Producto*> lista = mu->getListaProductos(nombre);
    return mp->listarProductos(lista);
}

void ControladorProducto::confirmarAltaPromocion(std::string nombreP, std::string descriP, float descuento, DTFecha fecha, std::map<int, int> infoProd)
{
}
std::set<DTProducto> ControladorProducto::getProductosDisp()
{
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
    return res ;
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
    std::map<std::string, Promocion*>::iterator it;
    std::map<std::string, DTPromocion> dtpromociones;
    for (it = mp->getPromos().begin(); it != mp->getPromos().end(); it++){
        if (it->second->getFecha().esVigente()){
            DTPromocion dtpromo = DTPromocion(it->second->getNombre(), it->second->getDescripcion(), it->second->getFecha());
            dtpromociones.insert({it->second->getNombre(), dtpromo});
        }
    }
    return dtpromociones;
}

std::set<DTProducto> ControladorProducto::getProductoPromo(std::string nombrePromo){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->getProductoPromo(nombrePromo);
}

DTVendedor ControladorProducto::vendedorPromo(DTProducto producto){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->vendedorPromo(producto);
}

void ControladorProducto::agregarPromoVendedor(std::string promo,std::string vendedor){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    Vendedor* vend=mu->getVendedor(vendedor);
    vend->addPromo(mp->getPromos().find(promo)->second);
}

void ControladorProducto::altaDeProducto(std::string nombre,int precio,int stock,std::string desc,Categoria categoria){
       Producto* nuevoProducto =new Producto(stock,precio,nombre,desc,categoria);       
       ManejadorProducto* mp = ManejadorProducto::getInstancia();
       mp->addProducto(nuevoProducto);
}

void ControladorProducto::linkVendProd(std::string nombV){
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       Vendedor* vendedor = mu->getVendedor(nombV);
       ManejadorProducto* mp = ManejadorProducto::getInstancia();
       Producto* prod = mp->finalProd();
       prod->setVendedor(vendedor);
       int cod = prod->getCodigo();
       vendedor->setProductos(cod,prod);
}



#endif