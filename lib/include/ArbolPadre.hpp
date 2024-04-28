#pragma once

#include <string>

class ArbolPadre {

private:
    std::string ID;
public:
    std::string obtenerID() const;
    void asignarID(std::string id);
    virtual ~ArbolPadre() = default; 
    virtual std::string toString() const;
};
