 #include "BaseMecha.hpp"
 
 
std::string BaseMecha::obtenerID() const {  return ID; }

void BaseMecha::asignarID(std::string id) { ID = id; }

std::string BaseMecha::toString() const { return " "; }

//std::vector<BaseMecha *> obtenerComentarios() const { return {}; };