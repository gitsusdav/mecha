import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:mecha_app/modelos/apunte_completo.dart';

Future<void> agregarApunte(ApunteCompleto apunte) async {
  CollectionReference apuntes = FirebaseFirestore.instance.collection('apunte');
  DocumentReference docRef = await apuntes.add(apunte.toMap());
  await docRef.update({'id': docRef.id});
  final usuario =FirebaseAuth.instance.currentUser;
  if(usuario != null){
        final referenciaRealTime = FirebaseDatabase.instance.ref().child('usuarios').child(usuario.uid).child('apuntesPropiosID');
        referenciaRealTime.push().set(docRef.id);
  }
}