#pragma once

class Apunte {
public:
    int id; // mejor estrategia para que sea unico 
    // por tabla hash

    // Constructor
    Apunte(int var) : id(var) {}

    // Getters y Setters 

    // Asignar 
    void asignar_clase( int id_clase);

    // paso 1 enunciamos los metodos a testiar 

    // Sobrecarga del operador ==
    bool operator==(const Apunte& otro_apunte) const {
        return id == otro_apunte.id;
    }
};