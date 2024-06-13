#ifndef DTFECHA_H
#define DTFECHA_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class DTFecha{
    private:
        int hora;
        int minuto;
        int dia;
        int mes;
        int anio;
    public:
        //Creadores
        DTFecha();
        DTFecha(int,int,int,int,int);
        ~DTFecha();
        //Getters
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
        //Setters
        void setDia(int);
        void setMes(int);
        void setAnio(int);  
        void setHora(int);
        void setMinuto(int);   
};
#endif
