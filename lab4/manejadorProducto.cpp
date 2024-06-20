#ifndef MANEJADORPRODUCTO_CPP
#define MANEJADORPRODUCTO_CPP

#include "declaraciones/manejadorProducto.h"

ManejadorProducto* ManejadorProducto::instancia = NULL;

ManejadorProducto* ManejadorProducto::getInstancia(){
    if (instancia == NULL){
        instancia = new ManejadorProducto();
    }
        return instancia;
}

void ManejadorProducto::agregarProducto(Producto* p){
    this->Productos.insert({p->getCodigo(),p});
}

std::set<DTProducto> ManejadorProducto::getProductosDisp(){
    std::set<DTProducto> res;
    for (std::map<int, Producto*>::iterator it = this->Productos.begin(); it!=this->Productos.end(); ++it){
        if(it->second->getStock()!=0){
            DTProducto  producto=DTProducto(it->second->getCodigo(),it->second->getStock(),it->second->getPrecio(),it->second->getNombre(),it->second->getDescripcion(),it->second->getCategoria());            
            res.insert(producto);
        }
    }
}

std::map<int, std::string> ManejadorProducto::getProds(){
    std::map<int, std::string> res;
    for (std::map<int, Producto*>::iterator it = this->Productos.begin(); it!=this->Productos.end(); ++it){
            res.insert({it->first,it->second->getNombre()});
    }
    return res;
    
}

bool ManejadorProducto::hayStock(int codigo, int cantidad){
    std::map<int,Producto*>::iterator it=this->Productos.find(codigo);
    return it->second->getStock()>=cantidad;
}


void ManejadorProducto::prodEnCompra(Producto* prod,int cantidad){
        prod->bajarStock(cantidad);//bajar el Stock del Producto
}

std::map<std::string, DTProducto > ManejadorProducto::getInfoProd(std::string producto){
    std::map<std::string, DTProducto > res;

    std::map<int, Producto*>::iterator it=Productos.begin();
    std::string astring=std::to_string(it->first);
    bool flag=((astring==producto)||(it->second->getNombre()==producto));

    while (!flag){
        it++;
        astring=std::to_string(it->first);
        flag=((astring==producto)||(it->second->getNombre()==producto));
    }

    DTProducto prod=DTProducto(it->second->getCodigo(),it->second->getStock(),it->second->getPrecio(),it->second->getNombre(),it->second->getDescripcion(),it->second->getCategoria());
    res.insert({it->second->getVendedor()->getNickname(),prod});  
    return res;
}



Producto *ManejadorProducto::getProducto(int c)
{
    std::map<int, Producto*>::iterator it;
    it = this->Productos.find(c);
    return it->second;
}

std::map<int, DT2Producto> ManejadorProducto::listarProductos(std::map<int, Producto*> lista){
    std::map<int, Producto*>::iterator it;
    std::map<int, DT2Producto> dataProductos;
    int num = 1;
    for (it = lista.begin(); it != lista.end(); it++){
        DT2Producto dProducto = DT2Producto(it->second->getCodigo(), it->second->getNombre());
        dataProductos.insert({num, dProducto});
        num++;
    }
    return dataProductos;
}

bool ManejadorProducto::checkPromo(int codigo){
    Producto* prod = this->Productos.find(codigo)->second;
    if (prod->getPromo() == NULL){
        return false;
    }
    else{
        return true;
    }
}
int ManejadorProducto::cantMinPromo(Producto* prod){
    return prod->getPromo()->getCantMin();
}
float ManejadorProducto::descPromo(Producto* prod){
    return prod->getPromo()->getDescuento();   
}

void ManejadorProducto::confirmarAltaPromocion(std::string nombreP,std::string descriP,float descuento,DTFecha fecha,std::map<int, int> infoProd){
    std::map<int, int>::iterator it;
    Promocion* promo = new Promocion(nombreP, descriP, fecha);
    this->Promociones.insert({nombreP, promo});
    for (it = infoProd.begin(); it != infoProd.end(); it++){
        Producto* producto = this->Productos.find(it->first)->second;
        ProductoPromocion* productoPromo = new ProductoPromocion(descuento, it->second, producto);
        producto->setPromo(productoPromo);
        promo->agregarProdProm(productoPromo);
    }
}

std::map<std::string, Promocion*> ManejadorProducto::getPromos(){
    return this->Promociones;
}

std::set<DTProducto> ManejadorProducto::getProductoPromo(std::string nombrePromo){
    std::set<DTProducto> productos;
    std::set<ProductoPromocion*>::iterator it;
    Promocion* promocion = this->Promociones.find(nombrePromo)->second;
    for (it = promocion->getProdProm().begin(); it != promocion->getProdProm().end(); it++){
        DTProducto dtproducto = DTProducto((*it)->getProducto()->getCodigo(), (*it)->getProducto()->getStock(), (*it)->getProducto()->getPrecio(), (*it)->getProducto()->getNombre(), (*it)->getProducto()->getDescripcion(), (*it)->getProducto()->getCategoria());
        productos.insert(dtproducto);
    }
    return productos;
}

DTVendedor ManejadorProducto::vendedorPromo(DTProducto producto){
    Vendedor* vendedor = this->Productos.find(producto.getCodigo())->second->getVendedor();
    DTVendedor dtv = DTVendedor(vendedor->getNickname(), vendedor->getFecha(), vendedor->getRUT());
    return dtv;
}

void ManejadorProducto::escribirCom(std::string comment,DTFecha fecha,int codProd,Usuario* usuario,int idCom){
    Producto* pProd=this->getProducto(codProd);
    Comentario* com=new Comentario(usuario,fecha,pProd,comment);
    int Id=1;
    if (idCom==0){
        if (!pProd->getComentarios().empty()) {
            Id = pProd->getComentarios().rbegin()->first + 1;
        }
        
    }else{

    }
    //agregar comentarioa producto ,si el id es 0 es com nuevo si es mayor es respuesta
}

std::list<CompraProducto *> ManejadorProducto::confirmarCompra(std::map<int, int> datos, int &monto){
    
    std::list<CompraProducto *> productos;

    for (std::map<int,int>::iterator it = datos.begin(); it!=datos.end(); ++it){

        Producto* prod=this->Productos.find(it->first)->second;
        CompraProducto* relacion=new CompraProducto(prod,it->second);

        productos.push_back(relacion);

        this->prodEnCompra(prod,it->second);

        int precioConvertido=prod->getPrecio();
        if(this->checkPromo(it->first)){//Chequea si esta en una promo
            if(this->cantMinPromo(prod)<=it->second){//Chequea que compre al menos la CantMin
                precioConvertido=precioConvertido-(precioConvertido*this->descPromo(prod));//Realiza el Descuento
            }
        }
        monto+=precioConvertido*it->second;

    }
    return productos;
}

void ManejadorProducto::addProducto(Producto* p){
    int u = 1;
    if(this->Productos.empty() == false){
       u = this->Productos.end()->first;
       u++;
    } 
    p->setCodigo(u);
    this->Productos.insert({u,p});
}

Producto* ManejadorProducto::finalProd(){
    return this->Productos.end()->second;
}    

#endif