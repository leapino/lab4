#ifndef CONTROLADORUSUARIO_CPP
#define CONTROLADORUSUARIO_CPP

#include "declaraciones/controladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario* ControladorUsuario::getInstancia(){
    if (instancia == NULL){
        instancia = new ControladorUsuario();
    }
        return instancia;
}

#endif