#include <Clase.hpp>

// Constructor
Clase::Clase(const std::string& descripcion,
             const std::tm& fecha, const std::string& tema)
    : Descripcion(descripcion), Fecha(fecha), Tema(tema) {}

Clase::Clase(){};
// Getters
std::string Clase::obtenerID() const { return ID; }
std::string Clase::obtenerIDMateria() const { return ID_Materia; }
std::string Clase::obtenerDescripcion() const { return Descripcion; }
std::tm Clase::obtenerFecha() const { return Fecha; }
std::vector<Apunte*> Clase::obtenerApuntes() const { return Apuntes; }
std::vector<std::string> Clase::obtenerRecursos() const { return Recursos; }
std::string Clase::obtenerTema() const { return Tema; }


void Clase::asignarID(std::string id) { ID = id; }
void Clase::asignarIDMateria(const std::string& idMateria) { ID_Materia = idMateria; }
void Clase::asignarDescripcion(const std::string& descripcion) { Descripcion = descripcion; }
void Clase::asignarFecha(const std::tm& fecha) { Fecha = fecha; }
void Clase::asignarTema(const std::string& tema) { Tema = tema; }
void Clase::asignarRecursos(const std::vector<std::string>& recurso) { Recursos = recurso; }
void Clase::asignarApuntes(const std::vector<Apunte*>& listaApuntes) { Apuntes = listaApuntes; }
void Clase::agregarApunte(Apunte* nuevoApunte) { Apuntes.push_back(nuevoApunte); }

std::string Clase::toString() const {
        std::ostringstream oss;
    oss << Descripcion << " " << Tema << " " <<  std::put_time(&Fecha, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}



