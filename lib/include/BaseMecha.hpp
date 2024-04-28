#pragma once

#include <string>

/// Esta es una clase de la cual heredan las siguientes clases
/// Comentario Apunte Clase Materia Periodo Usuario
/// Es así para introducir objetos de esas clases en un Nodo Padre 
class BaseMecha {

private:
    std::string ID;
public:
    std::string obtenerID() const;
    void asignarID(std::string id);
    virtual ~BaseMecha() = default; 
    virtual std::string toString() const;
};
