#include "HashTable.hpp"

// Constructor
HashTable::HashTable() {
    table.resize(capacity);
}

// Función hash simple (puede ser mejorada)
int HashTable::hashFunction(const std::string& key) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % capacity;
}

// Insertar un elemento en la tabla hash
void HashTable::insert(const std::string& key, int value) {
    int index = hashFunction(key);
    auto& items = table[index];
    for (auto& item : items) {
        if (item.key == key) {
            item.value = value;
            return;
        }
    }
    items.push_back({key, value});
}

// Buscar un elemento en la tabla hash
int HashTable::search(const std::string& key) {
    int index = hashFunction(key);
    for (const HashItem& item : table[index]) {
        if (item.key == key) {
            return item.value;
        }
    }
    return -1; // No se encontró la clave
}
