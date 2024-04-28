#include <NodoPadre.hpp>


NodoPadre::NodoPadre(BaseMecha* val, const std::string& path) : padre(nullptr), valor(val), camino(path) {}


void NodoPadre::asignarPadre(NodoPadre* nodoPadre) {
    asignarCamino( nodoPadre->obtenerCamino() + camino + "/");
    padre = nodoPadre;
}


BaseMecha* NodoPadre::obtenerValor() const {
    return valor;
}


void NodoPadre::asignarCamino(const std::string& nuevoCamino) {
    camino = nuevoCamino;
}


std::string NodoPadre::obtenerCamino() const {
    return camino;
}
