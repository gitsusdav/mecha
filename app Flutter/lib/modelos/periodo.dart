class Periodo {
  String facultad ='';
  String nombre ='';
  bool enCurso = false;
  String codigo = '';
  String instituto ='';
  Periodo({
    required this.facultad,
    required this.nombre,
    this.enCurso = false,
    required this.instituto,
    this.codigo = '',
  });

  Periodo.fromMap(Map<String, dynamic> map)
      : facultad = map['facultad'],
        nombre = map['nombre'],
        codigo = map['codigo'],
        instituto = map['instituto'],
        enCurso = map['enCurso'];

  Map<String, dynamic> toMap() {
    return {
      'facultad': facultad,
      'nombre': nombre,
      'enCurso': enCurso,
      'codigo': codigo,
      'instituto':instituto
    };
  }
}