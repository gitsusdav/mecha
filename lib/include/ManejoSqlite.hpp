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
};