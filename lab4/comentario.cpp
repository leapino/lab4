#ifndef COMENTARIO_CPP
#define COMENTARIO_CPP

#include "declaraciones/comentario.h"

Comentario::Comentario() {
    this->texto = "";
    this->fecha = DTFecha();
    this->prodComentado = NULL;
    this->miUsuario = NULL;
}

Comentario::Comentario(Usuario *miUsuario, DTFecha fecha, Producto *prodCom, std::string comment) {
    this->miUsuario = miUsuario;
    this->fecha = fecha;
    this->prodComentado = prodCom;
    this->texto = comment;
}

std::map<std::string, Comentario *> Comentario::getRespuestas(){
    return this->respuestas;
}
std::string Comentario::getTexto() {
    return this->texto;
}


DTFecha Comentario::getFecha() {
    return this->fecha;
}


Producto *Comentario::getProdCom() {
    return this->prodComentado;
}


Usuario *Comentario::getUsuario() {
    return this->miUsuario;
}


std::string Comentario::getIdcom() {
    return this->idcom;
}

void Comentario::setRespuestas(std::map<std::string,Comentario*> respuesta){
    this->respuestas= respuesta;
}

void Comentario::setTexto(std::string text) {
    this->texto = text;
}


void Comentario::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}


void Comentario::setProdComentado(Producto *prod) {
    this->prodComentado = prod;
}


void Comentario::setMiUsuario(Usuario *miUser) {
    this->miUsuario = miUser;
}


void Comentario::setIdCom(std::string id) {
    this->idcom = id;
}


Comentario::~Comentario() {
    delete this->prodComentado;
    //delete this->miUsuario;
}

void Comentario::borrarRespuestas(){
     std::map<std::string, Comentario*>::iterator it;
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