#pragma once

#include <string>

class Apunte;
class Usuario;

class Comentario {
private:
    Apunte* apunte;
    Usuario* usuario;
    std::string Contenido;
    std::string Fecha;
    int Like;
    int Dislikes;

public:
    // Constructor
    Comentario(Apunte* apunte, Usuario* usuario, const std::string& contenido,
               const std::string& fecha, int likes, int dislikes);

    // Métodos de acceso (getters)
    Apunte* getApunte() const;
    Usuario* getUsuario() const;
    std::string getContenido() const;
    std::string getFecha() const;
    int getLikes() const;
    int getDislikes() const;

    // Métodos de modificación (setters)
    void setApunte(Apunte* apunte);
    void setUsuario(Usuario* usuario);
    void setContenido(const std::string& contenido);
    void setFecha(const std::string& fecha);
    void setLikes(int like);
    void setDislikes(int dislike);
};