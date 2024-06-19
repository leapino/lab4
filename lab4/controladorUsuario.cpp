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

void ControladorUsuario::agregarProductoCompra(int codigo, int cantidad){}

void ControladorUsuario::confirmarCompra(std::map<int, int> datos, Cliente *cliente,DTFecha *fechaActual){
    ManejadorUsuario* mUsuario;
    mUsuario=ManejadorUsuario::getInstancia();
    ManejadorProducto* mProducto;
    mProducto=ManejadorProducto::getInstancia();

    std::list<CompraProducto *> productos;

    int monto=0;

    for (std::map<int,int>::iterator it = datos.begin(); it!=datos.end(); ++it){

        Producto* prod=mProducto->getProducto(it->first);
        CompraProducto* relacion=new CompraProducto(prod,it->second);

        productos.push_back(relacion);

        int precioConvertido=prod->getPrecio();
        if(mProducto->checkPromo(it->first)){//Chequea si esta en una promo
            if(mProducto->cantMinPromo(prod)<=it->second){//Chequea que compre al menos la CantMin
                precioConvertido=precioConvertido-(precioConvertido*mProducto->descPromo(prod));//Realiza el Descuento
            }
        }
        monto+=precioConvertido*it->second;

    }
    Compra* compra=new Compra(fechaActual,monto,cliente,productos);
    mProducto->prodEnCompra(compra);// le baja el stock a los productos
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

std::list<DTCompra> ControladorUsuario::getInfoComprasCliente(Cliente *cliente){
    ManejadorUsuario* mU=ManejadorUsuario::getInstancia();
    return mU->getInfoComprasCliente(cliente);
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

std::map<int ,std::string> ControladorUsuario::listarNickUsuarios(){
    ManejadorUsuario* mu;
    mu = ManejadorUsuario::getInstancia();
    return mu->listarNickUsuarios();
}

std::map<int, std::string> ControladorUsuario::listarComentario(std::string nombreU){
       Usuario* usuario = getUsuario(nombreU);
       return usuario->listarComentarios();
}

void ControladorUsuario::eliminarComentario(int id,std::string nombreU){
        Usuario* usuario = getUsuario(nombreU);
        usuario->borrarComentario(id);
}
#endif