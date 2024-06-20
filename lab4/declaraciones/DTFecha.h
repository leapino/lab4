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
        int getDia() const;
        int getMes() const;
        int getAnio() const;
        int getHora() const;
        int getMinuto() const;
        //Setters
        void setDia(int);
        void setMes(int);
        void setAnio(int);  
        void setHora(int);
        void setMinuto(int);
        
        //Funciones
};
#endif
