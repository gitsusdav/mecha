#include "Comentario.hpp"

// Constructor
Comentario::Comentario(Apunte* apunte, Usuario* usuario, const std::string& contenido,
           const std::string& fecha, int likes, int dislikes)
    : apunte(apunte), usuario(usuario), Contenido(contenido),
      Fecha(fecha), Like(likes), Dislikes(dislikes) {}

// Métodos de acceso (getters)
Apunte* Comentario::getApunte() const {
    return apunte;
}

Usuario* Comentario::getUsuario() const {
    return usuario;
}

std::string Comentario::getContenido() const {
    return Contenido;
}

std::string Comentario::getFecha() const {
    return Fecha;
}

int Comentario::getLikes() const {
    return Like;
}

int Comentario::getDislikes() const {
    return Dislikes;
}

// Métodos de modificación (setters)
void Comentario::setApunte(Apunte* apunte) {
    this->apunte = apunte;
}

void Comentario::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void Comentario::setContenido(const std::string& contenido) {
    Contenido = contenido;
}

void Comentario::setFecha(const std::string& fecha) {
    Fecha = fecha;
}

void Comentario::setLikes(int like) {
    Like = like;
}

void Comentario::setDislikes(int dislike) {
    Dislikes = dislike;
}
