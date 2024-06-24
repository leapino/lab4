#ifndef MANEJADORUSUARIO_CPP
#define MANEJADORUSUARIO_CPP

#include "declaraciones/manejadorUsuario.h"



ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario() {};

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ManejadorUsuario();
    }
        return instancia;
}

void ManejadorUsuario::addUsuario(Usuario* u){
    std::string nick=u->getNickname();
    this->Usuarios.insert(std::make_pair(nick,u));
}

Usuario* ManejadorUsuario::getUsuario(std::string usuario){
    std::map<std::string, Usuario*>::iterator it;
    it = this->Usuarios.find(usuario);
    if (it != this->Usuarios.end())
      return it->second;
    else
      return nullptr;
}

std::list< Comentario *> ManejadorUsuario::getComentarios()
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
    return cliente->getDTCompras();  
}

std::list<DTProducto> ManejadorUsuario::getProdEnVenta(Vendedor * vendedor){
    return vendedor->getDTProds();
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
        this->Comentarios.push_back(agregar);
        user->agregarComentario(agregar);
        codProd->agregarComentario(idCom,agregar,codProd->getComentarios());
    }

void ManejadorUsuario::escribirCom(std::string comentario, DTFecha fecha, Producto *codProd, int id, std::string usuario){
    Usuario* user=this->getUsuario(usuario);
    Comentario* agregar=new Comentario(user,fecha,codProd,comentario,id);
    codProd->agregarComentario(agregar);    
    user->agregarComentario(agregar);
    this->Comentarios.push_back(agregar);    
}

std::list<DTVendedor> ManejadorUsuario::ListarUsuariosV(){
     std::map<std::string, Usuario*>::iterator it;
     std::list<DTVendedor> vends;
     DTVendedor sec;
     for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
       Vendedor* vendedor=dynamic_cast<Vendedor*> (it->second);
       if (vendedor!=nullptr){
          sec = getInfoVendedor(vendedor);
          vends.push_back(sec);
       }       
     }
     return vends;
}

std::list<DTCliente> ManejadorUsuario::ListarUsuariosC(){
     std::map<std::string, Usuario*>::iterator it;
     std::list<DTCliente> clients ;
     DTCliente sec ;
     for (it = this->Usuarios.begin(); it != this->Usuarios.end(); it++){
       Cliente* cliente=dynamic_cast<Cliente*> (it->second);
       if (cliente!=nullptr){
          sec = getInfoCliente(cliente);
          clients.push_back(sec);
       }
              
     }
     return clients;
}


void ManejadorUsuario::eliminarSusVendedores(std::string cliente, std::string vendedor){
    Cliente* pCliente=dynamic_cast<Cliente*> (this->getUsuario(cliente));
    Vendedor* pVendedor=dynamic_cast<Vendedor*> (this->getUsuario(vendedor));
    pCliente->eliminarLinkV(vendedor);
    pVendedor->eliminarLinkC(cliente);
}

std::list<DTPromocion> ManejadorUsuario::getPromoVigente(std::string vendedor,DTFecha fechaActual){
    Vendedor * vend=dynamic_cast<Vendedor*> (this->getUsuario(vendedor));
    return vend->getDTPromocion();
}

int ManejadorUsuario::eraseComent(int id)
{   
    int aux=0;
        auto it = std::find_if(this->Comentarios.begin(), this->Comentarios.end(), [id](Comentario* comentario) {
        return comentario->getIdcom() == id;
    });

    if (it != this->Comentarios.end()) {
        this->Comentarios.erase(it);
        aux=(*it)->getProdCom()->getCodigo();
    }
    return aux;
}

std::map<int, DT2Producto > ManejadorUsuario::getProductosNoEnv(std::string nomVend) {
    std::map<int, DT2Producto > resu;
    int num = 1;
    Vendedor* vendedor = this->getVendedor(nomVend);
    std::map<int, Producto*> productos = vendedor->getProductos();
    std::map<int, Producto*>::iterator it;
    for (it = productos.begin(); it != productos.end(); ++it){
        std::set<CompraProducto*> compraProductos = it->second->getCompraProductos();
        std::set<CompraProducto*>::iterator it2;
        std::set<int> lista;
        for (it2 = compraProductos.begin(); it2 != compraProductos.end(); ++it2){
            if (!(*it2)->getEnviado() && lista.find((*it2)->getProd()->getCodigo()) == lista.end()){
                Producto *prodAux = (*it2)->getProd();
                lista.insert(prodAux->getCodigo());
                DT2Producto productoAinsertar = prodAux->getData2();
                resu.insert({num, productoAinsertar});
                num++;
                std::cout<< "codigo a insertar en lista" << prodAux->getCodigo();
            }
        }
    }
    return resu;

}

void ManejadorUsuario::setComentarios(std::list< Comentario *> comm)
{
    this->Comentarios=comm;
}


Vendedor *ManejadorUsuario::getVendedor(std::string v) {
    std::map<std::string, Usuario*>::iterator it;
    it = this->Usuarios.find(v);
    return dynamic_cast<Vendedor *>(it->second);
}


std::map<int, std::pair<std::string, DTFecha>> ManejadorUsuario::nickYFechaDeProdNoEnviado(std::string v, int codigoProd) {
    int num = 1;
    std::map<int, std::pair<std::string, DTFecha>> resu;
    Vendedor *vendedor = getVendedor(v);
    
    Producto *productoNoEnviado = (*vendedor).getProductos().find(codigoProd)->second;
    std::set<CompraProducto*> compraProductos = productoNoEnviado->getCompraProductos();
    std::set<CompraProducto*>::iterator compraProducto = compraProductos.begin();
    
    for(compraProducto = compraProductos.begin(); compraProducto != compraProductos.end(); ++compraProducto) {

        if( !((*compraProducto)->getEnviado()) ) {

            std::pair<std::string, DTFecha> nickYFecha( (*compraProducto)->getCompra()->getCliente()->getNickname(), (*compraProducto)->getCompra()->getFecha() );
            resu.insert(std::make_pair(num, nickYFecha));
            num++;
        }
    }
    return resu;
}

std::list<std::string> ManejadorUsuario::getVendedores() {
    std::list<std::string> listaVendedores;
    for (std::map<std::string, Usuario*>::iterator it = this->Usuarios.begin(); it!=this->Usuarios.end(); ++it){
        Vendedor* vendedor=dynamic_cast<Vendedor*> (it->second);
        if (vendedor !=nullptr){
            listaVendedores.push_front(it->first);
        }
    }
    return listaVendedores;
}


void ManejadorUsuario::setProductoEnviado(std::string c, DTFecha f, int id) {
    Cliente *cliente = (dynamic_cast<Cliente *> (getUsuario(c)));
    std::list<Compra *> compras = cliente->getCompras();
    std::list<Compra *>::iterator it = compras.begin();
    while(it != compras.end() && !(f.esIgualFecha((*it)->getFecha()))) {
        ++it;
    }
    if((it) != compras.end() && f.esIgualFecha((*it)->getFecha())) {
        std::list<CompraProducto *> compraProductos = (*it)->getcompraProductos();
        std::list<CompraProducto *>::iterator compraProducto = compraProductos.begin();
        while(compraProducto != compraProductos.end() && (*compraProducto)->getProd()->getCodigo() != id) {   
            ++compraProducto;

        }
        ((*compraProducto)->getEnviado());
        if(compraProducto != compraProductos.end() && !((*compraProducto)->getEnviado())) {
            ((*compraProducto))->setEnviado(true);
        }
    }
}

void ManejadorUsuario::mandarNotificacion(std::string nombreP, std::string nombreV, std::list<DTProducto> productos){
    Vendedor* vendedor = dynamic_cast<Vendedor*>(this->Usuarios.find(nombreV)->second);
    std::list<Cliente*> clientes = vendedor->getClientes();
    std::list<Cliente*>::iterator it;
    DTNotificacion noti = DTNotificacion(nombreP, nombreV, productos);
    for (it = clientes.begin(); it != clientes.end(); ++it){
        (*it)->addNotificacion(noti);
    }
}

std::list<DTComentario> ManejadorUsuario::listarComentsUser(std::string nombreU)
{
    std::list<DTComentario> res;
    std::list <DTComentario> aux;
    for(std::list<Comentario*>::iterator it =this->Comentarios.begin();it!=this->Comentarios.end();it++){
        if ((*it)->getUsuario()->getNickname()==nombreU){
            DTComentario apushear=DTComentario((*it)->getTexto(),(*it)->getFecha(),(*it)->getIdcom(),aux);
            res.push_front(apushear);
        }
    }
    return res;
}
#endif