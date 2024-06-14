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

int main() {

    std::cout << "\n";
    int i =-2;
    while ( i !=0 ){
        std::cout << "¿Qué operación deseas realizar?\n";
        std::cin>>i;
        switch (i){
        case 1:{
            std::cout << "Si es vendedor ingrese 0, si es cliente ingrese 1\n";
            int cliente;
            std::cin >>cliente;
            std::cout <<"\n";
            DTUsuario nuevo;
            nuevo.DTesCliente=cliente;
            std::cout <<"Ingrese el nickname del usuario\n";
            std::cin >>nuevo.DTNickname;
            std::cout <<"\n";
            std::cout <<"Ingrese la fecha de nacimiento con el formato DD/MM/YYYY";
            int dia,mes,anio;
            std::cout <<"\n";
            std::cin >> dia >> "/">>mes>> "/" >>anio;
            nuevo.DTNacimiento=DTFecha(dia,mes,anio,0,0);
            if (nuevo.DTesCliente){
                DTCliente nuevoCliente;
                std::cout <<"Ingrese la dirección del Cliente\n";
                std::cin >>nuevoCliente.DTAdress;
                std::cout <<"\n";
                std::cout <<"Ingrese la Ciudad \n";
                std::cin >>nuevoCliente.DTCiudad;
                nuevo.pDTCliente=*nuevoCliente;
                
            }
        }
            break;
        
        default:
            std::cout<<"\n Ese número no es correcto, Escriba otro número dentro de las opciones\n";
            break;
        }
    }

};