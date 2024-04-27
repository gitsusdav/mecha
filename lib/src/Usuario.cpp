#include <Usuario.hpp>
#include "Apunte.hpp"
#include "Periodo.hpp"

// Constructor
Usuario::Usuario(const std::string& nombre, const std::string& descripcion,
        const std::vector<Rol>& roles,
        const std::string& correo, const std::string& clave)
    : Nombre(nombre), Descripcion(descripcion), Roles(roles),
      Correo(correo), Clave(clave) {}
Usuario::Usuario(){}

// Métodos de acceso (getters)
std::string Usuario::getNombre() const {
    return Nombre;
}

std::string Usuario::getID() const {
    return ID;
}

std::string Usuario::getDescripcion() const {
    return Descripcion;
}

std::vector<Usuario*> Usuario::getConexiones() const {
    return Conexiones;
}

std::vector<Rol> Usuario::getRoles() const {
    return Roles;
}

int Usuario::getPopularidad() const {
    return Popularidad;
}

std::string Usuario::getCorreo() const {
    return Correo;
}

std::string Usuario::getClave() const {
    return Clave;
}

std::vector<Apunte*> Usuario::getApuntesPropios() const {
    return ApuntesPropios;
}

std::vector<Apunte*> Usuario::getApuntesSeguidos() const {
    return ApuntesSeguidos;
}

// Métodos de modificación (setters)
void Usuario::setNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Usuario::setID(const std::string& id) {
    ID = id;
}

void Usuario::setDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Usuario::setConexiones(const std::vector<Usuario*>& conexiones) {
    Conexiones = conexiones;
}

void Usuario::setRoles(const std::vector<Rol>& roles) {
    Roles = roles;
}

void Usuario::setPopularidad(int popularidad) {
    Popularidad = popularidad;
}

void Usuario::setCorreo(const std::string& correo) {
    Correo = correo;
}

void Usuario::setClave(const std::string& clave) {
    Clave = clave;
}

void Usuario::setApuntesPropios(const std::vector<Apunte*>& apuntesPropios) {
    ApuntesPropios = apuntesPropios;
}

void Usuario::setApuntesSeguidos(const std::vector<Apunte*>& apuntesSeguidos) {
    ApuntesSeguidos = apuntesSeguidos;
}

std::string Usuario::toString() const  {
    return Nombre +" "+ Descripcion +" "+  Correo;
} 

bool Usuario::operator==(const Usuario& otro) const {
    return ID == otro.getID();
}

void Usuario::agregarApunteSeguido(Apunte* apunte) {
    if (std::find(ApuntesSeguidos.begin(), ApuntesSeguidos.end(), apunte) == ApuntesSeguidos.end()) {
        ApuntesSeguidos.push_back(apunte);
    }
}

void Usuario::eliminarApunteSeguido(const std::string& idApunte) {
    auto it = std::find_if(ApuntesSeguidos.begin(), ApuntesSeguidos.end(), [&idApunte](Apunte* apunte) {
        return apunte->getID() == idApunte;
    });
    if (it != ApuntesSeguidos.end()) {
        ApuntesSeguidos.erase(it);
    }
}

void Usuario::agregarApuntePropio(Apunte* apunte) {
    if (std::find(ApuntesPropios.begin(), ApuntesPropios.end(), apunte) == ApuntesPropios.end()) {
        ApuntesPropios.push_back(apunte);
    }
}

void Usuario::eliminarApuntePropio(const std::string& idApunte) {
    auto it = std::find_if(ApuntesPropios.begin(), ApuntesPropios.end(), [&idApunte](Apunte* apunte) {
        return apunte->getID() == idApunte;
    });
    if (it != ApuntesPropios.end()) {
        ApuntesPropios.erase(it);
    }
}

Apunte* Usuario::buscarApuntePropiosPorID(const std::string& idApunte) const {
    auto it = std::find_if(ApuntesPropios.begin(), ApuntesPropios.end(), [&idApunte](Apunte* apunte) {
        return apunte->getID() == idApunte;
    });
    if (it != ApuntesPropios.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

Apunte* Usuario::buscarApunteSeguidosPorID(const std::string& idApunte) const {
    auto it = std::find_if(ApuntesSeguidos.begin(), ApuntesSeguidos.end(), [&idApunte](Apunte* apunte) {
        return apunte->getID() == idApunte;
    });
    if (it != ApuntesSeguidos.end()) {
        return *it;
    } else {
        return nullptr;
    }
}
void Usuario::agregarPeriodoActual(Periodo* periodo) {
    Periodos.push_back(periodo);
}

void Usuario::eliminarPeriodoActual(const std::string& idPeriodo) {
    for (auto it = Periodos.begin(); it != Periodos.end(); ++it) {
        if ((*it)->getID() == idPeriodo) {
            delete *it;
            Periodos.erase(it);
            break; 
        }
    }
}

Periodo* Usuario::buscarPeriodoActualPorID(const std::string& idPeriodo) const {
    for (auto periodo : Periodos) {
        if (periodo->getID() == idPeriodo) {
            return periodo;
        }
    }
    return nullptr;
}