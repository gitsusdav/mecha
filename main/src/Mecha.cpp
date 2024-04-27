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
    lineas de codigo para obtener la fecha

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

        Usuario usuario(nombre, descripcion, {}, correo, clave);
        guardarUsuarioEnLaBaseDeDatos(usuario);  

    } else if (opcion == 2) {
        //codigo de inicio de sesion
        
    } else {
        std::cout << "Opción inválida\n";
        return 0;
    }

    Usuario usuario(nombre, descripcion, {}, correo, clave);
    
    std::string nombrePeriodo, descripcionPeriodo;
    std::cout << "\n\n********** Periodo **********\n \n";
    std::cout << "¿En qué periodo te encuentras? ";
    std::getline(std::cin, nombrePeriodo);
    std::cout << "Ingrese la descripción del periodo: ";
    std::getline(std::cin, descripcionPeriodo);
    Periodo periodo(nombrePeriodo, descripcionPeriodo, {}, {});
    guardarPeriodoEnLaBaseDeDatos(periodo);  

    
    std::string nombreMateria, descripcionMateria;
    std::cout << "\n\n********** Materia **********\n \n";
    std::cout << "¿Qué materia quieres visualizar? ";
    std::getline(std::cin, nombreMateria);
    std::cout << "Ingrese la descripción de la materia: ";
    std::getline(std::cin, descripcionMateria);
    Materia materia(&periodo, descripcionMateria, {}, nombreMateria, {}, true);
    guardarMateriaEnLaBaseDeDatos(materia);  

    
    std::string idMateria, descripcionClase, tema;
    std::cout << "\n\n********** Clase **********\n \n";
    std::cout << "¿Hacia qué clase quieres ir? ";
    std::getline(std::cin, idMateria);
    std::cout << "Ingrese la descripción de la clase: ";
    std::getline(std::cin, descripcionClase);
    std::cout << "Ingrese el tema de la clase: ";
    std::getline(std::cin, tema);
    Clase clase(idMateria, descripcionClase, {}, tema);
    guardarClaseEnLaBaseDeDatos(clase);  
    

    std::string contenido;
    int popularidad;
    std::cout << "\n\n********** Apunte **********\n \n";
    std::cout << "¿Qué apunte quieres ver? ";
    std::getline(std::cin, contenido);
    std::cout << "Ingrese la popularidad del apunte: ";
    std::cin >> popularidad;
    std::cin.ignore();  
    Apunte apunte(&usuario, contenido, {}, popularidad);
    guardarApunteEnLaBaseDeDatos(apunte);  

    
    std::string contenidoComentario;
    std::cout << "\n\n********** Comentario **********\n \n";
    std::cout << "¿Quieres ver los comentarios que se hicieron a este apunte? ";
    std::getline(std::cin, contenidoComentario);
    Comentario comentario(&usuario, contenidoComentario, {});
    guardarComentarioEnLaBaseDeDatos(comentario);  

    //mostrar por pantalla todas las clases (apuntes, materias comentarios etc..)

    std::cout << "\n\n********** Periodos **********\n \n";  //obtener x DeLaBaseDeDatos seria la funcion de sqlite aun no implementada
    std::vector<Periodo> periodos = obtenerPeriodosDeLaBaseDeDatos();
    for (const Periodo& periodo : periodos) {
        std::cout << periodo.getNombre() << "\n";
    }

    std::cout << "\n\n********** Materias **********\n \n";
    std::vector<Materia> materias = obtenerMateriasDeLaBaseDeDatos();
    for (const Materia& materia : materias) {
        std::cout << materia.getNombre() << "\n";
    }

    std::cout << "\n\n********** Clases **********\n \n";
    std::vector<Clase> clases = obtenerClasesDeLaBaseDeDatos();
    for (const Clase& clase : clases) {
        std::cout << clase.getTema() << "\n";
    }

    std::cout << "\n\n********** Apuntes **********\n \n";
    std::vector<Apunte> apuntes = obtenerApuntesDeLaBaseDeDatos();
    for (const Apunte& apunte : apuntes) {
        std::cout << apunte.getContenido() << "\n";
    }

    std::cout << "\n\n********** Comentarios **********\n \n";
    std::vector<Comentario> comentarios = obtenerComentariosDeLaBaseDeDatos();
    for (const Comentario& comentario : comentarios) {
        std::cout << comentario.getContenido() << "\n";
    }

    return 0;
}

