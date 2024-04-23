#include "Clase.hpp"

// Constructor
Clase::Clase(int id, int idMateria, const std::string& descripcion,
          const std::string& fecha, const std::vector<std::string>& recursos,
          const std::vector<Apunte*>& apuntes, const std::string& tema)
    : ID(id), ID_Materia(idMateria), Descripcion(descripcion), Fecha(fecha),
      Recursos(recursos), Apuntes(apuntes), Tema(tema) {}

// Métodos de acceso (getters)
int Clase::getID() const {
    return ID;
}

int Clase::getIDMateria() const {
    return ID_Materia;
}

std::string Clase::getDescripcion() const {
    return Descripcion;
}

std::string Clase::getFecha() const {
    return Fecha;
}

std::vector<std::string> Clase::getRecursos() const {
    return Recursos;
}

std::vector<Apunte*> Clase::getApuntes() const {
    return Apuntes;
}

std::string Clase::getTema() const {
    return Tema;
}

// Métodos de modificación (setters)
void Clase::setID(int id) {
    ID = id;
}

void Clase::setIDMateria(int idMateria) {
    ID_Materia = idMateria;
}

void Clase::setDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Clase::setFecha(const std::string& fecha) {
    Fecha = fecha;
}

void Clase::setRecursos(const std::vector<std::string>& recursos) {
    Recursos = recursos;
}

void Clase::setApuntes(const std::vector<Apunte*>& apuntes) {
    Apuntes = apuntes;
}

void Clase::setTema(const std::string& tema) {
    Tema = tema;
}
