#include <Usuario.hpp>
#include "Apunte.hpp"
#include "Periodo.hpp"
#include "Utilidades.hpp"

// Constructor
Usuario::Usuario(const std::string& nombre, const std::string& descripcion,
        const std::vector<Rol>& roles,
        const std::string& correo, const std::string& clave)
    : Nombre(nombre), Descripcion(descripcion), Roles(roles),
      Correo(correo), Clave(clave) {
        seleccionRoles[Rol::PROFESOR] = "PROFESOR";
        seleccionRoles[Rol::ESTUDIANTE] = "ESTUDIANTE";
        seleccionRoles[Rol::GRADUADO] = "GRADUADO";
        ApuntesPropios = {};
        ApuntesSeguidos = {};
        ID = Utilidades::generarId(this->toString());
    }
Usuario::Usuario(){
    seleccionRoles[Rol::PROFESOR] = "PROFESOR";
    seleccionRoles[Rol::ESTUDIANTE] = "ESTUDIANTE";
    seleccionRoles[Rol::GRADUADO] = "GRADUADO";
    ApuntesPropios = {};
    ApuntesSeguidos = {};
}

// Métodos de acceso (getters)
std::string Usuario::obtenerNombre() const {
    return Nombre;
}

std::string Usuario::obtenerID() const {
    return ID;
}

std::string Usuario::obtenerDescripcion() const {
    return Descripcion;
}

std::vector<Usuario*> Usuario::obtenerConexiones() const {
    return Conexiones;
}
std::vector<Periodo*> Usuario::obtenerPeriodos () const {
    return Periodos;
}
std::vector<Rol> Usuario::obtenerRoles() const {
    return Roles;
}

int Usuario::obtenerPopularidad() const {
    return Popularidad;
}

std::string Usuario::obtenerCorreo() const {
    return Correo;
}

std::string Usuario::obtenerClave() const {
    return Clave;
}

std::vector<Apunte*> Usuario::obtenerApuntesPropios() const {
    return ApuntesPropios;
}

std::vector<Apunte*> Usuario::obtenerApuntesSeguidos() const {
    return ApuntesSeguidos;
}

// Métodos de modificación 
void Usuario::asignarNombre(const std::string& nombre) {
    Nombre = nombre;
}

void Usuario::asignarID(const std::string& id) {
    ID = id;
}

void Usuario::asignarDescripcion(const std::string& descripcion) {
    Descripcion = descripcion;
}

void Usuario::asignarConexiones(const std::vector<Usuario*>& conexiones) {
    Conexiones = conexiones;
}
void Usuario::asignarPeriodos(const std::vector<Periodo*>& periodos) {
    Periodos = periodos;
}
void Usuario::asignarRoles(const std::vector<Rol>& roles) {
    Roles = roles;
}

void Usuario::asignarPopularidad(int popularidad) {
    Popularidad = popularidad;
}

void Usuario::asignarCorreo(const std::string& correo) {
    Correo = correo;
}

void Usuario::asignarClave(const std::string& clave) {
    Clave = clave;
}

void Usuario::asignarApuntesPropios(const std::vector<Apunte*>& apuntesPropios) {
    ApuntesPropios = apuntesPropios;
}

void Usuario::asignarApuntesSeguidos(const std::vector<Apunte*>& apuntesSeguidos) {
    ApuntesSeguidos = apuntesSeguidos;
}

std::string Usuario::toString() const  {
    return Nombre +" "+ Descripcion +" "+  Correo;
} 

bool Usuario::operator==(const Usuario& otro) const {
    return ID == otro.obtenerID();
}

void Usuario::agregarApunteSeguido(Apunte* apunte) {
    if (std::find(ApuntesSeguidos.begin(), ApuntesSeguidos.end(), apunte) == ApuntesSeguidos.end()) {
        ApuntesSeguidos.push_back(apunte);
    }
}

void Usuario::eliminarApunteSeguido(const std::string& idApunte) {
    auto it = std::find_if(ApuntesSeguidos.begin(), ApuntesSeguidos.end(), [&idApunte](Apunte* apunte) {
        return apunte->obtenerID() == idApunte;
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
        return apunte->obtenerID() == idApunte;
    });
    if (it != ApuntesPropios.end()) {
        ApuntesPropios.erase(it);
    }
}

Apunte* Usuario::buscarApuntePropiosPorID(const std::string& idApunte) const {
    auto it = std::find_if(ApuntesPropios.begin(), ApuntesPropios.end(), [&idApunte](Apunte* apunte) {
        return apunte->obtenerID() == idApunte;
    });
    if (it != ApuntesPropios.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

Apunte* Usuario::buscarApunteSeguidosPorID(const std::string& idApunte) const {
    auto it = std::find_if(ApuntesSeguidos.begin(), ApuntesSeguidos.end(), [&idApunte](Apunte* apunte) {
        return apunte->obtenerID() == idApunte;
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
        if ((*it)->obtenerID() == idPeriodo) {
            delete *it;
            Periodos.erase(it);
            break; 
        }
    }
}

Periodo* Usuario::buscarPeriodoActualPorID(const std::string& idPeriodo) const {
    for (auto periodo : Periodos) {
        if (periodo->obtenerID() == idPeriodo) {
            return periodo;
        }
    }
    return nullptr;
}