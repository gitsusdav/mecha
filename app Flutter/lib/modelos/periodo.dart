class Periodo {
  String facultad ='';
  String nombre ='';
  bool enCurso = false;
  String codigo = '';
  Periodo({
    required this.facultad,
    required this.nombre,
    this.enCurso = false,
    this.codigo = '',
  });

  Periodo.fromMap(Map<String, dynamic> map)
      : facultad = map['facultad'],
        nombre = map['nombre'],
        codigo = map['codigo'],
        enCurso = map['enCurso'];

  Map<String, dynamic> toMap() {
    return {
      'facultad': facultad,
      'nombre': nombre,
      'enCurso': enCurso,
      'codigo': codigo
    };
  }
}