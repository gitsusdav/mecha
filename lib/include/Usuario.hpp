#pragma once

#include <string>
#include <vector>
#include <map>
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
    std::map<Rol, std::string> seleccionRoles;
    // Métodos de acceso
    std::string obtenerNombre() const;
    std::string obtenerID() const;
    std::string obtenerDescripcion() const;
    std::vector<Usuario*> obtenerConexiones() const;
    std::vector<Periodo*> obtenerPeriodos() const;
    std::vector<Rol> obtenerRoles() const;
    int obtenerPopularidad() const;
    std::string obtenerCorreo() const;
    std::string obtenerClave() const; 
    std::vector<Apunte*> obtenerApuntesPropios() const;
    std::vector<Apunte*> obtenerApuntesSeguidos() const;

    // Métodos de modificación
    void asignarNombre(const std::string& nombre);
    void asignarID(const std::string& id);
    void asignarDescripcion(const std::string& descripcion);
    void asignarConexiones(const std::vector<Usuario*>& conexiones);
    void asignarRoles(const std::vector<Rol>& roles);
    void asignarPopularidad(int popularidad);
    void asignarPeriodos(const std::vector<Periodo*>& periodos);
    void asignarCorreo(const std::string& correo);
    void asignarClave(const std::string& clave); 
    void asignarApuntesPropios(const std::vector<Apunte*>& apuntesPropios);
    void asignarApuntesSeguidos(const std::vector<Apunte*>& apuntesSeguidos);

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

