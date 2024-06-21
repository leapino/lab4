#ifndef DTCOMENTARIO_CPP
#define DTCOMENTARIO_CPP

#include "declaraciones/DTComentario.h"

DTComentario::DTComentario( std::string com,  DTFecha fec,int id,std::list<DTComentario> resp) {
    this->comentario=com;
    this->fecha=fec;
    this->respuestas=resp;
    this->idcom=id;
}

std::string DTComentario::getComentario()  {
    return this->comentario;
}

DTFecha DTComentario::getFecha()  {
    return this->fecha;
}

int DTComentario::getIdCom()  {
    return this->idcom;
}

std::list< DTComentario> DTComentario::getRespuestas()  {
    return this->respuestas;
}

void DTComentario::setComentario( std::string com) {
    this->comentario = com;
}

void DTComentario::setFecha( DTFecha fec) {
    this->fecha = fec;
}

void DTComentario::setIdCom( int id) {
    this->idcom = id;
}

void DTComentario::setRespuestas( std::list< DTComentario> resp) {
    this->respuestas = resp;
}

void DTComentario::agregarRespuesta( DTComentario respuesta) {
    if(!this->respuestas.empty())
        int id =this->respuestas.rbegin()->getIdCom()+1;
}

DTComentario::~DTComentario(){
    this->respuestas.clear();
}

#endif