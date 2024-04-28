#include <NodoPadre.hpp>


NodoPadre::NodoPadre(ArbolPadre* val, const std::string& path) : padre(nullptr), valor(val), camino(path) {}


void NodoPadre::setPadre(NodoPadre* nodoPadre) {
    asignarCamino( nodoPadre->obtenerCamino() + camino + "/");
    padre = nodoPadre;
}


ArbolPadre* NodoPadre::obtenerValor() const {
    return valor;
}


void NodoPadre::asignarCamino(const std::string& nuevoCamino) {
    camino = nuevoCamino;
}


std::string NodoPadre::obtenerCamino() const {
    return camino;
}
