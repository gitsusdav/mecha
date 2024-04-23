#include <iostream>
#include "Apunte.hpp"
#include "Usuario.hpp"
#include <vector>
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

void testGenerarId() {
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



int main()
{

    // Sha256 
    testGenerarId();

    // paso 2 hacemos los test como esperamos que funcione los metodos 
    std::cout << "Start Testing Mecha app" << "\n";

    {
        std::cout << "Testing Crear Apunte" << "\n";
        std::string contenido = "Apunte Nuevo";

        Apunte* nuevoApunte = new Apunte(); // recordar liberar memoria
        Apunte* nuevoApunteDos = new Apunte(); // recordar liberar memoria 
        
        nuevoApunte->setContenido(contenido);
        nuevoApunteDos->setContenido(contenido);

        std::string obtenerContenido = nuevoApunte->getContenido();

        assertEqual(obtenerContenido, contenido);
        
        obtenerContenido= nuevoApunteDos->getContenido();
        assertEqual(obtenerContenido, contenido);

        std::cout << "Testing Crear Usuario" << "\n";

        std::string nombre = "usurario";
        std::string id = "ID";
        std::string descripcion = "descripcion";
        std::vector<Usuario*> conexions;
        Usuario* nuevoUsuario = new Usuario();
        conexions.push_back(nuevoUsuario);
        std::vector<Rol> roles;
        roles.push_back(Rol::PROFESOR);
        int popular = 10;
        std::string correo = "correo@mail.com";
        std::string clave = "123456"; 
        std::vector<Apunte*> propios;
        std::vector<Apunte*> seguidos;

  
        propios.push_back(nuevoApunte);

        seguidos.push_back(nuevoApunteDos);

       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Asignar ID";
       
       // con los datos se genera un id por tabla hash
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Semestre";
       
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

        testGenerarId;
    }
  


}