#ifndef COMENTARIO_CPP
#define COMENTARIO_CPP

#include "declaraciones/comentario.h"

Comentario::Comentario() {
    this->texto = "";
    this->fecha = DTFecha();
    this->prodComentado = NULL;
    this->miUsuario = NULL;
}

Comentario::Comentario(Usuario *miUsuario, DTFecha fecha, Producto *prodCom, std::string comment, int idcom) {
    this->miUsuario = miUsuario;
    this->fecha = fecha;
    this->prodComentado = prodCom;
    this->texto = comment;
    this->idcom=idcom;
}

std::list< Comentario *> Comentario::getRespuestas(){
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


int Comentario::getIdcom() {
    return this->idcom;
}

void Comentario::setRespuestas(std::list<Comentario*> respuesta){
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


void Comentario::setIdCom(int id) {
    this->idcom = id;
}


Comentario::~Comentario() {
     this->prodComentado = nullptr;
     this->miUsuario = nullptr;
     this->respuestas.clear();
}

void Comentario::borrarRespuestas(){
}

void Comentario::agregarRespuesta(Comentario* com)
{   
    this->respuestas.push_back(com);
}
#endif