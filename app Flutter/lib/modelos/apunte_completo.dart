import 'package:mecha_app/modelos/comentarios_completos.dart';

class ApunteCompleto {
  bool seguir;
  int like;
  int dislike;
  List<ComentariosCompletos> comentarios;
  String nombreUsuario;
  String fotoUsuario;
  String contenido;
   String materia;
    String fecha;


  ApunteCompleto({
    required this.seguir,
    required this.like,
    required this.dislike,
    required this.comentarios,
    required this.nombreUsuario,
    required this.fotoUsuario,
    required this.contenido,
    required this.materia,
    required this.fecha,
  });

  Map<String, dynamic> toMap() {
    return {
      'seguir': seguir,
      'like': like,
      'dislike': dislike,
      'comentarios': comentarios.map((miClase) => miClase.toMap()).toList(),
      'nombreUsuario': nombreUsuario,
      'fotoUsuario': fotoUsuario,
      'contenido': contenido,
      'materia':materia,
      'fecha':fecha
    };
  }

  ApunteCompleto.fromMap(Map<String, dynamic> map)
      : seguir = map['seguir'],
        like = map['like'],
        dislike = map['dislike'],
        materia = map['materia'],
        fecha = map['fecha'],
        comentarios = (map['comentarios'] as List).map((i) => ComentariosCompletos.fromMap(i)).toList(),
        nombreUsuario = map['nombreUsuario'],
        fotoUsuario = map['fotoUsuario'],
        contenido = map['contenido'];
}