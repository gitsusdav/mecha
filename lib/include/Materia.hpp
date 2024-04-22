#pragma once

#include <string>
#include <vector>
#include "Clase.hpp" 
#include "Periodo.hpp"

class Materia {
private:
    int ID;
    Periodo* periodo;
    std::string Descripcion;
    std::vector<std::string> Profesores;
    std::string Nombre;
    std::vector<Clase*> Clases;
    bool PeriodoActivo;

public:
    // Constructor
    Materia(int id, Periodo* periodo, const std::string& descripcion,
            const std::vector<std::string>& profesores, const std::string& nombre,
            const std::vector<Clase*>& clases, bool periodoActivo);

    // Métodos de acceso (getters)
    int getID() const;
    Periodo* getPeriodo() const;
    std::string getDescripcion() const;
    std::vector<std::string> getProfesores() const;
    std::string getNombre() const;
    std::vector<Clase*> getClases() const;
    bool getPeriodoActivo() const;

    // Métodos de modificación (setters)
    void setID(int id);
    void setPeriodo(Periodo* periodo);
    void setDescripcion(const std::string& descripcion);
    void setProfesores(const std::vector<std::string>& profesores);
    void setNombre(const std::string& nombre);
    void setClases(const std::vector<Clase*>& clases);
    void setPeriodoActivo(bool periodo);
};