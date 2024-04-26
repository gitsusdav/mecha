#include "Materia.hpp"
#include "Periodo.hpp"
// Constructor
Materia::Materia( Periodo* periodo, const std::string& descripcion,
        const std::vector<std::string>& profesores, const std::string& nombre,
        const std::vector<Clase*>& clases, bool periodoActivo)
    :  periodo(periodo), Descripcion(descripcion), Profesores(profesores),
      Nombre(nombre), Clases(clases), PeriodoActivo(periodoActivo) {}
Materia::Materia(){}
// Métodos de acceso (getters)
std::string Materia::getID() const {
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
void Materia::setID(std::string id) {
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

// agregar clase a materia

void Materia::agregarClase(Clase* clase) {
    clase->setIDMateria(ID);
    Clases.push_back(clase);
}

std::vector<Clase*> Materia::buscarTemaEnClases(const std::string& tema) {
    std::vector<Clase*> clasesEncontradas;
    for (Clase* clase : Clases) {
        if (clase->getTema().find(tema) != std::string::npos) {
            clasesEncontradas.push_back(clase);
        }
    }
    return clasesEncontradas; 
}