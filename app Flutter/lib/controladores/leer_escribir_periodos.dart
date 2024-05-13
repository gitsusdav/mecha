import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:mecha_app/modelos/periodo.dart';

Future<void> agregarPeriodo(Periodo periodo) async {
  await FirebaseFirestore.instance.collection('periodo').add(periodo.toMap());
}

Future<List<Periodo>> obtenerPeriodo(String instituto) async {
  QuerySnapshot querySnapshot = await FirebaseFirestore.instance
      .collection('periodo')
      .where('instituto', isEqualTo: instituto)
      .get();
  return querySnapshot.docs
      .map((doc) => Periodo.fromMap(doc.data() as Map<String, dynamic>))
      .toList();
}