#pragma once

class Apunte {
public:
    int id;

    // Constructor
    Apunte(int var) : id(var) {}

    // Getters y Setters 



    // Sobrecarga del operador ==
    bool operator==(const Apunte& otro_apunte) const {
        return id == otro_apunte.id;
    }
};