#include <vector>
#include <list>
#include <string>

// Define la estructura de un elemento en la tabla hash
struct ElementoHash {
    std::string llave;
    int valor;
};

// Define la tabla hash
class TablaHash {
private:
    static const int capacidad = 100; // Tamaño de la tabla hash
    std::vector<std::list<ElementoHash>> tabla;

public:
    TablaHash();
    int funcionHash(const std::string& llave);
    void insert(const std::string& llave, int valor);
    int buscar(const std::string& llave);
};


