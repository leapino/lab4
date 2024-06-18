#ifndef DTFECHA_CPP
#define DTFECHA_CPP

#include "declaraciones/DTFecha.h"

DTFecha::DTFecha(){
    this->dia=1;
    this->mes=1;
    this->anio=1900;
    this->hora=0;
    this->minuto=0;
    }

DTFecha::DTFecha(int dia, int mes, int anio,int hora,int minuto){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}

int DTFecha::getDia(){
    return this->dia;
}

int DTFecha::getMes(){
    return this->mes;
}

int DTFecha::getAnio(){
    return this->anio;
}

int DTFecha::getHora(){
    return this->hora;
}

int DTFecha::getMinuto(){
    return this->minuto;
}

void DTFecha::setAnio(int anio){
     this->anio = anio;
}   

void DTFecha::setDia(int dia){
     this->dia = dia;
}   

void DTFecha::setMes(int mes){
     this->mes = mes;
}   

void DTFecha::setHora(int hora){
     this->hora = hora;
}   

void DTFecha::setMinuto(int minuto){
     this->minuto = minuto;
}

DTFecha::~DTFecha() {
}


#endif