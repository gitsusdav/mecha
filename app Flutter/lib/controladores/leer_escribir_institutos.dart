import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:mecha_app/modelos/instituto.dart';

Future<void> agregarInstituto(Instituto instituto) async {
  await FirebaseFirestore.instance.collection('instituto').add(instituto.toMap());
}

Future<List<Instituto>> obtenerInstitutos() async {
  QuerySnapshot querySnapshot = await FirebaseFirestore.instance.collection('instituto').get();
  List<Instituto> resultados = querySnapshot.docs.map((doc) => Instituto.fromMap(doc.data() as Map<String, dynamic>)).toList();
  resultados.add(Instituto(nombre: '', descripcion: '', codigo: '', privado: false, miembros: 0, agregar: true));

  return resultados;
}