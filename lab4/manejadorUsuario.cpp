#ifndef MANEJADORUSUARIO_CPP
#define MANEJADORUSUARIO_CPP

#include "declaraciones/manejadorUsuario.h"
#include "declaraciones/DT2Producto.h"
#include "declaraciones/usuario.h"
#include "declaraciones/cliente.h"
#include "declaraciones/vendedor.h"
#include "manejadorUsuario.h"


ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ManejadorUsuario();
    }
        return instancia;
}

void ManejadorUsuario::addUsuario(Usuario* u){
    this->Usuarios.insert({u->getNickname(),u});
}

Usuario* ManejadorUsuario::getUsuario(std::string usuario){
    std::map<std::string, Usuario*>::iterator it;
    it = this->Usuarios.find(usuario);
    return it->second;
}

std::map<int, Comentario *> ManejadorUsuario::getComentarios()
{
    return this->Comentarios;
}
DTUsuario ManejadorUsuario::getInfoUsuario(Usuario *usuario){
    return DTUsuario(usuario->getNickname(),usuario->getFecha());
}

DTCliente ManejadorUsuario::getInfoCliente(Cliente *usuario){
    return DTCliente(usuario->getNickname(),usuario->getFecha(),usuario->getDireccion(),usuario->getCiudad());
}
DTVendedor ManejadorUsuario::getInfoVendedor(Vendedor *usuario){
    return DTVendedor(usuario->getNickname(),usuario->getFecha(),usuario->getRUT());
}
std::list<DTCompra> ManejadorUsuario::getInfoComprasCliente(Cliente *cliente){

    std::list<DTCompra> res;

    for (std::list<Compra*>::iterator it = cliente->getCompras().begin(); it!=cliente->getCompras().end(); ++it){
        std::list<DTCompraProducto> prods;
        for(std::list<CompraProducto*>::iterator it2=(*it)->getcompraProductos().begin();it2!=(*it)->getcompraProductos().end();++it2){
            DTProducto amostrar=DTProducto((*it2)->getProd()->getCodigo(),(*it2)->getProd()->getStock(),(*it2)->getProd()->getPrecio(),(*it2)->getProd()->getNombre(),(*it2)->getProd()->getDescripcion(),(*it2)->getProd()->getCategoria());
            DTCompraProducto aingresar=DTCompraProducto((*it2)->getEnviado(),(*it2)->getCantidad(),amostrar);
            prods.push_back(aingresar);
        }
        DTCompra compraactual=DTCompra((*it)->getFecha(),(*it)->getMonto(),prods);
        res.push_back(compraactual);
    }
    return res;  
}

std::list<DTProducto> ManejadorUsuario::getProdEnVenta(Vendedor * vendedor){
    std::list<DTProducto> res;
    for (std::map<int,Producto*>::iterator it =vendedor->getProductos().begin(); it!=vendedor->getProductos().end(); ++it){;
        DTProducto apushear=DTProducto(it->second->getCodigo(),it->second->getStock(),it->second->getPrecio(),it->second->getNombre(),it->second->getDescripcion(),it->second->getCategoria());
        res.push_back(apushear);
    }
    
return res;
}


std::list<std::string> ManejadorUsuario::getVendedoresNoSuscrito(std::string cliente){
    std::list<std::string> res;
    std::map<int,std::string> Vendedores=this->listarNicknamesV();
    Cliente* pcliente=dynamic_cast<Cliente*> (this->getUsuario(cliente));

    std::list<Vendedor*> suscritos = pcliente->getVendedores();

    std::set<std::string> suscritosNicknames;
    
    for (auto it = suscritos.begin(); it != suscritos.end(); ++it) {
        suscritosNicknames.insert((*it)->getNickname());
    }
    for (auto it = Vendedores.begin(); it != Vendedores.end(); ++it) {
        if (suscritosNicknames.find(it->second) == suscritosNicknames.end()) {
            res.push_back(it->second);
        }
    }
    return res;
}

void ManejadorUsuario::suscribirVendedores(std::list<std::string> Vendedores, std::string cliente){
    Cliente * pCliente=dynamic_cast<Cliente*>(this->getUsuario(cliente));
    for (auto i = Vendedores.begin(); i !=Vendedores.end(); i++){
        Vendedor* pVendedor=dynamic_cast<Vendedor*>(this->getUsuario(*i));
        pCliente->crearLinkV((pVendedor));
        pVendedor->crearLinkC(pCliente);
    }
    
}

std::list<DTNotificacion> ManejadorUsuario::consultarNotificaciones(std::string cliente){
    Cliente * pCliente=dynamic_cast<Cliente*>(this->getUsuario(cliente));
    std::list <DTNotificacion> res=pCliente->getDTNotificaciones();
    pCliente->limpiarNotificaciones();
    return res;
}

std::list<std::string > ManejadorUsuario::getVendedoresSuscrito(std::string cliente){

    Cliente* pcliente=dynamic_cast<Cliente*> (this->getUsuario(cliente));

    std::list<Vendedor*> suscritos = pcliente->getVendedores();

    std::list<std::string> suscritosNicknames;
    
    for (auto it = suscritos.begin(); it != suscritos.end(); ++it) {
        std::string agregar=(*it)->getNickname();
        suscritosNicknames.push_front(agregar);
    }

    return suscritosNicknames;
}

std::set<std::string> ManejadorUsuario::getClientes() {

    std::set<std::string> listaClientes;
    for (std::map<std::string, Usuario*>::iterator it = this->Usuarios.begin(); it!=this->Usuarios.end(); ++it){
        Cliente* client=dynamic_cast<Cliente*> (it->second);
        if (client !=nullptr){
            listaClientes.insert(it->first);
        }
    }
    return listaClientes;
}

std::map<int ,std::string> ManejadorUsuario::listarNicknamesV(){
    std::map<std::string, Usuario*>::iterator it;
    std::map<int ,std::string> nicknames;
    Vendedor* vendedor;
    int num = 1;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
        vendedor = dynamic_cast<Vendedor*>(it->second);
        if (vendedor != NULL){
            nicknames.insert({num, it->first});
            num++;
        }
    }
    return nicknames;
}

std::map<int, Producto*> ManejadorUsuario::getListaProductos(std::string nombre){
    Vendedor* vendedor = dynamic_cast<Vendedor*>(this->Usuarios.find(nombre)->second);
    return vendedor->getProductos();
}

bool ManejadorUsuario::estaUsuario(std::string nombre) {   
       bool estaN = false;
       std::map<std::string, Usuario*>::iterator it;
       it = this->Usuarios.find(nombre);
       if (it != this->Usuarios.end())
          estaN = true;
       return estaN;
}

std::map<int ,std::string> ManejadorUsuario::listarNickUsuarios(){
    std::map<std::string, Usuario*>::iterator it;
    std::map<int ,std::string> nicknames;
    int num = 1;
    for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
        nicknames.insert({num, it->first});
        num++;
    }
    return nicknames;
}

void ManejadorUsuario::agregarCompraCliente(Cliente *cliente,Compra* compra){
    cliente->agregarCompra(compra);
}


void ManejadorUsuario::escribirCom(int idCom,std::string comentario, DTFecha fecha, Producto *codProd, int id, std::string usuario){
    Usuario* user=this->getUsuario(usuario);
    Comentario* agregar=new Comentario(user,fecha,codProd,comentario,id);
    auto i = this->getComentarios().begin(); 
    while ((i !=this->getComentarios().end())&&(i->first!=idCom))
        i++;
    if (i !=this->getComentarios().end())
        i->second->agregarRespuesta(agregar);
    this->Comentarios.insert(std::make_pair(id,agregar));    
}

void ManejadorUsuario::escribirCom(std::string comentario, DTFecha fecha, Producto *codProd, int id, std::string usuario){
    Usuario* user=this->getUsuario(usuario);
    Comentario* agregar=new Comentario(user,fecha,codProd,comentario,id);
    codProd->agregarComentario(agregar);
    user->agregarComentario(agregar);
    this->Comentarios.insert(std::make_pair(id,agregar));    
}

std::list<DTUsuario> ManejadorUsuario::ListarUsuarios(){
     std::map<std::string, Usuario*>::iterator it;
     std::list<DTUsuario> usuario;
     DTUsuario sec;
     for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
       Vendedor* vendedor=dynamic_cast<Vendedor*> (it->second);
       if (vendedor!=nullptr){
          sec = getInfoVendedor(it->second->getVend());
       }
       else{
          sec = getInfoCliente(it->second->getCliente());
       }
       usuario.push_back(sec);       
     }
     return usuario;
}

void ManejadorUsuario::eliminarSusVendedores(std::string cliente, std::string vendedor){
    Cliente* pCliente=dynamic_cast<Cliente*> (this->getUsuario(cliente));
    Vendedor* pVendedor=dynamic_cast<Vendedor*> (this->getUsuario(vendedor));
    pCliente->crearLinkV(pVendedor);
    pVendedor->crearLinkC(pCliente);
}

std::list<DTPromocion> ManejadorUsuario::getPromoVigente(std::string vendedor,DTFecha fechaActual){
    std::list<DTPromocion> res;
    Vendedor * vend=dynamic_cast<Vendedor*> (this->getUsuario(vendedor));
    for (auto i = vend->getPromociones().begin(); i !=vend->getPromociones().end(); ++i){
        DTFecha fechaPromo=i->second->getFecha();
        if (fechaPromo>fechaActual){
            DTPromocion agregarpromo=DTPromocion(i->second->getNombre(),i->second->getDescripcion(),i->second->getFecha());
            res.push_front(agregarpromo);
        }
    }
    return res;
}


std::map<int, DT2Producto > ManejadorUsuario::getProductosNoEnv(std::string nomVend) {
    std::map<int, DT2Producto > resu;
    int num = 1;

    std::list<Cliente *> clientes = getVendedor(nomVend)->getClientes();
    for(std::list<Cliente *>::iterator cliente = clientes.begin(); cliente!= clientes.end(); ++cliente) {
        
        std::list<Compra *> compras = (*cliente)->getCompras();
        for(std::list<Compra *>::iterator compra = compras.begin(); compra != compras.end(); ++compra) {

            std::list<CompraProducto *> compraProductos = (*compra)->getcompraProductos();
            for(std::list<CompraProducto *>::iterator compraProducto = compraProductos.begin(); compraProducto != compraProductos.end(); ++compraProducto){

                if(!(*compraProducto)->getEnviado()) {
                    Producto *prodAux = (*compraProducto)->getProd();
                    DT2Producto productoAinsertar = prodAux->getData2();
                    resu.insert({num, productoAinsertar});
                    num++;
                }
            }
        }
    }
    return resu;

}

void ManejadorUsuario::setComentarios(std::map<int, Comentario *> comm)
{
    this->Comentarios=comm;
}


Vendedor *ManejadorUsuario::getVendedor(std::string v) {
    std::map<std::string, Usuario*>::iterator it;
    it = this->Usuarios.find(v);
    return dynamic_cast<Vendedor *>(it->second);
}

void ManejadorUsuario::eraseRespuestas(int id){
     Comentario* com = this->Comentarios.find(id)->second;
     std::map<int, Comentario*>::iterator it;
     it = com->getRespuestas().begin();     
     while ( it != com->getRespuestas().end()){
         this->Comentarios.erase(it->second->getIdcom());
         ++it;
     }     
}

void ManejadorUsuario::eraseCom(int id){
     this->Comentarios.erase(id);
}    

#endif