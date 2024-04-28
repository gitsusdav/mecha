#include "NodoFuego.hpp"

    NodoFuego::NodoFuego() {
        derechaMayor = nullptr;
        izquierdaMenor = nullptr;
        llave = 0;
    }
    NodoFuego::~NodoFuego() {
        valor.clear();
        delete derechaMayor;
        delete izquierdaMenor;
    }
    // Métodos para obtener y asignar valores
    std::vector<BaseMecha> NodoFuego::obtenerValor() {
        return valor;
    }

    int NodoFuego::obtenerLlave() {
        return llave;
    }

    void NodoFuego::asignarMenor(NodoFuego* mayor) {
        izquierdaMenor = mayor;
    }

    void NodoFuego::asignarMayor(NodoFuego* mayor) {
        derechaMayor = mayor;
    }

    void NodoFuego::asignarValor(std::vector<BaseMecha> nuevoValor) {
        valor = nuevoValor;
    }

    void NodoFuego::asignarLlave(int nuevaLlave) {
        llave = nuevaLlave;
    }