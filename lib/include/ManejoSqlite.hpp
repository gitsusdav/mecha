#pragma once

#include <iostream>
#include <string>
#include <sqlite3.h>
#include "Usuario.hpp"
#include "Periodo.hpp"
#include "Materia.hpp"
#include "Clase.hpp"
#include "Apunte.hpp"
#include "Comentario.hpp"

class ManejoSqlite {
private:
    sqlite3* baseDeDatos;

public:
    ManejoSqlite(const std::string& caminoBaseDeDatos);
    ~ManejoSqlite();

    void executeQuery(const std::string& query);
    bool insertarUsuario(const Usuario& usuario);
    std::vector<Usuario> obtenerTodoLosUsuarios();
    std::vector<Periodo> obtenerTodoLosPeriodos(); 
    std::vector<Materia> obtenerTodasLasMaterias(); 
    std::vector<Clase> obtenerTodoLosClases(); 
    std::vector<Apunte> obtenerTodoLosApuntes(); 
    std::vector<Comentario> obtenerTodoLosComentarios();  
    bool insertarPeriodo(const Periodo& periodo);
    bool insertarMateria(const Materia& materia);
    bool insertarClase(const Clase& clase);
    bool insertarApunte(const Apunte& apunte);
    bool insertarComentario(const Comentario& comentario);
    bool insertarCredencialUsuario(const Usuario& credencial);
    bool insertarUsuarioPeriodo(int usuarioID, int periodoID);
    bool insertarUsuarioRol(int usuarioID, const std::string& rol); 
    bool insertarUsuarioApunte(int usuarioID, int apunteID, bool seguido); 
    bool insertarConexionUsuario(int usuarioID, int usuarioConectadoID);
    bool insertarPeriodoMateria(int periodoID, int materiaID); 
    bool insertarMateriaClase(int materiaID, int claseID);
    bool insertarMateriaProfesor(int materiaID, const std::string& profesor);
    bool insertarClaseApunte(int claseID, int apunteID); 
    bool insertarRecursoClase(int claseID, const std::string& recurso);
    bool insertarApunteComentario(int apunteID, int comentarioID);

};