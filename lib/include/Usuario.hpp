#pragma once

#include <string>
#include <vector>
#include "Apunte.hpp"


enum class Rol {
    PROFESOR,
    ESTUDIANTE,
    GRADUADO
};

class Usuario {
private:
    std::string Nombre;
    std::string ID;
    std::string Descripcion;
    std::vector<Usuario*> Conexiones;
    std::vector<Rol> Roles;
    int Popularidad;
    std::string Correo;
    std::string Clave; // Cambiado a "clave"
    std::vector<Apunte*> ApuntesPropios;
    std::vector<Apunte*> ApuntesSeguidos;

public:
    // Constructor sin ID
    Usuario(const std::string& nombre, const std::string& descripcion,
            const std::vector<Usuario*>& conexiones, const std::vector<Rol>& roles,
            int popularidad, const std::string& correo, const std::string& clave, // Cambiado a "clave"
            const std::vector<Apunte*>& apuntesPropios, const std::vector<Apunte*>& apuntesSeguidos);

    // Métodos de acceso (getters)
    std::string getNombre() const;
    std::string getID() const;
    std::string getDescripcion() const;
    std::vector<Usuario*> getConexiones() const;
    std::vector<Rol> getRoles() const;
    int getPopularidad() const;
    std::string getCorreo() const;
    std::string getClave() const; // Cambiado a "clave"
    std::vector<Apunte*> getApuntesPropios() const;
    std::vector<Apunte*> getApuntesSeguidos() const;

    // Métodos de modificación (setters)
    void setNombre(const std::string& nombre);
    void setID(const std::string& id);
    void setDescripcion(const std::string& descripcion);
    void setConexiones(const std::vector<Usuario*>& conexiones);
    void setRoles(const std::vector<Rol>& roles);
    void setPopularidad(int popularidad);
    void setCorreo(const std::string& correo);
    void setClave(const std::string& clave); // Cambiado a "clave"
    void setApuntesPropios(const std::vector<Apunte*>& apuntesPropios);
    void setApuntesSeguidos(const std::vector<Apunte*>& apuntesSeguidos);

    // Método para convertir Usuario en cadena
    std::string toString() const;
};

