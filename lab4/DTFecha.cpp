#ifndef DTFECHA_CPP
#define DTFECHA_CPP

#include <iostream>

#include "declaraciones/DTFecha.h"

std::ostream &operator<<(std::ostream &salida, const DTFecha  &   fecha){
    salida << "Año: "<<fecha.anio<<"\nMes: "<<fecha.mes<<"\nDia: " <<fecha.dia<<"\n";
    return salida;
}

bool operator>( const DTFecha &lhs, const DTFecha &rhs){
    if (lhs.anio != rhs.anio) {
        return lhs.anio > rhs.anio;
    }
    if (lhs.mes != rhs.mes) {
        return lhs.mes > rhs.mes;
    }
    if (lhs.dia != rhs.dia) {
        return lhs.dia > rhs.dia;
    }
}

DTFecha::DTFecha(){
    this->dia=1;
    this->mes=1;
    this->anio=1900;
    }

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::getDia() {
    return this->dia;
}

int DTFecha::getMes() {
    return this->mes;
}

int DTFecha::getAnio(){
    return this->anio;
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

bool DTFecha::esIgualFecha(DTFecha f) {
    bool resu = false;
    return resu = (this->anio == f.anio && this->mes == f.mes && this->dia == f.dia);
}

bool DTFecha::esVigente(DTFecha fechaActual){
    int actual = (fechaActual.getAnio() * 365 + fechaActual.getMes() * 31 + fechaActual.getDia());
    int final = (this->anio * 365 + this->mes * 31 + this->dia);
    return  actual <= final;
}

DTFecha::~DTFecha() {
}




#endif