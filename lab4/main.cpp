#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "../declaraciones/DTFecha.h"
#include "../declaraciones/DTUsuario.h"
#include "../declaraciones/DTCliente.h"
#include "../declaraciones/DTVendedor.h"
#include "../declaraciones/controladorUsuario.h"
#include "../declaraciones/controladorProducto.h"
#include "../declaraciones/controladorFecha.h"
#include "../declaraciones/usuario.h"
#include "../declaraciones/cliente.h"
#include "../declaraciones/vendedor.h"
#include "../declaraciones/categoria.h"


DTFecha leerFecha(){
    int dia,mes,anio;
    std::string separador;
    std::cout <<"Ingrese la fecha de nacimiento con el formato DD/MM/YYYY\n";
    std::cin >> dia>>separador>>mes>>separador>>anio;
    std::cout <<"\n";
    return DTFecha(dia,mes,anio,0,0);
}

void selecVendedor(){
        //Aca hay que crear instancia de controlador Usuario

        std::cout<< "Ingrese el nickname de uno de los siguientes Vendedores a cargo del producto \n";

        std::vector<std::string> Nicknames;//=ctrlUsuario.listarNicknames Notar qe lista vendedores nomas
        for (int j = 0; j < Nicknames.size(); j++){
                //std::cout <<Nicknames[j]->toString();
        }

        std::string vendedor;
        std::cin >> vendedor;
            
        //ctrlUsuario.selectNick(vendedor);
}

int main() {

    ControladorFecha* ControladorFecha = ControladorFecha::getInstancia();
    ControladorProducto* ControladorProducto = ControladorProducto::getInstancia();
    ControladorUsuario* ControladorUsuario = ControladorUsuario::getInstancia();

    std::cout << "\n";
    int i =-2;

    while ( i !=0 ){

        std::cout << "¿Qué operación deseas realizar?\n";
        std::cout << "1-Creación de Usuario \n"<<"2-Listado de Usuarios \n"<< "3-Alta de Producto\n"<<"4-Consultar Producto\n"<<"5-Crear Promoción\n";
        std::cout << "6-Consultar Promoción \n"<<"7-Realizar Compra\n"<<"8-Dejar Comentario\n"<<"9-Eliminar Comentario\n"<<"10-Enviar Producto\n"<<"11-Expediente de Usuario\n";
        std::cout << "12-Suscribirse a Notificaciones\n"<<"13-Consulta Notificacion\n"<<"14-Eliminar Suscripciones\n"<<"0-Salir";
        std::cin>>i;
        std::cout <<"\n";


    switch (i){

        case 1:{//Crear Usuario
            bool Confirmar=false;
            int usuario;
            std::cout << "Si es vendedor ingrese 0, si es cliente ingrese 1\n";
            std::cin >>usuario;
            std::cout <<"\n";

            std::string nickname;
            std::cout <<"Ingrese el nickname del usuario \n";
            std::cin >>nickname;
            std::cout <<"\n";

            std::string password;
            std::cout <<"Ingrese la contraseña (de al menos 6 caracteres)\n";
            std::cin >>password;
            std::cout <<"\n";
            
            DTFecha fecha=leerFecha();
            
            bool estanom = false;
            if (ControladorUsuario->estaVacio() == false)
                 if (ControladorUsuario->estaUsuario(nickname))
                    estanom = true;
            
            bool contrabien = true;
            if (password.length()<6)
                contrabien = false;
            
        if ((estanom == false) && (contrabien == true)){

            if (usuario == 1){
               
            
                std::string direccion;
                std::cout <<"Ingrese la dirección del Cliente\n";
                std::cin >>direccion;
                std::cout <<"\n";

                std::string ciudad;                
                std::cout <<"Ingrese la Ciudad \n";
                std::cin >>ciudad;
                std::cout <<"\n";

               ControladorUsuario->altaDeUsuario(nickname,password,fecha,direccion,ciudad);

                }else{
                
                std::string RUT;
                std::cout <<"Ingrese el número de RUT\n";
                std::cin >>RUT;
                std::cout <<"\n";
     
                ControladorUsuario->altaDeUsuario(nickname,password,fecha,RUT);

            }
            std::cout << "El usuario se a creado correctamente";
          }  
            else{            
                std::cout<< "El usuario no se creo correctamente\n";
                if (estanom == true)
                 std::cout<< "Ese nickname ya esta en uso, elija otro\n";
                if (contrabien == false)
                 std::cout<< "Su contraseña tiene menos de 6 caracteres, ingrese una con 6 o mas caracteres\n";
             }   
        }  
         
            break;

        case 2:{//LIstado de Usuarios, muestra el nick , la fecha de nacimiento y los datos de cliente o vendedor
              std::list<Usuario*> lista = ControladorUsuario->ListaUsuarios();
              for (std::list<Usuario*>::iterator it = lista.begin(); it != lista.end(); it++){
                   if((*it)->esCliente()){
                      DTCliente client = ControladorUsuario->getInfoCliente(*it);
                      std::cout<<& client;
                    }
                   else{
                      DTVendedor vend = ControladorUsuario->getInfoVendedor(*it);
                      std::cout<<& vend;
                   }  
            }
        }
            break;

        case 3:{//alta de Producto
            

            std::string nomProd;
            std::cout << "Nombre del producto a ingresar\n";
            std::cin >> nomProd;
            std::cout <<"\n";

            float precio;
            std::cout <<"Precio del Producto\n";
            std::cin >>precio;
            std::cout <<"\n";

            int stock;
            std::cout <<"Stock\n";
            std::cin >>stock;
            std::cout <<"\n";

            std::string descripProd;
            std::cout <<"Descipción del producto\n";
            std::cin >>descripProd;
            std::cout <<"\n";

            Categoria categoria;
            int j;
            std::cout <<"Categoria de su producto\n"<<"1-Ropa\n"<<"2-Electrodomestico\n"<<"3-Otro\n";
            std::cin >>j;
            
            //preguntar en caso de q el usuario erre es factible o deberiamos tomar como que no

            switch (j){
            case 1:
                categoria=ropa;
                break;
            case 2:
                categoria=electrodomestico;
                break;
            case 3:
                categoria=otro;
            default:
                std::cout<<"Numero ingresado no válido";
                break;
            }

            //ctrlUsuario.altaDeProducto(nomProd,precio,stock,descripProd,categoria);
        }
        break;
        
        case 4:{//Consultar Producto
             std::map<int,std::string> prods=ControladorProducto->getProds();

            for (auto i = prods.begin(); i != prods.end(); ++i){
                std::cout <<&i;
            }
            std::string eleccion;
            std::cout <<"Ingresar Nombre o Código del producto\n";
            std::cin >>eleccion;
            
            std::map<std::string,DTProducto*> amostrar=ControladorProducto->getInfoProd(eleccion);
            std::cout <<amostrar.begin()->first;
            std::cout <<amostrar.begin()->second;

            amostrar.clear();
        }
        break;

        case 5:{//Crear Promocion

            std::string nombreP;
            std::cout<<"Ingresar el nombre de la promoción\n";
            std::cin >>nombreP;

            std::string descriP;
            std::cout<<"Ingresar la descripción de la promoción\n";
            std::cin >>descriP;

            float descuento;
            std::cout <<"Ingresar Descuento\n";
            std::cin >>descuento;

            DTFecha fecha=leerFecha();
            
            std::map<int ,std::string> nicknames = ControladorProducto->listarNicknamesV();
            std::map<int ,std::string>::iterator it;
            std::cout<<"Selecciona un vendedor por su número:\n";
            for (it = nicknames.begin(); it != nicknames.end(); it++){
                std::cout<< it->first <<")" << " " << it->second << "\n";
            }
            int numVend;
            std::cin >> numVend;
            std::map<int, DT2Producto*> productosVend = ControladorProducto->listarProductos(nicknames.find(numVend)->second);
            std::map<int, DT2Producto*>::iterator it2;
            std::cout<<"\nIngrese un producto del vendedor que desee agregar junto a su cantidad mínima o ingrese 0 para no agregar más:";
            std::map<int, int> infoProd;
            
            for(it2 = productosVend.begin(); it2 != productosVend.end(); it++){
                std::cout<< numVend <<")" << " " << it2->second << "\n";
            }
            int numProd = 1;
            int cantMin;
            while (numProd > 0){
                std::cout<< "Número producto:\n";
                std::cin>> numProd;
                std::cout <<"\n";
                if (numProd > 0){
                    DT2Producto* prod = productosVend.find(numProd)->second;
                    bool tienePromo = ControladorProducto->checkPromo(prod->getCodigo());
                    if (!tienePromo){
                        std::cout<< "Cantidad mínima:\n";
                        std::cin>> cantMin;
                        std::cout <<"\n";
                        infoProd.insert({numProd, cantMin});
                    }
                    else{
                        std::cout<< "Este producto ya se encuentra en una promoción\n";
                    }
                }
            }
            int confirm = 2;
            while (confirm != 1 || confirm!= 0)
            {
                std::cout<< "Ingrese 1 si desea confirmar la creación de la promoción o 0 si no:\n";
                std::cin>> confirm;
                if (confirm == 1){
                    ControladorProducto->confirmarAltaPromocion(nombreP, descriP, descuento, fecha, infoProd, nicknames.find(numVend)->second);
                    std::cout<< "\nSe agregó la promoción\n";
                }if (confirm == 0){
                    std::cout<< "\nNo se agregó la promoción\n";
                }else{
                    std::cout<<"\nSe ingresó mal el número, intente denuevo\n";
                }
            }
        }
        break;
        case 6:{//Consultar Promocion

            std::map<std::string, DTPromocion*> promociones = ControladorProducto->getPromos();
            std::map<std::string, DTPromocion*>::iterator it;
            for (it = promociones.begin(); it != promociones.end(); it++){
                std::cout<< it->second;
            }
            int confirm;
            std::cout << "Desea consultar una promoción?\n1)Si\n2)No\n";
            std::cin>> confirm;
            if (confirm == 1){
                std::cout <<"Ingresar nombre de la promocion que desea consultar:\n";
                std::string nombrePromo;
                std::cin >>nombrePromo;
                std::set<DTProducto*> productos = ControladorProducto->getProductoPromo(nombrePromo);
                DTVendedor* vendedor = ControladorProducto->vendedorPromo(nombrePromo);
                std::set<DTProducto*>::iterator it2;
                std::cout << "Vendedor que ofrece la promoción:\n";
                std::cout << vendedor;
                std::cout << "Productos de la promoción:\n";
                for (it2 = productos.begin(); it2 != productos.end(); ++it){
                    std::cout << *it2;
                }
            }
        }
            break;
        case 7:{//Realizar Compra
            std::set <std::string> clientes=ControladorUsuario->listarClientes();

            std::cout <<"Ingresar Nickname del Cliente que va a comprar\n";
            std::string cliente;
            std::cin >>cliente;//deberiamos chequear si el admin ingresa bien el cliente?

            std::set <DTProducto*> productos=ControladorProducto->getProductosDisp();

            for(std::set<DTProducto*>::iterator it=productos.begin();it!=productos.end();++it){
                std::cout <<&it;
            }

            int i=1;
            std::cout <<"Desea ingresar producto a la compra\n"<<"0-No\n"<<"1-Sí\n";
            std::cin >>i;

            std::map <int,int> productoCompra;

            while(i){

                std::cout<<"Ingresar codigo del Producto\n";
                int codigo;
                std::cin>>codigo;
                
                std::cout<<"Ingresar cantidad del producto a comprar \n";
                int cantidad;
                std::cin >>cantidad;

                ControladorUsuario->agregarProductoCompra(codigo,cantidad);
                productoCompra.insert(codigo,cantidad);//deberiamos chequear si la cantidad que ingreso es menor o igual a la del stock

                std::cout<<"Desea agregar otro producto?\n"<<"0-No\n"<<"1-Sí\n";
                std::cin >> i;
            }
            int monto=0;

            Cliente* pCliente=dynamic_cast<Cliente*>(ControladorUsuario->getUsuario(cliente));

            DTFecha* fechaActual=new DTFecha;

            fechaActual=&ControladorFecha->getFechaActual();

            std::list<CompraProducto*> compra=ControladorProducto->confirmarCompra(productoCompra,monto);

            ControladorUsuario->confirmarCompra(compra,monto,pCliente,fechaActual);

            productos.clear();
        }
            break;
        
        case 8:{//Dejar Comentario
            //iniciar controlador Usuario
            //std::vector <string> nicknames=ctrl.Usuario.listadoDeUsuarios();
            //imprimir el vector;
            std::cout <<"Ingrese el nickname que quiere dejar un comentario\n";
            std::string usuario;
            std::cin >>usuario;
            //ctrlUsuario.selectUsuario();

            //iniciar controlador Prod

            std::vector <DTProducto>productos;//=listarProductos();
            for (int j = 0; j < productos.size(); j++){
                //std::cout <<productos[j]->toString();
            }
            std::cout <<"Ingrese el codigo del producto para dejar el comentario\n";
            int codProd;
            std::cin >> codProd;
            //ctrlProd.selectProducto(codProd);

            std::cout <<"Desea responder a un comentario existente o crear un nuevo comentario\n"<<"0-Nuevo Comentario\n"<<"1-Responder a un comentario existente\n";
            int alt;
            std::cin >>alt;

            if (alt){
                //std::vector <DTComentario> comentarios=ctrlUsuario.listarComProd();
                std::cout<<"A que comentario quiere responder\n";

                //idea:recorrer el vector y darle un numero como "id" a los comentarios
                int id;
                std::cin >>id;
                //ctrlUsuario.selectComProd(comentarios[id]);

                std::cout <<"Ingrese el comentario\n";
                std::string comentario;
                std::cin >>comentario;

                //ctrlUsuario.escribirCom(comentarios[id],comentario)//ver que pide el comentario incial denuevo;
            }else{
                std::cout <<"Ingrese el comentario\n";
                std::string comentario;
                std::cin >>comentario;

                //ctrlUsuario.escribirComNuevo(comentario);                
            }
        }
            break;
        case 9:{//Eliminar Comentario
            std::map<int ,std::string> nicknames = ControladorUsuario->listarNickUsuarios();
            std::map<int ,std::string>::iterator it;
            std::cout<<"Selecciona un usuario por su número:\n";
            for (it = nicknames.begin(); it != nicknames.end(); it++){
                std::cout<< it->first <<")" << " " << it->second << "\n";
            }
            int usu;
            std::cin >>usu;
            std::map<int ,std::string> comentarios = ControladorUsuario->listarComentario(nicknames.find(usu)->second);
            std::map<int ,std::string>::iterator it2;
            std::cout<<"Selecciona un comentario por su identificador:\n";
            for (it = comentarios.begin(); it2 != comentarios.end(); it2++){
                std::cout<< it2->first <<")" << " " << it2->second << "\n";
            }
            int id;
            std::cin >>id;
            ControladorUsuario->eliminarComentario(id,nicknames.find(usu)->second);
        } 
        break;  
        case 10:{//Enviar Producto

        } 
        break;
        case 11:{//Expediente de usuario
            std::map<int,std::string> nicknames=ControladorUsuario->listarNickUsuarios();

            for (std::map<int,std::string>::iterator it =nicknames.begin(); it!=nicknames.end(); ++it){

                std::cout << it->second;
            }

            std::cout <<"Ingrese el nickname del usuario";
            std::string usuario;
            std::cin >>usuario;

            Usuario* elegido=ControladorUsuario->getUsuario(usuario);

            DTUsuario infoUsuario=ControladorUsuario->getInfoUsuario(elegido);
            std::cout << &infoUsuario;

            Cliente* pElegido=dynamic_cast<Cliente*>(elegido);
            if (pElegido!=nullptr){
                std::cout<<&ControladorUsuario->getInfoCliente(pElegido);
                std::cout<<&ControladorUsuario->getInfoComprasCliente(pElegido);
                
            }else{
                Vendedor* pElegido=dynamic_cast<Vendedor*>(elegido);
                std::cout<<&ControladorUsuario->getInfoVendedor(pElegido);
                std::cout<<&ControladorUsuario->getProdEnVenta(pElegido);
                std::cout<<&ControladorUsuario->getPromoVigente(pElegido);//Falta Crear el Link entre promocion y vendedor
            }

        }
        break;
        case 12:{//Suscribirse a notis
            std::string cliente;
            std::cout<<"Ingrese el nickname del cliente";
            std::cin >>cliente;

            std::list<std::string> vendnosus=ControladorUsuario->getVendedoresNoSuscrito(cliente);
            for (auto i = vendnosus.begin(); i !=vendnosus.end(); ++i){
                std::cout << &i;
            }

            std::list<std::string> asuscribirse;
            
            std::cout<<"Ingrese el nickname del vendedor que se quiere suscribir";

            int i=1;
            while (i){
                std::string agregar;
                std::cin >> agregar;
                asuscribirse.push_front(agregar);

                std::cout <<"Desea Suscribirse a otro vendedor?"<<"\n 0-No"<<"1-Sí";
                std::cin >>i;
            }
            ControladorUsuario->suscribirVendedores(asuscribirse,cliente);

        }
        break; 
        case 13:{//Consulta de Notificaciones
            std::string cliente;
            std::cout<<"Ingrese el nickname del cliente";
            std::cin >>cliente;
            std::list<DTNotificacion*> notis=ControladorUsuario->consultarNotificaciones(cliente);
            for (auto i = notis.begin(); i !=notis.end(); ++i){
                std::cout<<&i;
            }
        }
        break;
        case 14:{ //eliminar Suscripciones
            std::string cliente;
            std::cout<<"Ingrese el nickname del cliente";
            std::cin >>cliente;

             std::list <std::string*> vendsus=ControladorUsuario->getVendedoresSuscrito(cliente);

            for (auto i =vendsus.begin(); i !=vendsus.end(); i++){
                std::cout<<&i;
            }

        } 
        break;

        default:
            std::cout<<"\n Ese número no es correcto, Ingerese otro número dentro de las opciones\n";
            break;
        }
    }

};