import 'package:mecha_app/modelos/apunte.dart';

class Clase{

  String fecha='';
  List<Apunte> apuntes = [];
  List<String> participantes = [];
  String materiaID='';
  List<String> recursos = [];
  String tema='';

  Clase({
    required this.fecha,
    required this.apuntes,
    required this.participantes,
    required this.materiaID,
    required this.recursos,
    required this.tema,
  });
  
  Clase.fromMap(Map<String, dynamic> map)
      : fecha = map['fecha'],
        materiaID = map['materiaID'],
        tema = map['tema'],
        participantes = List<String>.from(map['participantes']),
        recursos = List<String>.from(map['recursos']),
        apuntes = (map['apuntes'] as List).map((i) => Apunte.fromMap(i)).toList();

  Map<String, dynamic> toMap() {
    return {
      'fecha': fecha,
      'materiaID': materiaID,
      'tema': tema,
      'participantes': participantes.toList(),
      'recursos': recursos,
      'apuntes': apuntes.map((i) => i.toMap()).toList(),
    };
  }
}