#pragma once

#include <string>
#include <vector>
#include <iomanip>

#include "BaseMecha.hpp"

class Materia;

class Periodo : public BaseMecha{
private:
    std::string ID;
    std::string Nombre;
    std::string Descripcion;
    std::tm FechaInicio;
    std::tm FechaFin;
    std::vector<Materia *> Materias;

public:
    // Constructor
    Periodo(const std::string& nombre, const std::string& descripcion,
            const std::tm& fechaInicio, const std::tm& fechaFin);
    Periodo();
    // Métodos de acceso (getters)
    std::string obtenerID() const;
    std::string obtenerNombre() const;
    std::string obtenerDescripcion() const;
    std::tm obtenerFechaInicio() const;
    std::tm obtenerFechaFin() const;
    std::vector<Materia *> obtenerMaterias() const;

    // Métodos de modificación (setters)
    void asignarID(std::string id);
    void asignarNombre(const std::string& nombre);
    void asignarDescripcion(const std::string& descripcion);
    void asignarFechaInicio(const std::tm& fechaInicio);
    void asignarFechaFin(const std::tm& fechaFin);
    void asignarMaterias(const std::vector<Materia *>& materias);
    void agregarMateria(Materia* materia);

    // Método para convertir Periodo en cadena
    std::string toString() const;
};
