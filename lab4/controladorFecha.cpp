#ifndef CONTROLADORFECHA_CPP
#define CONTROLADORFECHA_CPP

#include "declaraciones/controladorFecha.h"

ControladorFecha* ControladorFecha::instancia = NULL;

ControladorFecha::ControladorFecha() {};

ControladorFecha* ControladorFecha::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorFecha();
    }
        return instancia;
}

DTFecha ControladorFecha::getFecha(){
    return this->fecha;
}

DTFecha ControladorFecha::getFechaActual(){
    time_t now=time(0);
    tm *ltm=localtime(&now);
    return DTFecha(ltm->tm_mday,1+ltm->tm_mon,1900 + ltm->tm_year,ltm->tm_hour,ltm->tm_min);
}

void ControladorFecha::setFecha(DTFecha nFecha){
    this->fecha = nFecha;
}

#endif