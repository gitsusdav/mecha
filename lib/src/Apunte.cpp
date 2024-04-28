#include <Apunte.hpp>
#include "Comentario.hpp"

// Constructor
Apunte::Apunte(Usuario* usuario, const std::string& contenido, const std::tm& fecha, int popularidad) :usuario(usuario), Contenido(contenido), Fecha(fecha), Popularidad(popularidad) {}
Apunte::Apunte(){}
// Destructor
Apunte::~Apunte() {
    
}

std::string Apunte::obtenerID() const { return ID; }
Clase* Apunte::obtenerClase() const { return clase; }
Usuario* Apunte::obtenerUsuario() const { return usuario; }
std::string Apunte::obtenerContenido() const { return Contenido; }
std::tm Apunte::obtenerFecha() const { return Fecha; }
std::vector<Comentario*> Apunte::obtenerComentarios() const { return Comentarios; }
int Apunte::obtenerLike() const { return Like; }
int Apunte::obtenerDislike() const { return Dislike; }
int Apunte::obtenerPopularidad() const { return Popularidad; }

// Métodos de modificación (setters)
void Apunte::asignarID(std::string id) { ID = id; }
void Apunte::asignarClase(Clase* clase) { this->clase = clase; }
void Apunte::asignarUsuario(Usuario* usuario) { this->usuario = usuario; }
void Apunte::asignarContenido(const std::string& contenido) { Contenido = contenido; }
void Apunte::asignarFecha(const std::tm& fecha) { Fecha = fecha; }
void Apunte::asignarComentarios(const std::vector<Comentario*> comentarios) { Comentarios = comentarios; }
void Apunte::asignarLike(int like) { Like = like; }
void Apunte::asignarDislike(int dislike) { Dislike = dislike; }
void Apunte::asignarPopularidad(int popularidad) { Popularidad = obtenerLike() - obtenerDislike(); }

void Apunte::agregarComentario(Comentario *nuevoComentario){
    Comentarios.push_back(nuevoComentario);
}

// Método para convertir Apunte en cadena
std::string Apunte::toString() const{
    std::ostringstream oss;
    oss << Contenido << " " << std::put_time(&Fecha, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

bool Apunte::operator==(const Apunte& otro) const {
    return ID == otro.obtenerID();
}