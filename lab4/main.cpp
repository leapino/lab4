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

    std::cout << "\n";
    int i =-2;

    while ( i !=0 ){

        std::cout << "¿Qué operación deseas realizar?\n";
        std::cout << "1-Creación de Usuario \n"<<" 2-Listado de Usuarios \n"<< "3-Alta de Producto\n"<<"4-Consultar Producto\n"<<"5-Crear Promoción\n";
        std::cout << "6-Consultar Promoción \n";
        std::cin>>i;
        std::cout <<"\n";


        switch (i){

        case 1:{//Crear Usuario
            bool Confirmar=false;
            int cliente;
            std::cout << "Si es vendedor ingrese 0, si es cliente ingrese 1\n";
            std::cin >>cliente;
            std::cout <<"\n";

            std::string nickname;
            std::cout <<"Ingrese el nickname del usuario\n";
            std::cin >>nickname;
            std::cout <<"\n";

            std::string password;
            std::cout <<"Ingrese la contraseña\n";
            std::cin >>password;
            std::cout <<"\n";
            
            DTFecha fecha=leerFecha();
            
            //Aca hay q crear la instancia de Controlador Usuario 

            if (cliente){
                Cliente nuevoCliente;

                std::string direccion;
                std::cout <<"Ingrese la dirección del Cliente\n";
                std::cin >>direccion;
                std::cout <<"\n";

                std::string ciudad;                
                std::cout <<"Ingrese la Ciudad \n";
                std::cin >>ciudad;
                std::cout <<"\n";

                nuevoCliente=Cliente(nickname,password,fecha,direccion,ciudad);
                
                //Aca hay que hacerle ctrlUsuario.altadeUsuario(nuevoCliente);

                }else{
                Vendedor nuevoVendedor;

                std::string RUT;
                std::cout <<"Ingrese el número de RUT\n";
                std::cin >>RUT;
                std::cout <<"\n";

                nuevoVendedor=Vendedor(nickname,password,fecha,RUT);

                //aca hay que hacer ctrlUsuario.altaDeUsuario(nuevoVendedor);
            }

            if (Confirmar)
                std::cout << "El usuario se a creado correctamente";
                else{
                std::cout<< "El usuario no se creo correctamente\n";
                std::cout<< "Revise si el nickname utilizado es único\n";
                }
        }
            break;

        case 2:{//LIstado de Usuarios, muestra el nick , la fecha de nacimiento y los datos de cliente o vendedor

            //Aca hay q crear la instancia de Controlador Usuario

            std::vector<DTUsuario> infousuarios;//=ctrlUsuario.listarUsuarios();
            for(int j=0;j<infousuarios.size();j++)
                j=j+1;//esta aca para q no salten errores
                //std::cout <<infousuarios[j]->toString();Falta hacer el toString
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
            std::map<std::string,int> InfoProd;
            //Crear Controlador Producto
            //InfoProd=ctrlProd.ListarCodNom();
            for (std::map<std::string, int>::iterator it = InfoProd.begin(); it != InfoProd.end(); ++it) {
                std::cout << it->first << "     " << it->second << std::endl;
            } 
            std::string eleccion;
            std::cout <<"Ingresar Nombre o Código del producto\n";
            std::cin >>eleccion;
            //DTProducto elegido=SelecCodName(eleccion);
            //std::cout<<elegido->toString();
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

            //Crear COntrolador Producto            
            //ctrlProd.ingrDatosPromocion(nombreP,descriP,decuento,fecha);

            selecVendedor();
            //vector<DTProducto> ProductosdelVendedor=ctrlProd.listarProductos(sacar vendedor guardado en linea anterior);
            /*for (int j = 0; i < productosdelVendedor.size(); i++){
                std::cout<<productosdelVendedor[j]->toString();
            }*/
            

            int agregarmasprod=1;
            while(agregarmasprod){

                int eleccion;
                std::cout <<"Ingresar Código del producto a agregar a la promoción\n";
                std::cin >>eleccion;
                std::cout <<"\n";

                int cantmin;
                std::cout <<"Ingresar cantidad mínima de compra del Producto para aplicar la promo\n";
                std::cin >>cantmin;
                std::cout <<"\n";
 
                /*bool prodAptoparaPromocion=
                if (prodAptoparaPromocion)
                    agregarProducto(eleccion,cantmin);
                else
                    std::cout <<"Producto no apto para Promoción\n";
                */
                std::cout <<"Desea ingresar mar productos\n"<<"0-No\n"<<"1-Si\n";
                std::cin >>agregarmasprod;
            }
            //CtrlProd.ConfirmarAltaPromocion();
        }
        case 6:{//Consultar Promocion
            

        }
            break;

        default:
            std::cout<<"\n Ese número no es correcto, Ingerese otro número dentro de las opciones\n";
            break;
        }
    }

};