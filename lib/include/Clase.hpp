#pragma once
#pragma once

#include <string>
#include <vector>

class Apunte;

class Clase {
private:
    int ID;
    int ID_Materia;
    std::string Descripcion;
    std::string Fecha;
    std::vector<std::string> Recursos;
    std::vector<Apunte*> Apuntes; // Cambiado a vector de punteros a Apunte
    std::string Tema;

public:
    // Constructor
    Clase(int id, int idMateria, const std::string& descripcion,
          const std::string& fecha, const std::vector<std::string>& recursos,
          const std::vector<Apunte*>& apuntes, const std::string& tema);

    // Métodos de acceso (getters)
    int getID() const;
    int getIDMateria() const;
    std::string getDescripcion() const;
    std::string getFecha() const;
    std::vector<std::string> getRecursos() const;
    std::vector<Apunte*> getApuntes() const; // Cambiado el tipo de retorno
    std::string getTema() const;

    // Métodos de modificación (setters)
    void setID(int id);
    void setIDMateria(int idMateria);
    void setDescripcion(const std::string& descripcion);
    void setFecha(const std::string& fecha);
    void setRecursos(const std::vector<std::string>& recursos);
    void setApuntes(const std::vector<Apunte*>& apuntes); // Cambiado el parámetro
    void setTema(const std::string& tema);
};