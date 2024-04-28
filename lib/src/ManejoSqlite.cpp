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

    sqlite3_bind_text(stmt, 1, std::string("03c6c5b585aecfd5090268358b07077dec6422b9a1cb1f2f2a4c8bd200dfcbe3").c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, usuario.getNombre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, usuario.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, usuario.getPopularidad());
    sqlite3_bind_text(stmt, 5, usuario.getCorreo().c_str(), -1, SQLITE_STATIC);

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
            usuario.setID(id);
        } 
             if (nombre) {
            usuario.setNombre(nombre);
        } 
        if (descripcion) {
            usuario.setDescripcion(descripcion);
        }
                  if (popularidad) {
            usuario.setPopularidad(popularidad);
        } 
             if (correo) {
            usuario.setCorreo(correo);
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

    sqlite3_bind_text(stmt, 1, periodo.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, periodo.getNombre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, periodo.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, Utilidades::crearFecha(periodo.getFechaInicio()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha(periodo.getFechaFin()).c_str(), -1, SQLITE_STATIC);

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

    sqlite3_bind_text(stmt, 1, materia.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, materia.getPeriodo()->getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, materia.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, materia.getNombre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 5, materia.getPeriodoActivo() ? 1 : 0);

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

    sqlite3_bind_text(stmt, 1, clase.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, clase.getIDMateria().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, clase.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, Utilidades::crearFecha(clase.getFecha()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, clase.getTema().c_str(), -1, SQLITE_STATIC);

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

    sqlite3_bind_text(stmt, 1, apunte.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, apunte.getClase()->getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, apunte.getUsuario()->getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, apunte.getContenido().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha(apunte.getFecha()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, apunte.getLike());
    sqlite3_bind_int(stmt, 7, apunte.getDislike());
    sqlite3_bind_int(stmt, 8, apunte.getPopularidad());

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

    sqlite3_bind_text(stmt, 1, comentario.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, comentario.getApunte()->getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, comentario.getUsuario()->getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, comentario.getContenido().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha( comentario.getFecha()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 6, comentario.getLikes());
    sqlite3_bind_int(stmt, 7, comentario.getDislikes());

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
    std::string query = "INSERT INTO Usuario_Crendeciales (id_Usuario, Correo, Clave) "
                        "VALUES (?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, credencial.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, credencial.getCorreo().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, credencial.getClave().c_str(), -1, SQLITE_STATIC);

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
    sqlite3_bind_text(stmt, 2, rol.c_str(), -1, SQLITE_STATIC);

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
    sqlite3_bind_text(stmt, 2, profesor.c_str(), -1, SQLITE_STATIC);

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
    sqlite3_bind_text(stmt, 2, recurso.c_str(), -1, SQLITE_STATIC);

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