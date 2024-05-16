import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:mecha_app/modelos/comentario.dart';
import 'package:mecha_app/modelos/usuario.dart';

class Apunte {

  Usuario? creador;
  DateTime? fecha;
  String contenido='';
  List<String> imagenes = [];
  List<Comentario> comentarios = [];
  String claseID='';
  int like=0;
  int dislike=0;
  int popularidad=0;

  Apunte({
    this.creador,
    this.fecha,
    required this.contenido,
    required this.imagenes,
    required this.comentarios,
    required this.claseID,
    required this.like,
    required this.dislike,
    required this.popularidad,
  });

  Apunte.fromMap(Map<String, dynamic> map)
      : creador = Usuario.fromMap(map['creador']),
        fecha = (map['fecha'] as Timestamp).toDate(),
        contenido = map['contenido'],
        imagenes = List<String>.from(map['imagenes']),
        comentarios = (map['comentarios'] as List).map((i) => Comentario.fromMap(i)).toList(),
        claseID = map['claseID'],
        like = map['like'],
        dislike = map['dislike'],
        popularidad = map['popularidad'];

  Map<String, dynamic> toMap() {
    return {
      'creador': creador?.toMap(),
      'fecha': fecha,
      'contenido': contenido,
      'imagenes': imagenes,
      'comentarios': comentarios.map((i) => i.toMap()).toList(),
      'claseID': claseID,
      'like': like,
      'dislike': dislike,
      'popularidad': popularidad,
    };
  }
}