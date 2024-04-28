#include <iostream>
#include <vector>
#include "Utilidades.hpp"
#include "Usuario.hpp"
#include "Periodo.hpp"
#include "Materia.hpp"
#include "Clase.hpp"
#include "Apunte.hpp"
#include "Comentario.hpp"


/*
    lineas de codigo provicionales para obtener la fecha

    std::tm fechaInicio = Utilidades::obtenerFecha(2024, 4, 1); // 1 de abril de 2024
    std::tm fechaFin = Utilidades::obtenerFecha(2024, 7, 31);   // 31 de julio de 2024

*/


void guardarUsuarioEnLaBaseDeDatos(const Usuario& usuario) {
    //logica con sqlite para guardar la clase
}

void guardarPeriodoEnLaBaseDeDatos(const Periodo& periodo) {
    //logica con sqlite para guardar la clase
}

void guardarMateriaEnLaBaseDeDatos(const Materia& materia) {
    //logica con sqlite para guardar la clase
}

void guardarClaseEnLaBaseDeDatos(const Clase& clase) {
    //logica con sqlite para guardar la clase
}

void guardarApunteEnLaBaseDeDatos(const Apunte& apunte) {
    //logica con sqlite para guardar la clase
}

void guardarComentarioEnLaBaseDeDatos(const Comentario& comentario) {
    //logica con sqlite para guardar la clase
}

std::vector<Usuario> obtenerUsuariosDeLaBaseDeDatos(){
    return {};
}

std::vector<Materia> obtenerMateriasDeLaBaseDeDatos(){
    return {};
}

std::vector<Periodo> obtenerPeriodosDeLaBaseDeDatos(){
    return {};
}
std::vector<Clase> obtenerClasesDeLaBaseDeDatos(){
    return {};
}
std::vector<Apunte> obtenerApuntesDeLaBaseDeDatos(){
    return {};
}
std::vector<Comentario> obtenerComentariosDeLaBaseDeDatos(){
    return {};
}

int main(int argc, char* argv[])
{
    std::string nombre, descripcion, correo, clave;
    int opcion, rol;

    std::cout << "\n\n********** MECHA APP **********\n \n";

    std::cout << "1. Registrarse\n";
    std::cout << "2. Iniciar sesión\n";
    std::cout << "Ingrese una opción: ";
    std::cin >> opcion;
    std::cin.ignore(); 

    if (opcion == 1) {
        std::cout << "Ingrese su nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Ingrese una descripción: ";
        std::getline(std::cin, descripcion);
        std::cout << "Ingrese su correo: ";
        std::getline(std::cin, correo);
        std::cout << "Ingrese su clave: ";
        std::getline(std::cin, clave);
        std::cout << "Elija su rol (1. Profesor, 2. Estudiante, 3. Graduado): ";
        std::cin >> rol;
        std::cin.ignore(); 

        Usuario usuario(nombre, descripcion, {static_cast<Rol>(rol)}, correo, clave); 
        guardarUsuarioEnLaBaseDeDatos(usuario);  

    } else if (opcion == 2) {
        //codigo de inicio de sesion
        
    } else {
        std::cout << "Opción inválida\n";
        return 0;
    }

    Usuario usuario(nombre, descripcion, {static_cast<Rol>(rol)}, correo, clave);

    int accion;
    do {
        std::cout << "\n\n********** Opciones **********\n \n";
        std::cout << "1. Añadir periodo\n";
        std::cout << "2. Añadir materia\n";
        std::cout << "3. Añadir clase\n";
        std::cout << "4. Añadir apunte\n";
        std::cout << "5. Añadir comentario\n";
        std::cout << "6. Ver datos\n";
        std::cout << "7. Salir\n";
        std::cout << "Ingrese una opción: ";
        std::cin >> accion;
        std::cin.ignore();

        switch (accion) {
            case 1: {
                std::string nombrePeriodo, descripcionPeriodo;
                std::cout << "\n\n********** Periodo **********\n \n";
                std::cout << "Añade un nuevo periodo: ";
                std::getline(std::cin, nombrePeriodo);
                std::cout << "Ingrese la descripción del periodo: ";
                std::getline(std::cin, descripcionPeriodo);
                Periodo periodo(nombrePeriodo, descripcionPeriodo, {}, {});
                guardarPeriodoEnLaBaseDeDatos(periodo);
                break;
            }
            case 2: {
                std::string nombreMateria, descripcionMateria;
                std::cout << "\n\n********** Materia **********\n \n";
                std::cout << "Añade una nueva materia: ";
                std::getline(std::cin, nombreMateria);
                std::cout << "Ingrese la descripción de la materia: ";
                std::getline(std::cin, descripcionMateria);
                Materia materia(nullptr, descripcionMateria, {}, nombreMateria, {}, true);
                guardarMateriaEnLaBaseDeDatos(materia);
                break;
            }
            case 3: {
                std::string idMateria, descripcionClase, tema;
                std::cout << "\n\n********** Clase **********\n \n";
                std::cout << "Añade una nueva clase: ";
                std::getline(std::cin, idMateria);
                std::cout << "Ingrese la descripción de la clase: ";
                std::getline(std::cin, descripcionClase);
                std::cout << "Ingrese el tema de la clase: ";
                std::getline(std::cin, tema);
                Clase clase(idMateria, descripcionClase, {}, tema);
                guardarClaseEnLaBaseDeDatos(clase);
                break;
            }
            case 4: {
                std::string contenido;
                int popularidad;
                std::cout << "\n\n********** Apunte **********\n \n";
                std::cout << "Añade un nuevo apunte: ";
                std::getline(std::cin, contenido);
                std::cout << "Ingrese la popularidad del apunte: ";
                std::cin >> popularidad;
                std::cin.ignore();  
                Apunte apunte(&usuario, contenido, {}, popularidad);
                guardarApunteEnLaBaseDeDatos(apunte);
                break;
            }
            case 5: {
                std::string contenidoComentario;
                std::cout << "\n\n********** Comentario **********\n \n";
                std::cout << "Añade un nuevo comentario: ";
                std::getline(std::cin, contenidoComentario);
                Comentario comentario(&usuario, contenidoComentario, {});
                guardarComentarioEnLaBaseDeDatos(comentario);
                break;
            }
            case 6: {
                std::cout << "\n\n********** Usuario **********\n \n";  
                std::vector<Usuario> usuarios = obtenerUsuariosDeLaBaseDeDatos();
                for (const Usuario& usuario : usuarios) {
                    std::cout << "Nombre: " << usuario.obtenerNombre() << "\n";
                    std::cout << "Rol: ";
                    switch (usuario.getRoles()[0]) {  
                        case Rol::PROFESOR:
                            std::cout << "Profesor\n";
                            break;
                        case Rol::ESTUDIANTE:
                            std::cout << "Estudiante\n";
                            break;
                        case Rol::GRADUADO:
                            std::cout << "Graduado\n";
                            break;
                    }
                }

                std::cout << "\n\n********** Periodos **********\n \n";  //obtener x DeLaBaseDeDatos seria la funcion de sqlite aun no implementada
                std::vector<Periodo> periodos = obtenerPeriodosDeLaBaseDeDatos();
                for (const Periodo& periodo : periodos) {
                    std::cout << periodo.obtenerNombre() << "\n";
                }

                std::cout << "\n\n********** Materias **********\n \n";
                std::vector<Materia> materias = obtenerMateriasDeLaBaseDeDatos();
                for (const Materia& materia : materias) {
                    std::cout << materia.obtenerNombre() << "\n";
                }

                std::cout << "\n\n********** Clases **********\n \n";
                std::vector<Clase> clases = obtenerClasesDeLaBaseDeDatos();
                for (const Clase& clase : clases) {
                    std::cout << clase.obtenerTema() << "\n";
                }

                std::cout << "\n\n********** Apuntes **********\n \n";
                std::vector<Apunte> apuntes = obtenerApuntesDeLaBaseDeDatos();
                for (const Apunte& apunte : apuntes) {
                    std::cout << apunte.obtenerContenido() << "\n";
                }

                std::cout << "\n\n********** Comentarios **********\n \n";
                std::vector<Comentario> comentarios = obtenerComentariosDeLaBaseDeDatos();
                for (const Comentario& comentario : comentarios) {
                    std::cout << comentario.obtenerContenido() << "\n";
                }
                break;
            }
            case 7: {
                std::cout << "Saliendo...\n";
                break;
            }
            default: {
                std::cout << "Opción inválida\n";
                break;
            }
        }
    } while (accion != 7);

    return 0;
}
