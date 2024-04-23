#pragma once

#include <string>
#include <vector>
#include <iomanip>

class Comentario;
class Usuario;
class Clase;

class Apunte {

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
    // Constructor
    Apunte( Clase* clase, Usuario* usuario, const std::string& contenido,
           const std::tm& fecha, const std::vector<Comentario*>& comentarios,
           int like, int dislike, int popularidad);

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

    // Métodos de modificación (setters)
    void setID(std::string id);
    void setClase(Clase* clase);
    void setUsuario(Usuario* usuario);
    void setContenido(const std::string& contenido);
    void setFecha(const std::tm& fecha);
    void setComentarios(const std::vector<Comentario*>& comentarios);
    void setLike(int like);
    void setDislike(int dislike);
    void setPopularidad(int popularidad);

    // Método para convertir Apunte en cadena
    std::string toString();
};

