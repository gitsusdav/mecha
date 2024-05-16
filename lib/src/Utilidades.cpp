#include <sstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <chrono>
#include <ctime>
#include <openssl/evp.h> //funcion a quitar
#include <vector>
#include <iostream>
#include <sqlite3.h>
#include <functional>

#include "Utilidades.hpp"


std::string Utilidades::generarId(const std::string& claseToString)
{
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto value = now_ms.time_since_epoch().count();
    
    std::stringstream ss;
    ss << claseToString << value;

    std::hash<std::string> str_hash;
    auto hashed_value = str_hash(ss.str());

    std::stringstream hashStream;
    hashStream << std::hex << std::setw(16) << std::setfill('0') << hashed_value;

    return hashStream.str();
}


std::string Utilidades::crearFecha(int year, int month, int day) {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year << '-'
        << std::setw(2) << std::setfill('0') << month << '-'
        << std::setw(2) << std::setfill('0') << day;
    return oss.str();
}

std::string Utilidades::crearFecha(const std::tm& fecha) {
    std::ostringstream oss;
    oss << std::put_time(&fecha, "%Y-%m-%d");
    return oss.str();
}
std::tm Utilidades::crearTmDesdeString(const std::string& fechaStr) {
    std::tm fecha = {}; 
    std::istringstream iss(fechaStr);
    iss >> std::get_time(&fecha, "%Y-%m-%d");

    return fecha;
}
std::tm Utilidades::obtenerFecha(int year, int month, int day) {
    std::tm fecha = {0, 0, 0, day, month - 1, year - 1900}; 
    return fecha;
}

bool Utilidades::instanciarBaseDeDatos() {

    sqlite3* baseDeDatos;
    int resultado = sqlite3_open_v2("DatosCalientesMecha.db", &baseDeDatos, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);

    if (resultado) {
        return false;
    }

    const char* crearTablaUsuario = R"(
        CREATE TABLE Usuario (
            ID INTEGER PRIMARY KEY,
            id_Usuario TEXT NOT NULL,
            Nombre TEXT NOT NULL,
            Descripcion TEXT,
            Popularidad INTEGER,
            Correo TEXT NOT NULL UNIQUE
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaUsuario, nullptr, nullptr, nullptr);

    const char* crearTablaPeriodo = R"(
        CREATE TABLE Periodo (
            ID INTEGER PRIMARY KEY,
            id_Periodo TEXT NOT NULL,
            Nombre TEXT NOT NULL,
            Descripcion TEXT,
            FechaInicio TEXT NOT NULL,
            FechaFin TEXT NOT NULL
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaPeriodo, nullptr, nullptr, nullptr);

    const char* crearTablaMateria = R"(
        CREATE TABLE Materia (
            ID INTEGER PRIMARY KEY,
            id_Materia TEXT NOT NULL,
            id_Periodo INTEGER NOT NULL,
            Descripcion TEXT,
            Nombre TEXT,
            PeriodoActivo INTEGER,
            FOREIGN KEY (id_Periodo) REFERENCES Periodo(ID) 
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaMateria, nullptr, nullptr, nullptr);

    const char* crearTablaClase = R"(
        CREATE TABLE Clase (
            ID INTEGER PRIMARY KEY,
            id_Clase TEXT NOT NULL,
            id_Materia TEXT NOT NULL,
            Descripcion TEXT,
            Fecha TEXT, 
            Tema TEXT,
            FOREIGN KEY (id_Materia) REFERENCES Materia(ID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaClase, nullptr, nullptr, nullptr);
 
    const char* crearTablaApunte = R"(
        CREATE TABLE Apunte (
            ID INTEGER PRIMARY KEY,
            id_Apunte TEXT NOT NULL,
            id_Clase TEXT NOT NULL,
            id_Usuario TEXT NOT NULL,
            Contenido TEXT,
            Fecha TEXT,
            Like INTEGER,
            Dislike INTEGER,
            Popularidad INTEGER,
            FOREIGN KEY (id_Clase) REFERENCES Clase(ID),
            FOREIGN KEY (id_Usuario) REFERENCES Usuario(ID) 
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaApunte, nullptr, nullptr, nullptr);
    
    const char* crearTablaComentario = R"(
        CREATE TABLE Comentario (
            ID INTEGER PRIMARY KEY,
            id_Comentario TEXT NOT NULL,
            id_Apunte TEXT NOT NULL,
            id_Usuario TEXT NOT NULL,
            Contenido TEXT,
            Fecha TEXT, 
            Like INTEGER,
            Dislikes INTEGER,
            FOREIGN KEY (id_Apunte) REFERENCES Apunte(ID), 
            FOREIGN KEY (id_Usuario) REFERENCES Usuario(ID) 
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaComentario, nullptr, nullptr, nullptr);

    const char* crearTablaUsuarioCredenciales = R"(
        CREATE TABLE Usuario_Credenciales (
            ID INTEGER PRIMARY KEY,
            id_Usuario TEXT NOT NULL,
            Correo TEXT NOT NULL UNIQUE,
            Clave TEXT NOT NULL
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaUsuarioCredenciales, nullptr, nullptr, nullptr);

    const char* crearTablaUsuarioPeriodos = R"(
        CREATE TABLE Usuario_Periodos (
            UsuarioID INTEGER,
            PeriodoID INTEGER,
            FOREIGN KEY (UsuarioID) REFERENCES Usuario(ID),
            FOREIGN KEY (PeriodoID) REFERENCES Periodo(ID),
            PRIMARY KEY (UsuarioID, PeriodoID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaUsuarioPeriodos, nullptr, nullptr, nullptr);

    const char* crearTablaUsuarioRoles = R"(
        CREATE TABLE Usuario_Roles (
            UsuarioID INTEGER,
            Rol TEXT,
            FOREIGN KEY (UsuarioID) REFERENCES Usuario(ID),
            PRIMARY KEY (UsuarioID, Rol)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaUsuarioRoles, nullptr, nullptr, nullptr);

    const char* crearTablaUsuarioApuntes = R"(
        CREATE TABLE Usuario_Apuntes (
            UsuarioID INTEGER,
            ApunteID INTEGER,
            Seguido INTEGER,
            FOREIGN KEY (UsuarioID) REFERENCES Usuario(ID),
            FOREIGN KEY (ApunteID) REFERENCES Apunte(ID),
            PRIMARY KEY (UsuarioID, ApunteID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaUsuarioApuntes, nullptr, nullptr, nullptr);

    const char* crearTablaUsuarioConexiones = R"(
        CREATE TABLE Usuario_Conexiones (
            UsuarioID INTEGER,
            UsuarioConectadoID TEXT,
            FOREIGN KEY (UsuarioID) REFERENCES Usuario(ID),
            FOREIGN KEY (UsuarioConectadoID) REFERENCES Usuario(id_Usuario),
            PRIMARY KEY (UsuarioID, UsuarioConectadoID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaUsuarioConexiones, nullptr, nullptr, nullptr);

    const char* crearTablaPeriodoMaterias= R"(
        CREATE TABLE Periodo_Materias (
            PeriodoID INTEGER,
            MateriaID INTEGER,
            FOREIGN KEY (PeriodoID) REFERENCES Periodo(ID),
            FOREIGN KEY (MateriaID) REFERENCES Materia(ID),
            PRIMARY KEY (PeriodoID, MateriaID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaPeriodoMaterias, nullptr, nullptr, nullptr);
    
    const char* crearTablaMateriaClases = R"(
        CREATE TABLE Materia_Clases (
            MateriaID INTEGER,
            ClaseID INTEGER,
            FOREIGN KEY (MateriaID) REFERENCES Materia(ID),
            FOREIGN KEY (ClaseID) REFERENCES Clase(ID),
            PRIMARY KEY (MateriaID, ClaseID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaMateriaClases, nullptr, nullptr, nullptr);
    
    const char* crearTablaMateriaProfesores = R"(
        CREATE TABLE Materia_Profesores (
            MateriaID INTEGER,
            Profesor TEXT,
            FOREIGN KEY (MateriaID) REFERENCES Materia(ID),
            PRIMARY KEY (MateriaID, Profesor)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaMateriaProfesores, nullptr, nullptr, nullptr);

    const char* crearTablaClaseApuntes = R"(
        CREATE TABLE Clase_Apuntes (
            ClaseID INTEGER,
            ApunteID INTEGER,
            FOREIGN KEY (ClaseID) REFERENCES Clase(ID),
            FOREIGN KEY (ApunteID) REFERENCES Apunte(ID),
            PRIMARY KEY (ClaseID, ApunteID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaClaseApuntes, nullptr, nullptr, nullptr);

    const char* crearTablaClaseRecursos = R"(
        CREATE TABLE Clase_Recursos (
            ClaseID INTEGER,
            Recurso TEXT,
            FOREIGN KEY (ClaseID) REFERENCES Clase(ID),
            PRIMARY KEY (ClaseID, Recurso)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaClaseRecursos, nullptr, nullptr, nullptr);

    const char* crearTablaApunteComentarios = R"(
        CREATE TABLE Apunte_Comentarios (
            ApunteID INTEGER,
            ComentarioID INTEGER,
            FOREIGN KEY (ApunteID) REFERENCES Apunte(ID),
            FOREIGN KEY (ComentarioID) REFERENCES Comentario(ID),
            PRIMARY KEY (ApunteID, ComentarioID)
        );
    )";
    resultado = sqlite3_exec(baseDeDatos, crearTablaApunteComentarios, nullptr, nullptr, nullptr);

    sqlite3_close(baseDeDatos);

    return true;

}

bool Utilidades::esDigito(char c) {
    return c >= '0' && c <= '9';
}
bool Utilidades::esLetra(char c) {
    return std::isalpha(c);
}

int Utilidades::sumarNumeros(const std::string& cadena) {
    int sumaTotal = 1;
    int i = 0;

    while (i < cadena.size()) {
        while (i < cadena.size() && cadena[i] != '/') {
            i++;
        }

        if (i + 1 < cadena.size()) {
            int j = i + 1;
            while (j < cadena.size() && cadena[j] != '/') {
                j++;
            }

            int sumaGrupo = 0;
            int multiplicador = 1;

            for (int k = i + 1; k < j; k++) {
                if (esDigito(cadena[k])) {
                    sumaGrupo += (cadena[k] - '0') * multiplicador;
                } else if (esLetra(cadena[k])) {
                    int valorLetra = std::toupper(cadena[k]) - 'A' + 1;
                    sumaGrupo += valorLetra;
                }
            }

            sumaTotal += sumaGrupo;
            i = j; 
        } else {
            break; 
        }
    }

    return sumaTotal;
}