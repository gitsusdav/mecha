#include "ManejoSqlite.hpp"

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

bool ManejoSqlite::insertUsuario(const Usuario& usuario) {
    std::string query = "INSERT INTO Usuario (id_Usuario, Nombre, Descripcion, Popularidad, Correo) "
                        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt;
    int resultado = sqlite3_prepare_v2(baseDeDatos, query.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, usuario.obtenerID().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, usuario.obtenerNombre().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, usuario.obtenerDescripcion().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, usuario.obtenerPopularidad());
    sqlite3_bind_text(stmt, 5, usuario.obtenerCorreo().c_str(), -1, SQLITE_STATIC);


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