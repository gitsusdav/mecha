#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector>
#include <list>
#include <string>

// Define la estructura de un elemento en la tabla hash
struct HashItem {
    std::string key;
    int value;
};

// Define la tabla hash
class HashTable {
private:
    static const int capacity = 100; // Tamaño de la tabla hash
    std::vector<std::list<HashItem>> table;

public:
    HashTable();
    int hashFunction(const std::string& key);
    void insert(const std::string& key, int value);
    int search(const std::string& key);
};

#endif // HASH_TABLE_HPP
