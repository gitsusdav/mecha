#include "Comentario.hpp"

// Constructor
Comentario::Comentario(Usuario* usuario, const std::string& contenido, const std::tm& fecha) : usuario(usuario), Contenido(contenido), Fecha(fecha) {}
Comentario::Comentario(){}
// Métodos de acceso (getters)

Apunte* Comentario::obtenerApunte() const {
    return apunte;
}

Usuario* Comentario::obtenerUsuario() const {
    return usuario;
}

std::string Comentario::obtenerContenido() const {
    return Contenido;
}

std::string Comentario::obtenerID() const {
    return id;
}


std::tm Comentario::obtenerFecha() const {
    return Fecha;
}

int Comentario::obtenerLikes() const {
    return Like;
}

int Comentario::obtenerDislikes() const {
    return Dislikes;
}

// Métodos de modificación (setters)
void Comentario::asignarApunte(Apunte* apunte) {
    this->apunte = apunte;
}

void Comentario::asignarUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void Comentario::asignarContenido(const std::string& contenido) {
    Contenido = contenido;
}

void Comentario::asignarFecha(const std::tm& fecha) {
    Fecha = fecha;
}

void Comentario::asignarID(const std::string& ID) {
    id = ID;
}

void Comentario::asignarLikes(int like) {
    Like = like;
}

void Comentario::asignarDislikes(int dislike) {
    Dislikes = dislike;
}
std::string Comentario::toString() const {
            std::ostringstream oss;
    oss << Contenido  << " " <<  std::put_time(&Fecha, "%Y-%m-%d %H:%M:%S");
    return oss.str();
} 