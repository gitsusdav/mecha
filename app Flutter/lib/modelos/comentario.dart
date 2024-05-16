import 'package:cloud_firestore/cloud_firestore.dart';

class Comentario{
  String apunteID='';
  String usuarioNombre ='';
  String usuarioFoto='';
  String usuarioID='';
  String contenido='';
  int like=0;
  int dislike=0;
  DateTime? fecha;

  Comentario({
    required this.apunteID,
    required this.usuarioNombre,
    required this.usuarioFoto,
    required this.usuarioID,
    required this.contenido,
    required this.like,
    required this.dislike,
    this.fecha,
  });

  Comentario.fromMap(Map<String, dynamic> map)
      : apunteID = map['apunteID'],
        usuarioNombre = map['usuarioNombre'],
        usuarioFoto = map['usuarioFoto'],
        usuarioID = map['usuarioID'],
        contenido = map['contenido'],
        like = map['like'],
        dislike = map['dislike'],
        fecha = (map['fecha'] as Timestamp).toDate();

  Map<String, dynamic> toMap() {
    return {
      'apunteID': apunteID,
      'usuarioNombre': usuarioNombre,
      'usuarioFoto': usuarioFoto,
      'usuarioID': usuarioID,
      'contenido': contenido,
      'like': like,
      'dislike': dislike,
      'fecha': fecha,
    };
  }
}