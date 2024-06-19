#ifndef DTFECHA_H
#define DTFECHA_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

struct DTFecha{
    private:
        int hora;
        int minuto;
        int dia;
        int mes;
        int anio;
    public:
        //Creadores
        DTFecha();
        DTFecha(int dia,int mes,int anio,int hora,int minuto);
        //Destructor
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
        //Funciones
        bool EsFechaMayor(DTFecha fecha1, DTFecha fecha2);
};
#endif
