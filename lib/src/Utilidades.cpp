
#include "Utilidades.hpp"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>

std::string Utilidades::generarId(const std::string& claseToString)
{
    // Concatenar la representación de la clase con la marca de tiempo actual
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto value = now_ms.time_since_epoch().count();
    
    std::stringstream ss;
    ss << claseToString << value;

    // Calcular el hash SHA-256 del resultado de la concatenación
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, ss.str().c_str(), ss.str().length());
    SHA256_Final(hash, &sha256);

    // Convertir el hash a una cadena hexadecimal
    std::stringstream hashStream;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return hashStream.str();
}

std::string Utilidades::crearFecha(int year, int month, int day) {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year << '-'
        << std::setw(2) << std::setfill('0') << month << '-'
        << std::setw(2) << std::setfill('0') << day;
    return oss.str();
}

std::string Utilidades::crearFecha(const std::tm& fecha) {
    std::ostringstream oss;
    oss << std::put_time(&fecha, "%Y-%m-%d");
    return oss.str();
}

std::tm Utilidades::obtenerFecha(int year, int month, int day) {
    std::tm fecha = {0, 0, 0, day, month - 1, year - 1900}; // Ajustar mes y año
    return fecha;
}
