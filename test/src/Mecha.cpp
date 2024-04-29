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
#include "NodoFuego.hpp"
#include "TablaHash.hpp"
#include "BaseMecha.hpp"
#include "ManejoSqlite.hpp"
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
    std::vector<Periodo*> periodoUsuario = {nuevoPeriodo};

    ManejoSqlite baseDatos("DatosCalientesMecha.db");
    TablaHash hijosArbol = TablaHash();

    NodoPadre* rootTreeFather;
    NodoPadre* periodoTreeFather;
    NodoPadre* materiaTreeFather;
    NodoPadre* claseTreeFather;
    NodoPadre* apunteTreeFather;
    NodoPadre* comentarioTreeFather;
    NodoPadre* usuarioTreeFather;

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
        
        nuevoApunte->asignarContenido(contenido);
        nuevoApunte->asignarFecha(*local_time);
        nuevoApunte->asignarUsuario(nuevoUsuario);
        nuevoApunte->asignarClase(nuevaClase);

        nuevoApunteDos->asignarContenido(contenido);
        nuevoApunteDos->asignarFecha(*local_time);
        nuevoApunteDos->asignarUsuario(nuevoUsuario);
        nuevoApunteDos->asignarClase(nuevaClase);

        std::string obtenerContenido = nuevoApunte->obtenerContenido();

        assertEqual(obtenerContenido, contenido);
        
        obtenerContenido= nuevoApunteDos->obtenerContenido();
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

        nuevoUsuario->asignarCorreo(correo);
        nuevoUsuario->asignarClave(clave);
        nuevoUsuario->asignarNombre(nombre);
        nuevoUsuario->asignarRoles(roles);
        nuevoUsuario->asignarConexiones(conexions);
        nuevoUsuario->asignarPeriodos(periodoUsuario);

        std::vector<Apunte*> propios;
        std::vector<Apunte*> seguidos;

  
        propios.push_back(nuevoApunte);
        seguidos.push_back(nuevoApunteDos);

        nuevoUsuario->asignarApuntesPropios(propios);
        nuevoUsuario->asignarApuntesSeguidos(seguidos);


        assertEqual(correo, nuevoUsuario->obtenerCorreo());
        assertEqual(clave, nuevoUsuario->obtenerClave());


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

        nuevoComentario->asignarContenido("contenido");
        nuevoComentario->asignarDislikes(1);
        nuevoComentario->asignarFecha(*local_time);
        nuevoComentario->asignarLikes(1);
        nuevoComentario->asignarUsuario(nuevoUsuario);
        nuevoComentario->asignarApunte(nuevoApunte);

        std::tm fechaComentario = nuevoComentario->obtenerFecha();
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &fechaComentario);
        std::string fechaAsignada(buffer);

        assertEqual(std::string ("contenido"), nuevoComentario->obtenerContenido());
        assertEqual(1, nuevoComentario->obtenerDislikes());
        assertEqual(1, nuevoComentario->obtenerLikes());
        assertEqual(local_time->tm_yday,fechaComentario.tm_yday);
        assertEqual(std::string ("usurario"), nuevoUsuario->obtenerNombre());
        assertEqual(std::string ("Apunte Nuevo"), nuevoApunte->obtenerContenido());
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

        nuevaClase->asignarApuntes(misApuntes);
        nuevaClase->asignarDescripcion("descrip");
        nuevaClase->asignarFecha(*local_time);
        nuevaClase->asignarIDMateria("string");
        nuevaClase->asignarRecursos(misRecursos);
        nuevaClase->asignarTema("tema principal");

        assertEqual(nuevoApunte->obtenerContenido(), nuevaClase->obtenerApuntes().at(0)->obtenerContenido());
        assertEqual(std::string("descrip"), nuevaClase->obtenerDescripcion());
        assertEqual(local_time->tm_yday,nuevaClase->obtenerFecha().tm_yday);
        assertEqual(std::string("string"),nuevaClase->obtenerIDMateria());
        assertEqual(std::string("tema principal"), nuevaClase->obtenerTema());
        assertEqual(misApuntes.at(0),nuevaClase->obtenerApuntes().at(0));

        // Constructor full

    }

    {

        std::cout << "Testing Crear Materia" << "\n";

        std::vector<std::string> profesoresMateria = {"Profesor1", "Profesor2", "Profesor3"};

        nuevaMateria->asignarClases(clasesMateria);
        nuevaMateria->asignarDescripcion("descrip");
        nuevaMateria->asignarNombre("Materia");
        nuevaMateria->asignarPeriodo(nuevoPeriodo);
        nuevaMateria->asignarPeriodoActivo(true);
        nuevaMateria->asignarProfesores(profesoresMateria);

        assertEqual(nuevaClase->obtenerDescripcion() ,nuevaMateria->obtenerClases().at(0)->obtenerDescripcion());
        assertEqual(std::string("descrip") ,nuevaMateria->obtenerDescripcion());
        assertEqual(nuevoPeriodo->obtenerDescripcion() ,nuevaMateria->obtenerPeriodo()->obtenerDescripcion());
        assertEqual(std::string("Materia") ,nuevaMateria->obtenerNombre());
        assertEqual(true ,nuevaMateria->obtenerPeriodoActivo());
        assertEqual(profesoresMateria.at(0) ,nuevaMateria->obtenerProfesores().at(0));
    
    }

    {

        std::cout << "Testing Crear Periodo" << "\n";

        auto now = std::chrono::system_clock::now();

        std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm* local_time = std::localtime(&time);

        nuevoPeriodo->asignarDescripcion("descr");
        nuevoPeriodo->asignarFechaFin(*local_time);
        nuevoPeriodo->asignarFechaInicio(*local_time);
        nuevoPeriodo->asignarMaterias(periodoMateria);
        nuevoPeriodo->asignarNombre("A2024");
    
    }

    {
        std::cout << "Testing Asignar ID Usuario" << "\n";

        std::string idUsuario =  Utilidades::generarId(nuevoUsuario->toString());
        nuevoUsuario->asignarID(idUsuario);

        assertEqual(idUsuario, nuevoUsuario->obtenerID());

    }

     {
        std::cout << "Testing Asignar ID Apunte" << "\n";

        std::string idApunte =  Utilidades::generarId(nuevoApunte->toString());
        nuevoApunte->asignarID(idApunte);

        assertEqual(idApunte, nuevoApunte->obtenerID());

    }

    {
        std::cout << "Testing Asignar ID Clase" << "\n";

        std::string idClase =  Utilidades::generarId(nuevaClase->toString());
        nuevaClase->asignarID(idClase);

        assertEqual(idClase, nuevaClase->obtenerID());

    }

    {
        std::cout << "Testing Asignar ID Materia" << "\n";

        std::string idMateria =  Utilidades::generarId(nuevaMateria->toString());
        nuevaMateria->asignarID(idMateria);

        assertEqual(idMateria, nuevaMateria->obtenerID());

    }

    {
        std::cout << "Testing Asignar ID Periodo" << "\n";

        std::string idPeriodo =  Utilidades::generarId(nuevoPeriodo->toString());
        nuevoPeriodo->asignarID(idPeriodo);

        assertEqual(idPeriodo, nuevoPeriodo->obtenerID());

    }
    
    {
        std::cout << "Testing Asignar ID Comentario" << "\n";

        std::string idComentario =  Utilidades::generarId(nuevoComentario->toString());
        nuevoComentario->asignarID(idComentario);

        assertEqual(idComentario, nuevoComentario->obtenerID());

    }

   
    {
        std::cout << "Testing Agregar Apunte a Clase"<< "\n";

        auto idClase = nuevaClase->obtenerIDMateria();
        auto id = nuevoApunte->obtenerClase()->obtenerID();

/*
        std::cout << "idClase: " << idClase << " \n";
        std::cout << "id: " << id << " \n";


        std::cout << "Despues de los cambios: " << " \n";
*/
        nuevaClase->agregarApunte(nuevoApunte);
        nuevoApunte->asignarClase(nuevaClase);

        idClase = nuevaClase->obtenerIDMateria();
        id = nuevoApunte->obtenerClase()->obtenerID();
/*
        std::cout << "idClase: " << idClase << " \n";
        std::cout << "id: " << id << " \n";
*/
        auto idMateria = nuevaClase->obtenerIDMateria();
        id = nuevaMateria->obtenerID();
   
        assertEqual(nuevoApunte->obtenerClase()->obtenerID(), nuevaClase->obtenerID());
        assertEqual(nuevoApunte->obtenerContenido(), nuevaClase->obtenerApuntes().back()->obtenerContenido());
    }
    
    {
        std::cout << "Testing Agregar Clase a Materia" << " \n";

        auto idMateria = nuevaClase->obtenerIDMateria();
        auto id = nuevaMateria->obtenerID();
/*
        std::cout << "idMateria: " << idMateria << " \n";
        std::cout << "id: " << id << " \n";


        std::cout << "Despues de los cambios:" << " \n";
*/
        nuevaMateria->agregarClase(nuevaClase);

        idMateria = nuevaClase->obtenerIDMateria();
        id = nuevaMateria->obtenerID();
/*
        std::cout << "idMateria: " << idMateria << " \n";
        std::cout << "id: " << id << " \n";
*/         //  esperamos que la materia tenga esa clase
        assertEqual(nuevaClase->obtenerIDMateria(), nuevaMateria->obtenerID());

        // revisamos que la ultima clase, sea la ultima de el vector de clases
        assertEqual(nuevaClase->obtenerDescripcion(), nuevaMateria->obtenerClases().back()->obtenerDescripcion());

    }

    {
        std::cout << "Testing Agregar Materia a Periodo" << " \n";
        auto idMateria = nuevaMateria->obtenerPeriodo()->obtenerID();
        auto idPeriodo = nuevoPeriodo->obtenerID();
/*
        std::cout << "ID materia: " << idMateria << " \n";
        std::cout << "ID periodo: " << idPeriodo << " \n";
*/
        nuevoPeriodo->agregarMateria(nuevaMateria);
        nuevaMateria->asignarPeriodo(nuevoPeriodo);

        idMateria = nuevaMateria->obtenerPeriodo()->obtenerID();
        idPeriodo = nuevoPeriodo->obtenerID();
/*
        std::cout << "Despues\n" << "ID materia: " << idMateria << " \n";
        std::cout << "ID periodo: " << idPeriodo << " \n";
*/
        assertEqual(idMateria, idPeriodo);
        assertEqual(nuevaMateria->obtenerDescripcion(), nuevoPeriodo->obtenerMaterias().back()->obtenerDescripcion());
    }


    {
        std::cout << "Testing Agregar Comentario a Apunte" << " \n";
        auto idComentario = nuevoComentario->obtenerApunte()->obtenerID();
        auto idApunte = nuevoApunte->obtenerID();
/*
        std::cout << "id comentario: " << idComentario << " \n";
        std::cout << "id apunte: " << idApunte << " \n";
*/
        nuevoComentario->asignarApunte(nuevoApunte);
        nuevoApunte->agregarComentario(nuevoComentario);

        idComentario = nuevoComentario->obtenerApunte()->obtenerID();
        idApunte = nuevoApunte->obtenerID();

        assertEqual(idComentario, idApunte);
        assertEqual(nuevoComentario->obtenerID(), nuevoApunte->obtenerComentarios().back()->obtenerID());
    } 

    {

        std::cout << "Testing Buscar tema devuelve Lista de Apuntes" << " \n";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Materia Buscar tema devuelve Lista de Clases" << " \n";
       
        std::vector<Clase *> resultado =  nuevaMateria->buscarTemaEnClases("principal");

        assertEqual(false,resultado.empty());
        assertEqual(resultado.at(0)->obtenerID(), nuevaMateria->obtenerClases().at(0)->obtenerID());
        
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
        std::cout << "Testing Modificar Apunte";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Eliminar Apunte"<< " \n";
       
       // assert_equal(actual, esperado);
    }

    {
        std::cout << "Testing Crear Raiz con Usuario del Arbol Padre"<< " \n";
       
        BaseMecha* controlUsuario = nuevoUsuario;
        rootTreeFather = new NodoPadre(controlUsuario, "/");

        //std::cout << "Valor (root): " << rootTreeFather->obtenerValor()->toString() << " Camino (path): " << rootTreeFather->obtenerCamino()  << " \n";

        assertEqual(std::string("/"), rootTreeFather->obtenerCamino());
        assertEqual(rootTreeFather->obtenerValor()->toString(), nuevoUsuario->toString() );
    }

    {
        std::cout << "Testing Agregar nodos al Arbol Padre"<< " \n";

        BaseMecha* controlComentario = nuevoComentario;
        BaseMecha* controlApunte = nuevoApunte;
        BaseMecha* controlClase = nuevaClase;
        BaseMecha* controlMateria = nuevaMateria;
        BaseMecha* controlPeriodo = nuevoPeriodo;
        BaseMecha* controlUsuario = nuevoUsuario;

        apunteTreeFather = new NodoPadre(controlApunte, nuevoApunte->obtenerID());
        comentarioTreeFather = new NodoPadre(controlComentario, nuevoComentario->obtenerID());
        periodoTreeFather = new NodoPadre(controlPeriodo, nuevoPeriodo->obtenerID());
        materiaTreeFather = new NodoPadre(controlMateria, nuevaMateria->obtenerID());
        claseTreeFather =  new NodoPadre(controlClase, nuevaClase->obtenerID());

        periodoTreeFather->asignarPadre(rootTreeFather);

        materiaTreeFather->asignarPadre(periodoTreeFather);

        claseTreeFather->asignarPadre(materiaTreeFather);

        apunteTreeFather->asignarPadre(claseTreeFather);

        comentarioTreeFather->asignarPadre(apunteTreeFather);
    /*
        std::cout << "Valor (Usuario root): " << rootTreeFather->obtenerValor()->toString() << " Camino (path): " << rootTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Periodo): " << periodoTreeFather->obtenerValor()->toString() << " Camino (path): " << periodoTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Materia): " << materiaTreeFather->obtenerValor()->toString() << " Camino (path): " << materiaTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Clase): " << claseTreeFather->obtenerValor()->toString() << " Camino (path): " << claseTreeFather->obtenerCamino()  << " \n\n";
        
        std::cout << "Valor (Apunte): " << apunteTreeFather->obtenerValor()->toString() << " Camino (path): " << apunteTreeFather->obtenerCamino()  << " \n\n";

        std::cout << "Valor (Comentario): " << comentarioTreeFather->obtenerValor()->toString() << " Camino (path): " << comentarioTreeFather->obtenerCamino()  << " \n\n";
    */
        assertEqual(rootTreeFather->obtenerValor()->toString(), nuevoUsuario->toString());
        assertEqual(periodoTreeFather->obtenerValor()->toString(), nuevoPeriodo->toString());
        assertEqual(materiaTreeFather->obtenerValor()->toString(), nuevaMateria->toString());
        assertEqual(claseTreeFather->obtenerValor()->toString(), nuevaClase->toString());
        assertEqual(apunteTreeFather->obtenerValor()->toString(), nuevoApunte->toString());
        assertEqual(comentarioTreeFather->obtenerValor()->toString(), nuevoComentario->toString());

        // Testing de path 
        assertEqual(rootTreeFather->obtenerCamino(),       std::string("/"));
        assertEqual(periodoTreeFather->obtenerCamino(),    std::string("/")+nuevoPeriodo->obtenerID()+std::string("/"));
        assertEqual(materiaTreeFather->obtenerCamino(),    std::string("/")+nuevoPeriodo->obtenerID()+std::string("/")+nuevaMateria->obtenerID()+std::string("/"));
        assertEqual(claseTreeFather->obtenerCamino(),      std::string("/")+nuevoPeriodo->obtenerID()+std::string("/")+nuevaMateria->obtenerID()+std::string("/")+nuevaClase->obtenerID()+std::string("/"));
        assertEqual(apunteTreeFather->obtenerCamino(),     std::string("/")+nuevoPeriodo->obtenerID()+std::string("/")+nuevaMateria->obtenerID()+std::string("/")+nuevaClase->obtenerID()+std::string("/")+nuevoApunte->obtenerID()+std::string("/"));
        assertEqual(comentarioTreeFather->obtenerCamino(), std::string("/")+nuevoPeriodo->obtenerID()+std::string("/")+nuevaMateria->obtenerID()+std::string("/")+nuevaClase->obtenerID()+std::string("/")+nuevoApunte->obtenerID()+std::string("/")+nuevoComentario->obtenerID()+std::string("/"));

    }


    {
        std::cout << "Testing Tabla Hash Apuntes Clase"<< " \n";
        std::vector<BaseMecha *> apuntesClase;
        for( Apunte * apunte : nuevaClase->obtenerApuntes()){
            apuntesClase.push_back(apunte);
        }

        NodoFuego apuntes = NodoFuego();
        apuntes.asignarValor(apuntesClase);
        hijosArbol.insert(claseTreeFather->obtenerCamino(),apuntes);
        ElementoHash * nodo = hijosArbol.buscar(claseTreeFather->obtenerCamino());


        std::cout << "Encontrado  "<< nodo->valor.obtenerValor().at(0)->toString()<< " \n";
    }

    {
        std::cout << "Testing Tabla Hash Clase Materia"<< " \n";
        std::vector<BaseMecha *> clasesMateria;
        for( Clase * clase : nuevaMateria->obtenerClases()){
            clasesMateria.push_back(clase);
        }

        NodoFuego clases = NodoFuego();
        clases.asignarValor(clasesMateria);
        hijosArbol.insert(materiaTreeFather->obtenerCamino(),clases);
        ElementoHash * nodo = hijosArbol.buscar(materiaTreeFather->obtenerCamino());


        std::cout << "Encontrado  "<< nodo->valor.obtenerValor().at(0)->toString()<< " \n";
    }

    {
        std::cout << "Testing Tabla Hash Materia Periodo"<< " \n";
        std::vector<BaseMecha *> materiasPeriodo;
        for( Materia * materias : nuevoPeriodo->obtenerMaterias()){
            materiasPeriodo.push_back(materias);
        }

        NodoFuego materias = NodoFuego();
        materias.asignarValor(materiasPeriodo);
        hijosArbol.insert(periodoTreeFather->obtenerCamino(),materias);
        ElementoHash * nodo = hijosArbol.buscar(periodoTreeFather->obtenerCamino());


        std::cout << "Encontrado  "<< nodo->valor.obtenerValor().at(0)->toString()<< " \n";
    }

    {
        std::cout << "Testing Tabla Hash Periodo Usuario"<< " \n";
        std::vector<BaseMecha *> periodosUsuario;
        for( Periodo * periodos : nuevoUsuario->obtenerPeriodos()){
            periodosUsuario.push_back(periodos);
        }
        NodoFuego periodos = NodoFuego();
        periodos.asignarValor(periodosUsuario);
        hijosArbol.insert(rootTreeFather->obtenerCamino(),periodos);
        ElementoHash * nodo = hijosArbol.buscar(rootTreeFather->obtenerCamino());


        std::cout << "Encontrado  "<< nodo->valor.obtenerValor().at(0)->toString()<< " \n";
    }

    
    
    {
        std::cout << "Testing Creando o Abriendo Base de Datos"<< " \n";

        bool crearBaseDeDatos = Utilidades::instanciarBaseDeDatos();
        assertEqual(crearBaseDeDatos,true);
    }

    {
        std::cout << "Testing Insertar Usuario en la Base de Datos"<< " \n";


        nuevoUsuario->asignarCorreo(std::string(nuevoUsuario->obtenerID()));
        nuevoUsuario->asignarNombre(std::string("Nombre"));
        nuevoUsuario->asignarDescripcion(std::string("Descripcion Apuntes Seguidos"));
        nuevoUsuario->asignarRoles({Rol::ESTUDIANTE});
        nuevoUsuario->asignarPopularidad(1);

        int resultado = baseDatos.insertarUsuario(*nuevoUsuario);
        assertEqual(resultado != -1, true);
    }

    {
        std::cout << "Testing Insertar Usuario Crendenciales en la Base de Datos"<< " \n";

        baseDatos.insertarCredencialUsuario(*nuevoUsuario);
    }

    {
        std::cout << "Testing Obtener todo los Usuario de la Base de Datos"<< " \n";

        std::vector<Usuario> todoLosUsuarios=  baseDatos.obtenerTodoLosUsuarios();

         for (const Usuario& usuario : todoLosUsuarios) {
            std::cout << "Usuario: " << usuario.toString() << "\n";
        }

    }
    {
        std::cout << "Testing Insertar Periodo en la Base de Datos"<< " \n";

        baseDatos.insertarPeriodo(*nuevoPeriodo);
    }

        {
        std::cout << "Testing Obtener todo los Periodo de la Base de Datos"<< " \n";

        std::vector<Periodo> todoLosPeriodos =  baseDatos.obtenerTodoLosPeriodos();

         for (const Periodo& periodo : todoLosPeriodos) {
            std::cout << "Periodo: " << periodo.toString() << "\n";
        }

    }
    {
        std::cout << "Testing Insertar Materia en la Base de Datos"<< " \n";

        nuevaMateria->asignarPeriodoActivo(true);

        baseDatos.insertarMateria(*nuevaMateria);
    }

        {
        std::cout << "Testing Obtener todo las Materia de la Base de Datos"<< " \n";

        std::vector<Materia> todaLasMaterioas=  baseDatos.obtenerTodasLasMaterias();

         for (const Materia& materia : todaLasMaterioas) {
            std::cout << "Materia: " << materia.toString() << "\n";
        }

    }
    {
        std::cout << "Testing Insertar Clase en la Base de Datos"<< " \n";

        baseDatos.insertarClase(*nuevaClase);
    }

        {
        std::cout << "Testing Obtener todas las Clase de la Base de Datos"<< " \n";

        std::vector<Clase> todaLasClases=  baseDatos.obtenerTodoLosClases();

         for (const Clase& clase : todaLasClases) {
            std::cout << "Clases: " << clase.toString() << "\n";
        }

    }
    {
        std::cout << "Testing Insertar Apunte en la Base de Datos"<< " \n";

        baseDatos.insertarApunte(*nuevoApunte);
    }

    {
        std::cout << "Testing Obtener todo los Apunte de la Base de Datos"<< " \n";

        std::vector<Apunte> todoLosApuntes=  baseDatos.obtenerTodoLosApuntes();

         for (const Apunte& apunte : todoLosApuntes) {
            std::cout << "Apunte: " << apunte.toString() << "\n";
        }

    }
    {
        std::cout << "Testing Insertar Comentario en la Base de Datos"<< " \n";

        baseDatos.insertarComentario(*nuevoComentario);
    }

        {
        std::cout << "Testing Obtener todo los Comentario de la Base de Datos"<< " \n";

        std::vector<Comentario> todoLosComentarios=  baseDatos.obtenerTodoLosComentarios();

         for (const Comentario& comentario : todoLosComentarios) {
            std::cout << "Comentario: " << comentario.toString() << "\n";
        }

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