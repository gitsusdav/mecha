class PreTarjetaApunte {
  int dislike;
  int like;
  String materia;
  String contenido;

  PreTarjetaApunte({
    required this.dislike,
    required this.like,
    required this.materia,
    required this.contenido,
  });

  // Método para convertir la clase a un mapa (útil para bases de datos)
  Map<String, dynamic> toMap() {
    return {
      'dislike': dislike,
      'like': like,
      'materia': materia,
      'contenido': contenido,
    };
  }

  // Método para crear una instancia de la clase a partir de un mapa
  PreTarjetaApunte.fromMap(Map<String, dynamic> map)
      : dislike = map['dislike'],
        like = map['like'],
        materia = map['materia'],
        contenido = map['contenido'];
}