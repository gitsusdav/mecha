import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:mecha_app/modelos/clase.dart';

Future<void> escribirClase(Clase clase) async {
  CollectionReference clases = FirebaseFirestore.instance.collection('clase');
  DocumentReference docRef = await clases.add(clase.toMap());
  await docRef.update({'id': docRef.id});
}