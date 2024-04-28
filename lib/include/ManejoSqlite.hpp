#include <iostream>
#include <string>
#include <sqlite3.h>
#include "Usuario.hpp"

class ManejoSqlite {
private:
    sqlite3* baseDeDatos;

public:
    ManejoSqlite(const std::string& caminoBaseDeDatos);
    ~ManejoSqlite();

    void executeQuery(const std::string& query);
    bool insertUsuario(const Usuario& usuario);
};