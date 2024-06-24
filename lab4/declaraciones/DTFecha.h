#ifndef DTFECHA_H
#define DTFECHA_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

class DTFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        //Creadores
        DTFecha();
        DTFecha(int dia,int mes,int anio);
        //Destructor
        ~DTFecha();
        //Getters
        int getDia();
        int getMes();
        int getAnio();
        //Setters
        void setDia(int);
        void setMes(int);
        void setAnio(int);  
        //Funciones
        bool esIgualFecha(DTFecha f);
        friend std::ostream &operator<<(std::ostream& salida, const DTFecha& fecha);
        friend bool operator>(const DTFecha& lhs, const DTFecha& rhs);
        bool esVigente(DTFecha);
};
#endif
