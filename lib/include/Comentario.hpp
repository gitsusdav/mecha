#pragma once

#include <string>
#include <iomanip>
#include "Apunte.hpp"
#include "Usuario.hpp"
#include "ArbolPadre.hpp"

class Comentario : public ArbolPadre {
private:
    std::string id;
    Apunte* apunte;
    Usuario* usuario;
    std::string Contenido;
    std::tm Fecha;
    int Like;
    int Dislikes;

public:
    // Constructor
    Comentario(Usuario* usuario, const std::string& contenido,
               const std::tm& fecha);
    Comentario();
    // Métodos de acceso (getters)
    Apunte* obtenerApunte() const;
    Usuario* obtenerUsuario() const;
    std::string obtenerContenido() const;
    std::tm obtenerFecha() const;
    std::string obtenerID() const;
    int obtenerLikes() const;
    int obtenerDislikes() const;

    // Métodos de modificación (setters)
    void asignarApunte(Apunte* apunte);
    void asignarUsuario(Usuario* usuario);
    void asignarContenido(const std::string& contenido);
    void asignarFecha(const std::tm& fecha);
    void asignarLikes(int like);
    void asignarID(const std::string& ID);
    void asignarDislikes(int dislike);

    // Método para convertir Comentario en cadena
    std::string toString() const;
};