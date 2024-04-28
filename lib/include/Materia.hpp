#pragma once

#include <string>
#include <vector>
#include "Clase.hpp" 
#include "BaseMecha.hpp"

class Periodo;
class Materia : public BaseMecha{
private:
    std::string ID;
    Periodo* periodo;
    std::string Descripcion;
    std::vector<std::string> Profesores;
    std::string Nombre;
    std::vector<Clase*> Clases;
    bool PeriodoActivo;

public:
    // Constructor
    Materia( Periodo* periodo, const std::string& descripcion,
            const std::vector<std::string>& profesores, const std::string& nombre,
            const std::vector<Clase*>& clases, bool periodoActivo);
    Materia();
    // Métodos de acceso (getters)
    std::string obtenerID() const;
    Periodo* obtenerPeriodo() const;
    std::string obtenerDescripcion() const;
    std::vector<std::string> obtenerProfesores() const;
    std::string obtenerNombre() const;
    std::vector<Clase*> obtenerClases() const;
    bool obtenerPeriodoActivo() const;

    // Métodos de modificación (setters)
    void asignarID(std::string id);
    void asignarPeriodo(Periodo* periodo);
    void asignarDescripcion(const std::string& descripcion);
    void asignarProfesores(const std::vector<std::string>& profesores);
    void asignarNombre(const std::string& nombre);
    void asignarClases(const std::vector<Clase*>& clases);
    void asignarPeriodoActivo(bool periodo);
    void agregarClase(Clase *clase);
    std::vector<Clase*> buscarTemaEnClases(const std::string& tema);
    // Método para convertir Materia en cadena
    std::string toString() const;
};