#include "Usuario.hpp"

// Constructor
Usuario::Usuario(const std::string& nombre, const std::string& id, const std::string& descripcion,
        const std::vector<Usuario*>& conexiones, const std::vector<Rol>& roles,
        int popularidad, const std::string& correo, const std::string& clave,
        const std::vector<Apunte*>& apuntesPropios, const std::vector<Apunte*>& apuntesSeguidos)
    : Nombre(nombre), ID(id), Descripcion(descripcion), Conexiones(conexiones),
      Roles(roles), Popularidad(popularidad), Correo(correo), Clave(clave),
      ApuntesPropios(apuntesPropios), ApuntesSeguidos(apuntesSeguidos) {}

// Métodos de acceso (getters)
std::string Usuario::getNombre() const {
    return Nombre;
}

std::string Usuario::getID() const {
    return ID;
}

std::string Usuario::getDescripcion() const {
    return Descripcion;
}

std::vector<Usuario*> Usuario::getConexiones() const {
    return Conexiones;
}

std::vector<Rol> Usuario::getRoles() const {
    return Roles;
}

int Usuario::getPopularidad() const {
    return Popularidad;
}

std::string Usuario::getCorreo() const {
    return Correo;
}

std::string Usuario::getClave() const {
    return Clave;
}

std::vector<Apunte*> Usuario::getApuntesPropios() const {
    return ApuntesPropios;
}

std::vector<Apunte*> Usuario::getApuntesSeguidos() const {
    return ApuntesSeguidos;
}

// Métodos de modificación (setters)
void Usuario::setNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Usuario::setID(const std::string& id) {
    ID = id;
}

void Usuario::setDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Usuario::setConexiones(const std::vector<Usuario*>& conexiones) {
    Conexiones = conexiones;
}

void Usuario::setRoles(const std::vector<Rol>& roles) {
    Roles = roles;
}

void Usuario::setPopularidad(int popularidad) {
    Popularidad = popularidad;
}

void Usuario::setCorreo(const std::string& correo) {
    Correo = correo;
}

void Usuario::setClave(const std::string& clave) {
    Clave = clave;
}

void Usuario::setApuntesPropios(const std::vector<Apunte*>& apuntesPropios) {
    ApuntesPropios = apuntesPropios;
}

void Usuario::setApuntesSeguidos(const std::vector<Apunte*>& apuntesSeguidos) {
    ApuntesSeguidos = apuntesSeguidos;
}
