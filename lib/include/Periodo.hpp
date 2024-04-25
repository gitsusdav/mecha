#pragma once

#include <string>
#include <vector>
#include <iomanip>

class Periodo {
private:
    std::string ID;
    std::string Nombre;
    std::string Descripcion;
    std::tm FechaInicio;
    std::tm FechaFin;
    std::vector<std::string> Materias;

public:
    // Constructor
    Periodo(const std::string& nombre, const std::string& descripcion,
            const std::tm& fechaInicio, const std::tm& fechaFin,
            const std::vector<std::string>& materias);
    Periodo();
    // Métodos de acceso (getters)
    std::string getID() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    std::tm getFechaInicio() const;
    std::tm getFechaFin() const;
    std::vector<std::string> getMaterias() const;

    // Métodos de modificación (setters)
    void setID(int id);
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);
    void setFechaInicio(const std::tm& fechaInicio);
    void setFechaFin(const std::tm& fechaFin);
    void setMaterias(const std::vector<std::string>& materias);

    // Método para convertir Periodo en cadena
    std::string toString() const;
};
