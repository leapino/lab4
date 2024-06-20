#ifndef COMENTARIO_CPP
#define COMENTARIO_CPP

#include "declaraciones/comentario.h"

Comentario::Comentario() {
    this->texto = "";
    this->fecha = NULL;
    this->prodComentado = NULL;
    this->miUsuario = NULL;
}

Comentario::Comentario(Usuario *miUsuario, DTFecha *fecha, Producto *prodCom, std::string comment) {
    this->miUsuario = miUsuario;
    this->fecha = fecha;
    this->prodComentado = prodCom;
    this->texto = comment;
}

std::string Comentario::getTexto() {
    return this->texto;
}


DTFecha *Comentario::getFecha() {
    return this->fecha;
}


Producto *Comentario::getProdCom() {
    return this->prodComentado;
}


Usuario *Comentario::getUsuario() {
    return this->miUsuario;
}


int Comentario::getIdcom() {
    return this->idcom;
}


void Comentario::setTexto(std::string text) {
    this->texto = text;
}


void Comentario::setFecha(DTFecha *fecha) {
    this->fecha = fecha;
}


void Comentario::setProdComentado(Producto *prod) {
    this->prodComentado = prod;
}


void Comentario::setMiUsuario(Usuario *miUser) {
    this->miUsuario = miUser;
}


void Comentario::setIdCom(int id) {
    this->idcom = id;
}


Comentario::~Comentario() {
    delete this->fecha;
    delete this->prodComentado;
    delete this->miUsuario;
}

void Comentario::borrarRespuestas(){
     std::map<int, Comentario*>::iterator it;
     it = this->respuestas.begin();
     Comentario* aborrar;
     while ( it != this->respuestas.end()){
        aborrar = it->second;
        it = this->respuestas.erase(it);     
        aborrar->~Comentario();
     }
     aborrar = nullptr;
}

void Comentario::agregarRespuesta(Comentario com){
    //this->getRespuestas()->insert()
}
#endif