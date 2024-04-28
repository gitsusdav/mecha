#include "TablaHash.hpp"

// Constructor
TablaHash::TablaHash() {
    tabla.resize(capacidad);
}

// Función hash simple (puede ser mejorada)
int TablaHash::funcionHash(const std::string& llave) {
    int hash = 0;
    for (char c : llave) {
        hash += c;
    }
    return hash % capacidad;
}

// Insertar un elemento en la tabla hash
void TablaHash::insert(const std::string& llave, int valor) {
    int index = funcionHash(llave);
    auto& elementos = tabla[index];
    for (auto& elemento : elementos) {
        if (elemento.llave == llave) {
            elemento.valor = valor;
            return;
        }
    }
    elementos.push_back({llave, valor});
}

// Buscar un elemento en la tabla hash
int TablaHash::buscar(const std::string& llave) {
    int index = funcionHash(llave);
    for (const ElementoHash& elemento : tabla[index]) {
        if (elemento.llave == llave) {
            return elemento.valor;
        }
    }
    return -1;
}
