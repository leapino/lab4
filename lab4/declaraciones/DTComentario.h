#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
#include <list>
#include "DTFecha.h"

class DTComentario {
private:
    std::string comentario;
    DTFecha fecha;
    int idcom;
    std::list<DTComentario> respuestas;

public:
    DTComentario( std::string com,  DTFecha fec,int id, std::list<DTComentario> resp);
    ~DTComentario();
    std::string getComentario() ;
    DTFecha getFecha() ;
    int getIdCom() ;
    std::list< DTComentario> getRespuestas() ;

    void setComentario( std::string com);
    void setFecha( DTFecha fec);
    void setIdCom( int id);
    void setRespuestas( std::list< DTComentario> resp);
    //DTComentario obtenerRespuesta( int id) ;
    void agregarRespuesta( DTComentario respuesta);
};

#endif