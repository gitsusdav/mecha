#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector>
#include <list>
#include <string>

// Define la estructura de un elemento en la tabla hash
struct ItemHash {
    std::string llave;
    int value;
};

// Define la tabla hash
class TablaHash {
private:
    static const int capacidad = 100; // Tamaño de la tabla hash
    std::vector<std::list<ItemHash>> tabla;

public:
    TablaHash();
    int funcionHash(const std::string& llave);
    void insert(const std::string& llave, int value);
    int buscar(const std::string& llave);
};

#endif // HASH_TABLE_HPP
