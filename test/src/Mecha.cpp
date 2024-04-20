#pragma once

#include <iostream>

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


    std::cout << "Start Testing Mecha app ";

    {
        std::cout << "Testing Crear Usuario ";
       
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

}