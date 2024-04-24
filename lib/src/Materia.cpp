#include "Materia.hpp"

// Constructor
Materia::Materia(int id, Periodo* periodo, const std::string& descripcion,
        const std::vector<std::string>& profesores, const std::string& nombre,
        const std::vector<Clase*>& clases, bool periodoActivo)
    : ID(id), periodo(periodo), Descripcion(descripcion), Profesores(profesores),
      Nombre(nombre), Clases(clases), PeriodoActivo(periodoActivo) {}

// Métodos de acceso (getters)
int Materia::getID() const {
    return ID;
}

Periodo* Materia::getPeriodo() const {
    return periodo;
}

std::string Materia::getDescripcion() const {
    return Descripcion;
}

std::vector<std::string> Materia::getProfesores() const {
    return Profesores;
}

std::string Materia::getNombre() const {
    return Nombre;
}

std::vector<Clase*> Materia::getClases() const {
    return Clases;
}

bool Materia::getPeriodoActivo() const {
    return PeriodoActivo;
}

// Métodos de modificación (setters)
void Materia::setID(int id) {
    ID = id;
}

void Materia::setPeriodo(Periodo* periodo) {
    this->periodo = periodo;
}

void Materia::setDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Materia::setProfesores(const std::vector<std::string>& profesores) {
    Profesores = profesores;
}

void Materia::setNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Materia::setClases(const std::vector<Clase*>& clases) {
    Clases = clases;
}

void Materia::setPeriodoActivo(bool periodo) {
    PeriodoActivo = periodo;
}
std::string Materia::toString() const {
        return Nombre +" "+ Descripcion;
} 