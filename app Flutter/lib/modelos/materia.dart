import 'package:mecha_app/modelos/integrante.dart';

class Materia{
  String nombre='';
  String profesor = '';
  String descripcion= '';
  String instituto='';
  String periodo = '';
  List<Integrante> integrantes = []; 

  Materia({
    required this.nombre,
    required this.profesor,
    required this.descripcion,
    required this.integrantes,
    required this.instituto,
    required this.periodo
  });

  Materia.fromMap(Map<String, dynamic> map)
      : nombre = map['nombre'],
        profesor = map['profesor'],
        descripcion = map['descripcion'],
        instituto = map['instituto'],
        periodo = map['periodo'],
        integrantes = (map['integrantes'] as List).map((i) => Integrante.fromMap(i)).toList();

  Map<String, dynamic> toMap() {
    return {
      'nombre': nombre,
      'profesor': profesor,
      'descripcion': descripcion,
      'periodo':periodo,
      'instituto':instituto,
      'integrantes': integrantes.map((i) => i.toMap()).toList(),
    };
  }

  @override
bool operator ==(Object other) {
  if (identical(this, other)) return true;

  return other is Materia &&
      other.nombre == nombre &&
      other.profesor == profesor &&
      other.descripcion == descripcion &&
      other.instituto == instituto &&
      other.periodo == periodo &&
      other.integrantes == integrantes ;
  }
@override
int get hashCode {
  return nombre.hashCode ^
      profesor.hashCode ^
      descripcion.hashCode ^
      instituto.hashCode ^
      periodo.hashCode ^
      integrantes.hashCode;
}

}