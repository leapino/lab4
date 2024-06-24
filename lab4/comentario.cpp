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

std::map<int, Comentario *> Comentario::getRespuestas(){
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

void Comentario::setRespuestas(std::map<int,Comentario*> respuesta){
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
     std::map<int, Comentario*>::iterator it;
     if (this->respuestas.empty() == false){
     std::vector<int> respuestaIds;
     for (const auto& pair : this->respuestas) {
        respuestaIds.push_back(pair.first);
    }
    for (int respuestaId : respuestaIds) {
        Comentario* aborrar = this->respuestas[respuestaId];
        if (aborrar) {
            aborrar->borrarRespuestas();  
            aborrar->~Comentario();               
        }
        this->respuestas.erase(respuestaId);
    }
     }
}

void Comentario::agregarRespuesta(Comentario* com)
{   
    int id=com->getIdcom();
    this->respuestas.insert(std::make_pair(id,com));
}
#endif