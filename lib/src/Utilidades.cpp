
#include "Utilidades.hpp"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <openssl/evp.h>
#include <vector>

std::string Utilidades::generarId(const std::string& claseToString) //sha256
{
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto value = now_ms.time_since_epoch().count();
    
    std::stringstream ss;
    ss << claseToString << value;

    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();

    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);

    EVP_DigestUpdate(mdctx, ss.str().c_str(), ss.str().size());

    std::vector<unsigned char> hash(EVP_MD_size(EVP_sha256()));

    unsigned int len;
    EVP_DigestFinal_ex(mdctx, hash.data(), &len);

    EVP_MD_CTX_free(mdctx); // Limpiar

    std::stringstream hashStream;   // Se convierte el hash a una cadena hexadecimal
    for(auto byte : hash) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
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
