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


int main() {
    std::cout << "\n";
    int i =-2;
    while ( i !=0 ){
        std::cout << "¿Qué operación deseas realizar?\n";
        std::cout << "1-Creación de Usuario \n"<<" 2-Listado de Usuarios \n"<< "3-Alta de Producto";
        std::cin>>i;
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

            std::string separador;
            std::cout <<"Ingrese la fecha de nacimiento con el formato DD/MM/YYYY\n";
            int dia,mes,anio;
            std::cin >> dia>>separador>>mes>>separador>>anio;
            
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

                nuevoCliente=Cliente(nickname,password,DTFecha(dia,mes,anio,0,0),direccion,ciudad);
                
                //Aca hay que hacerle ctrlUsuario.altadeUsuario(nuevoCliente);

                }else{
                Vendedor nuevoVendedor;

                std::string RUT;
                std::cout <<"Ingrese el número de RUT\n";
                std::cin >>RUT;
                std::cout <<"\n";

                nuevoVendedor=Vendedor(nickname,password,DTFecha(dia,mes,anio,0,0),RUT);

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
        //Aca hay que crear instancia de controlador Usuario

        std::cout<< "Ingrese el nickname de uno de los siguientes Vendedores a cargo del producto \n";

        std::vector<std::string> Nicknames;//=ctrlUsuario.listarNicknames Notar qe lista vendedores nomas
        for (int j = 0; j < Nicknames.size(); j++){
            //std::cout <<Nicknames[j]->toString();
        }

        std::string vendedor;
        std::cin >> vendedor;
        
        //ctrlUsuario.selectNick(vendedor);

        std::string nomProd;
        std::cout << "Nombre del producto a ingresar\n";
        std::cin >> nomProd;

        //ctrlUsuario.altaDeProducto()

        }
        
        default:
            std::cout<<"\n Ese número no es correcto, Ingerese otro número dentro de las opciones\n";
            break;
        }
    }

};