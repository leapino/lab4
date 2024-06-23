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

void ImprimirComentarios(std::list <DTComentario> comentarios){
    for (auto i =comentarios.begin(); i !=comentarios.end(); i++)
    {
        std::cout << *i;

        if(!i->getRespuestas().empty())
            std::cout << "\n Respuestas comentario con id "<<i->getIdCom();
            ImprimirComentarios(i->getRespuestas());   
    }
}

DTFecha leerFecha(){
    int dia,mes,anio;
    std::string separador;
    std::cout <<"Ingrese la fecha con el formato DD/MM/YYYY\n";
    std::cout <<"dia\n";
    std::cin >> dia;
    std::cout <<"mes\n";
    std::cin >>mes;
    std::cout <<"anio\n";
    std::cin >>anio;
    std::cout <<"\n";
    DTFecha creada=DTFecha(dia,mes,anio,0,0);
    std::cout <<creada<<"\n";

    return creada;
}

//hola
int main() {

    ControladorFecha* ControladorFecha = ControladorFecha::getInstancia();
    ControladorProducto* ControladorProducto = ControladorProducto::getInstancia();
    ControladorUsuario* ControladorUsuario = ControladorUsuario::getInstancia();

    DTFecha fechaactual=leerFecha();


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
    infoProd1.insert(2, 1);
    infoProd1.insert(4, 1);
    infoProd1.insert(8, 1);
    DTFecha fecha11 = DTFecha(25, 10, 2024, 0, 0);

    ControladorProducto->confirmarAltaPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", 30, fecha11, infoProd1);
    
    std::map<int, int> infoProd2;
    infoProd2.insert(3, 2);
    infoProd2.insert(6, 3);
    DTFecha fecha12 = DTFecha(26, 10, 2024, 0, 0);

    ControladorProducto->confirmarAltaPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", 20, fecha12, infoProd2);

    std::map<int, int> infoProd3;
    infoProd3.insert(5, 2);
    DTFecha fecha13 = DTFecha(26, 10, 2024, 0, 0);

    ControladorProducto->confirmarAltaPromocion("Domotica", "Para modernizar tu casa", 10, fecha13, infoProd3);

    std::map<int, int> infoProd4;
    infoProd4.insert(14, 1);
    DTFecha fecha14 = DTFecha(26, 3, 2024, 0, 0);

    ControladorProducto->confirmarAltaPromocion("Liquidacion", "Hasta agotar stock", 10, fecha14, infoProd4);


    //COMPRAS
    std::map<int, int> productosCompra1;
    productosCompra1.insert(2, 2);
    productosCompra1.insert(4, 1);
    productosCompra1.insert(8, 1);
    DTFecha fechaC1 = DTFecha(1, 5, 2024, 0, 0);
    
    std::map<int, int> productosCompra2;
    productosCompra2.insert(5, 1);
    DTFecha fechaC2 = DTFecha(1, 5, 2024, 0, 0);

    std::map<int, int> productosCompra3;
    productosCompra3.insert(14, 10);
    DTFecha fechaC3 = DTFecha(15, 5, 2024, 0, 0);

    std::map<int, int> productosCompra4;
    productosCompra4.insert(11, 1);
    productosCompra4.insert(12, 1);
    productosCompra4.insert(13, 1);
    DTFecha fechaC4 = DTFecha(25, 4, 2024, 0, 0);

    std::map<int, int> productosCompra5;
    productosCompra5.insert(3, 2);
    productosCompra5.insert(6, 3);
    DTFecha fechaC5 = DTFecha(20, 5, 2024, 0, 0);

    std::map<int, int> productosCompra6;
    productosCompra6.insert(1, 2);
    DTFecha fechaC6 = DTFecha(12, 5, 2024, 0, 0);

    std::map<int, int> productosCompra7;
    productosCompra7.insert(1, 3);
    DTFecha fechaC7 = DTFecha(13, 5, 2024, 0, 0);

    std::map<int, int> productosCompra8;
    productosCompra8.insert(1, 4);
    DTFecha fechaC8 = DTFecha(14, 5, 2024, 0, 0);


    std::map<int, int> productosCompra9;
    productosCompra8.insert(1, 5);
    DTFecha fechaC9 = DTFecha(15, 5, 2024, 0, 0);


    ControladorUsuario->confirmarCompra(productosCompra1, 68389.293, "juan87", fechaC1);
    ControladorUsuario->confirmarCompra(productosCompra2, 599.99, "juan87", fechaC2);
    ControladorUsuario->confirmarCompra(productosCompra3, 150000, "laura", fechaC3);
    ControladorUsuario->confirmarCompra(productosCompra4, 11734, "natalia", fechaC4);
    ControladorUsuario->confirmarCompra(productosCompra5, 1263.984, "juan87", fechaC5);
    ControladorUsuario->confirmarCompra(productosCompra6, 2800, "laura", fechaC6);
    ControladorUsuario->confirmarCompra(productosCompra7, 4200, "natalia", fechaC7);
    ControladorUsuario->confirmarCompra(productosCompra8, 5600, "pablo10", fechaC8);
    ControladorUsuario->confirmarCompra(productosCompra9, 7000, "roberto", fechaC9);

    ControladorUsuario->setProductoEnviado("juan87", fechaC1, 2);
    ControladorUsuario->setProductoEnviado("juan87", fechaC2, 5);
    ControladorUsuario->setProductoEnviado("laura", fechaC3, 14);
    ControladorUsuario->setProductoEnviado("natalia", fechaC4, 11);
    ControladorUsuario->setProductoEnviado("natalia", fechaC4, 12);
    ControladorUsuario->setProductoEnviado("natalia", fechaC4, 13);
    ControladorUsuario->setProductoEnviado("juan87", fechaC5, 6);
    ControladorUsuario->setProductoEnviado("natalia", fechaC7, 1);
    

    //FALTA LO DE LAS PROMOS DE LA PARTE 5.1
    //CREO QUE LA CAGUE EN SETPRODUCTOENVIADO CON LO DE LA KEY (POSIBLEMENTE EN NICKYFECHADEPRODENVIADO TAMBIEN)

    //COMENTARIOS

    ///////////////////////////////FIN DE CARGA DE DATOS///////////////////////////////

    std::cout << "\n";
    int i =-2;  
    while ( i !=0 ){

        std::cout << "¿Qué operación deseas realizar?\n";
        std::cout << "1-Creación de Usuario \n"<<"2-Listado de Usuarios \n"<< "3-Alta de Producto\n"<<"4-Consultar Producto\n"<<"5-Crear Promoción\n";
        std::cout << "6-Consultar Promoción \n"<<"7-Realizar Compra\n"<<"8-Dejar Comentario\n"<<"9-Eliminar Comentario\n"<<"10-Enviar Producto\n"<<"11-Expediente de Usuario\n";
        std::cout << "12-Suscribirse a Notificaciones\n"<<"13-Consulta Notificacion\n"<<"14-Eliminar Suscripciones\n"<<"0-Salir\n";
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
            

            int dia,mes,anio;
            std::string separador;
            std::cout <<"Inato DD/MM/YYYY\n";
            std::cout <<"d\n";
            std::cin >> dia;
            std::cout <<"\nm\n";
            std::cin >>mes;
            std::cout <<"\nanio";
            std::cin >>anio;
            std::cout <<"\n";
            DTFecha fecha=DTFecha(dia,mes,anio,0,0);
            std::cout <<fecha;

            std::cout <<"salio de crear la fecha";
            
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
              std::list<DTVendedor> listaV = ControladorUsuario->ListaUsuariosV();
              std::list<DTCliente> listaC = ControladorUsuario->ListaUsuariosC();
              for (std::list<DTVendedor>::iterator it = listaV.begin(); it != listaV.end(); it++){                 
                     std::cout<< *it;
              }
              for (std::list<DTCliente>::iterator it2 = listaC.begin(); it2 != listaC.end(); it2++){                 
                     std::cout<< *it2;
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
            std::cin >> nomProd;
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
            std::cin >>descripProd;
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
            std::cout <<"creo bien el producto";
            ControladorProducto->linkVendProd(nombreV);
        }    
        break;
        
        case 4:{//Consultar Producto
             std::map<int,std::string> prods=ControladorProducto->getProds();

            for (auto i = prods.begin(); i != prods.end(); ++i){
                std::cout <<"Codigo:"<<i->first<<"\n Nombre:"<<i->second;
            }
            std::string eleccion;
            std::cout <<"Ingresar Nombre o Código del producto\n";
            std::cin >>eleccion;
            
            std::map<std::string,DTProducto> amostrar=ControladorProducto->getInfoProd(eleccion);
            std::cout <<amostrar.begin()->first;
            std::cout <<amostrar.begin()->second;

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

            int dia,mes,anio;
            std::cout <<"Ingrese la fecha de vencimiento de la promoción ingresando primero el día, luego el mes y finalmente el año:\n";
            std::cin >> dia>>mes>>anio;
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

                for(it2 = productosVend.begin(); it2 != productosVend.end(); it++){
                    std::cout<< it2->first <<")" << " " << it2->second.getNombre() << "\n";
                }
                int numProd = 1;
                int cantMin;
                std::set<int> lista;
                while (numProd > 0){
                    std::cout<< "Número producto:\n";
                    std::cin>> numProd;
                    std::cout <<"\n";                    
                    if (numProd > 0 && lista.find(numProd) == lista.end()){
                        lista.insert(numProd);
                        DT2Producto prod = productosVend.find(numProd)->second;
                        bool tienePromo = ControladorProducto->checkPromo(prod.getCodigo());
                        if (!tienePromo){
                            std::cout<< "Cantidad mínima:\n";
                            std::cin>> cantMin;
                            std::cout <<"\n";
                            infoProd.insert(std::make_pair(numProd, cantMin));
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
                        ControladorProducto->confirmarAltaPromocion(nombreP, descriP, descuento, fecha, infoProd);
                        ControladorProducto->agregarPromoVendedor(nombreP, nicknames.find(numVend)->second);
                        std::cout<< "\nSe agregó la promoción\n";
                    }if (confirm == 0){
                        std::cout<< "\nNo se agregó la promoción\n";
                    }else{
                        std::cout<<"\nSe ingresó mal el número, intente denuevo\n";
                    }
                }
            }else{
                std::cout<< "El vendedor no tiene productos asignados.";
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
                    std::cin >>nombrePromo;
                    std::set<DTProducto> productos = ControladorProducto->getProductoPromo(nombrePromo);
                    DTVendedor vendedor = ControladorProducto->vendedorPromo(*productos.begin());
                    std::set<DTProducto>::iterator it2;
                    std::cout << "Vendedor que ofrece la promoción:\n";
                    std::cout << vendedor.getDTNickname();
                    std::cout << "\nProductos de la promoción:\n";
                    for (it2 = productos.begin(); it2 != productos.end(); it++){
                        std::cout << *it2;
                    }
                }
            }else{
                std::cout<< "No hay promociones disponibles.";
            }
        }
            break;
        case 7:{//Realizar Compra

            std::set <std::string> clientes=ControladorUsuario->listarClientes();

            for (auto i = clientes.begin(); i !=clientes.end(); i++)
            {
                std::cout<<*i<<"\n";
            }
            

            std::cout <<"Ingresar Nickname del Cliente que va a comprar\n";
            std::string cliente;
            std::cin >>cliente;//deberiamos chequear si el admin ingresa bien el cliente?

            std::set <DTProducto> productos=ControladorProducto->getProductosDisp();

            for(std::set<DTProducto>::iterator it=productos.begin();it!=productos.end();++it){
                std::cout <<*it;
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
                productoCompra.insert(std::make_pair(codigo,cantidad));

                std::cout<<"Desea agregar otro producto?\n"<<"0-No\n"<<"1-Sí\n";
                std::cin >> i;
            }

            int monto=0;


            ControladorUsuario->confirmarCompra(productoCompra,monto,cliente,fechaactual);

        }
            break;
        
        case 8:{//Dejar Comentario

            std::map<int, std::string> usuarios=ControladorUsuario->listarNickUsuarios();
            for (auto i = usuarios.begin(); i !=usuarios.end(); ++i){
                std::cout <<i->first<<"  "<<i->second;
            }
            
            std::cout <<"Ingrese el nickname que quiere dejar un comentario\n";
            std::string usuario;
            std::cin >>usuario;

            std::map <int,std::string>productos=ControladorProducto->getProds();
            for (auto i = productos.begin(); i !=productos.end(); ++i){
                std::cout<<"Codigo: " <<i->first<<"\n Nombre: "<<i->second;
            }
            
            std::cout <<"Ingrese el codigo del producto para dejar el comentario\n";
            int codProd;
            std::cin >> codProd;

            std::cout <<"Desea responder a un comentario existente o crear un nuevo comentario\n"<<"0-Nuevo Comentario\n"<<"1-Responder a un comentario existente\n";
            int alt;
            std::cin >>alt;


            std::cout <<"Ingrese el comentario\n";
                std::string comentario;
                std::cin >>comentario;

            if (alt){

                std::list <DTComentario> comentarios=ControladorProducto->listarComProd(codProd);
                std::cout<<"A que comentario quiere responder\n";

                ImprimirComentarios(comentarios);

                //funcion recursiva para imprimir sus comentarios y sus respuestas

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
            std::map<int ,std::string> comentarios = ControladorUsuario->listarComentario(nicknames.find(usu)->second);
            std::map<int ,std::string>::iterator it2;
            std::cout<<"Selecciona un comentario por su identificador:\n";
            for (it2 = comentarios.begin(); it2 != comentarios.end(); it2++){
                std::cout<< it2->first <<")" << " " << it2->second << "\n";
            }
            int id;
            std::cin >>id;
            ControladorUsuario->eliminarComentario(id,nicknames.find(usu)->second);
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
            std::cout << "Seleccione un producto por su número. \n";

            for(std::map<int, DT2Producto >::iterator it = productosNoEnviados.begin(); it != productosNoEnviados.end(); ++it) {
                std::cout<< it->first <<")" << " " << it->second.getNombre() << "\n";
            }
            std::cout << "aca";
            
            int numProdNoEnviado;
            std::cin >> numProdNoEnviado;

            int idProdNoEnv = productosNoEnviados.find(numProdNoEnviado)->second.getCodigo();

            std::map<int, std::pair<std::string, DTFecha>> nickYFecha = ControladorUsuario->nickYFechaDeProdNoEnviado(nombreVendedor, idProdNoEnv);
            std::map<int, std::pair<std::string, DTFecha>>::iterator iterator;
        
            std::cout << "Seleccione una compra por su número. \n";

            for(iterator = (nickYFecha).begin(); iterator != nickYFecha.end(); ++iterator) {

                std::cout<< iterator->first <<")" << " " << iterator->second.first << ", " << iterator->second.second << "\n";
            }

            int numCompra;
            std::cin >> numCompra;

            ControladorUsuario->setProductoEnviado(nombreVendedor, iterator->second.second, idProdNoEnv);
            
            
        }
        break; 
        case 11:{//Expediente de usuario

            std::map<int,std::string> nicknames=ControladorUsuario->listarNickUsuarios();

            for (std::map<int,std::string>::iterator it =nicknames.begin(); it!=nicknames.end(); ++it){

                std::cout << it->second<<"\n";
            }

            std::cout <<"Ingrese el nickname del usuario";
            std::string usuario;
            std::cin >>usuario;


            DTUsuario infoUsuario=ControladorUsuario->getInfoUsuario(usuario);
            std::cout << infoUsuario;


            if (ControladorUsuario->esCliente(usuario)){
                std::cout<<ControladorUsuario->getInfoCliente(usuario);

                std::list<DTCompra> compras=ControladorUsuario->getInfoComprasCliente(usuario);

                std::cout<< "\n Compras:";
                
                for (const auto i:compras)
                {
                    std::cout<<i<<"\n";
                }
                
            }else{
                std::cout<<ControladorUsuario->getInfoVendedor(usuario);
                
                std::cout<<"\n Productos:";

                std::list <DTProducto> prods=ControladorUsuario->getProdEnVenta(usuario);
                for (const auto i:prods ){
                    std::cout<<i<<"\n";
                }
                
                std::cout<<"\n Promociones:";

                std::list <DTPromocion> promos=ControladorUsuario->getPromoVigente(usuario,fechaactual);
                for(const auto & i:promos)
                    std::cout<<i<<"\n";
            }

        }
        break;
        case 12:{//Suscribirse a notis
            std::string cliente;
            std::cout<<"Ingrese el nickname del cliente";
            std::cin >>cliente;

            std::list<std::string> vendnosus=ControladorUsuario->getVendedoresNoSuscrito(cliente);
            for (auto i = vendnosus.begin(); i !=vendnosus.end(); ++i){
                std::cout << *i;
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
            std::list<DTNotificacion> notis=ControladorUsuario->consultarNotificaciones(cliente);
            for (auto i = notis.begin(); i !=notis.end(); ++i){
                std::cout<<*i;
            }
        }
        break;
        case 14:{ //eliminar Suscripciones
            std::string cliente;
            std::cout<<"Ingrese el nickname del cliente";
            std::cin >>cliente;

            std::list <std::string> vendsus=ControladorUsuario->getVendedoresSuscrito(cliente);

            for (auto i =vendsus.begin(); i !=vendsus.end(); i++){
                std::cout<<*i;
            }

            std::list<std::string> aeliminar;
            int i;
            std::cout << "Desea Desuscribirse de algun \n"<<"0-No\n"<<"1-Sí";
            std::cin >>i;
            while(i){
                std::string vendedor;
                std::cout <<"Ingrese el nickname del vendedor";
                std::cin >> vendedor;

                ControladorUsuario->eliminarSusVendedores(cliente,vendedor);

                std::cout << "Desea Desuscribirse de algun otro? \n"<<"0-No\n"<<"1-Sí";
            }            

        } 
        break;

        default:
            std::cout<<"\n Ese número no es correcto, Ingerese otro número dentro de las opciones\n";
            break;
        }
    }

};