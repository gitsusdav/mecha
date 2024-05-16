import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:mecha_app/modelos/clase.dart';
import 'package:mecha_app/modelos/materia_mecha.dart';

Future<void> agregarMateria(Materia materia) async {
  CollectionReference materias = FirebaseFirestore.instance.collection('materia');
  DocumentReference docRef = await materias.add(materia.toMap());
  await docRef.update({'id': docRef.id});
}

Future<List<Materia>> obtenerMateria(String periodo, String instituto) async {
  print('periodo $periodo instituto $instituto');
  QuerySnapshot querySnapshot = await FirebaseFirestore.instance
      .collection('materia')
      .where('periodo', isEqualTo: periodo)
      .where('instituto', isEqualTo: instituto)
      .get();
  return querySnapshot.docs
      .map((doc) => Materia.fromMap(doc.data() as Map<String, dynamic>))
      .toList();
}
Future<Materia> obtenerMateriaPorID(String id) async {
  DocumentSnapshot docSnapshot = await FirebaseFirestore.instance
      .collection('materia')
      .doc(id)
      .get();
  
  if (docSnapshot.exists) {
    return Materia.fromMap(docSnapshot.data() as Map<String, dynamic>);
  } else {
    throw Exception('No se encontró la materia con el ID proporcionado');
  }
}


void agregarClase(String materiaID, Clase nuevaClase) {
  CollectionReference materias = FirebaseFirestore.instance.collection('materia');

  materias
      .doc(materiaID)
      .update({
        'clases': FieldValue.arrayUnion([nuevaClase.toMap()]),
      })
      .then((value) => print("Clase añadida"))
      .catchError((error) => print("Error al añadir clase: $error"));
}