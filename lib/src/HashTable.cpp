#include "HashTable.hpp"

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
    auto& items = tabla[index];
    for (auto& item : items) {
        if (item.llave == llave) {
            item.valor = valor;
            return;
        }
    }
    items.push_back({llave, valor});
}

// Buscar un elemento en la tabla hash
int TablaHash::buscar(const std::string& llave) {
    int index = funcionHash(llave);
    for (const ItemHash& item : tabla[index]) {
        if (item.llave == llave) {
            return item.valor;
        }
    }
    return -1; // No se encontró la clave
}
