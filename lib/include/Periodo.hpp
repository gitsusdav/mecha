#pragma once

#include <string>
#include <vector>

class Periodo {
private:
    std::string ID;
    std::string Nombre;
    std::string Descripcion;
    std::string FechaInicio;
    std::string FechaFin;
    std::vector<std::string> Materias;

public:
    // Constructor
    Periodo(std::string id, const std::string& nombre, const std::string& descripcion,
            const std::string& fechaInicio, const std::string& fechaFin,
            const std::vector<std::string>& materias);

    // Métodos de acceso (getters)
    std::string getID() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    std::string getFechaInicio() const;
    std::string getFechaFin() const;
    std::vector<std::string> getMaterias() const;

    // Métodos de modificación (setters)
    void setID(int id);
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);
    void setFechaInicio(const std::string& fechaInicio);
    void setFechaFin(const std::string& fechaFin);
    void setMaterias(const std::vector<std::string>& materias);
};
