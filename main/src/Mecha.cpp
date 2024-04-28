#include <iostream>
#include "Utilidades.hpp"
#include "Usuario.hpp"
#include "Periodo.hpp"
#include "Materia.hpp"
#include "Clase.hpp"
#include "Apunte.hpp"
#include "Comentario.hpp"

int main(int argc, char* argv[])
{
    std::cout << "\n\n MECHA APP \n \n";

    std::string resultados = Utilidades::generarId("aqui van las clases toString");
    std::cout << "ID: " << resultados << "\n";

std::cout << "\n\n *Usuario* \n \n";
    Usuario usuario("Nombre", "Descripción", {}, "correo@example.com", "clave");  //Datos de ejemplo

    std::cout << "Nombre: " << usuario.obtenerNombre() << std::endl;
    std::cout << "Descripción: " << usuario.obtenerDescripcion() << std::endl;
    std::cout << "Correo: " << usuario.obtenerCorreo() << std::endl;
    std::cout << "Roles: ";
    for (const auto& rol : usuario.obtenerRoles()) {
        switch (rol) {
            case Rol::PROFESOR:
                std::cout << "Profesor ";
                break;
            case Rol::ESTUDIANTE:
                std::cout << "Estudiante ";
                break;
            case Rol::GRADUADO:
                std::cout << "Graduado ";
                break;
        }
    }
    std::cout << std::endl;

std::cout << "\n\n *Periodo* \n \n";
    std::tm fechaInicio = Utilidades::obtenerFecha(2024, 4, 1); // 1 de abril de 2024
    std::tm fechaFin = Utilidades::obtenerFecha(2024, 7, 31);   // 31 de julio de 2024

    Periodo periodo("Semestre 2024", "Descripción del semestre", fechaInicio, fechaFin); //Datos de ejemplo

    std::cout << "Nombre: " << periodo.obtenerNombre() << std::endl;
    std::cout << "Descripción: " << periodo.obtenerDescripcion() << std::endl;
    std::cout << "Fecha de inicio: " << Utilidades::crearFecha(periodo.obtenerFechaInicio()) << std::endl;
    std::cout << "Fecha de fin: " << Utilidades::crearFecha(periodo.obtenerFechaFin()) << std::endl;
    std::cout << "Materias: ";
    for (const auto& materia : periodo.obtenerMaterias()) {
        std::cout << materia << ", ";
    }
    std::cout << std::endl;

std::cout << "\n\n *Materia* \n \n";

    Materia materia( &periodo, "Descripción de la materia", {"Profesor1", "Profesor2"}, "Nombre de la materia", {}, true); //Datos de ejemplo

    std::cout << "Nombre: " << materia.obtenerNombre() << std::endl;
    std::cout << "Descripción: " << materia.obtenerDescripcion() << std::endl;
    std::cout << "Periodo: " << periodo.obtenerNombre() << std::endl;
    std::cout << "Profesores: ";
    for (const auto& profesor : materia.obtenerProfesores()) {
        std::cout << profesor << ", ";
    }
    std::cout << std::endl;

std::cout << "\n\n *Clases* \n \n";

Clase clase("ID de la materia", "Descripción", fechaInicio, "Tema"); //se usa la fecha de utilidades como ejemplo

std::cout << "ID de la materia: " << clase.obtenerIDMateria() << std::endl;
std::cout << "Descripción: " << clase.obtenerDescripcion() << std::endl;
std::cout << "Fecha: " << Utilidades::crearFecha(clase.obtenerFecha()) << std::endl;
std::cout << "Tema: " << clase.obtenerTema() << std::endl;


std::cout << "\n\n *Apunte* \n \n";
    int popularidad = 10; //provicional aun no se define bien la popularidad

    Apunte apunte(&usuario, "Contenido", fechaInicio, popularidad);

    std::cout << "Nombre: " << usuario.getNombre() << std::endl;
    std::cout << "Contenido: " << apunte.obtenerContenido() << std::endl;
    std::cout << "Fecha: " << Utilidades::crearFecha(clase.obtenerFecha()) << std::endl;
    std::cout << "Popularidad: " << apunte.obtenerPopularidad() << std::endl;


std::cout << "\n\n *Comentario* \n \n";
    
    std::string contenido = "Este es un comentario de ejemplo";
    std::tm fecha; // Supongamos que ya tienes la estructura de fecha inicializada

    // Instanciar un objeto Comentario
    Comentario comentario(&usuario, "contenido", fechaInicio);

    // Ahora puedes utilizar el objeto comentario como desees
    std::cout << "Nombre: " << usuario.getNombre() << std::endl;
    std::cout << "Contenido del comentario: " << comentario.obtenerContenido() << std::endl;
    std::cout << "Fecha: " << Utilidades::crearFecha(clase.obtenerFecha()) << std::endl;

    return 0;
}


