#pragma once

#include <string>
#include <memory>
#include <BaseMecha.hpp>

class NodoPadre : public BaseMecha  {
private:
    NodoPadre* padre;  
    BaseMecha* valor;           
    std::string camino; 
public:
    NodoPadre(BaseMecha* val, const std::string& path);
    void setPadre(NodoPadre* nodoPadre);
    BaseMecha* obtenerValor() const;
    void asignarCamino(const std::string& nuevoCamino);
    std::string obtenerCamino() const; 
};

