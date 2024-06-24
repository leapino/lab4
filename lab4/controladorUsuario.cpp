#ifndef CONTROLADORUSUARIO_CPP
#define CONTROLADORUSUARIO_CPP

#include "declaraciones/controladorUsuario.h"



ControladorUsuario* ControladorUsuario::instancia = nullptr;


ControladorUsuario::ControladorUsuario() {};

ControladorUsuario* ControladorUsuario::getInstancia(){
    if (instancia == nullptr){
        instancia = new ControladorUsuario();
    }
        return instancia;
}

std::list<std::string> ControladorUsuario::getVendedores() {
    ManejadorUsuario *mU;
    mU = ManejadorUsuario::getInstancia();
    return mU->getVendedores();

}

std::set<std::string> ControladorUsuario::listarClientes(){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    std::set<std::string> listaClientes=mUsuario->getClientes();
    return listaClientes;
}

void ControladorUsuario::selectCliente(){}

/*std::set<DTProducto> ControladorUsuario::mostrarProductos(){
    return std::set<DTProducto>();
}*/

void ControladorUsuario::agregarProductoCompra(int codigo, int cantidad){}

void ControladorUsuario::confirmarCompra(std::map<int,int > productos,double monto,std::string cliente,DTFecha fechaActual){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    ManejadorProducto * mP=ManejadorProducto::getInstancia();

    Cliente* pCliente=dynamic_cast<Cliente*>(mUsuario->getUsuario(cliente));
    std::list<CompraProducto*> prodEnCompra=mP->confirmarCompra(productos,monto);
    Compra *compra = new Compra(fechaActual, monto, pCliente ,prodEnCompra);
    for(std::list<CompraProducto*>::iterator it = prodEnCompra.begin(); it != prodEnCompra.end(); ++it) {
        (*it)->setCompra(compra);
    }
    
    mUsuario->agregarCompraCliente(pCliente,compra);
}

DTUsuario ControladorUsuario::getInfoUsuario(std::string usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getInfoUsuario(mU->getUsuario(usuario));
}

DTCliente ControladorUsuario::getInfoCliente(std::string usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Cliente* pCliente=dynamic_cast<Cliente*> (mU->getUsuario(usuario));
    return mU->getInfoCliente(pCliente);
}

DTVendedor ControladorUsuario::getInfoVendedor(std::string usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Vendedor* pVendedor=dynamic_cast<Vendedor*> (mU->getUsuario(usuario));
    return mU->getInfoVendedor(pVendedor);
}

std::list<DTCompra> ControladorUsuario::getInfoComprasCliente(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Cliente* pCliente=dynamic_cast<Cliente*> (mU->getUsuario(cliente));
    return mU->getInfoComprasCliente(pCliente);
}

std::list<DTProducto> ControladorUsuario::getProdEnVenta(std::string vendedor){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Vendedor* pVendedor=dynamic_cast<Vendedor*> (mU->getUsuario(vendedor));
    return mU->getProdEnVenta(pVendedor);
}

std::list<std::string> ControladorUsuario::getVendedoresNoSuscrito(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getVendedoresNoSuscrito(cliente);
}

void ControladorUsuario::suscribirVendedores(std::list<std::string> Vendedores, std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    mU->suscribirVendedores(Vendedores,cliente);
}

std::list<DTNotificacion> ControladorUsuario::consultarNotificaciones(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->consultarNotificaciones(cliente);
}

std::list<std::string > ControladorUsuario::getVendedoresSuscrito(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getVendedoresSuscrito(cliente);
}

Usuario * getUsuario(std::string Usuario){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    return mUsuario->getUsuario(Usuario);
}

void ControladorUsuario::altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciudad){
      bool estanom = false;
            if (this->estaVacio() == false)
                 if (this->estaUsuario(nick))
                    estanom = true;
            
            bool contrabien = true;
            if (pass.length()<6)
                contrabien = false;
            
        if ((estanom == false) && (contrabien == true)){
       Cliente* nuevoCliente =new  Cliente(nick,pass,fechnaci,dir,ciudad);       
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       mu->addUsuario(nuevoCliente);
       }
}

void ControladorUsuario::altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string RUT){
       bool estanom = false;
            if (this->estaVacio() == false)
                 if (this->estaUsuario(nick))
                    estanom = true;
            
            bool contrabien = true;
            if (pass.length()<6)
                contrabien = false;
            
        if ((estanom == false) && (contrabien == true)){
       Vendedor* nuevoVendedor =new  Vendedor(nick,pass,fechnaci,RUT);       
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       mu->addUsuario(nuevoVendedor); 
       }
}

bool ControladorUsuario::estaVacio(){
        bool estaV = true;
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        std::map<int ,std::string> nombres = mu->listarNickUsuarios();
        if (nombres.empty() == false)
          estaV = false;
          return estaV;
    }

bool ControladorUsuario::estaUsuario(std::string nombre){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return (mU->getUsuario(nombre)!=nullptr);
}
std::map<int, std::string> ControladorUsuario::listarNickUsuarios()
    {
        ManejadorUsuario *mu;
        mu = ManejadorUsuario::getInstancia();
        return mu->listarNickUsuarios();
    }

std::map<int, std::string> ControladorUsuario::listarComentario(std::string nombreU){
       ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
       Usuario* usuario = mU->getUsuario(nombreU);
       return usuario->listarComentarios();
}

void ControladorUsuario::escribirCom(int idCom,std::string comentario, DTFecha fecha,int codProd, std::string usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    ManejadorProducto * mP=ManejadorProducto::getInstancia();
    Producto * prod=mP->getProducto(codProd);
    int id=mU->getComentarios().size();
    mU->escribirCom(idCom,comentario,fecha,prod,id,usuario);
}

void ControladorUsuario::escribirCom(std::string comentario, DTFecha fecha,int codProd, std::string usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    ManejadorProducto * mP=ManejadorProducto::getInstancia();
    Producto * prod=mP->getProducto(codProd);
    int id=mU->getComentarios().size();
    mU->escribirCom(comentario,fecha,prod,id,usuario);
}

void ControladorUsuario::eliminarComentario(int id,std::string nombreU){
        ManejadorUsuario * mU=ManejadorUsuario::getInstancia();
        mU->eraseRespuestas(id);
        Usuario* usuario = mU->getUsuario(nombreU);
        usuario->borrarComentario(id);
        mU->eraseCom(id);
}

std::list<DTVendedor> ControladorUsuario::ListaUsuariosV(){
        ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->ListarUsuariosV();
}

std::list<DTCliente> ControladorUsuario::ListaUsuariosC(){
        ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->ListarUsuariosC();
}

void ControladorUsuario::eliminarSusVendedores(std::string cliente, std::string vendedor){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    mU->eliminarSusVendedores(cliente,vendedor);
}

bool ControladorUsuario::esCliente(std::string usuario)
{   
    ManejadorUsuario * mU=ManejadorUsuario::getInstancia();
    Cliente * pCliente=dynamic_cast<Cliente*> (mU->getUsuario(usuario));
    return pCliente!=nullptr;
}

std::map<int, DT2Producto> ControladorUsuario::getProductosNoEnv(std::string nomVend)
{
    ManejadorUsuario *mU;
    mU = ManejadorUsuario::getInstancia();
    std::map<int, DT2Producto > productosNoEnviados = mU->getProductosNoEnv(nomVend);
    return productosNoEnviados;
}

Vendedor *ControladorUsuario::getVendedor(std::string v) {
    ManejadorUsuario *mU;
    mU = ManejadorUsuario::getInstancia();
    return mU->getVendedor(v);
}

std::list<DTPromocion> ControladorUsuario::getPromoVigente(std::string vendedor,DTFecha fechaActual){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getPromoVigente(vendedor,fechaActual);
}

//esto esta medio raro no??
std::map<int, std::pair<std::string, DTFecha>> ControladorUsuario:: nickYFechaDeProdNoEnviado(std::string v, int codigoProd){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->nickYFechaDeProdNoEnviado(v, codigoProd);
}

void ControladorUsuario::setProductoEnviado(std::string c, DTFecha f, int id) {
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    return mU->setProductoEnviado(c, f, id);
}

void ControladorUsuario::limpiarNotificaciones(std::string cliente)
{
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Cliente* client=dynamic_cast<Cliente*> (mU->getUsuario(cliente));
    client->limpiarNotificaciones();
}
#endif