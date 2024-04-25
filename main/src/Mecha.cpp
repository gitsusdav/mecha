#include <iostream>
#include "Utilidades.hpp"

int main(int argc, char* argv[])
{
    std::cout <<"\n\n MECHA APP \n \n" ;

    std::cout <<" # Crear Usuario \n \n" ;
   
    std::string resultados= Utilidades::generarId("aqui van las clases toString");
    std::cout << "ID" << "\n";

    std::cout << resultados << "\n\n";


}

