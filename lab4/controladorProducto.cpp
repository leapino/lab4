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

void ControladorProducto::confirmarAltaPromocion(std::string nombreP,std::string descriP,float descuento,DTFecha fecha,std::map<int, int> infoProd, std::string nombreV){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    mp->confirmarAltaPromocion(nombreP, descriP, descuento, fecha, infoProd);
    Vendedor* vend=mu->getVendedor(nombreV);
    vend->addPromo(mp->getPromos().find(nombreP)->second);
    std::list<DTProducto> dtProductos;
    std::map<int, int>::iterator it;
    for (it = infoProd.begin(); it != infoProd.end(); ++it){
        DTProducto dtProd = mp->getProducto((*it).first)->getData();
        dtProductos.push_back(dtProd);
    }
    mu->mandarNotificacion(nombreP, nombreV, dtProductos);
}

std::map<std::string, DTPromocion> ControladorProducto::getPromos(){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    ControladorFecha* cf;
    cf = ControladorFecha::getInstancia();
    std::map<std::string, Promocion*>::iterator it;
    std::map<std::string, Promocion*> promos = mp->getPromos();
    std::map<std::string, DTPromocion> dtpromociones;
    for (it = promos.begin(); it != promos.end(); ++it){
        if (it->second->getFecha().esVigente(cf->getFecha())){
            DTPromocion dtpromo = DTPromocion(it->second->getNombre(), it->second->getDescripcion(), it->second->getFecha(),(*it->second->getProdProm().begin())->getDescuento());
            std::set<ProductoPromocion *> prodProm = it->second->getProdProm();
            std::set<ProductoPromocion *>::iterator it2;
            for (it2 = prodProm.begin(); it2 != prodProm.end(); ++it2){
                dtpromo.addProducto((*it2)->getProducto()->getData());
            }
            dtpromociones.insert(std::make_pair(it->second->getNombre(), dtpromo));
        }
    }
    return dtpromociones;
}

DTVendedor ControladorProducto::vendedorPromo(DTProducto producto){
    ManejadorProducto* mp;
    mp = ManejadorProducto::getInstancia();
    return mp->vendedorPromo(producto);
}

void ControladorProducto::altaDeProducto(std::string nombre,double precio,int stock,std::string desc,Categoria categoria){
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