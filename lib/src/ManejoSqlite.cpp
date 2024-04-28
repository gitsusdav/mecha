#include "ManejoSqlite.hpp"
#include "Utilidades.hpp"

ManejoSqlite::ManejoSqlite(const std::string& caminoBaseDeDatos) {
    sqlite3_open(caminoBaseDeDatos.c_str(), &baseDeDatos);
}

ManejoSqlite::~ManejoSqlite() {
    sqlite3_close(baseDeDatos);
}

void ManejoSqlite::executeQuery(const std::string& query) {
    char* errMsg = nullptr;
    int resultado = sqlite3_exec(baseDeDatos, query.c_str(), nullptr, nullptr, &errMsg);
    if (resultado != SQLITE_OK) {
        std::cerr << "Error al ejecutar la consulta: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool ManejoSqlite::insertarUsuario(const Usuario& usuario) {
    std::string query = "INSERT INTO Usuario (id_Usuario, Nombre, Descripcion, Popularidad, Correo) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, usuario.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, usuario.obtenerNombre().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, usuario.obtenerDescripcion().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_int(stmt, 4, usuario.obtenerPopularidad());
    sqlite3_bind_text(stmt, 5, usuario.obtenerCorreo().c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    } 

    if (resultado != SQLITE_DONE) {
        return false;
    }
    sqlite3_int64 idUsuarioInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idUsuario = static_cast<int>(idUsuarioInsertado);

    std::cout <<" ID USUARIO  insertado" << idUsuario << "\n";

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Usuario> ManejoSqlite::obtenerTodoLosUsuarios() {
    std::vector<Usuario> usuarios;
        std::cout <<" START Todo los usuarios " << "\n";
        std::string query = "SELECT * FROM Usuario";
    // std::string query = R"(
    //     SELECT
    //         Usuario.ID,
    //         Usuario.id_Usuario,
    //         Usuario.Nombre,
    //         Usuario.Descripcion,
    //         Usuario.Popularidad,
    //         Usuario.Correo,
    //         Usuario_Periodos.PeriodoID,
    //         Usuario_Roles.Rol,
    //         Usuario_Apuntes.ApunteID,
    //         Usuario_Conexiones.UsuarioID
    //     FROM
    //         Usuario
    //     INNER JOIN
    //         Usuario_Periodos ON Usuario.ID = Usuario_Periodos.UsuarioID
    //     INNER JOIN
    //         Usuario_Apuntes ON Usuario.ID = Usuario_Apuntes.UsuarioID
    //     INNER JOIN
    //         Usuario_Conexiones ON Usuario.ID = Usuario_Conexiones.UsuarioID
    //     INNER JOIN
    //         Usuario_Roles ON Usuario.ID = Usuario_Roles.UsuarioID
    // )";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    std::cout <<" SREsultado " << resultado  <<"\n";
    if (resultado != SQLITE_OK) {
        return usuarios;
    }
    std::cout <<" OK " << resultado  <<"\n";
    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
            std::cout <<" ROW "  << sqlite3_column_text(stmt, 1) << "\n"<< sqlite3_column_text(stmt, 2) << "\n" << sqlite3_column_text(stmt, 3) << "\n"<< sqlite3_column_text(stmt, 4) << "\n"<< sqlite3_column_text(stmt, 5) << "\n";
        Usuario usuario;
         const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
          const char* nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
           const char* descripcion = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            const int popularidad = sqlite3_column_int(stmt, 4);
             const char* correo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
             if (id) {
            usuario.asignarID(id);
        } 
             if (nombre) {
            usuario.asignarNombre(nombre);
        } 
        if (descripcion) {
            usuario.asignarDescripcion(descripcion);
        }
                  if (popularidad) {
            usuario.asignarPopularidad(popularidad);
        } 
             if (correo) {
            usuario.asignarCorreo(correo);
        } 
   
    
        usuarios.push_back(usuario);
    }

    sqlite3_finalize(stmt);

    return usuarios;
}

bool ManejoSqlite::insertarPeriodo(const Periodo& periodo) {
    std::string query = "INSERT INTO Periodo (id_Periodo, Nombre, Descripcion, FechaInicio, FechaFin) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, periodo.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, periodo.obtenerNombre().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, periodo.obtenerDescripcion().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 4, Utilidades::crearFecha(periodo.obtenerFechaInicio()).c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha(periodo.obtenerFechaFin()).c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    } 

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Periodo> ManejoSqlite::obtenerTodoLosPeriodos(){
    std::vector<Periodo> periodos;
    return periodos;
} 
  
bool ManejoSqlite::insertarMateria(const Materia& materia) {
    std::string query = "INSERT INTO Materia (id_Materia, id_Periodo, Descripcion, Nombre, PeriodoActivo) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, materia.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, materia.obtenerPeriodo()->obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, materia.obtenerDescripcion().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 4, materia.obtenerNombre().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_int(stmt, 5, materia.obtenerPeriodoActivo() ? 1 : 0);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Materia> ManejoSqlite::obtenerTodasLasMaterias(){
    std::vector<Materia> materias;
    return materias;
}  
 

bool ManejoSqlite::insertarClase(const Clase& clase) {
    std::string query = "INSERT INTO Clase (id_Clase, id_Materia, Descripcion, Fecha, Tema) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, clase.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, clase.obtenerIDMateria().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, clase.obtenerDescripcion().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 4, Utilidades::crearFecha(clase.obtenerFecha()).c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 6, clase.obtenerTema().c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Clase> ManejoSqlite::obtenerTodoLosClases(){
    std::vector<Clase> clases;
    return clases;
}  
 
bool ManejoSqlite::insertarApunte(const Apunte& apunte ) {
    std::string query = "INSERT INTO Apunte (id_Apunte, id_Clase, id_Usuario, Contenido, Fecha, Like, Dislike, Popularidad) "
                        "VALUES (?, ?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, apunte.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, apunte.obtenerClase()->obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, apunte.obtenerUsuario()->obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 4, apunte.obtenerContenido().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha(apunte.obtenerFecha()).c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_int(stmt, 6, apunte.obtenerLike());
    sqlite3_bind_int(stmt, 7, apunte.obtenerDislike());
    sqlite3_bind_int(stmt, 8, apunte.obtenerPopularidad());

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Apunte> ManejoSqlite::obtenerTodoLosApuntes(){
    std::vector<Apunte> apuntes;
    return apuntes;
}  
    

bool ManejoSqlite::insertarComentario(const Comentario& comentario) {
    std::string query = "INSERT INTO Comentario (id_Comentario, id_Apunte, id_Usuario, Contenido, Fecha, Like, Dislikes) "
                        "VALUES (?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, comentario.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, comentario.obtenerApunte()->obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, comentario.obtenerUsuario()->obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 4, comentario.obtenerContenido().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha( comentario.obtenerFecha()).c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_int(stmt, 6, comentario.obtenerLikes());
    sqlite3_bind_int(stmt, 7, comentario.obtenerDislikes());

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Comentario> ManejoSqlite::obtenerTodoLosComentarios(){
    std::vector<Comentario> comentarios;

    return comentarios;
}  

bool ManejoSqlite::insertarCredencialUsuario(const Usuario& credencial) {
    std::string query = "INSERT INTO Usuario_Credenciales (id_Usuario, Correo, Clave) "
                        "VALUES (?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, credencial.obtenerID().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 2, credencial.obtenerCorreo().c_str(), -1, SQL_TRANSIENT);
    sqlite3_bind_text(stmt, 3, credencial.obtenerClave().c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarUsuarioPeriodo(int usuarioID, int periodoID) {
    std::string query = "INSERT INTO Usuario_Periodos (UsuarioID, PeriodoID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_int(stmt, 2, periodoID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarUsuarioRol(int usuarioID, const std::string& rol) {
    std::string query = "INSERT INTO Usuario_Roles (UsuarioID, Rol) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_text(stmt, 2, rol.c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarUsuarioApunte(int usuarioID, int apunteID, bool seguido) {
    std::string query = "INSERT INTO Usuario_Apuntes (UsuarioID, ApunteID, Seguido) "
                        "VALUES (?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_int(stmt, 2, apunteID);
    sqlite3_bind_int(stmt, 3, seguido ? 1 : 0);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarConexionUsuario(int usuarioID, int usuarioConectadoID) {
    std::string query = "INSERT INTO Usuario_Conexiones (UsuarioID, UsuarioConectadoID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_int(stmt, 2, usuarioConectadoID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarPeriodoMateria(int periodoID, int materiaID) {
    std::string query = "INSERT INTO Periodo_Materias (PeriodoID, MateriaID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, periodoID);
    sqlite3_bind_int(stmt, 2, materiaID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarMateriaClase(int materiaID, int claseID) {
    std::string query = "INSERT INTO Materia_Clases (MateriaID, ClaseID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, materiaID);
    sqlite3_bind_int(stmt, 2, claseID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarMateriaProfesor(int materiaID, const std::string& profesor) {
    std::string query = "INSERT INTO Materia_Profesores (MateriaID, Profesor) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, materiaID);
    sqlite3_bind_text(stmt, 2, profesor.c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarClaseApunte(int claseID, int apunteID) {
    std::string query = "INSERT INTO Clase_Apuntes (ClaseID, ApunteID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, claseID);
    sqlite3_bind_int(stmt, 2, apunteID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarRecursoClase(int claseID, const std::string& recurso) {
    std::string query = "INSERT INTO Clase_Recursos (ClaseID, Recurso) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, claseID);
    sqlite3_bind_text(stmt, 2, recurso.c_str(), -1, SQL_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool ManejoSqlite::insertarApunteComentario(int apunteID, int comentarioID) {
    std::string query = "INSERT INTO Apunte_Comentarios (ApunteID, ComentarioID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_int(stmt, 1, apunteID);
    sqlite3_bind_int(stmt, 2, comentarioID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}