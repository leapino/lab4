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

DTCompra ControladorUsuario::confirmarCompra(std::map<int,int > productos,double &monto,std::string cliente,DTFecha fechaActual){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    ManejadorProducto * mP=ManejadorProducto::getInstancia();

    Cliente* pCliente=dynamic_cast<Cliente*>(mUsuario->getUsuario(cliente));
    std::list<CompraProducto*> prodEnCompra=mP->confirmarCompra(productos,monto);
    // std::cout << "tamanio lista" << prodEnCompra.size();
    Compra *compra = new Compra(fechaActual, monto, pCliente ,prodEnCompra);

    for(std::list<CompraProducto*>::iterator it = prodEnCompra.begin(); it != prodEnCompra.end(); ++it) {
        (*it)->setCompra(compra);
    }
    
    mUsuario->agregarCompraCliente(pCliente,compra);

    std::list<DTCompraProducto> DTProds;
    for (std::list<CompraProducto*>::iterator it2=prodEnCompra.begin(); it2!=prodEnCompra.end(); it2++)
    {   
        DTProds.push_back((*it2)->getData());               
    }
    
    return DTCompra (fechaActual,monto,DTProds,compra->getIdCompra());
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

std::list<DTComentario> ControladorUsuario::listarComentario(std::string nombreU){
       ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
       return mU->listarComentsUser(nombreU);
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
        ManejadorProducto* mP=ManejadorProducto::getInstancia();
        std::list<Comentario*> comentarios=mU->getComentarios();
        auto it = std::find_if(comentarios.begin(), comentarios.end(), [id](Comentario* comentario) {
            return comentario->getIdcom() == id;
        });

        if (it != comentarios.end()) {
            Comentario* coment = *it;

            // Obtener el usuario y el producto asociados
            Usuario* usuario = coment->getUsuario();
            Producto* producto = (*it)->getProdCom();

            if(usuario)
                usuario->borrarComentario(id);
            if (producto)
                producto->borrarComment(id);
            // Eliminar de la lista global
            delete coment;
            comentarios.erase(it);
        }
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

void ControladorUsuario::setProductoEnviado(std::string c, int idCompra,int id) {
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    return mU->setProductoEnviado(c, idCompra, id);
}

void ControladorUsuario::limpiarNotificaciones(std::string cliente)
{
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Cliente* client=dynamic_cast<Cliente*> (mU->getUsuario(cliente));
    client->limpiarNotificaciones();
}

int ControladorUsuario::getIdCompra(std::string cliente, DTFecha fecha, int idProducto) {
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    return mU->getIdCompra(cliente, fecha, idProducto);
}

#endif