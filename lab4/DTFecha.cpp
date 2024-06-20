#ifndef DTFECHA_CPP
#define DTFECHA_CPP

#include <iostream>

#include "declaraciones/DTFecha.h"

std::ostream &operator<<(std::ostream &salida, DTFecha *fecha){
    salida << "Año:"<<fecha->getAnio()<<"\n Mes:"<<fecha->getMes()<<"\n Dia" <<fecha->getDia()<<"\n Hora"<<fecha->getHora()<<"\n Minuto"<<fecha->getMinuto();
    return salida;
}

bool operator>( const DTFecha& lhs, const DTFecha& rhs) {
    if (lhs.getAnio()!= rhs.getAnio()) {
        return lhs.getAnio() > rhs.getAnio();
    }
    if (lhs.getMes() != rhs.getMes()) {
        return lhs.getMes() > rhs.getMes();
    }
    if (lhs.getDia() != rhs.getDia()) {
        return lhs.getDia() > rhs.getDia();
    }
    if (lhs.getHora() != rhs.getHora()) {
        return lhs.getHora() > rhs.getHora();
    }
    return lhs.getMinuto() > rhs.getMinuto();
}

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

int DTFecha::getDia() const{
    return this->dia;
}

int DTFecha::getMes() const{
    return this->mes;
}

int DTFecha::getAnio()const{
    return this->anio;
}

int DTFecha::getHora()const {
    return this->hora;
}

int DTFecha::getMinuto()const {
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