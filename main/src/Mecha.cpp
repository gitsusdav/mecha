#include <iostream>
#include "Utilidades.hpp"
#include "Usuario.hpp"
#include "Periodo.hpp"

int main(int argc, char* argv[])
{
    std::cout << "\n\n MECHA APP \n \n";

    std::string resultados = Utilidades::generarId("aqui van las clases toString");
    std::cout << "ID: " << resultados << "\n\n";

    Usuario usuario("Nombre", "Descripción", {}, "correo@example.com", "clave");

    std::cout << "Nombre: " << usuario.getNombre() << std::endl;
    std::cout << "Descripción: " << usuario.getDescripcion() << std::endl;
    std::cout << "Correo: " << usuario.getCorreo() << std::endl;
    std::cout << "Roles: ";
    for (const auto& rol : usuario.getRoles()) {
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

    std::tm fechaInicio = Utilidades::obtenerFecha(2024, 4, 1); // 1 de abril de 2024
    std::tm fechaFin = Utilidades::obtenerFecha(2024, 7, 31);   // 31 de julio de 2024

    Periodo periodo("Semestre de Verano 2024", "Descripción del semestre de verano",
                    fechaInicio, fechaFin,
                    {"Matemáticas", "Física", "Química"});

    std::cout << "Nombre: " << periodo.getNombre() << std::endl;
    std::cout << "Descripción: " << periodo.getDescripcion() << std::endl;
    std::cout << "Fecha de inicio: " << Utilidades::crearFecha(periodo.getFechaInicio()) << std::endl;
    std::cout << "Fecha de fin: " << Utilidades::crearFecha(periodo.getFechaFin()) << std::endl;
    std::cout << "Materias: ";
    for (const auto& materia : periodo.getMaterias()) {
        std::cout << materia << ", ";
    }
    std::cout << std::endl;

    return 0;
}
