#include "Comentario.hpp"

// Constructor
Comentario::Comentario(Usuario* usuario, const std::string& contenido, const std::tm& fecha) : usuario(usuario), Contenido(contenido), Fecha(fecha) {}
Comentario::Comentario(){}
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

std::string Comentario::getID() const {
    return id;
}


std::tm Comentario::getFecha() const {
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

void Comentario::setFecha(const std::tm& fecha) {
    Fecha = fecha;
}

void Comentario::setID(const std::string& ID) {
    id = ID;
}

void Comentario::setLikes(int like) {
    Like = like;
}

void Comentario::setDislikes(int dislike) {
    Dislikes = dislike;
}
std::string Comentario::toString() const {
            std::ostringstream oss;
    oss << Contenido  << " " <<  std::put_time(&Fecha, "%Y-%m-%d %H:%M:%S");
    return oss.str();
} 