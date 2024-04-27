#include <Clase.hpp>

// Constructor
Clase::Clase(std::string idMateria, const std::string& descripcion,
             const std::tm& fecha, const std::string& tema)
    : ID_Materia(idMateria), Descripcion(descripcion), Fecha(fecha), Tema(tema) {}

Clase::Clase(){};
// Getters
std::string Clase::getID() const { return ID; }
std::string Clase::getIDMateria() const { return ID_Materia; }
std::string Clase::getDescripcion() const { return Descripcion; }
std::tm Clase::getFecha() const { return Fecha; }
std::string Clase::getTema() const { return Tema; }

// Setters
void Clase::setID(std::string id) { ID = id; }
void Clase::setIDMateria(const std::string& idMateria) { ID_Materia = idMateria; }
void Clase::setDescripcion(const std::string& descripcion) { Descripcion = descripcion; }
void Clase::setFecha(const std::tm& fecha) { Fecha = fecha; }
void Clase::setTema(const std::string& tema) { Tema = tema; }

/*void Clase::agregarApunte(Apunte* nuevoApunte) {
    Apuntes.push_back(nuevoApunte);
}*/

std::string Clase::toString() {
        std::ostringstream oss;
    oss << Descripcion << " " << Tema << " " <<  std::put_time(&Fecha, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}



