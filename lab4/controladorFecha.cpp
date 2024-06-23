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


void ControladorFecha::setFecha(DTFecha nFecha){
    this->fecha = nFecha;
}

#endif