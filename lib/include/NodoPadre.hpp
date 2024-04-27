#pragma once

#include <string>

template <typename T>
class NodoPadre {
private:
    NodoPadre* padre;  
    T value;           
    std::string camino; 
public:
    NodoPadre(const T& val, const std::string& path);
    void setPadre(NodoPadre* nodoPadre);
    T obtenerValor() const;
    void asignarCamino(const std::string& nuevoCamino);
    std::string obtenerCamino() const; 
};

template <typename T>
NodoPadre<T>::NodoPadre(const T& val, const std::string& path) : padre(nullptr), value(val), camino(path) {}

template <typename T>
void NodoPadre<T>::setPadre(NodoPadre* nodoPadre) {
    padre = nodoPadre;
}

template <typename T>
T NodoPadre<T>::obtenerValor() const {
    return value;
}

template <typename T>
void NodoPadre<T>::asignarCamino(const std::string& nuevoCamino) {
    camino = nuevoCamino;
}

template <typename T>
std::string NodoPadre<T>::obtenerCamino() const {
    return camino;
}