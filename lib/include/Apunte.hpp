#pragma once

#include <string>
#include <vector>
#include <iomanip>

#include "Clase.hpp"
#include "Usuario.hpp"
#include "ArbolPadre.hpp"


class Comentario;
class Apunte : public ArbolPadre {

private:
    std::string ID;
    Clase* clase;
    Usuario* usuario;
    std::string Contenido;
    std::tm Fecha;
    std::vector<Comentario*> Comentarios;
    int Like;
    int Dislike;
    int Popularidad;

public:
    // Constructor (reducido)
    Apunte(Usuario* usuario, const std::string& contenido,
           const std::tm& fecha, int popularidad);
    Apunte();
    // Destructor
    ~Apunte();

    // Métodos de acceso (getters)
    std::string obtenerID() const;
    Clase* obtenerClase() const;
    Usuario* obtenerUsuario() const;
    std::string obtenerContenido() const;
    std::tm obtenerFecha() const;
    std::vector<Comentario*> obtenerComentarios() const;
    int obtenerLike() const;
    int obtenerDislike() const;
    int obtenerPopularidad() const;


    void asignarID(std::string id);
    void asignarClase(Clase* clase);
    void asignarUsuario(Usuario* usuario);
    void asignarContenido(const std::string& contenido);
    void asignarFecha(const std::tm& fecha);
    void asignarComentarios(const std::vector<Comentario*> comentarios);
    void asignarLike(int like);
    void asignarDislike(int dislike);
    void asignarPopularidad(int popularidad);
    void agregarComentario(Comentario *comentario);

    // Método para convertir Apunte en cadena
    std::string toString() const;

    // Sobrecargamos el operador de igualdad
    bool operator==(const Apunte& otro) const ;
};

