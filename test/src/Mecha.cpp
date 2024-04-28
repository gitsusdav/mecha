#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

#include "Comentario.hpp"
#include "Apunte.hpp"
#include "Clase.hpp"
#include "Materia.hpp"
#include "Periodo.hpp"
#include "Usuario.hpp"
#include "NodoPadre.hpp"
#include "ArbolPadre.hpp"
#include <Utilidades.hpp>

template <typename T>
void assertEqual(const T& current, const T& expected) noexcept
{
    if (!(current == expected))
    {
        std::cerr << "Test failed!\n";
        std::cerr << "Current value: " << current << " \n";
        std::cerr << "Expected value: " << expected << " \n";
        abort();
    }

    std::cout << "Test ok!\n";
}


int main()
{
    // reservamos memoria 
    Comentario* nuevoComentario = new Comentario();   
    Apunte* nuevoApunte = new Apunte(); 
    Apunte* nuevoApunteDos = new Apunte();
    Clase* nuevaClase = new Clase();
    Materia* nuevaMateria = new Materia();
    Periodo* nuevoPeriodo = new Periodo();         
    Usuario* nuevoUsuario = new Usuario(); 
    std::vector<Apunte*> misApuntes = {nuevoApunte, nuevoApunteDos};
    std::vector<Clase*> clasesMateria = {nuevaClase};
    std::vector<Materia*> periodoMateria = {nuevaMateria};

   
    NodoPadre* rootTreeFather;
    NodoPadre* periodoTreeFather;
    NodoPadre* materiaTreeFather;
    NodoPadre* claseTreeFather;
    NodoPadre* apunteTreeFather;
    NodoPadre* comentarioTreeFather;

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
        nuevoUsuario->setRoles(roles);
        nuevoUsuario->setConexiones(conexions);


        std::vector<Apunte*> propios;
        std::vector<Apunte*> seguidos;

  
        propios.push_back(nuevoApunte);
        seguidos.push_back(nuevoApunteDos);

        nuevoUsuario->setApuntesPropios(propios);
        nuevoUsuario->setApuntesSeguidos(seguidos);


        assertEqual(correo, nuevoUsuario->getCorreo());
        assertEqual(clave, nuevoUsuario->getClave());


        // Constructor full
       // Usuario * fullUsuario = new Usuario("nombre","sobre el usuario en cuestion",)

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

        std::cout << "Testing Crear Clase" << "\n";
    
        auto now = std::chrono::system_clock::now();

        std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm* local_time = std::localtime(&time);

        std::vector<std::string> misRecursos = {"urlRecuerso1", "urlRecuerso2", "urlRecuerso3"};

        nuevaClase->setApuntes(misApuntes);
        nuevaClase->setDescripcion("descrip");
        nuevaClase->setFecha(*local_time);
        nuevaClase->setIDMateria("string");
        nuevaClase->setRecursos(misRecursos);
        nuevaClase->setTema("tema principal");

        assertEqual(nuevoApunte->getContenido(), nuevaClase->getApuntes().at(0)->getContenido());
        assertEqual(std::string("descrip"), nuevaClase->getDescripcion());
        assertEqual(local_time->tm_yday,nuevaClase->getFecha().tm_yday);
        assertEqual(std::string("string"),nuevaClase->getIDMateria());
        assertEqual(std::string("tema principal"), nuevaClase->getTema());
        assertEqual(misApuntes.at(0),nuevaClase->getApuntes().at(0));

        // Constructor full

    }

    {

        std::cout << "Testing Crear Materia" << "\n";

        std::vector<std::string> profesoresMateria = {"Profesor1", "Profesor2", "Profesor3"};

        nuevaMateria->setClases(clasesMateria);
        nuevaMateria->setDescripcion("descrip");
        nuevaMateria->setNombre("Materia");
        nuevaMateria->setPeriodo(nuevoPeriodo);
        nuevaMateria->setPeriodoActivo(true);
        nuevaMateria->setProfesores(profesoresMateria);

        assertEqual(nuevaClase->getDescripcion() ,nuevaMateria->getClases().at(0)->getDescripcion());
        assertEqual(std::string("descrip") ,nuevaMateria->getDescripcion());
        assertEqual(nuevoPeriodo->getDescripcion() ,nuevaMateria->getPeriodo()->getDescripcion());
        assertEqual(std::string("Materia") ,nuevaMateria->getNombre());
        assertEqual(true ,nuevaMateria->getPeriodoActivo());
        assertEqual(profesoresMateria.at(0) ,nuevaMateria->getProfesores().at(0));
    
    }

    {

        std::cout << "Testing Crear Periodo" << "\n";

        auto now = std::chrono::system_clock::now();

        std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm* local_time = std::localtime(&time);

        nuevoPeriodo->setDescripcion("descr");
        nuevoPeriodo->setFechaFin(*local_time);
        nuevoPeriodo->setFechaInicio(*local_time);
        nuevoPeriodo->setMaterias(periodoMateria);
        nuevoPeriodo->setNombre("A2024");
    
    }

    {
        std::cout << "Testing Asignar ID Usuario" << "\n";

        std::string idUsuario =  Utilidades::generarId(nuevoUsuario->toString());
        nuevoUsuario->setID(idUsuario);

        assertEqual(idUsuario, nuevoUsuario->getID());

    }

     {
        std::cout << "Testing Asignar ID Apunte" << "\n";

        std::string idApunte =  Utilidades::generarId(nuevoApunte->toString());
        nuevoApunte->setID(idApunte);

        assertEqual(idApunte, nuevoApunte->getID());

    }

    {
        std::cout << "Testing Asignar ID Clase" << "\n";

        std::string idClase =  Utilidades::generarId(nuevaClase->toString());
        nuevaClase->setID(idClase);

        assertEqual(idClase, nuevaClase->getID());

    }

    {
        std::cout << "Testing Asignar ID Materia" << "\n";

        std::string idMateria =  Utilidades::generarId(nuevaMateria->toString());
        nuevaMateria->setID(idMateria);

        assertEqual(idMateria, nuevaMateria->getID());

    }

    {
        std::cout << "Testing Asignar ID Periodo" << "\n";

        std::string idPeriodo =  Utilidades::generarId(nuevoPeriodo->toString());
        nuevoPeriodo->setID(idPeriodo);

        assertEqual(idPeriodo, nuevoPeriodo->getID());

    }
    
    {
        std::cout << "Testing Asignar ID Comentario" << "\n";

        std::string idComentario =  Utilidades::generarId(nuevoComentario->toString());
        nuevoComentario->setID(idComentario);

        assertEqual(idComentario, nuevoComentario->getID());

    }

   
    {
        std::cout << "Testing Agregar Apunte a Clase"<< "\n";

        auto idClase = nuevaClase->getIDMateria();
        auto id = nuevoApunte->getClase()->getID();


        std::cout << "idClase: " << idClase << " \n";
        std::cout << "id: " << id << " \n";


        std::cout << "Despues de los cambios: " << " \n";

        nuevaClase->agregarApunte(nuevoApunte);
        nuevoApunte->setClase(nuevaClase);

        idClase = nuevaClase->getIDMateria();
        id = nuevoApunte->getClase()->getID();

        std::cout << "idClase: " << idClase << " \n";
        std::cout << "id: " << id << " \n";

        auto idMateria = nuevaClase->getIDMateria();
        id = nuevaMateria->getID();
   
        assertEqual(nuevoApunte->getClase()->getID(), nuevaClase->getID());
        assertEqual(nuevoApunte->getContenido(), nuevaClase->getApuntes().back()->getContenido());
    }
    
    {
        std::cout << "Testing Agregar Clase a Materia" << " \n";

        auto idMateria = nuevaClase->getIDMateria();
        auto id = nuevaMateria->getID();

        std::cout << "idMateria: " << idMateria << " \n";
        std::cout << "id: " << id << " \n";

        nuevaMateria->agregarClase(nuevaClase);

        std::cout << "Despues de los cambios:" << " \n";

        idMateria = nuevaClase->getIDMateria();
        id = nuevaMateria->getID();

        std::cout << "idMateria: " << idMateria << " \n";
        std::cout << "id: " << id << " \n";
         //  esperamos que la materia tenga esa clase
        assertEqual(nuevaClase->getIDMateria(), nuevaMateria->getID());

        // revisamos que la ultima clase, sea la ultima de el vector de clases
        assertEqual(nuevaClase->getDescripcion(), nuevaMateria->getClases().back()->getDescripcion());
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Agregar Materia a Periodo" << " \n";
        auto idMateria = nuevaMateria->getPeriodo()->getID();
        auto idPeriodo = nuevoPeriodo->getID();

        std::cout << "ID materia: " << idMateria << " \n";
        std::cout << "ID periodo: " << idPeriodo << " \n";

        nuevoPeriodo->agregarMateria(nuevaMateria);
        nuevaMateria->setPeriodo(nuevoPeriodo);

        idMateria = nuevaMateria->getPeriodo()->getID();
        idPeriodo = nuevoPeriodo->getID();

        std::cout << "Despues\n" << "ID materia: " << idMateria << " \n";
        std::cout << "ID periodo: " << idPeriodo << " \n";

        assertEqual(idMateria, idPeriodo);
        assertEqual(nuevaMateria->getDescripcion(), nuevoPeriodo->getMaterias().back()->getDescripcion());
    }

    {
        std::cout << "Testing Agregar Periodo a Usuario";
       
       // assert_equal(actual, esperado);
    }


    {
        std::cout << "Testing Agregar Comentario a Apunte" << " \n";
        auto idComentario = nuevoComentario->getApunte()->getID();
        auto idApunte = nuevoApunte->getID();

        std::cout << "id comentario: " << idComentario << " \n";
        std::cout << "id apunte: " << idApunte << " \n";

        nuevoComentario->setApunte(nuevoApunte);
        nuevoApunte->agregarComentario(nuevoComentario);

        idComentario = nuevoComentario->getApunte()->getID();
        idApunte = nuevoApunte->getID();

        assertEqual(idComentario, idApunte);
        assertEqual(nuevoComentario->getID(), nuevoApunte->getComentarios().back()->getID());
    } 

    {

        std::cout << "Testing Buscar tema devuelve Lista de Apuntes" << " \n";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Materia Buscar tema devuelve Lista de Clases" << " \n";
       
        std::vector<Clase *> resultado =  nuevaMateria->buscarTemaEnClases("principal");

        assertEqual(false,resultado.empty());
        assertEqual(resultado.at(0)->getID(), nuevaMateria->getClases().at(0)->getID());
        
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
        std::cout << "Testing Eliminar Apunte"<< " \n";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Raiz con Usuario del Arbol Padre"<< " \n";
       
        ArbolPadre* controlUsuario = nuevoUsuario;
        rootTreeFather = new NodoPadre(controlUsuario, "/");

        std::cout << "Valor (root): " << rootTreeFather->obtenerValor()->toString() << " Camino (path): " << rootTreeFather->obtenerCamino()  << " \n";

        assertEqual(std::string("/"), rootTreeFather->obtenerCamino());
        assertEqual(rootTreeFather->obtenerValor()->toString(), nuevoUsuario->toString() );
    }

    {
        std::cout << "Testing Agregar nodos al Arbol Padre"<< " \n";

        ArbolPadre* controlComentario = nuevoComentario;
        ArbolPadre* controlApunte = nuevoApunte;
        ArbolPadre* controlClase = nuevaClase;
        ArbolPadre* controlMateria = nuevaMateria;
        ArbolPadre* controlPeriodo = nuevoPeriodo;
        ArbolPadre* controlUsuario = nuevoUsuario;

        apunteTreeFather = new NodoPadre(controlApunte, nuevoApunte->getID());
        comentarioTreeFather = new NodoPadre(controlComentario, nuevoComentario->getID());
        periodoTreeFather = new NodoPadre(controlPeriodo, nuevoPeriodo->getID());
        materiaTreeFather = new NodoPadre(controlMateria, nuevaMateria->getID());
        claseTreeFather =  new NodoPadre(controlClase, nuevaClase->getID());

        periodoTreeFather->setPadre(rootTreeFather);

        materiaTreeFather->setPadre(periodoTreeFather);

        claseTreeFather->setPadre(materiaTreeFather);

        apunteTreeFather->setPadre(claseTreeFather);

        comentarioTreeFather->setPadre(apunteTreeFather);
    
        std::cout << "Valor (Usuario root): " << rootTreeFather->obtenerValor()->toString() << " Camino (path): " << rootTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Periodo): " << periodoTreeFather->obtenerValor()->toString() << " Camino (path): " << periodoTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Materia): " << materiaTreeFather->obtenerValor()->toString() << " Camino (path): " << materiaTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Clase): " << claseTreeFather->obtenerValor()->toString() << " Camino (path): " << claseTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Apunte): " << apunteTreeFather->obtenerValor()->toString() << " Camino (path): " << apunteTreeFather->obtenerCamino()  << " \n\n";

        std::cout << "Valor (Comentario): " << comentarioTreeFather->obtenerValor()->toString() << " Camino (path): " << comentarioTreeFather->obtenerCamino()  << " \n\n";
    
        assertEqual(rootTreeFather->obtenerValor()->toString(), nuevoUsuario->toString());
        assertEqual(periodoTreeFather->obtenerValor()->toString(), nuevoPeriodo->toString());
        assertEqual(materiaTreeFather->obtenerValor()->toString(), nuevaMateria->toString());
        assertEqual(claseTreeFather->obtenerValor()->toString(), nuevaClase->toString());
        assertEqual(apunteTreeFather->obtenerValor()->toString(), nuevoApunte->toString());
        assertEqual(comentarioTreeFather->obtenerValor()->toString(), nuevoComentario->toString());

        // Testing de path 
        assertEqual(rootTreeFather->obtenerCamino(),       std::string("/"));
        assertEqual(periodoTreeFather->obtenerCamino(),    std::string("/")+nuevoPeriodo->getID()+std::string("/"));
        assertEqual(materiaTreeFather->obtenerCamino(),    std::string("/")+nuevoPeriodo->getID()+std::string("/")+nuevaMateria->getID()+std::string("/"));
        assertEqual(claseTreeFather->obtenerCamino(),      std::string("/")+nuevoPeriodo->getID()+std::string("/")+nuevaMateria->getID()+std::string("/")+nuevaClase->getID()+std::string("/"));
        assertEqual(apunteTreeFather->obtenerCamino(),     std::string("/")+nuevoPeriodo->getID()+std::string("/")+nuevaMateria->getID()+std::string("/")+nuevaClase->getID()+std::string("/")+nuevoApunte->getID()+std::string("/"));
        assertEqual(comentarioTreeFather->obtenerCamino(), std::string("/")+nuevoPeriodo->getID()+std::string("/")+nuevaMateria->getID()+std::string("/")+nuevaClase->getID()+std::string("/")+nuevoApunte->getID()+std::string("/")+nuevoComentario->getID()+std::string("/"));

    }

   std::cout << "\n\n Testing Completados :D onFire"<< " \n\n";

    // se libera la memoria
    delete nuevoComentario;
    delete nuevoApunte;
    delete nuevoApunteDos;
    delete nuevaClase;
    delete nuevaMateria;
    delete nuevoPeriodo;
    delete nuevoUsuario;

    delete rootTreeFather;
    delete periodoTreeFather;
    delete materiaTreeFather;
    delete claseTreeFather;
    delete apunteTreeFather;
    delete comentarioTreeFather;

}