#include "Materia.hpp"
#include "Periodo.hpp"
#include "Clase.hpp" 
#include "Utilidades.hpp" 

// Constructor
Materia::Materia( Periodo* periodo, const std::string& descripcion,
        const std::vector<std::string>& profesores, const std::string& nombre,
        const std::vector<Clase*>& clases, bool periodoActivo)
    :  periodo(periodo), Descripcion(descripcion), Profesores(profesores),
      Nombre(nombre), Clases(clases), PeriodoActivo(periodoActivo) {ID = Utilidades::generarId(this->toString());}
Materia::Materia(){}
// Métodos de acceso (getters)
std::string Materia::obtenerID() const {
    return ID;
}

Periodo* Materia::obtenerPeriodo() const {
    return periodo;
}

std::string Materia::obtenerDescripcion() const {
    return Descripcion;
}

std::vector<std::string> Materia::obtenerProfesores() const {
    return Profesores;
}

std::string Materia::obtenerNombre() const {
    return Nombre;
}

std::vector<Clase*> Materia::obtenerClases() const {
    return Clases;
}

bool Materia::obtenerPeriodoActivo() const {
    return PeriodoActivo;
}

// Métodos de modificación (setters)
void Materia::asignarID(std::string id) {
    ID = id;
}

void Materia::asignarPeriodo(Periodo* periodo) {
    this->periodo = periodo;
}

void Materia::asignarDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Materia::asignarProfesores(const std::vector<std::string>& profesores) {
    Profesores = profesores;
}

void Materia::asignarNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Materia::asignarClases(const std::vector<Clase*>& clases) {
    Clases = clases;
}

void Materia::asignarPeriodoActivo(bool periodo) {
    PeriodoActivo = periodo;
}
std::string Materia::toString() const {
        return Nombre +" "+ Descripcion;
} 

// agregar clase a materia

void Materia::agregarClase(Clase* clase) {
    clase->asignarIDMateria(ID);
    Clases.push_back(clase);
}

std::vector<Clase*> Materia::buscarTemaEnClases(const std::string& tema) {
    std::vector<Clase*> clasesEncontradas;
    for (Clase* clase : Clases) {
        if (clase->obtenerTema().find(tema) != std::string::npos) {
            clasesEncontradas.push_back(clase);
        }
    }
    return clasesEncontradas; 
}