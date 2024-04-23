#include "Periodo.hpp"

// Constructor
Periodo::Periodo(std::string id, const std::string& nombre, const std::string& descripcion,
        const std::string& fechaInicio, const std::string& fechaFin,
        const std::vector<std::string>& materias)
    : ID(id), Nombre(nombre), Descripcion(descripcion), FechaInicio(fechaInicio),
      FechaFin(fechaFin), Materias(materias) {}

// Métodos de acceso (getters)
std::string Periodo::getID() const {
    return ID;
}

std::string Periodo::getNombre() const {
    return Nombre;
}

std::string Periodo::getDescripcion() const {
    return Descripcion;
}

std::string Periodo::getFechaInicio() const {
    return FechaInicio;
}

std::string Periodo::getFechaFin() const {
    return FechaFin;
}

std::vector<std::string> Periodo::getMaterias() const {
    return Materias;
}

// Métodos de modificación (setters)
void Periodo::setID(int id) {
    ID = id;
}

void Periodo::setNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Periodo::setDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Periodo::setFechaInicio(const std::string& fechaInicio) {
    FechaInicio = fechaInicio;
}

void Periodo::setFechaFin(const std::string& fechaFin) {
    FechaFin = fechaFin;
}

void Periodo::setMaterias(const std::vector<std::string>& materias) {
    Materias = materias;
}
