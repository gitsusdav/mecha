#include <string>
#include <cstring>
#include "Usuario.hpp"
#include "Periodo.hpp"
#include "Materia.hpp"
#include "Clase.hpp"
#include "Apunte.hpp"
#include "Comentario.hpp"
#include "NodoPadre.hpp"

// Declaración de variables globales
Usuario* usuarioG = nullptr;
Periodo* periodoG = nullptr;
Materia* materiaG = nullptr;
Clase* claseG = nullptr;
Apunte* apunteG = nullptr;
Comentario* comentarioG = nullptr;

NodoPadre* nodoPadreGlobal = nullptr;

std::string funcina(std::string entrada ){
    return std::string("si ")+entrada;
}

extern "C" const char* funciona(const char* entrada) {
    std::string entrada_str(entrada);
    std::string resultado = "si " + entrada_str;
    char* resultado_cstr = new char[resultado.length() + 1];
    strcpy(resultado_cstr, resultado.c_str());
    return resultado_cstr;
}

extern "C" void crearUsuario(const char* nombre, const char* id) {
    std::vector<Rol> roles;
    usuarioG = new Usuario(nombre, "", roles, "", "");
    usuarioG->asignarID(id);
    nodoPadreGlobal = new NodoPadre(usuarioG, "/usuario/" + usuarioG->obtenerID());
}

extern "C" void crearPeriodo(const char* nombre, const char* id) {
    periodoG = new Periodo(nombre, "");
    periodoG->asignarID(id);
    nodoPadreGlobal = new NodoPadre(periodoG, "/periodo/" + periodoG->obtenerID());
}

extern "C" void crearMateria(const char* nombre, const char* id) {
    materiaG = new Materia(nullptr, "", std::vector<std::string>(), nombre, std::vector<Clase*>(), false);
    materiaG->asignarID(id);
    nodoPadreGlobal = new NodoPadre(materiaG, "/materia/" + materiaG->obtenerID());
}

extern "C" void crearClase(const char* nombre, const char* id) {
    claseG = new Clase("", nombre, std::tm(), "");
    claseG->asignarID(id);
    nodoPadreGlobal = new NodoPadre(claseG, "/clase/" + claseG->obtenerID());
}

extern "C" void crearApunte(const char* nombre, const char* id) {
    apunteG = new Apunte(nullptr, nombre, std::tm(), 0);
    apunteG->asignarID(id);
    nodoPadreGlobal = new NodoPadre(apunteG, "/apunte/" + apunteG->obtenerID());
}

extern "C" void crearComentario(const char* nombre, const char* id) {
    comentarioG = new Comentario(nullptr, nombre, std::tm());
    comentarioG->asignarID(id);
    nodoPadreGlobal = new NodoPadre(comentarioG, "/comentario/" + comentarioG->obtenerID());
}


// variable usuario Global
//Funcion que se le pase por parametro un nombre de un usuario
// void (String usuario)
//con el nombre construye el usuario

// funcion que se le pase el nombre de un peridodo 
// con el NodoPadre le asigna global le asigne el uisuario como padre

// Materia con las Clases con los APuntes y los Comentarios 
// agreagar materia (String materia)
// se le asgina un NodoPadre Gloval y se le pone como padre el NodaPadre de periodo
//---- obtener 
