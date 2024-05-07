#include "Periodo.hpp"
#include "Materia.hpp"
#include "Utilidades.hpp"

// Constructor
Periodo::Periodo( const std::string& nombre, const std::string& descripcion,
        const std::tm& fechaInicio, const std::tm& fechaFin )
    : Nombre(nombre), Descripcion(descripcion), FechaInicio(fechaInicio),
      FechaFin(fechaFin) {
         ID = Utilidades::generarId(this->toString());
      }
Periodo::Periodo(){}
// Métodos de acceso (getters)
std::string Periodo::obtenerID() const {
    return ID;
}

std::string Periodo::obtenerNombre() const {
    return Nombre;
}

std::string Periodo::obtenerDescripcion() const {
    return Descripcion;
}

std::tm Periodo::obtenerFechaInicio() const {
    return FechaInicio;
}

std::tm Periodo::obtenerFechaFin() const {
    return FechaFin;
}

std::vector<Materia *> Periodo::obtenerMaterias() const {
    return Materias;
}

// Métodos de modificación (setters)
void Periodo::asignarID(std::string id) {
    ID = id;
}

void Periodo::asignarNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Periodo::asignarDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Periodo::asignarFechaInicio(const std::tm& fechaInicio) {
    FechaInicio = fechaInicio;
}

void Periodo::asignarFechaFin(const std::tm& fechaFin) {
    FechaFin = fechaFin;
}

void Periodo::asignarMaterias(const std::vector<Materia *>& materias) {
    Materias = materias;
}

void Periodo::agregarMateria(Materia* materia) {
    Materias.push_back(materia);
}

std::string Periodo::toString() const {
    std::ostringstream oss;
    oss << Nombre  << " " << Descripcion  << " " <<  std::put_time(&FechaInicio, "%Y-%m-%d %H:%M:%S");
    return oss.str();
} 