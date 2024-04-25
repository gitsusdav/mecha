#include <iostream>
#include "Comentario.hpp"
#include "Apunte.hpp"
#include "Clase.hpp"
#include "Materia.hpp"
#include "Periodo.hpp"
#include "Usuario.hpp"
#include <vector>
#include <chrono>
#include <ctime>
#include <Utilidades.hpp>

template <typename T>
void assertEqual(const T& current, const T& expected) noexcept
{
    if (!(current == expected))
    {
        std::cerr << "Test failed!\n";
        std::cerr << "Current value: " << current << std::endl;
        std::cerr << "Expected value: " << expected << std::endl;
        abort();
    }

    std::cout << "Test ok!\n";
}


int main()
{
    // reserbamos memoria 
    Comentario* nuevoComentario = new Comentario();   
    Apunte* nuevoApunte = new Apunte(); 
    Apunte* nuevoApunteDos = new Apunte();
    Clase* nuevaClase = new Clase();
    Materia* nuevaMateria = new Materia();
    Periodo* nuevoPeriodo = new Periodo();         
    Usuario* nuevoUsuario = new Usuario(); 

    // paso 2 hacemos los test como esperamos que funcione los metodos 
    std::cout << "Start Testing Mecha app" << "\n";
    {
         // Sha256 
        std::cout << "Testing Generación de ID\n";

        //Caso de prueba 1: Generación de ID con un ejemplo

        std::string id1 = Utilidades::generarId("ejemplo");
        if (id1.empty()) {
            std::cerr << "Test failed: Generación de ID con cadena vacía\n";
        } else {
            std::cout << "Test ok: " << id1 << "\n";
        }

        // Caso de prueba 2: Generación de ID con cadena vacía
        std::string id2 = Utilidades::generarId("");
        if (id2.empty()) {
            std::cerr << "Test failed: Generación de ID con cadena vacía\n";
        } else {
            std::cout << "Test ok: Generación de ID con cadena vacía\n";
        }   
    }

    {

        std::cout << "Testing Crear Apunte" << "\n";
        std::string contenido = "Apunte Nuevo";

        auto now = std::chrono::system_clock::now();

        std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm* local_time = std::localtime(&time);
        
        nuevoApunte->setContenido(contenido);
        nuevoApunte->setFecha(*local_time);
        nuevoApunte->setUsuario(nuevoUsuario);
        nuevoApunte->setClase(nuevaClase);

        nuevoApunteDos->setContenido(contenido);

        std::string obtenerContenido = nuevoApunte->getContenido();

        assertEqual(obtenerContenido, contenido);
        
        obtenerContenido= nuevoApunteDos->getContenido();
        assertEqual(obtenerContenido, contenido);
    }

    {  
        std::cout << "Testing Crear Usuario" << "\n";

        std::string nombre = "usurario";
        std::string id = "ID";
        std::string descripcion = "descripcion";
        std::vector<Usuario*> conexions;
        conexions.push_back(nuevoUsuario);
        std::vector<Rol> roles;
        roles.push_back(Rol::PROFESOR);
        int popular = 10;
        std::string correo = "correo@mail.com";
        std::string clave = "123456"; 

        nuevoUsuario->setCorreo(correo);
        nuevoUsuario->setClave(clave);
        nuevoUsuario->setNombre(nombre);


        std::vector<Apunte*> propios;
        std::vector<Apunte*> seguidos;

  
        propios.push_back(nuevoApunte);

        seguidos.push_back(nuevoApunteDos);


        assertEqual(correo, nuevoUsuario->getCorreo());
        assertEqual(clave, nuevoUsuario->getClave());


        // Constructor full


    }

    {

        std::cout << "Testing Crear Comentario" << "\n";


        auto now = std::chrono::system_clock::now();

        std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm* local_time = std::localtime(&time);

        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
        std::string fechaString(buffer);

        nuevoComentario->setContenido("contenido");
        nuevoComentario->setDislikes(1);
        nuevoComentario->setFecha(*local_time);
        nuevoComentario->setLikes(1);
        nuevoComentario->setUsuario(nuevoUsuario);
        nuevoComentario->setApunte(nuevoApunte);

        std::tm fechaComentario = nuevoComentario->getFecha();
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &fechaComentario);
        std::string fechaAsignada(buffer);

        assertEqual(std::string ("contenido"), nuevoComentario->getContenido());
        assertEqual(1, nuevoComentario->getDislikes());
        assertEqual(1, nuevoComentario->getLikes());
        assertEqual(local_time->tm_yday,fechaComentario.tm_yday);
        assertEqual(std::string ("usurario"), nuevoUsuario->getNombre());
        assertEqual(std::string ("Apunte Nuevo"), nuevoApunte->getContenido());
        assertEqual(fechaString, fechaAsignada);
        std::cout << "Testing Fecha to String: " << fechaAsignada << "\n";

        // Constructor full
    
    }

    {
        std::cout << "Testing Asignar ID Usuario";

       // std::string idApunte =  
       
     //  assertEqual(actual, esperado);
    }

    {
        std::cout << "Testing Crear Periodo";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Materia";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Clase";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Apunte";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Agregar Apunte a Clase";
        // Apunte ...
       //  Clase...
       //  Apunte::asignar_clase( 1 ); // funciones como esperamos 

         //  esperamos que la clase tenga ese apunte 

       // assert_equal(actual, esperado);
    }
    
    {
        std::cout << "Testing Agregar Clase a Materia";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Agregar Materia a Semestre";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Agregar Semestre a Usuario";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Comentario";
       
       // assert_equal(actual, esperado);
    } 

    {
        std::cout << "Testing Crear Apunte anonimo";
       
       // assert_equal(actual, esperado);
    } 

    {
        std::cout << "Testing Agregar Comentario a Apunte";
       
       // assert_equal(actual, esperado);
    } 

    {
        std::cout << "Testing Buscar tema devuelve Lista de Apuntes";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Buscar tema devuelve Lista de Clases";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Seguir Apunte";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Seguir Usuario";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Agregar Materia a Usuario";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Modificar Apunte";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Eliminar Apunte";
       
       // assert_equal(actual, esperado);
    }

  
    {
        std::cout << "Testing Generar ID";

    }

    // se libera la memoria
    delete nuevoComentario;
    delete nuevoApunte;
    delete nuevoApunteDos;
    delete nuevaClase;
    delete nuevaMateria;
    delete nuevoPeriodo;
    delete nuevoUsuario;

}