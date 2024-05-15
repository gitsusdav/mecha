import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:mecha_app/modelos/Materia.dart';

Future<void> agregarMateria(Materia materia) async {
  await FirebaseFirestore.instance.collection('materia').add(materia.toMap());
}

Future<List<Materia>> obtenerMateria(String periodo, String instituto) async {
  QuerySnapshot querySnapshot = await FirebaseFirestore.instance
      .collection('materia')
      .where('periodo', isEqualTo: periodo)
      .where('instituto', isEqualTo: instituto)
      .get();
  return querySnapshot.docs
      .map((doc) => Materia.fromMap(doc.data() as Map<String, dynamic>))
      .toList();
}