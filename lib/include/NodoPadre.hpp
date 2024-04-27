#pragma once

#include <string>
#include <memory>
#include <ArbolPadre.hpp>

class NodoPadre : public ArbolPadre  {
private:
    NodoPadre* padre;  
    ArbolPadre* value;           
    std::string camino; 
public:
    NodoPadre(ArbolPadre* val, const std::string& path);
    void setPadre(NodoPadre* nodoPadre);
    ArbolPadre* obtenerValor() const;
    void asignarCamino(const std::string& nuevoCamino);
    std::string obtenerCamino() const; 
};

