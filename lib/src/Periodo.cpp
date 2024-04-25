#include "Periodo.hpp"
#include "Materia.hpp"

// Constructor
Periodo::Periodo( const std::string& nombre, const std::string& descripcion,
        const std::tm& fechaInicio, const std::tm& fechaFin)
    : Nombre(nombre), Descripcion(descripcion), FechaInicio(fechaInicio),
      FechaFin(fechaFin) {}
Periodo::Periodo(){}
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

std::tm Periodo::getFechaInicio() const {
    return FechaInicio;
}

std::tm Periodo::getFechaFin() const {
    return FechaFin;
}

std::vector<Materia *> Periodo::getMaterias() const {
    return Materias;
}

// Métodos de modificación (setters)
void Periodo::setID(std::string id) {
    ID = id;
}

void Periodo::setNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Periodo::setDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Periodo::setFechaInicio(const std::tm& fechaInicio) {
    FechaInicio = fechaInicio;
}

void Periodo::setFechaFin(const std::tm& fechaFin) {
    FechaFin = fechaFin;
}

void Periodo::setMaterias(const std::vector<Materia *>& materias) {
    Materias = materias;
}
std::string Periodo::toString() const {
              std::ostringstream oss;
    oss << Nombre  << " " << Descripcion  << " " <<  std::put_time(&FechaInicio, "%Y-%m-%d %H:%M:%S");
    return oss.str();
} 