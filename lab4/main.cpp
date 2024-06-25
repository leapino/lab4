#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include "declaraciones/DTFecha.h"
#include "declaraciones/DTUsuario.h"
#include "declaraciones/DTCliente.h"
#include "declaraciones/DTVendedor.h"
#include "declaraciones/DTProducto.h"
#include "declaraciones/controladorUsuario.h"
#include "declaraciones/controladorProducto.h"
#include "declaraciones/controladorFecha.h"
#include "declaraciones/usuario.h"
#include "declaraciones/cliente.h"
#include "declaraciones/vendedor.h"
#include "declaraciones/categoria.h"
#include "declaraciones/comentario.h"
#include "declaraciones/DTComentario.h"
using namespace std; 

void ImprimirComentarios(std::list <DTComentario> comentarios){
    if (comentarios.size()>0){
        std::cout<<"\n";
        for (auto i =comentarios.begin(); i !=comentarios.end(); i++)
        {
            std::cout << *i<<"\n";

            if(!i->getRespuestas().empty())
                std::cout << "\n Respuestas comentario con id "<<i->getIdCom();
                ImprimirComentarios(i->getRespuestas());
                std::cout <<"\n";   
        }
    }
}

DTFecha leerFecha(){
    int dia,mes,anio;
    std::string separador;
    std::cout <<"Ingrese la fecha actual del sistema\n";
    std::cout << "dia\n";
    std::cin >> dia;
    std::cout <<"mes\n";
    std::cin >>mes;
    std::cout <<"anio\n";
    std::cin >>anio;
    std::cout <<"\n";
    DTFecha creada=DTFecha(dia,mes,anio,0,0);

    return creada;
}

int main() {

    ControladorFecha* ControladorFecha = ControladorFecha::getInstancia();
    ControladorProducto* ControladorProducto = ControladorProducto::getInstancia();
    ControladorUsuario* ControladorUsuario = ControladorUsuario::getInstancia();

    DTFecha fechaactual=leerFecha();
    ControladorFecha->setFecha(fechaactual);


   

    std::cout << "\n";
    int i =-2;
    int looppreventer=0;
    while (( i !=0 )&&(looppreventer<3)){

        std::cout << "¿Qué operación deseas realizar?\n";
        std::cout << "1-Creación de Usuario \n"<<"2-Listado de Usuarios \n"<< "3-Alta de Producto\n"<<"4-Consultar Producto\n"<<"5-Crear Promoción\n";
        std::cout << "6-Consultar Promoción \n"<<"7-Realizar Compra\n"<<"8-Dejar Comentario\n"<<"9-Eliminar Comentario\n"<<"10-Enviar Producto\n"<<"11-Expediente de Usuario\n";
        std::cout << "12-Suscribirse a Notificaciones\n"<<"13-Consulta Notificacion\n"<<"14-Eliminar Suscripciones\n"<<"15-Cambiar fecha del sistema\n"<<"16- PreCarga de Datos\n"<<"0-Salir\n";
        std::cout <<"\n";
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline (std::cin,password);
            std::cout <<"\n";
            

            int dia,mes,anio;
            std::string separador;
            std::cout <<"Ingrese la Fecha de Nacimiento \n";
            std::cout <<"día\n";
            std::cin >> dia;
            std::cout <<"\nmes\n";
            std::cin >>mes;
            std::cout <<"\naño\n";
            std::cin >>anio;
            std::cout <<"\n";
            DTFecha fecha=DTFecha(dia,mes,anio,0,0);
            
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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline (std::cin,direccion);
                std::cout <<"\n";

                std::string ciudad;                
                std::cout <<"Ingrese la Ciudad \n";
                std::getline (std::cin,ciudad);
                std::cout <<"\n";

               ControladorUsuario->altaDeUsuario(nickname,password,fecha,direccion,ciudad);

                }else{
                
                std::string RUT;
                std::cout <<"Ingrese el número de RUT\n";
                std::cin >>RUT;
                std::cout <<"\n";
     
                ControladorUsuario->altaDeUsuario(nickname,password,fecha,RUT);

            }
            std::cout << "El usuario se a creado correctamente\n\n";
          }  
            else{            
                if (estanom == true)
                 std::cout<< "Ese nickname ya esta en uso, elija otro\n";
                if (contrabien == false)
                 std::cout<< "Su contraseña tiene menos de 6 caracteres, ingrese una con 6 o mas caracteres\n";
             }   
        }  
         
            break;

        case 2:{//LIstado de Usuarios, muestra el nick , la fecha de nacimiento y los datos de cliente o vendedor
              std::list<DTVendedor> listaV = ControladorUsuario->ListaUsuariosV();
              std::list<DTCliente> listaC = ControladorUsuario->ListaUsuariosC();
              for (std::list<DTVendedor>::iterator it = listaV.begin(); it != listaV.end(); it++){                 
                     std::cout<< *it<<"\n";
              }
              for (std::list<DTCliente>::iterator it2 = listaC.begin(); it2 != listaC.end(); it2++){                 
                     std::cout<< *it2<<"\n";
              }  
        }
            break;

        case 3:{//alta de Producto
           std::map<int ,std::string> nicknames = ControladorProducto->listarNicknamesV();
            std::map<int ,std::string>::iterator it;
            std::cout<<"Selecciona un vendedor por su número:\n";
            for (it = nicknames.begin(); it != nicknames.end(); it++){
                std::cout<< it->first <<")" << " " << it->second << "\n";
            }
            int numVend;
            std::cin >> numVend;
            std::string nombreV = nicknames.find(numVend)->second;

            std::string nomProd;
            std::cout << "Nombre del producto a ingresar\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline (std::cin,nomProd);
            std::cout <<"\n";

            double precio;
            std::cout <<"Precio del Producto\n";
            std::cin >>precio;
            std::cout <<"\n";

            int stock;
            std::cout <<"Stock\n";
            std::cin >>stock;
            std::cout <<"\n";

            std::string descripProd;
            std::cout <<"Descipción del producto\n";
            std::getline(std::cin,descripProd);
            std::cout <<"\n";

            Categoria categoria;
            int j;
            std::cout <<"Categoria de su producto\n"<<"1-Ropa\n"<<"2-Electrodomestico\n"<<"3-Otro\n";
            std::cin >>j;
            
            switch (j)
            {
            case 1:
                  categoria = ropa;
                break;
            case 2:
                  categoria = electrodomestico;
                break;
            case 3:
                  categoria = otro;
                break;
            default:
                std::cout<<"\n Ese número no es correcto, Ingerese otro número dentro de las opciones\n";
                break;
            }
            ControladorProducto->altaDeProducto(nomProd,precio,stock,descripProd,categoria);
            std::cout <<"Se creó el producto correctamente\n\n";
            ControladorProducto->linkVendProd(nombreV);
        }    
        break;
        
        case 4:{//Consultar Producto
             std::map<int,std::string> prods=ControladorProducto->getProds();

            for (auto i = prods.begin(); i != prods.end(); ++i){
                std::cout <<"Codigo:"<<i->first<<"-----"<<"Nombre:"<<i->second<<"\n";
            }
            std::string eleccion;
            std::cout <<"Ingresar codigo del producto\n";
            std::cout<<"\n";
            std::cin >>eleccion;
            std::cout <<"\n";
            
            std::map<std::string,DTProducto> amostrar=ControladorProducto->getInfoProd(eleccion);
            std::cout <<"Vendedor: "<<amostrar.begin()->first<<"\n";
            std::cout <<amostrar.begin()->second<<"\n";

        }
        break;

        case 5:{//Crear Promocion

            
            std::cout<<"Ingresar el nombre de la promoción\n";
            std::string nombreP;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline (std::cin,nombreP);

            
            std::cout<<"Ingresar la descripción de la promoción\n";
            std::string descriP;
            std::getline (std::cin,descriP);

            float descuento;
            std::cout <<"Ingresar Descuento\n";
            std::cin >>descuento;

            int dia,mes,anio;
            std::cout <<"Ingrese la fecha de vencimiento de la promoción con el formato DD/MM/YYYY\n";

            std::cout <<"dia\n";
            std::cin >> dia;
            std::cout <<"mes\n";
            std::cin >>mes;
            std::cout <<"anio\n";
            std::cin >>anio;
            std::cout <<"\n";
            
            DTFecha fecha = DTFecha(dia,mes,anio,0,0);
            
            std::map<int ,std::string> nicknames = ControladorProducto->listarNicknamesV();
            std::map<int ,std::string>::iterator it;
            std::cout<<"Selecciona un vendedor por su número:\n";
            for (it = nicknames.begin(); it != nicknames.end(); it++){
                std::cout<< it->first <<")" << " " << it->second << "\n";
            }
            int numVend;
            std::cin >> numVend;
            std::map<int, DT2Producto> productosVend = ControladorProducto->listarProductos(nicknames.find(numVend)->second);
            std::map<int, DT2Producto>::iterator it2;
            if (productosVend.size() != 0){
                std::cout<<"\nIngrese un producto del vendedor que desee agregar junto a su cantidad mínima o ingrese 0 para no agregar más:\n";
                std::map<int, int> infoProd;

                for(it2 = productosVend.begin(); it2 != productosVend.end(); it2++){
                    std::cout<< it2->first <<")" << " " << it2->second.getNombre() << "\n";
                }
                int numProd = 1;
                int cantMin;
                std::set<int> lista;
                while (numProd > 0){
                    std::cout<< "Número producto:\n";
                    std::cin>> numProd;
                    std::cout <<"\n";                    
                    if (numProd > 0){
                        DT2Producto prod = productosVend.find(numProd)->second;
                        bool tienePromo = ControladorProducto->checkPromo(prod.getCodigo());
                        if (!tienePromo && lista.find(numProd) == lista.end()){
                            lista.insert(numProd);
                            std::cout<< "Cantidad mínima:\n";
                            std::cin>> cantMin;
                            std::cout <<"\n";
                            infoProd.insert(std::make_pair(prod.getCodigo(), cantMin));
                        }
                        else{
                            std::cout<< "Este producto ya se encuentra en una promoción\n";
                        }
                    }
                }
                int confirm = 2;
                while (confirm != 1 && confirm!= 0)
                {
                    std::cout<< "Ingrese 1 si desea confirmar la creación de la promoción o 0 si no:\n";
                    std::cin>> confirm;
                    switch (confirm)
                    {
                    case 1:
                        ControladorProducto->confirmarAltaPromocion(nombreP, descriP, descuento, fecha, infoProd, nicknames.find(numVend)->second);
                        std::cout<< "\nSe agregó la promoción\n";
                        break;
                    case 0:
                        std::cout<< "\nNo se agregó la promoción\n";
                        break;
                    default:
                        std::cout<<"\nSe ingresó mal el número, intente denuevo\n";
                        break;
                    }
                }
            }else{
                std::cout<< "El vendedor no tiene productos asignados.\n";
            }
        }
        break;
        case 6:{//Consultar Promocion
            std::map<std::string, DTPromocion> promociones = ControladorProducto->getPromos();
            std::map<std::string, DTPromocion>::iterator it;
            if (promociones.size() != 0){
                for (it = promociones.begin(); it != promociones.end(); it++){
                    std::cout<< it->second;
                }
                int confirm;
                std::cout << "Desea consultar una promoción?\n1)Si\n2)No\n";
                std::cin>> confirm;
                if (confirm == 1){
                    std::cout <<"Ingresar nombre de la promocion que desea consultar:\n";
                    std::string nombrePromo;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline (std::cin,nombrePromo);
                    std::set<DTProducto> productos = promociones.find(nombrePromo)->second.getProductos();
                    DTVendedor vendedor = ControladorProducto->vendedorPromo(*productos.begin());
                    std::set<DTProducto>::iterator it2;
                    std::cout << "Vendedor que ofrece la promoción:\n";
                    std::cout << "\nDescuento de la promoción:\n";
                    std::cout << promociones.find(nombrePromo)->second.getDescuento() <<"%";

                    std::cout << vendedor.getDTNickname();
                    std::cout << "\nDescuento de la promoción:\n";
                    std::cout << promociones.find(nombrePromo)->second.getDescuento() <<"%";
                    std::cout << "\nProductos de la promoción:\n";
                    for (it2 = productos.begin(); it2 != productos.end(); it2++){
                        std::cout << *it2;
                    }
                }
            }else{
                std::cout<< "No hay promociones disponibles.\n\n";
            }
        }
            break;
        case 7:{//Realizar Compra

            std::set <std::string> clientes=ControladorUsuario->listarClientes();

            std::cout <<"Ingresar Nickname del Cliente que va a comprar\n"<<"\n";

            for (auto i = clientes.begin(); i !=clientes.end(); i++)
            {
                std::cout<<*i<<"\n";
            }
            std::cout <<"\n";
           
            std::string cliente;
            std::cin >>cliente;//deberiamos chequear si el admin ingresa bien el cliente?

            std::set <DTProducto> productos=ControladorProducto->getProductosDisp();

            for(std::set<DTProducto>::iterator it=productos.begin();it!=productos.end();++it){
                std::cout <<*it<<"\n";
            }

            int i=1;
            std::cout <<"Desea ingresar producto a la compra\n"<<"0-No\n"<<"1-Sí\n"<<"\n";
            std::cin >>i;

            std::map <int,int> productoCompra;

            while(i){

                std::cout<<"Ingresar codigo del Producto\n"<<"\n";
                int codigo;

                std::cin>>codigo;
                
                std::cout<<"Ingresar cantidad del producto a comprar \n"<<"\n";
                int cantidad;
                std::cin >>cantidad;

                ControladorUsuario->agregarProductoCompra(codigo,cantidad);
                productoCompra.insert(std::make_pair(codigo,cantidad));

                std::cout<<"Desea agregar otro producto?\n"<<"0-No\n"<<"1-Sí\n"<<"\n";
                std::cin >> i;
            }

            double monto=0;


            DTCompra amostrar=ControladorUsuario->confirmarCompra(productoCompra,monto,cliente,fechaactual);
            
            std::cout<<"\n\n"<<amostrar;

        }
            break;
        
        case 8:{//Dejar Comentario

            std::cout <<"Ingrese el nickname que quiere dejar un comentario\n";

            std::map<int, std::string> usuarios=ControladorUsuario->listarNickUsuarios();
            for (auto j = usuarios.begin(); j !=usuarios.end(); ++j){
                std::cout <<j->first<<")"<<j->second<<"\n";
            }

            std::cout<<"\n";
            
            std::string usuario;
            std::cin >>usuario;
            std::cout<<"\n";

            std::cout <<"Ingrese el codigo del producto para dejar el comentario\n";

            std::map <int,std::string>productos=ControladorProducto->getProds();
            for (auto j = productos.begin(); j !=productos.end(); ++j){
                std::cout<<"Codigo: " <<j->first<<"-----Nombre: "<<j->second<<"\n";
            }
            std::cout <<"\n";
            
            int codProd;
            std::cin >> codProd;

            std::cout <<"Desea responder a un comentario existente o crear un nuevo comentario\n"<<"0-Nuevo Comentario\n"<<"1-Responder a un comentario existente\n";
            int k;
            std::cin >>k;


            std::cout <<"Ingrese el comentario: \n";
            std::string comentario;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(cin,comentario);

            if (k){

                std::list <DTComentario> comentarios=ControladorProducto->listarComProd(codProd);
                std::cout<<"A que comentario quiere responder\n";

                ImprimirComentarios(comentarios);

                std::cout <<"Ingrese el  id del comentario a responder\n";
                int idPrincipal;
                std::cin >>idPrincipal;

                ControladorUsuario->escribirCom(idPrincipal,comentario,fechaactual,codProd,usuario);

            }else
                ControladorUsuario->escribirCom(comentario,fechaactual,codProd,usuario);
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
            std::string user=nicknames.find(usu)->second;
            std::list<DTComentario> comentarios = ControladorUsuario->listarComentario(user);
            std::list<DTComentario>::iterator it2;
            std::cout<<"Selecciona un comentario por su identificador:\n";

            for (it2 = comentarios.begin(); it2 != comentarios.end(); it2++){
                std::cout << (*it2)<< "\n";
                std::cout<<"\n";
            }

            int id;
            std::cin >>id;
            ControladorUsuario->eliminarComentario(id,user);
        } 
        break;  
        case 10:{//Enviar Producto

            std::list<std::string> vendedores = ControladorUsuario->getVendedores();
            std::cout << "Seleccione un vendedor por su nombre \n";

            std::list<std::string>::iterator it;
            for(it = vendedores.begin(); it != vendedores.end(); it++) {
                std::cout << (*it) << "\n";
            }
            std::string nombreVendedor;
            std::cin >> nombreVendedor;

            std::map<int, DT2Producto > productosNoEnviados = ControladorUsuario->getProductosNoEnv(nombreVendedor);
            if(productosNoEnviados.size() != 0){
                std::cout << "Seleccione un producto por su número. \n";
                
                for(std::map<int, DT2Producto >::iterator it = productosNoEnviados.begin(); it != productosNoEnviados.end(); ++it) {
                    std::cout<< it->first <<")" << " " << it->second.getNombre() << "\n";
                }
                std::cout << "\n";
            }
            int numProdNoEnviado;
            std::cin >> numProdNoEnviado;

            int idProdNoEnv = productosNoEnviados.find(numProdNoEnviado)->second.getCodigo();

            std::map<int, std::pair<std::string, DTFecha>> nickYFecha = ControladorUsuario->nickYFechaDeProdNoEnviado(nombreVendedor, idProdNoEnv);
            std::map<int, std::pair<std::string, DTFecha>>::iterator iterator;
    
            if(!(nickYFecha).empty()) {

                std::cout << "Seleccione una compra por su número. \n";
                for(iterator = (nickYFecha).begin(); iterator != nickYFecha.end(); ++iterator) {

                    std::cout<< iterator->first <<")" << " " << iterator->second.first << ", " << iterator->second.second << "\n";
                }
                 std::cout << "\n";
            
            int numCompra;
            std::cin >> numCompra;
            ControladorUsuario->setProductoEnviado(nickYFecha.find(numCompra)->second.first, nickYFecha.find(numCompra)->second.second, idProdNoEnv);
            }
            else (std::cout << "El vendedor seleccionado no tiene envios pendientes. \n");
            std::cout << "\n";
        
        }
        break; 
        case 11:{//Expediente de usuario

            std::map<int,std::string> nicknames=ControladorUsuario->listarNickUsuarios();

            std::cout <<"Ingrese el nickname del usuario\n";

            for (std::map<int,std::string>::iterator it =nicknames.begin(); it!=nicknames.end(); ++it){

                std::cout << it->second<<"\n";
            }
            std::cout<<"\n";

            std::string usuario;
            std::cin >>usuario;


            if (ControladorUsuario->esCliente(usuario)){
                std::cout<<ControladorUsuario->getInfoCliente(usuario)<<"\n";

                std::list<DTCompra> compras=ControladorUsuario->getInfoComprasCliente(usuario);

                std::cout<< "\n Compras:";
                
                for (const auto i:compras)
                {
                    std::cout<<i<<"\n";
                }
                
            }else{
                std::cout<<ControladorUsuario->getInfoVendedor(usuario);
                
                std::cout<<"\n\nProductos:\n\n";

                std::list <DTProducto> prods=ControladorUsuario->getProdEnVenta(usuario);
                
                for (std::list<DTProducto>::iterator l=prods.begin();l!=prods.end();l++ ){
                    std::cout<<*l<<"\n";
                }
                
                std::cout<<"\nPromociones:\n";

                std::list <DTPromocion> promos=ControladorUsuario->getPromoVigente(usuario,fechaactual);
                for(std::list<DTPromocion>::iterator it=promos.begin();it!=promos.end();it++)
                    std::cout<<*it<<"\n";
            }   

        }
        break;
        case 12:{//Suscribirse a notis
            std::set <std::string> clientes=ControladorUsuario->listarClientes();

            std::cout <<"Ingresar Nickname del Cliente que va a suscribirse\n"<<"\n";

            for (auto i = clientes.begin(); i !=clientes.end(); i++)
            {
                std::cout<<*i<<"\n";
            }
            std::cout <<"\n";

            std::string cliente;
            std::cin >>cliente;

            std::list<std::string> vendnosus=ControladorUsuario->getVendedoresNoSuscrito(cliente);

            std:: cout<<"\nVendedores: \n";
            for (auto i = vendnosus.begin(); i !=vendnosus.end(); ++i){
                std::cout << *i<<"\n";
            }
            std::cout<<"\n";
            std::list<std::string> asuscribirse;

            int i=1;
            while (i){

                std::cout<<"Ingrese el nickname del vendedor que se quiere suscribir\n\n";
                std::string agregar;
                std::cin >> agregar;
                asuscribirse.push_front(agregar);

                std::cout <<"Desea Suscribirse a otro vendedor?"<<"\n 0-No    "<<"1-Sí\n";
                std::cin >>i;
            }
            ControladorUsuario->suscribirVendedores(asuscribirse,cliente);

        }
        break; 
        case 13:{//Consulta de Notificaciones

            std::set <std::string> clientes=ControladorUsuario->listarClientes();

            std::cout <<"Ingresar Nickname del Cliente para ver sus notificaciones\n"<<"\n";

            for (auto i = clientes.begin(); i !=clientes.end(); i++)
            {
                std::cout<<*i<<"\n";
            }
            std::cout <<"\n";

            std::string cliente;
            std::cin >>cliente;
            std::list<DTNotificacion> notis=ControladorUsuario->consultarNotificaciones(cliente);
            for (auto i = notis.begin(); i !=notis.end(); ++i){
                std::cout<<*i<<"\n";
            }

            if (notis.size()==0){
                std::cout <<"\n\n El cliente no tiene notificaciones de los vendedores que esta suscrito\n\n";
            }
            ControladorUsuario->limpiarNotificaciones(cliente);
        }
        break;
        case 14:{ //eliminar Suscripciones
            std::set <std::string> clientes=ControladorUsuario->listarClientes();

            std::cout <<"Ingresar Nickname del Cliente que va a desuscribirse\n"<<"\n";

            for (auto i = clientes.begin(); i !=clientes.end(); i++)
            {
                std::cout<<*i<<"\n";
            }
            std::cout <<"\n";
            
            std::string cliente;
            std::cin >>cliente;

            std::list <std::string> vendsus=ControladorUsuario->getVendedoresSuscrito(cliente);
            std::cout <<"\n";
            std::cout <<"Vendedores Suscritos:\n\n";
            for (std::list<std::string>::iterator i  =vendsus.begin(); i !=vendsus.end(); i++){
                std::cout<<*i<<"\n";
            }

            std::list<std::string> aeliminar;
            int i;
            std::cout << "Desea Desuscribirse de algun Vendedor \n"<<"0-No     "<<"1-Sí\n\n";
            std::cin >>i;

            while(i){
                std::string vendedor;
                std::cout <<"Ingrese el nickname del vendedor\n\n";
                std::cin >> vendedor;

                ControladorUsuario->eliminarSusVendedores(cliente,vendedor);

                std::cout << "Desea Desuscribirse de algun otro? \n"<<"0-No      "<<"1-Sí\n\n";
                std::cin >>i;
            } 
            
            
            std::list <std::string> vendsusnuevo=ControladorUsuario->getVendedoresSuscrito(cliente);
            std::cout <<"\n";
            std::cout <<"Vendedores Suscritos:\n\n";
            for (std::list<std::string>::iterator i  =vendsusnuevo.begin(); i !=vendsusnuevo.end(); i++){
                std::cout<<*i<<"\n\n";
            }
        } 
        break;
        case 15:{ //Cambiar fecha del sistema
            DTFecha nuevaFecha = leerFecha();
            ControladorFecha->setFecha(nuevaFecha);
        }
        break;
        case 16:{
                ///////////////////////////////////CARGA DE DATOS///////////////////////////////////
        //USUARIOS
        
        DTFecha fecha1 = DTFecha(15,5,1988,0,0);
        ControladorUsuario->altaDeUsuario("ana23", "qwer1234", fecha1, "212345678001");
        DTFecha fecha2 = DTFecha(18,6,1986,0,0);
        ControladorUsuario->altaDeUsuario("carlos78", "asdfghj", fecha2, "356789012345");
        DTFecha fecha3 = DTFecha(28,7,1993,0,0);
        ControladorUsuario->altaDeUsuario("diegom", "zxcvbn", fecha3, "190123456789");
        DTFecha fecha4 = DTFecha(20,10,1992,0,0);
        ControladorUsuario->altaDeUsuario("juan87", "1qaz2wsx", fecha4, "Av. 18 de Julio 456", "Melo");
        DTFecha fecha5 = DTFecha(22,9,1979,0,0);
        ControladorUsuario->altaDeUsuario("laura", "3edc4rfv", fecha5, "Rondeau 1617", "Montevideo");
        DTFecha fecha6 = DTFecha(25,3,1985,0,0);
        ControladorUsuario->altaDeUsuario("maria01", "5tgb6yhn", fecha6, "321098765432");
        DTFecha fecha7 = DTFecha(14,4,1982,0,0);
        ControladorUsuario->altaDeUsuario("natalia", "poiuyt", fecha7, "Paysandú 2021", "Salto");
        DTFecha fecha8 = DTFecha(30,11,1995,0,0);
        ControladorUsuario->altaDeUsuario("pablo10", "lkjhgv", fecha8, "Av. Rivera 1819", "Mercedes");
        DTFecha fecha9 = DTFecha(12,8,1990,0,0);
        ControladorUsuario->altaDeUsuario("roberto", "mnbvcx", fecha9, "Av. Brasil 1011", "Montevideo");
        DTFecha fecha10 = DTFecha(07,12,1983,0,0);
        ControladorUsuario->altaDeUsuario("sofia25", "1234asdf", fecha10, "445678901234");
        

        //PRODUCTOS 
        ControladorProducto->altaDeProducto("Camiseta Azul", 1400, 50, "Camiseta de poliester", ropa);
        ControladorProducto->linkVendProd("carlos78");

        ControladorProducto->altaDeProducto("Televisor LED", 40500, 30, "Televisor LED 55 pulgadas", electrodomestico);
        ControladorProducto->linkVendProd("ana23");

        ControladorProducto->altaDeProducto("Chaqueta de Cuero", 699.99, 20, "Chaqueta de cuero, color negro", ropa);
        ControladorProducto->linkVendProd("carlos78");

        ControladorProducto->altaDeProducto("Microondas Digital", 1199.99, 15, "Microondas digital, 30L", electrodomestico);
        ControladorProducto->linkVendProd("ana23");

        ControladorProducto->altaDeProducto("Luz LED", 599.99, 40, "Luz Bluetooth LED", otro);
        ControladorProducto->linkVendProd("diegom");

        ControladorProducto->altaDeProducto("Pantalones Vaqueros", 60, 25, "Pantalones vaqueros, talla 32", ropa);
        ControladorProducto->linkVendProd("carlos78");

        ControladorProducto->altaDeProducto("Auriculares Bluetooth", 199.99, 35, "Auriculares bluethooth para celular", otro);
        ControladorProducto->linkVendProd("diegom");

        ControladorProducto->altaDeProducto("Refrigerador", 15499, 10, "Refrigerador de doble puerta", electrodomestico);
        ControladorProducto->linkVendProd("ana23");

        ControladorProducto->altaDeProducto("Cafetera", 23000, 50, "Cafetera de goteo programable", electrodomestico);
        ControladorProducto->linkVendProd("ana23");

        ControladorProducto->altaDeProducto("Zapatillas Deportivas", 5500, 20, "Zapatillas para correr, talla 42", ropa);
        ControladorProducto->linkVendProd("carlos78");

        ControladorProducto->altaDeProducto("Mochila", 9000, 30, "Mochila de viaje, 40L", otro);
        ControladorProducto->linkVendProd("carlos78");

        ControladorProducto->altaDeProducto("Plancha de Ropa", 2534, 25, "Plancha a vapor, 1500W", electrodomestico);
        ControladorProducto->linkVendProd("diegom");

        ControladorProducto->altaDeProducto("Gorra", 200, 50, "Gorra para deportes, color rojo", ropa);
        ControladorProducto->linkVendProd("sofia25");

        ControladorProducto->altaDeProducto("Tablet", 15000, 15, "Tablet Android de 10 pulgadas", electrodomestico);
        ControladorProducto->linkVendProd("diegom");

        ControladorProducto->altaDeProducto("Reloj de Pared", 150.50, 20, "Reloj de pared vintage", otro);
        ControladorProducto->linkVendProd("sofia25"); 
        
        //PROMOCIONES
        std::map<int, int> infoProd1;
        infoProd1.insert(std::make_pair(2, 1));
        infoProd1.insert(std::make_pair(4, 1));
        infoProd1.insert(std::make_pair(8, 1));
        DTFecha fecha11 = DTFecha(25, 10, 2024, 0, 0);

        ControladorProducto->confirmarAltaPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", 30, fecha11, infoProd1, "ana23");
        
        std::map<int, int> infoProd2;
        infoProd2.insert(std::make_pair(3, 2));
        infoProd2.insert(std::make_pair(6, 3));
        DTFecha fecha12 = DTFecha(26, 10, 2024, 0, 0);

        ControladorProducto->confirmarAltaPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", 20, fecha12, infoProd2, "carlos78");

        std::map<int, int> infoProd3;
        infoProd3.insert(std::make_pair(5, 2));
        DTFecha fecha13 = DTFecha(26, 10, 2024, 0, 0);

        ControladorProducto->confirmarAltaPromocion("Domotica", "Para modernizar tu casa", 10, fecha13, infoProd3,"diegom");

        std::map<int, int> infoProd4;
        infoProd4.insert(std::make_pair(14, 1));
        DTFecha fecha14 = DTFecha(26, 3, 2024, 0, 0);

        ControladorProducto->confirmarAltaPromocion("Liquidacion", "Hasta agotar stock", 10, fecha14, infoProd4, "diegom");


        //COMPRAS
        std::map<int, int> productosCompra1;
        double monto1=0;
        productosCompra1.insert(std::make_pair(2, 2));
        productosCompra1.insert(std::make_pair(4, 1));
        productosCompra1.insert(std::make_pair(8, 1));
        DTFecha fechaC1 = DTFecha(1, 5, 2024, 0, 0);
        
        std::map<int, int> productosCompra2;
        double monto2=0;
        productosCompra2.insert(std::make_pair(5, 1));
        DTFecha fechaC2 = DTFecha(1, 5, 2024, 0, 0);

        std::map<int, int> productosCompra3;
        double monto3=0;
        productosCompra3.insert(std::make_pair(14, 10));
        DTFecha fechaC3 = DTFecha(15, 5, 2024, 0, 0);

        std::map<int, int> productosCompra4;
        double monto4=0;
        productosCompra4.insert(std::make_pair(11, 1));
        productosCompra4.insert(std::make_pair(12, 1));
        productosCompra4.insert(std::make_pair(13, 1));
        DTFecha fechaC4 = DTFecha(25, 4, 2024, 0, 0);

        std::map<int, int> productosCompra5;
        double monto5=0;
        productosCompra5.insert(std::make_pair(3, 2));
        productosCompra5.insert(std::make_pair(6, 3));
        DTFecha fechaC5 = DTFecha(20, 5, 2024, 0, 0);

        std::map<int, int> productosCompra6;
        double monto6=0;
        productosCompra6.insert(std::make_pair(1, 2));
        DTFecha fechaC6 = DTFecha(12, 5, 2024, 0, 0);

        std::map<int, int> productosCompra7;
        double monto7=0;
        productosCompra7.insert(std::make_pair(1, 3));
        DTFecha fechaC7 = DTFecha(13, 5, 2024, 0, 0);

        std::map<int, int> productosCompra8;
        double monto8=0;
        productosCompra8.insert(std::make_pair(1, 4));
        DTFecha fechaC8 = DTFecha(14, 5, 2024, 0, 0);


        std::map<int, int> productosCompra9;
        double monto9=0;
        productosCompra8.insert(std::make_pair(1, 5));
        DTFecha fechaC9 = DTFecha(15, 5, 2024, 0, 0);


        ControladorUsuario->confirmarCompra(productosCompra1, monto1, "juan87", fechaC1);  
        ControladorUsuario->confirmarCompra(productosCompra2, monto2, "juan87", fechaC2);
        ControladorUsuario->confirmarCompra(productosCompra3, monto3, "laura", fechaC3);
        ControladorUsuario->confirmarCompra(productosCompra4, monto4, "natalia", fechaC4);
        ControladorUsuario->confirmarCompra(productosCompra5, monto5, "juan87", fechaC5);
        ControladorUsuario->confirmarCompra(productosCompra6, monto6, "laura", fechaC6);
        ControladorUsuario->confirmarCompra(productosCompra7, monto7, "natalia", fechaC7);
        ControladorUsuario->confirmarCompra(productosCompra8, monto8, "pablo10", fechaC8);
        ControladorUsuario->confirmarCompra(productosCompra9, monto9, "roberto", fechaC9);


        ControladorUsuario->setProductoEnviado("juan87", fechaC1, 2);
         ControladorUsuario->setProductoEnviado("juan87", fechaC2, 5);
         ControladorUsuario->setProductoEnviado("laura", fechaC3, 14);
         ControladorUsuario->setProductoEnviado("natalia", fechaC4, 11);
         ControladorUsuario->setProductoEnviado("natalia", fechaC4, 12);
         ControladorUsuario->setProductoEnviado("natalia", fechaC4, 13);
         ControladorUsuario->setProductoEnviado("juan87", fechaC5, 6);
         ControladorUsuario->setProductoEnviado("natalia", fechaC7, 1);
        


        //COMENTARIOS
        DTFecha fecha36 = DTFecha(1,6,2024,0,0);
        ControladorUsuario->escribirCom("¿La camiseta azul esta disponible en talla M?",fecha36,1,"juan87");
        DTFecha fecha37 = DTFecha(1,6,2024,0,0);
        ControladorUsuario->escribirCom(0,"Si,tenemos la camiseta azul en talla M.",fecha37,1,"carlos78");
        DTFecha fecha38 = DTFecha(2,6,2024,0,0);
        ControladorUsuario->escribirCom(1,"¿Es de buen material? Me preocupa la durabilidad.",fecha38,1,"laura");
        DTFecha fecha39 = DTFecha(2,6,2024,0,0);
        ControladorUsuario->escribirCom(2,"He comprado antes y la calidad es buena",fecha39,1,"juan87");
        DTFecha fecha15 = DTFecha(2,6,2024,0,0);
        ControladorUsuario->escribirCom("¿Como es el ajuste? ¿Es ajustada o holgada?",fecha15,1,"natalia");
        DTFecha fecha16 = DTFecha(2,6,2024,0,0);
        ControladorUsuario->escribirCom("¿Cual es la resolucion del Televisor LED?",fecha16,2,"laura");
        DTFecha fecha17 = DTFecha(2,6,2024,0,0);
        ControladorUsuario->escribirCom(5,"El televisor LED tiene una resolucion de 4K UHD.",fecha17,2,"ana23");
        DTFecha fecha18 = DTFecha(3,6,2024,0,0);
        ControladorUsuario->escribirCom("¿Tiene soporte para HDR10?",fecha18,2,"pablo10");
        DTFecha fecha19 = DTFecha(3,6,2024,0,0);
        ControladorUsuario->escribirCom(7,"Si, soporta HDR10.",fecha19,2,"ana23");
        DTFecha fecha20 = DTFecha(3,6,2024,0,0);
        ControladorUsuario->escribirCom("¿La chaqueta de cuero es resistente al agua?",fecha20,3,"natalia");
        DTFecha fecha21 = DTFecha(3,6,2024,0,0);
        ControladorUsuario->escribirCom(9,"No, la chaqueta de cuero no es resistente al agua.",fecha21,3,"carlos78");
        DTFecha fecha22 = DTFecha(4,6,2024,0,0);
        ControladorUsuario->escribirCom(9,"¿Viene en otros colores?",fecha22,3,"laura");
        DTFecha fecha23 = DTFecha(4,6,2024,0,0);
        ControladorUsuario->escribirCom(11,"Si, tambien esta disponible en marron.",fecha23,3,"carlos78");
        DTFecha fecha24 = DTFecha(4,6,2024,0,0);
        ControladorUsuario->escribirCom(9,"¿Es adecuada para climas frios?",fecha24,3,"roberto");
        DTFecha fecha25 = DTFecha(4,6,2024,0,0);
        ControladorUsuario->escribirCom("¿El microondas digital tiene funcion de descongelacion rapida?",fecha25,4,"pablo10");
        DTFecha fecha26 = DTFecha(4,6,2024,0,0);
        ControladorUsuario->escribirCom(14,"Si, el microondas digital incluye una funcion de descongelacion rapida.",fecha26,4,"ana23");
        DTFecha fecha27 = DTFecha(5,6,2024,0,0);
        ControladorUsuario->escribirCom(14,"¿Cuantos niveles de potencia tiene?",fecha27,4,"natalia");
        DTFecha fecha28 = DTFecha(5,6,2024,0,0);
        ControladorUsuario->escribirCom(16,"Tiene 10 niveles de potencia.",fecha28,4,"ana23");
        DTFecha fecha29 = DTFecha(5,6,2024,0,0);
        ControladorUsuario->escribirCom(14,"¿Es facil de limpiar?",fecha29,4,"roberto");
        DTFecha fecha30 = DTFecha(5,6,2024,0,0);
        ControladorUsuario->escribirCom("¿La luz LED se puede controlar con una aplicacion movil?",fecha30,5,"roberto");
        DTFecha fecha31 = DTFecha(5,6,2024,0,0);
        ControladorUsuario->escribirCom(19,"Si, la luz LED se puede controlar a traves de una aplicacion movil.",fecha31,5,"diegom");
        DTFecha fecha32 = DTFecha(6,6,2024,0,0);
        ControladorUsuario->escribirCom(19,"¿Es compatible con Alexa o Google Home?",fecha32,5,"pablo10");
        DTFecha fecha33 = DTFecha(6,6,2024,0,0);
        ControladorUsuario->escribirCom(21,"Si, es compatible con ambos.",fecha33,5,"diegom");
        DTFecha fecha34 = DTFecha(6,6,2024,0,0);
        ControladorUsuario->escribirCom(19,"¿Cuanto dura la bateria?",fecha34,5,"natalia");
        DTFecha fecha35 = DTFecha(7,6,2024,0,0);
        ControladorUsuario->escribirCom(19,"¿La aplicacion movil es facil de usar?",fecha35,5,"pablo10");
        
        //PROMOCIONES

        std::cout <<"PreCarga de Datos realizada correctamente\n\n";
        ///////////////////////////////FIN DE CARGA DE DATOS///////////////////////////////
            }
            break;

        case 0:{
            std::cout <<"Desconexion Exitosa\n";
        }
        break;
        default:{
            std::cout<<"\nEse número no es correcto, Ingerese otro número dentro de las opciones\n";
            looppreventer++;
            if (looppreventer==3){
                std::cout<<"Se te desconectara del programa\n";
            }
        }

            break;
        }
    }

};