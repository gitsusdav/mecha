class ComentariosCompletos {
  int like;
  int dislike;
  String fotoUsuario;
  String nombreUsuario;
  String contenido;

  ComentariosCompletos({
    required this.like,
    required this.dislike,
    required this.fotoUsuario,
    required this.nombreUsuario,
    required this.contenido,
  });

  // Método para convertir la clase a un mapa (útil para bases de datos)
  Map<String, dynamic> toMap() {
    return {
      'like': like,
      'dislike': dislike,
      'fotoUsuario': fotoUsuario,
      'nombreUsuario': nombreUsuario,
      'contenido': contenido,
    };
  }

  // Método para crear una instancia de la clase a partir de un mapa
  ComentariosCompletos.fromMap(Map<String, dynamic> map)
      : like = map['like'],
        dislike = map['dislike'],
        fotoUsuario = map['fotoUsuario'],
        nombreUsuario = map['nombreUsuario'],
        contenido = map['contenido'];
}