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

int ManejoSqlite::insertarUsuario(const Usuario& usuario) {
    std::string query = "INSERT INTO Usuario (id_Usuario, Nombre, Descripcion, Popularidad, Correo) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, usuario.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, usuario.obtenerNombre().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, usuario.obtenerDescripcion().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, usuario.obtenerPopularidad());
    sqlite3_bind_text(stmt, 5, usuario.obtenerCorreo().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    } 

    if (resultado != SQLITE_DONE) {
        return -1;
    }
    sqlite3_int64 idUsuarioInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idUsuario = static_cast<int>(idUsuarioInsertado);

    for (Periodo *periodo : usuario.obtenerPeriodos()) {
        int idPeriodo = insertarPeriodo(*periodo);
        insertarUsuarioPeriodo(idUsuario,idPeriodo);
    }
    
    for (Apunte *apunte : usuario.obtenerApuntesPropios()) {
        int idApunte = insertarApunte(*apunte);
        insertarUsuarioApunte(idUsuario,idApunte, false);
    }

   for (Apunte *apunteSeguidos : usuario.obtenerApuntesSeguidos()) {
       int idApunteSeguido = insertarApunte(*apunteSeguidos);
       insertarUsuarioApunte(idUsuario,idApunteSeguido, true);
   }

    for (Rol rol : usuario.obtenerRoles()) { 
        insertarUsuarioRol(idUsuario, usuario.seleccionRoles.at(rol));
    }

    for( Usuario *conexion : usuario.obtenerConexiones()){

        insertarConexionUsuario(idUsuario, conexion->obtenerID());
    }
    sqlite3_finalize(stmt);
    return idUsuario;
}

std::vector<Usuario> ManejoSqlite::obtenerTodoLosUsuarios() {
    std::vector<Usuario> usuarios;
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

    if (resultado != SQLITE_OK) {
        return usuarios;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Usuario usuario;
        const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        const char* descripcion = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        const int popularidad = sqlite3_column_int(stmt, 4);
        const char* correo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

    // const int periodoID = sqlite3_column_int(stmt, 6);
    // const char* rol = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
    // const int apunteID = sqlite3_column_int(stmt, 8);
    // const int conexionUsuarioID = sqlite3_column_int(stmt, 9);

    // std::cout <<" START Periodo " <<  periodoID << "\n";
    // std::cout <<" START apunteID " <<  apunteID << "\n";
    // std::cout <<" START conexionUsuarioID " <<  conexionUsuarioID << "\n";
    // std::cout <<" START Rol " <<  rol << "\n\n";

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

int ManejoSqlite::insertarPeriodo(const Periodo& periodo) {
    std::string query = "INSERT INTO Periodo (id_Periodo, Nombre, Descripcion, FechaInicio, FechaFin) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, periodo.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, periodo.obtenerNombre().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, periodo.obtenerDescripcion().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, Utilidades::crearFecha(periodo.obtenerFechaInicio()).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha(periodo.obtenerFechaFin()).c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    } 

    sqlite3_int64 idPeriodoInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idPeriodo = static_cast<int>(idPeriodoInsertado);

    for (Materia *materia : periodo.obtenerMaterias()) {
       int idMateria = insertarMateria(*materia);
       insertarPeriodoMateria(idPeriodo,idMateria);
   }

    sqlite3_finalize(stmt);

    return idPeriodo;
}

std::vector<Periodo> ManejoSqlite::obtenerTodoLosPeriodos(){
    std::vector<Periodo> periodos;
    std::string query = "SELECT * FROM Periodo";
    
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return periodos;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Periodo periodo;

        const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        const char* descripcion = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        const char* fechaInicio = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        const char* fechaFin = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

        if (id) {
            periodo.asignarID(id);
        } 
        if (nombre) {
            periodo.asignarNombre(nombre);
        } 
        if (descripcion) {
            periodo.asignarDescripcion(descripcion);
        }
        if (fechaInicio) {
            periodo.asignarFechaFin(Utilidades::crearTmDesdeString(fechaInicio));
        } 
        if (fechaFin) {
            periodo.asignarFechaFin(Utilidades::crearTmDesdeString(fechaFin));
        } 
    
        periodos.push_back(periodo);
    }

    sqlite3_finalize(stmt);

    return periodos;
} 
  
int ManejoSqlite::insertarMateria(const Materia& materia) {
    std::string query = "INSERT INTO Materia (id_Materia, id_Periodo, Descripcion, Nombre, PeriodoActivo) "
                        "VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, materia.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, materia.obtenerPeriodo()->obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, materia.obtenerDescripcion().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, materia.obtenerNombre().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, materia.obtenerPeriodoActivo() ? 1 : 0);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_int64 idMateriaInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idMateria = static_cast<int>(idMateriaInsertado);

    for (Clase *clase : materia.obtenerClases()) {
       int idClase = insertarClase(*clase);
       insertarMateriaClase(idMateria,idClase);
    }

    for (std::string profesor : materia.obtenerProfesores()) {
       insertarMateriaProfesor(idMateria,profesor);
    }

    sqlite3_finalize(stmt);

    return idMateria;
}

std::vector<Materia> ManejoSqlite::obtenerTodasLasMaterias(){
    std::vector<Materia> materias;
    std::string query = "SELECT * FROM Materia";
    
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return materias;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Materia materia;

        const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* idPeriodo = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        const char* descripcion = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        const char* nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        const int periodoActual = sqlite3_column_int(stmt, 5);

        if (id) {
            materia.asignarID(id);
        } 
        if (idPeriodo) {
            //materia.asignarPeriodo(nombre); buscar periodo por el id 
        } 
        if (descripcion) {
            materia.asignarDescripcion(descripcion);
        }
        if (nombre) {
            materia.asignarNombre(nombre);
        } 
        if (periodoActual) {
            materia.asignarPeriodoActivo(periodoActual == 1 ? true : false);
        } 
    
        materias.push_back(materia);
    }

    sqlite3_finalize(stmt);

    return materias;
}  
 

int ManejoSqlite::insertarClase(const Clase& clase) {
    std::string query = "INSERT INTO Clase (id_Clase, id_Materia, Descripcion, Fecha, Tema) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, clase.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, clase.obtenerIDMateria().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, clase.obtenerDescripcion().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, Utilidades::crearFecha(clase.obtenerFecha()).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, clase.obtenerTema().c_str(), -1, SQLITE_TRANSIENT);

    sqlite3_int64 idUsuarioInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idUsuario = static_cast<int>(idUsuarioInsertado);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_int64 idClaseInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idClase = static_cast<int>(idClaseInsertado);

    for (Apunte *apunte : clase.obtenerApuntes()) {
       int idApunte = insertarApunte(*apunte);
       insertarClaseApunte(idClase,idApunte);
    }

    for (std::string profesor : clase.obtenerRecursos()) {
        insertarRecursoClase(idClase,profesor);
    }

    sqlite3_finalize(stmt);

    return idClase;
}

std::vector<Clase> ManejoSqlite::obtenerTodoLosClases(){
    std::vector<Clase> clases;
    std::string query = "SELECT * FROM Clase";
    
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return clases;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Clase clase;

        const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* idMateria = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        const char* descripcion = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        const char* fecha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        const char* tema = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

        if (id) {
            clase.asignarID(id);
        } 
        if (idMateria) {
            clase.asignarIDMateria(idMateria);  
        } 
        if (descripcion) {
            clase.asignarDescripcion(descripcion);
        }
        if (fecha) {
            clase.asignarFecha(Utilidades::crearTmDesdeString(fecha));
        } 
        if (tema) {
            clase.asignarTema(tema);
        } 
    
        clases.push_back(clase);
    }

    sqlite3_finalize(stmt);
    return clases;
}  
 
int ManejoSqlite::insertarApunte(const Apunte& apunte ) {
    std::string query = "INSERT INTO Apunte (id_Apunte, id_Clase, id_Usuario, Contenido, Fecha, Like, Dislike, Popularidad) "
                        "VALUES (?, ?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, apunte.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, apunte.obtenerClase()->obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, apunte.obtenerUsuario()->obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, apunte.obtenerContenido().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha(apunte.obtenerFecha()).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, apunte.obtenerLike());
    sqlite3_bind_int(stmt, 7, apunte.obtenerDislike());
    sqlite3_bind_int(stmt, 8, apunte.obtenerPopularidad());

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_int64 idApunteInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    int idApunte = static_cast<int>(idApunteInsertado);

    for (Comentario *comentario : apunte.obtenerComentarios()) {
       int idComentario = insertarComentario(*comentario);
       insertarApunteComentario(idApunte,idComentario);
    }

    sqlite3_finalize(stmt);

    return idApunte;
}

std::vector<Apunte> ManejoSqlite::obtenerTodoLosApuntes(){
    std::vector<Apunte> apuntes;
    std::string query = "SELECT * FROM Apunte";
    
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return apuntes;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Apunte apunte;

        const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* idClase = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        const char* idUsuario = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        const char* contenido = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        const char* fecha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        const int like = sqlite3_column_int(stmt, 6);
        const int dislike = sqlite3_column_int(stmt, 7);
        const int popularidad = sqlite3_column_int(stmt, 8);

        if (id) {
            apunte.asignarID(id);
        } 
        if (idClase) {
            //apunte.asignarClase(idClase);   buscar la clase por el ID
        } 
        if (idUsuario) {
            //apunte.asignarUsuario(idClase);   buscar usuario por el ID 
        }
        if (contenido) {
            apunte.asignarContenido(contenido);
        } 
        if (fecha) {
            apunte.asignarFecha(Utilidades::crearTmDesdeString(fecha));
        } 
        if (like) {
            apunte.asignarLike(like);
        } 
        if (dislike) {
            apunte.asignarDislike(dislike);
        }
        if (popularidad) {
            apunte.asignarPopularidad(popularidad);
        } 

        apuntes.push_back(apunte);
    }

    sqlite3_finalize(stmt);

    return apuntes;
}  
    

int ManejoSqlite::insertarComentario(const Comentario& comentario) {
    std::string query = "INSERT INTO Comentario (id_Comentario, id_Apunte, id_Usuario, Contenido, Fecha, Like, Dislikes) "
                        "VALUES (?, ?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, comentario.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, comentario.obtenerApunte()->obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, comentario.obtenerUsuario()->obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, comentario.obtenerContenido().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, Utilidades::crearFecha( comentario.obtenerFecha()).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, comentario.obtenerLikes());
    sqlite3_bind_int(stmt, 7, comentario.obtenerDislikes());

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);
    sqlite3_int64 idComentarioInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idComentarioInsertado);
}

std::vector<Comentario> ManejoSqlite::obtenerTodoLosComentarios(){
    std::vector<Comentario> comentarios;
    std::string query = "SELECT * FROM Comentario";
    
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return comentarios;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Comentario comentario;

        const char* id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        const char* idUsuario = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        const char* idApunte = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        const char* contenido = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        const char* fecha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        const int like = sqlite3_column_int(stmt, 6);
        const int dislike = sqlite3_column_int(stmt, 7);

        if (id) {
            comentario.asignarID(id);
        } 
        if (idUsuario) {
            //comentario.asignarClase(idClase);   buscar la clase por el ID
        } 
        if (idApunte) {
            //comentario.asignarUsuario(idClase);   buscar usuario por el ID 
        }
        if (contenido) {
            comentario.asignarContenido(contenido);
        } 
        if (fecha) {
            comentario.asignarFecha(Utilidades::crearTmDesdeString(fecha));
        } 
        if (like) {
            comentario.asignarLikes(like);
        } 
        if (dislike) {
            comentario.asignarDislikes(dislike);
        }

        comentarios.push_back(comentario);
    }

    sqlite3_finalize(stmt);
    return comentarios;
}  

int ManejoSqlite::insertarCredencialUsuario(const Usuario& credencial) {
    std::string query = "INSERT INTO Usuario_Credenciales (id_Usuario, Correo, Clave) "
                        "VALUES (?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_text(stmt, 1, credencial.obtenerID().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, credencial.obtenerCorreo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, credencial.obtenerClave().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);
    
    sqlite3_int64 idCredencialUsuarioInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idCredencialUsuarioInsertado);
}

int ManejoSqlite::insertarUsuarioPeriodo(int usuarioID, int periodoID) {
    std::string query = "INSERT INTO Usuario_Periodos (UsuarioID, PeriodoID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_int(stmt, 2, periodoID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);
    sqlite3_int64 idUsuarioPeriodosInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idUsuarioPeriodosInsertado);
}

int ManejoSqlite::insertarUsuarioRol(int usuarioID, const std::string& rol) {
    std::string query = "INSERT INTO Usuario_Roles (UsuarioID, Rol) "
                        "VALUES (?, ?);";
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_text(stmt, 2, rol.c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idRolInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idRolInsertado);
}

int ManejoSqlite::insertarUsuarioApunte(int usuarioID, int apunteID, bool seguido) {
    std::string query = "INSERT INTO Usuario_Apuntes (UsuarioID, ApunteID, Seguido) "
                        "VALUES (?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_int(stmt, 2, apunteID);
    sqlite3_bind_int(stmt, 3, seguido ? 1 : 0);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idApunteInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idApunteInsertado);
}

int ManejoSqlite::insertarConexionUsuario(int usuarioID, std::string usuarioConectadoID) {
    std::string query = "INSERT INTO Usuario_Conexiones (UsuarioID, UsuarioConectadoID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, usuarioID);
    sqlite3_bind_text(stmt, 2, (usuarioConectadoID).c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);
    
    sqlite3_int64 idUsuarioConexionesInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idUsuarioConexionesInsertado);
}

int ManejoSqlite::insertarPeriodoMateria(int periodoID, int materiaID) {
    std::string query = "INSERT INTO Periodo_Materias (PeriodoID, MateriaID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, periodoID);
    sqlite3_bind_int(stmt, 2, materiaID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idPeriodoMateriasInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idPeriodoMateriasInsertado);
}

int ManejoSqlite::insertarMateriaClase(int materiaID, int claseID) {
    std::string query = "INSERT INTO Materia_Clases (MateriaID, ClaseID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, materiaID);
    sqlite3_bind_int(stmt, 2, claseID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idMateriaClasesInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idMateriaClasesInsertado);
}

int ManejoSqlite::insertarMateriaProfesor(int materiaID, const std::string& profesor) {
    std::string query = "INSERT INTO Materia_Profesores (MateriaID, Profesor) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, materiaID);
    sqlite3_bind_text(stmt, 2, profesor.c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idMateriaProfesorInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idMateriaProfesorInsertado);
}

int ManejoSqlite::insertarClaseApunte(int claseID, int apunteID) {
    std::string query = "INSERT INTO Clase_Apuntes (ClaseID, ApunteID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, claseID);
    sqlite3_bind_int(stmt, 2, apunteID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idClaseApunteInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idClaseApunteInsertado);
}

int ManejoSqlite::insertarRecursoClase(int claseID, const std::string& recurso) {
    std::string query = "INSERT INTO Clase_Recursos (ClaseID, Recurso) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, claseID);
    sqlite3_bind_text(stmt, 2, recurso.c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);
    
    sqlite3_int64 idRecursoClaseInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idRecursoClaseInsertado);
}

int ManejoSqlite::insertarApunteComentario(int apunteID, int comentarioID) {
    std::string query = "INSERT INTO Apunte_Comentarios (ApunteID, ComentarioID) "
                        "VALUES (?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return -1;
    }

    sqlite3_bind_int(stmt, 1, apunteID);
    sqlite3_bind_int(stmt, 2, comentarioID);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return -1;
    }

    sqlite3_finalize(stmt);

    sqlite3_int64 idApunteComentarioInsertado = sqlite3_last_insert_rowid(baseDeDatos);
    return static_cast<int>(idApunteComentarioInsertado);
}

std::string ManejoSqlite::obtenerIngresoUsuario( std::string correo, std::string clave){
    std::string query = "SELECT id_Usuario FROM Usuario_Credenciales WHERE Correo = ? AND Clave = ?;";
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return "0";
    }

    sqlite3_bind_text(stmt, 1, correo.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, clave.c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado == SQLITE_ROW) {
        std::string idUsuario = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        sqlite3_finalize(stmt);
        return idUsuario;
    } else {
        sqlite3_finalize(stmt);
        return std::string("0");
    }
}

Usuario ManejoSqlite::obtenerUsuario(std::string usuarioID) {
    Usuario usuario;
    std::string query = "SELECT * FROM Usuario WHERE id_Usuario = ?;";
    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return usuario;
    }

    sqlite3_bind_text(stmt, 1, usuarioID.c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    if (resultado == SQLITE_ROW) {
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
    }

    sqlite3_finalize(stmt);

    return usuario;
}

