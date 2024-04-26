// convertir clase toString + Time.now () a sha256 

#pragma once

#include <string>

class Utilidades{

public:
    static std::string generarId(const std::string& claseToString);

};
