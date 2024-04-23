#include <iostream>
#include <Apunte.hpp>

template <typename T>
void assert_equal(const T& current, const T& expected) noexcept
{
    if (!equal(current, expected))
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

    // paso 2 hacemos los test como esperamos que funcione los metodos 
    std::cout << "Start Testing Mecha app ";

    {
        std::cout << "Testing Crear Usuario ";
        // nombre Esperdo
        // Usuario
       

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

}