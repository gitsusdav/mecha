cmake_minimum_required(VERSION 3.10)

project(mecha)

# Agrega las bibliotecas precompiladas
add_library(sqlite3 SHARED IMPORTED)
set_target_properties(sqlite3 PROPERTIES IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libsqlite3.so)

add_library(crypto SHARED IMPORTED)
set_target_properties(crypto PROPERTIES IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libcrypto.so)

# Agrega tu módulo mecha
add_library(mecha SHARED
    lib/src/Apunte.cpp
    lib/src/BaseMecha.cpp
    lib/src/Clase.cpp
    lib/src/Comentario.cpp
    lib/src/ManejoSqlite.cpp
    lib/src/Materia.cpp
    lib/src/NodoFuego.cpp
    lib/src/NodoPadre.cpp
    lib/src/Periodo.cpp
    lib/src/TablaHash.cpp
    lib/src/Usuario.cpp
    lib/src/Utilidades.cpp
)

# Indica que tu módulo mecha depende de las bibliotecas crypto y sqlite3
target_link_libraries(mecha PRIVATE crypto sqlite3)

# Incluye las rutas de inclusión necesarias
target_include_directories(mecha PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ lib/include /usr/include/openssl)

# Opciones de compilación adicionales si las necesitas
target_compile_options(mecha PRIVATE -DDEBUG -g -O0)
