// convertir clase toString + Time.now () a sha256 

#pragma once

#include <string>
#include <ctime>

class Utilidades{

public:
    static std::string generarId(const std::string& claseToString);
    static std::string crearFecha(int year, int month, int day);
    static std::string crearFecha(const std::tm& fecha);
    static std::tm obtenerFecha(int year, int month, int day);
    static std::tm crearTmDesdeString(const std::string& fechaStr);
    static bool instanciarBaseDeDatos();
    static int sumarNumeros(const std::string& cadena);
    static bool esDigito(char c);
    static bool esLetra(char c);
};
