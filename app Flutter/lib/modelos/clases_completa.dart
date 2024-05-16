class ClaseCompleta {
  String contenido;
  String materia;
  String fotoUsuario;
  String fecha;

  ClaseCompleta({
    required this.contenido,
    required this.materia,
    required this.fotoUsuario,
    required this.fecha,
  });

  Map<String, dynamic> toMap() {
    return {
      'contenido': contenido,
      'materia': materia,
      'fotoUsuario': fotoUsuario,
      'fecha': fecha,
    };
  }

  ClaseCompleta.fromMap(Map<String, dynamic> map)
      : contenido = map['contenido'],
        materia = map['materia'],
        fotoUsuario = map['fotoUsuario'],
        fecha = map['fecha'];
}