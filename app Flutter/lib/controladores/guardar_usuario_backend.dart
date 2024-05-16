import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:mecha_app/modelos/usuario.dart';

void guardarDatosUsuario(Usuario nuevo){
  final usuario =FirebaseAuth.instance.currentUser;
  if(usuario != null){
    nuevo.usuarioID=usuario.uid;

    final referenciaRealTime = FirebaseDatabase.instance.ref().child('usuarios').child(usuario.uid);
    referenciaRealTime.set({
      "nuevo":nuevo.nombre,
      "periodoActual":nuevo.periodoActual,
      "apuntesPropiosID":nuevo.apuntesPropiosID.asMap(),
      "apuntesSeguidosID":nuevo.apuntesSeguidosID.asMap(),
      "institucionesID":nuevo.institucionesID.asMap(),
      "materiasID":nuevo.materiasID.asMap(),
      "usuarioFoto":nuevo.usuarioFoto,
      "usuarioID":nuevo.usuarioID
      });
  }
}

