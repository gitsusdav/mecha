#pragma once

#include <string>
#include <vector>
#include <algorithm> 
#include <iterator>  
#include "BaseMecha.hpp"

class Apunte;
class Periodo;

enum class Rol {
    PROFESOR,
    ESTUDIANTE,
    GRADUADO
};

class Usuario : public BaseMecha  {
private:
    std::string Nombre;
    std::string ID;
    std::string Descripcion;
    std::vector<Usuario*> Conexiones;
    std::vector<Rol> Roles;
    int Popularidad;
    std::string Correo;
    std::string Clave; 
    std::vector<Periodo*> Periodos;
    std::vector<Apunte*> ApuntesPropios;
    std::vector<Apunte*> ApuntesSeguidos;

public:
    // Constructor sin ID
     Usuario(const std::string& nombre, const std::string& descripcion,
       const std::vector<Rol>& roles,
       const std::string& correo, const std::string& clave);
    Usuario();
    // Métodos de acceso (getters)
    std::string obtenerNombre() const;
    std::string obtenerID() const;
    std::string obtenerDescripcion() const;
    std::vector<Usuario*> obtenerConexiones() const;
    std::vector<Rol> obtenerRoles() const;
    int obtenerPopularidad() const;
    std::string obtenerCorreo() const;
    std::string obtenerClave() const; // Cambiado a "clave"
    std::vector<Apunte*> obtenerApuntesPropios() const;
    std::vector<Apunte*> obtenerApuntesSeguidos() const;

    // Métodos de modificación (setters)
    void asignarNombre(const std::string& nombre);
    void asignarID(const std::string& id);
    void asignarDescripcion(const std::string& descripcion);
    void setConexiones(const std::vector<Usuario*>& conexiones);
    void setRoles(const std::vector<Rol>& roles);
    void asignarPopularidad(int popularidad);
    void setCorreo(const std::string& correo);
    void setClave(const std::string& clave); // Cambiado a "clave"
    void setApuntesPropios(const std::vector<Apunte*>& apuntesPropios);
    void setApuntesSeguidos(const std::vector<Apunte*>& apuntesSeguidos);

    // Método para convertir Usuario en cadena
    std::string toString() const override ;
    
    // Sobrecargamos el operador de igualdad
    bool operator==(const Usuario& otro) const;

    void agregarApunteSeguido(Apunte* apunte);
    void eliminarApunteSeguido(const std::string& idApunte);
    void agregarApuntePropio(Apunte* apunte);
    void eliminarApuntePropio(const std::string& idApunte);
    Apunte* buscarApuntePropiosPorID(const std::string& idApunte) const;
    Apunte* buscarApunteSeguidosPorID(const std::string& idApunte) const;

    void agregarPeriodoActual(Periodo* periodo);
    void eliminarPeriodoActual(const std::string& idPeriodo);
    Periodo* buscarPeriodoActualPorID(const std::string& idPeriodo) const;
};

