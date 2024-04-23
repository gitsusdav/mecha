#pragma once
#include <string>
#include <vector>
#include "Comentario.hpp"
#include "Clase.hpp"
#include "Usuario.hpp" // Incluir el archivo de encabezado de Comentario


class Apunte {
private:
    int ID;
    Clase* clase;
    Usuario* usuario;
    std::string Contenido;
    std::string Fecha;
    std::vector<Comentario*> Comentarios;
    int Like;
    int Dislike;
    int Popularidad;

public:
    // Constructor
    Apunte(int id, Clase* clase, Usuario* usuario, const std::string& contenido,
           const std::string& fecha, const std::vector<Comentario*>& comentarios,
           int like, int dislike, int popularidad);

    // Destructor
    ~Apunte();

    // Métodos de acceso (getters)
    int getID() const;
    Clase* getClase() const;
    Usuario* getUsuario() const;
    std::string getContenido() const;
    std::string getFecha() const;
    std::vector<Comentario*> getComentarios() const;
    int getLike() const;
    int getDislike() const;
    int getPopularidad() const;

    // Métodos de modificación (setters)
    void setID(int id);
    void setClase(Clase* clase);
    void setUsuario(Usuario* usuario);
    void setContenido(const std::string& contenido);
    void setFecha(const std::string& fecha);
    void setComentarios(const std::vector<Comentario*>& comentarios);
    void setLike(int like);
    void setDislike(int dislike);
    void setPopularidad(int popularidad);
};

