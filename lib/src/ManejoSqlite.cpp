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

    sqlite3_bind_text(stmt, 1, usuario.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, usuario.getNombre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, usuario.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, usuario.getPopularidad());
    sqlite3_bind_text(stmt, 5, usuario.getCorreo().c_str(), -1, SQLITE_STATIC);


    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    } 


    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Usuario> ManejoSqlite::obtenerTodoLosUsuarios() {
    std::vector<Usuario> usuarios;

    std::string query = R"(
        SELECT
            Usuario.ID,
            Usuario.id_Usuario,
            Usuario.Nombre,
            Usuario.Descripcion,
            Usuario.Popularidad,
            Usuario.Correo,
            Usuario_Periodos.PeriodoID,
            Usuario_Roles.Rol,
            Usuario_Apuntes.ApunteID,
            Usuario_Conexiones.UsuarioID
        FROM
            Usuario
        INNER JOIN
            Usuario_Periodos ON Usuario.ID = Usuario_Periodos.UsuarioID
        INNER JOIN
            Usuario_Apuntes ON Usuario.ID = Usuario_Apuntes.UsuarioID
        INNER JOIN
            Usuario_Conexiones ON Usuario.ID = Usuario_Conexiones.UsuarioID
        INNER JOIN
            Usuario_Roles ON Usuario.ID = Usuario_Roles.UsuarioID;
    )";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return usuarios;
    }

    while ((resultado = sqlite3_step(stmt)) == SQLITE_ROW) {
        Usuario usuario;
        usuario.setID(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        usuario.setNombre( reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        usuario.setDescripcion( reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        usuario.setPopularidad( sqlite3_column_int(stmt, 4));
        usuario.setCorreo( reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));

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

    sqlite3_bind_text(stmt, 1, periodo.getId().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, periodo.getNombre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, periodo.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, crearFecha(periodo.getFechaInicio()).c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, crearFecha(periodo.getFechaFin()).c_str(), -1, SQLITE_STATIC);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    } 

    sqlite3_finalize(stmt);
    return true;
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
    sqlite3_bind_text(stmt, 2, materia.getPeriodo()->getID());
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

bool ManejoSqlite::insertarClase(const Clase& clase) {
    std::string query = "INSERT INTO Clase (id_Clase, id_Materia, Descripcion, Fecha, Recursos, Tema) "
                        "VALUES (?, ?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, clase.getID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, clase.getIDMateria());
    sqlite3_bind_text(stmt, 3, clase.getDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, clase.getFecha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, clase.getRecursos().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, clase.getTema().c_str(), -1, SQLITE_STATIC);

    resultado = sqlite3_step(stmt);
    if (resultado != SQLITE_DONE) {
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
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
    sqlite3_bind_int(stmt, 2, apunte.getId_Clase());
    sqlite3_bind_int(stmt, 3, apunte.getId_Usuario());
    sqlite3_bind_text(stmt, 4, apunte.getContenido().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, apunte.getFecha().c_str(), -1, SQLITE_STATIC);
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