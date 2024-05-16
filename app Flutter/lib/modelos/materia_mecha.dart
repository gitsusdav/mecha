import 'package:mecha_app/modelos/clase.dart';
import 'package:mecha_app/modelos/integrante.dart';

class Materia{
  String id='';
  String nombre='';
  String profesor = '';
  String descripcion= '';
  String instituto='';
  String periodo = '';
  List<Clase> clases = [];
  List<Integrante> integrantes = []; 

  Materia({
    required this.nombre,
    required this.profesor,
    required this.descripcion,
    required this.integrantes,
    required this.instituto,
    required this.clases,
    required this.periodo,
    this.id=''
  });

  Materia.fromMap(Map<String, dynamic> map)
    : nombre = map['nombre'],
      profesor = map['profesor'],
      descripcion = map['descripcion'],
      instituto = map['instituto'],
      periodo = map['periodo'],
      id = map['id'],
      clases = (map['clases'] as List).map((i) => Clase.fromMap(i)).toList(),
      integrantes = (map['integrantes'] as List).map((i) => Integrante.fromMap(i)).toList();

  Map<String, dynamic> toMap() {
    return {
      'nombre': nombre,
      'profesor': profesor,
      'descripcion': descripcion,
      'periodo': periodo,
      'instituto': instituto,
      'clases': clases.map((i) => i.toMap()).toList(),
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