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
    std::string getID() const;
    Clase* getClase() const;
    Usuario* getUsuario() const;
    std::string getContenido() const;
    std::tm getFecha() const;
    std::vector<Comentario*> getComentarios() const;
    int getLike() const;
    int getDislike() const;
    int getPopularidad() const;


    void setID(std::string id);
    void setClase(Clase* clase);
    void setUsuario(Usuario* usuario);
    void setContenido(const std::string& contenido);
    void setFecha(const std::tm& fecha);
    void setComentarios(const std::vector<Comentario*> comentarios);
    void setLike(int like);
    void setDislike(int dislike);
    void setPopularidad(int popularidad);
    void agregarComentario(Comentario *comentario);

    // Método para convertir Apunte en cadena
    std::string toString() const;

    // Sobrecargamos el operador de igualdad
    bool operator==(const Apunte& otro) const ;
};

