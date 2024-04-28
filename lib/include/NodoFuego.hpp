#pragma once

#include <string>
#include <vector>

#include "BaseMecha.hpp"

class NodoFuego{
private:
    std::vector<BaseMecha> valor;
    NodoFuego* derechaMayor;
    NodoFuego* izquierdaMenor;
    int llave;
public:

    NodoFuego();
    ~NodoFuego();
    std::vector<BaseMecha> obtenerValor();
    int obtenerLlave();
    void asignarMenor( NodoFuego * mayor);
    void asignarMayor( NodoFuego * mayor);
    void asignarValor( std::vector<BaseMecha> valor);
    void asignarLlave( int llave);
};