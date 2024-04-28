#pragma once

#include <string>
#include <vector>
#include <iomanip>
#include "ArbolPadre.hpp"

class Apunte;

class Clase : public ArbolPadre {
private:
    std::string ID;
    std::string ID_Materia;
    std::string Descripcion;
    std::tm Fecha;
    std::vector<std::string> Recursos;
    std::vector<Apunte*> Apuntes;
    std::string Tema;

public:
    // Constructor 
    Clase( std::string idMateria, const std::string& descripcion,
          const std::tm& fecha, const std::string& tema);
    Clase();

    // Métodos de acceso (getters)    
    std::string obtenerID() const;
    std::string obtenerIDMateria() const;
    std::string obtenerDescripcion() const;
    std::tm obtenerFecha() const;
    std::vector<std::string> obtenerRecursos() const;
    std::vector<Apunte*> obtenerApuntes() const; 
    std::string obtenerTema() const;

    // Métodos de modificación (setters)
    void asignarID(std::string id);
    void asignarIDMateria(const std::string& idMateria );
    void asignarDescripcion(const std::string& descripcion);
    void asignarFecha(const std::tm& fecha);
    void asignarRecursos(const std::vector<std::string>& recursos);
    void asignarApuntes(const std::vector<Apunte*>& apuntes); 
    void asignarTema(const std::string& tema);
    void agregarApunte(Apunte *apunte);

    // Método para convertir Clase en cadena
    std::string toString() const;
};