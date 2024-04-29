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
    int insertarUsuario(const Usuario& usuario);
    std::vector<Usuario> obtenerTodoLosUsuarios();
    std::vector<Periodo> obtenerTodoLosPeriodos(); 
    std::vector<Materia> obtenerTodasLasMaterias(); 
    std::vector<Clase> obtenerTodoLosClases(); 
    std::vector<Apunte> obtenerTodoLosApuntes(); 
    std::vector<Comentario> obtenerTodoLosComentarios();  
    int insertarPeriodo(const Periodo& periodo);
    int insertarMateria(const Materia& materia);
    int insertarClase(const Clase& clase);
    int insertarApunte(const Apunte& apunte);
    int insertarComentario(const Comentario& comentario);
    int insertarCredencialUsuario(const Usuario& credencial);
    int insertarUsuarioPeriodo(int usuarioID, int periodoID);
    int insertarUsuarioRol(int usuarioID, const std::string& rol); 
    int insertarUsuarioApunte(int usuarioID, int apunteID, bool seguido); 
    int insertarConexionUsuario(int usuarioID, std::string usuarioConectadoID);
    int insertarPeriodoMateria(int periodoID, int materiaID); 
    int insertarMateriaClase(int materiaID, int claseID);
    int insertarMateriaProfesor(int materiaID, const std::string& profesor);
    int insertarClaseApunte(int claseID, int apunteID); 
    int insertarRecursoClase(int claseID, const std::string& recurso);
    int insertarApunteComentario(int apunteID, int comentarioID);

};