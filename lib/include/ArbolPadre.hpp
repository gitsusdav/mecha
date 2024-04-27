#pragma once

#include <string>

class ArbolPadre {

private:
    std::string ID;
public:
    std::string getID() const;
    void setID(std::string id);
    virtual ~ArbolPadre() = default; 
    virtual std::string toString() const;
};
