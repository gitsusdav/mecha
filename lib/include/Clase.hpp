#pragma once

#include <string>
#include <vector>
#include <iomanip>

class Apunte;

class Clase {
private:
    std::string ID;
    std::string ID_Materia;
    std::string Descripcion;
    std::tm Fecha;
    std::vector<std::string> Recursos;
    std::vector<Apunte*> Apuntes; // Cambiado a vector de punteros a Apunte
    std::string Tema;

public:
    // Constructor
    Clase( std::string idMateria, const std::string& descripcion,
          const std::tm& fecha, const std::vector<std::string>& recursos,
          const std::vector<Apunte*>& apuntes, const std::string& tema);
    Clase();
    // Métodos de acceso (getters)
    std::string getID() const;
    std::string getIDMateria() const;
    std::string getDescripcion() const;
    std::tm getFecha() const;
    std::vector<std::string> getRecursos() const;
    std::vector<Apunte*> getApuntes() const; // Cambiado el tipo de retorno
    std::string getTema() const;

    // Métodos de modificación (setters)
    void setID(std::string id);
    void setIDMateria(const std::string& idMateria );
    void setDescripcion(const std::string& descripcion);
    void setFecha(const std::tm& fecha);
    void setRecursos(const std::vector<std::string>& recursos);
    void setApuntes(const std::vector<Apunte*>& apuntes); // Cambiado el parámetro
    void setTema(const std::string& tema);

    // Método para convertir Clase en cadena
    std::string toString();
};