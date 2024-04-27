#pragma once

#include <string>
#include <iomanip>
#include "Apunte.hpp"
#include "Usuario.hpp"

class Comentario {
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
    Apunte* getApunte() const;
    Usuario* getUsuario() const;
    std::string getContenido() const;
    std::tm getFecha() const;
    std::string getID() const;
    int getLikes() const;
    int getDislikes() const;

    // Métodos de modificación (setters)
    void setApunte(Apunte* apunte);
    void setUsuario(Usuario* usuario);
    void setContenido(const std::string& contenido);
    void setFecha(const std::tm& fecha);
    void setLikes(int like);
    void setID(const std::string& ID);
    void setDislikes(int dislike);

    // Método para convertir Comentario en cadena
    std::string toString() const;
};