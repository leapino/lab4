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

int main() {
    std::cout << "\n";
    int i =-2;
    while ( i !=0 ){
        std::cout << "¿Qué operación deseas realizar?\n";
        std::cout << "1-Creación de Usuario";
        std::cin>>i;
        std::string aux;
        switch (i){
        case 1:{//Crear Usuario
            std::cout << "Si es vendedor ingrese 0, si es cliente ingrese 1\n";
            int cliente;
            std::cin >>cliente;
            std::cout <<"\n";

            DTUsuario nuevo;
            nuevo.setDTesCliente(cliente);

            std::cout <<"Ingrese el nickname del usuario\n";
            std::cin >>aux;
            nuevo.setDTNickname(aux);
            std::cout <<"\n";

            std::cout <<"Ingrese la fecha de nacimiento con el formato DD/MM/YYYY\n";
            int dia,mes,anio;
            std::cin >> dia>>aux>>mes>>aux>>anio;
            nuevo.setDTNacimiento(DTFecha(dia,mes,anio,0,0));

            if (nuevo.getDTesCliente()){
                DTCliente nuevoCliente;
                std::cout <<"Ingrese la dirección del Cliente\n";
                std::cin >>aux;
                nuevoCliente.setDTAdress(aux);
                std::cout <<"\n";
                std::cout <<"Ingrese la Ciudad \n";
                std::cin >>aux;
                nuevoCliente.setDTCiudad(aux);
                nuevo.setpDTCliente(&nuevoCliente);

                }else{
                DTVendedor nuevoVendedor;
                std::cout <<"Ingrese el número de RUT";
                std::cin >>aux;
                nuevoVendedor.setDTRUT(aux);
                nuevo.setpDTVendedor(&nuevoVendedor);

            }
            bool Confirmar=ControladorUsuario.altadeUsuario();
            if (Confirmar)
                std::cout << "El usuario se a creado correctamente";
                else{
                std::cout<< "El usuario no se creo correctamente\n";
                std::cout<< "Revise si el nickname utilizado es único\n";
                }
        }
            break;
        case 2:{//Crear un producto
        
        }
        
        default:
            std::cout<<"\n Ese número no es correcto, Ingerese otro número dentro de las opciones\n";
            break;
        }
    }

};