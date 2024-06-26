#ifndef USUARIO_CPP
#define USUARIO_CPP

#include "declaraciones/usuario.h"

Usuario::Usuario(){}


Usuario::Usuario(std::string nick,std::string pass, DTFecha fecha){


    this->nickname = nick;
    this->password = pass;
    this->fechaNacimiento = fecha;
}

std::list< Comentario *> Usuario::getComentarios()
{
    return this->comentarios;
}

std::string Usuario::getNickname()
{
    return this->nickname;
}

std::string Usuario::getPassword(){
    return this->password;
}

DTFecha Usuario::getFecha(){
    return this->fechaNacimiento;
}

void Usuario::setComentarios( Comentario * comm)
{
    this->comentarios.push_back(comm);
}

void Usuario::setNickname(std::string nick)
{
    this->nickname = nick;
}

void Usuario::setPassword(std::string pass){
    this->password = pass;
}

void Usuario::setFecha(DTFecha fecha){
    this->fechaNacimiento = fecha;
}

/*bool Usuario::esVendedor(){
    Vendedor* pVendedor;
    pVendedor=dynamic_cast<Vendedor*> (this);
    return pVendedor!=nullptr;
}

bool Usuario::esCliente(){
    Cliente* pCliente;
    pCliente=dynamic_cast<Cliente*> (this);
    return pCliente!=nullptr;
}
*/

std::list<DTComentario> Usuario::listarComentarios(){
    std::list< Comentario*>::iterator it;
    std::list<DTComentario> coments;
    std::list<DTComentario> resp;
    for (it = this->comentarios.begin(); it != this->comentarios.end(); it++){
        DTComentario comm = DTComentario((*it)->getTexto(),(*it)->getFecha(),(*it)->getIdcom(),resp);
        coments.push_back(comm);
    }
    return coments;
}    

void Usuario::borrarComentario(int id){
        auto it = std::find_if(this->comentarios.begin(), this->comentarios.end(), [id](Comentario* comentario) {
            return comentario->getIdcom() == id;
        });

        if (it != this->comentarios.end()) {
            this->comentarios.erase(it);
        }
    };


void Usuario::agregarComentario(Comentario *comm)
{
    this->comentarios.push_back(comm);
}

Usuario::~Usuario(){
}
#endif