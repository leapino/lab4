#ifndef COMENTARIO_CPP
#define COMENTARIO_CPP

#include "declaraciones/comentario.h"

Comentario::Comentario() {
    this->texto = "";
    this->fecha = NULL;
    this->prodCom = NULL;
    this->miUsuario = NULL;
}

Comentario::Comentario(Usuario *miUsuario, DTFecha *fecha, Producto *prodCom, std::string comment) {
    this->miUsuario = miUsuario;
    this->fecha = fecha;
    this->prodCom = prodCom;
    this->texto = comment;
}


// void Comentario::eliminarLinkUsuario() {
//     delete this->miUsuario;
// }

// void Comentario::eliminarLinkProducto() {
//     delete this->prodCom;
// }

//COMENTÉ ESAS 2 DE ARRIBA PORQUE ES AL PEDO SI EL DESTRUCTOR YA BORRA LAS RELACIONES AL ELIMINAR COMENTARIO NO?

Comentario::~Comentario() {
    delete this->fecha;
    delete this->prodCom;
    delete this->miUsuario;
}

#endif