#pragma once

#include <string>

class BaseMecha {

private:
    std::string ID;
public:
    std::string obtenerID() const;
    void asignarID(std::string id);
    virtual ~BaseMecha() = default; 
    virtual std::string toString() const;
};
