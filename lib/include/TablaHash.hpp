#include <vector>
#include <iostream>
#include <string>

#include "NodoFuego.hpp"

// Define la estructura de un elemento en la tabla hash
struct ElementoHash {
    std::string llave;
    NodoFuego valor; // NodoFuego
};

// Define la tabla hash
class TablaHash {
private:
    int capacidad = 599;
    ElementoHash tabla[599];
public:
    TablaHash();
    int funcionHash(const std::string& llave);
    void insert(const std::string& llave, NodoFuego valor);
    ElementoHash* buscar(const std::string& llave);
};


