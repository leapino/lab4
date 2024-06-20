#ifndef CONTROLADORUSUARIO_CPP
#define CONTROLADORUSUARIO_CPP

#include "declaraciones/controladorUsuario.h"



ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario* ControladorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorUsuario();
    }
        return instancia;
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

void ControladorUsuario::confirmarCompra(std::list<CompraProducto* > productos,int monto,Cliente *cliente,DTFecha *fechaActual){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();

    Compra* compra=new Compra(fechaActual,monto,cliente,productos);
    mUsuario->agregarCompraCliente(cliente,compra);
}

Usuario *ControladorUsuario::getUsuario(std::string Usuario)
{
    return nullptr;
}

DTUsuario ControladorUsuario::getInfoUsuario(Usuario *usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getInfoUsuario(usuario);
}

DTCliente ControladorUsuario::getInfoCliente(Usuario *usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Cliente* pCliente=dynamic_cast<Cliente*> (usuario);
    return mU->getInfoCliente(pCliente);
}

DTVendedor ControladorUsuario::getInfoVendedor(Usuario *usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    Vendedor* pVendedor=dynamic_cast<Vendedor*> (usuario);
    return mU->getInfoVendedor(pVendedor);
}

std::list<DTCompra*> ControladorUsuario::getInfoComprasCliente(Cliente *cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getInfoComprasCliente(cliente);
}

std::list<DTProducto*> ControladorUsuario::getProdEnVenta(Vendedor *vendedor){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getProdEnVenta(vendedor);
}

std::list<std::string> ControladorUsuario::getVendedoresNoSuscrito(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getVendedoresNoSuscrito(cliente);
}

void ControladorUsuario::suscribirVendedores(std::list<std::string> Vendedores, std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    mU->suscribirVendedores(Vendedores,cliente);
}

std::list<DTNotificacion*> ControladorUsuario::consultarNotificaciones(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->consultarNotificaciones(cliente);
}

std::list<std::string *> ControladorUsuario::getVendedoresSuscrito(std::string cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getVendedoresSuscrito(cliente);
}

Usuario * getUsuario(std::string Usuario){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    return mUsuario->getUsuario(Usuario);
}

void ControladorUsuario::altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string dir, std::string ciudad){
       Cliente* nuevoCliente =new  Cliente(nick,pass,fechnaci,dir,ciudad);       
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       mu->addUsuario(nuevoCliente);
}

void ControladorUsuario::altaDeUsuario(std::string nick, std::string pass, DTFecha fechnaci,std::string RUT){
       Vendedor* nuevoVendedor =new  Vendedor(nick,pass,fechnaci,RUT);       
       ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
       mu->addUsuario(nuevoVendedor);
}

bool ControladorUsuario::estaVacio(){
        bool estaV = true;
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        std::map<int ,std::string> nombres = mu->listarNickUsuarios();
        if (nombres.empty() == false)
          estaV = false;
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

std::map<std::string, std::string> ControladorUsuario::listarComentario(std::string nombreU){
       Usuario* usuario = getUsuario(nombreU);
       return usuario->listarComentarios();
}

void ControladorUsuario::escribirCom(std::string comentario, DTFecha fecha, Producto* codProd, std::string usuario){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    mU->escribirCom(comentario,fecha,codProd,usuario);
}

void ControladorUsuario::eliminarComentario(std::string id,std::string nombreU){
        Usuario* usuario = getUsuario(nombreU);
        usuario->borrarComentario(id);
}

std::list<Usuario*> ControladorUsuario::ListaUsuarios(){
        ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->ListarUsuarios();
}

void ControladorUsuario::eliminarSusVendedores(std::string cliente, std::string vendedor){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    mU->eliminarSusVendedores(cliente,vendedor);
}

std::map<int, DT2Producto *> ControladorUsuario::getProductosNoEnv(std::string nomVend) {
    ManejadorUsuario *mU;
    mU = ManejadorUsuario::getInstancia();
    std::map<int, DT2Producto *> productosNoEnviados = mU->getProductosNoEnv(nomVend);
    return productosNoEnviados;
}

Vendedor *ControladorUsuario::getVendedor(std::string v) {
    ManejadorUsuario *mU;
    mU = ManejadorUsuario::getInstancia();
    return mU->getVendedor(v);
}

#endif