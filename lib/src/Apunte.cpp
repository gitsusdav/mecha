#include "Apunte.hpp"

// Constructor
Apunte::Apunte( Clase* clase, Usuario* usuario, const std::string& contenido,
               const std::tm& fecha, const std::vector<Comentario*>& comentarios,
               int like, int dislike, int popularidad)
    : clase(clase), usuario(usuario), Contenido(contenido),
      Fecha(fecha), Comentarios(comentarios), Like(like), Dislike(dislike), Popularidad(popularidad) {}

// Destructor
Apunte::~Apunte() {
    // Implement any necessary cleanup here
}

// Métodos de acceso (getters)
int Apunte::getID() const { return ID; }
Clase* Apunte::getClase() const { return clase; }
Usuario* Apunte::getUsuario() const { return usuario; }
std::string Apunte::getContenido() const { return Contenido; }
std::tm Apunte::getFecha() const { return Fecha; }
std::vector<Comentario*> Apunte::getComentarios() const { return Comentarios; }
int Apunte::getLike() const { return Like; }
int Apunte::getDislike() const { return Dislike; }
int Apunte::getPopularidad() const { return Popularidad; }

// Métodos de modificación (setters)
void Apunte::setID(int id) { ID = id; }
void Apunte::setClase(Clase* clase) { this->clase = clase; }
void Apunte::setUsuario(Usuario* usuario) { this->usuario = usuario; }
void Apunte::setContenido(const std::string& contenido) { Contenido = contenido; }
void Apunte::setFecha(const std::tm& fecha) { Fecha = fecha; }
void Apunte::setComentarios(const std::vector<Comentario*>& comentarios) { Comentarios = comentarios; }
void Apunte::setLike(int like) { Like = like; }
void Apunte::setDislike(int dislike) { Dislike = dislike; }
void Apunte::setPopularidad(int popularidad) { Popularidad = popularidad; }


/*
// Método para convertir Apunte en cadena
std::string Apunte::toString() {
    std::ostringstream oss;
    oss << Contenido << " " << std::put_time(&Fecha, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}*/