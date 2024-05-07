#include <iostream>
#include <vector>
#include "Utilidades.hpp"
#include "Usuario.hpp"
#include "Periodo.hpp"
#include "Materia.hpp"
#include "Clase.hpp"
#include "Apunte.hpp"
#include "Comentario.hpp"
#include "NodoPadre.hpp"
#include "NodoFuego.hpp"
#include "TablaHash.hpp"
#include "BaseMecha.hpp"
#include "ManejoSqlite.hpp"


/*
    La aplicación Mecha utiliza para la estructura de datos un Árbol
    el cual se llamó Árbol Padre se utiliza con el NodoPadre
    los cuales tienen un apuntador a su padre.

    Para obtener la lista de nodos de los hijos se está empleando 
    una tabla hash que guarda la lista con la llave del camino
    donde esta cada nodo en el árbol, si hay colisión en la 
    tabla hash se guarda la lista en nodos de un árbol binario
    que es el NodoFuego.

    Los datos persisten gracias a que se está utilizando una
    base de datos Sqlite en el archivo "DatosCalientesMecha.db".

    Los test están listos, vamos a conectar el árbol y la tabla hash
    con el menú de este archivo. 

*/


void guardarUsuarioEnLaBaseDeDatos(const Usuario& usuario,  ManejoSqlite baseDatos ) {



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
    ManejoSqlite baseDatos("DatosCalientesMecha.db");
    bool crearBaseDeDatos = Utilidades::instanciarBaseDeDatos();
    TablaHash hijosArbol = TablaHash();

    NodoPadre* rootTreeFather;

    Usuario* actualUsuario;

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
        actualUsuario = &usuario;

        BaseMecha* controlUsuario = actualUsuario; // a periodo a materia a clases a apunte a comentario 

        rootTreeFather = new NodoPadre(controlUsuario, "/");
        // hijos de usuario que son la lista de peridodo se agrega a la tabla hash donde la lleve es el path y el valor la lista de hijos
        // asigna el perdio , apunte
        // usuario.asignarPeriodos(std::vector<Periodo *>);
        baseDatos.insertarUsuario(usuario);
        baseDatos.insertarCredencialUsuario(usuario);
       // guardarUsuarioEnLaBaseDeDatos(usuario, baseDatos);  

    } else if (opcion == 2) {
        //codigo de inicio de sesion
        std::cout << "Ingrese su correo: ";
        std::getline(std::cin, correo);
        std::cout << "Ingrese su clave: ";
        std::getline(std::cin, clave);
        
        std::string idUsuario = baseDatos.obtenerIngresoUsuario( correo, clave);
        if(idUsuario != std::string("0")){
            Usuario usuarioRegistrado = baseDatos.obtenerUsuario(idUsuario);
            // cargar todo los datos del usuario construir el arbol y la tabla hash
            std::cout << "Binvenido de nuevo a Mecha " << usuarioRegistrado.obtenerNombre() <<  "\n";
        }else{
           std::cout << "Credenciales Incorrectas, vuelve a ejecutar la aplicación\n"; 
            return 0;
        }


    } else {
        std::cout << "Opción inválida\n";
        return 0;
    }

    Usuario usuario(nombre, descripcion, {static_cast<Rol>(rol)}, correo, clave);
    actualUsuario = &usuario;

    int accion;
    do {
        std::cout << "\n\n********** Opciones **********\n \n";
        // consultar perido devuelve la lista de los peridos guardados que tiene el usuario 
        std::cout << "1. Añadir periodo\n"; // crear periodo, se seleciona un periodo 
        // arbol 
        std::cout << "2. Añadir materia\n"; // peridodo selecionado ver materias agregar materia 
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
                //guardarPeriodoEnLaBaseDeDatos(periodo); // baseDatos 
                baseDatos.insertarPeriodo(periodo);
                Periodo * arbolPeriodo = &periodo;
                BaseMecha * controlPeriodo = arbolPeriodo;
                NodoPadre * nodoPeriodo = new NodoPadre(controlPeriodo,controlPeriodo->obtenerID());
                nodoPeriodo->asignarPadre(rootTreeFather);
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
                /*baseDatos.insertarMateria(materia);
                Materia * arbolMateria = &materia;
                BaseMecha * controlMateria = arbolMateria;
                NodoPadre * nodoMateria = new NodoPadre(controlMateria,controlMateria->obtenerID());
                nodoMateria->asignarPadre(rootTreeFather);*/
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
                    switch (usuario.obtenerRoles()[0]) {  
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
                //std::vector<Periodo> periodos = obtenerPeriodosDeLaBaseDeDatos();
                std::vector<Periodo> periodos = baseDatos.obtenerTodoLosPeriodos(); 
                for (const Periodo& periodo : periodos) {
                    std::cout << periodo.obtenerNombre() << "\n";
                }

                std::cout << "\n\n********** Materias **********\n \n";
                std::vector<Materia> materias = baseDatos.obtenerTodasLasMaterias();
                for (const Materia& materia : materias) {
                    std::cout << materia.obtenerNombre() << "\n";
                }

                std::cout << "\n\n********** Clases **********\n \n";
                std::vector<Clase> clases = baseDatos.obtenerTodoLosClases();
                for (const Clase& clase : clases) {
                    std::cout << clase.obtenerTema() << "\n";
                }

                std::cout << "\n\n********** Apuntes **********\n \n";
                std::vector<Apunte> apuntes = baseDatos.obtenerTodoLosApuntes();
                for (const Apunte& apunte : apuntes) {
                    std::cout << apunte.obtenerContenido() << "\n";
                }

                std::cout << "\n\n********** Comentarios **********\n \n";
                std::vector<Comentario> comentarios = baseDatos.obtenerTodoLosComentarios();
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

