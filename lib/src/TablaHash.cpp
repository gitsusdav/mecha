#include "TablaHash.hpp"
#include "Utilidades.hpp"

// Constructor de la tabla hash
TablaHash::TablaHash() {
    for (int i = 0; i < capacidad; ++i) {
        tabla[i].llave = ""; 
    }
}

// La llave es el camino 
int TablaHash::funcionHash(const std::string& llave) {
    int posicion = Utilidades::sumarNumeros(llave);
    return posicion % capacidad;
}

void TablaHash::insert(const std::string& llave, NodoFuego valor) {
     std::cout << "INSERTAR vacio?  " <<valor.obtenerValor().at(0)->toString()<< " \n";

    int indice = funcionHash(llave);
        std::cout << "INdice IF  " <<indice<< " \n";
    // colisiones 
    if(!tabla[indice].valor.obtenerValor().empty()){
        std::cout << "COLISION" << std::endl;
        return;
    }
    std::cout << "No es el If " << " \n";
    tabla[indice].llave = llave;
    tabla[indice].valor = valor;
}

ElementoHash* TablaHash::buscar(const std::string& llave) {
    int indice = funcionHash(llave);
    if (tabla[indice].llave == llave) {
        return &tabla[indice];
    }
    return nullptr; 
}