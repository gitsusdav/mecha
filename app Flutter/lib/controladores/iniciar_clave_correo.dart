import 'package:firebase_auth/firebase_auth.dart';
import 'package:mecha_app/controladores/guardar_usuario_backend.dart';
import 'package:mecha_app/modelos/usuario.dart';

Future<String> registrarUsuario(String correo, String clave, String nombre) async {
  try {
    await FirebaseAuth.instance.createUserWithEmailAndPassword(
      email: correo,
      password: clave,
    );
    Usuario nuevo = Usuario(apuntesPropiosID: [],apuntesSeguidosID: [''],institucionesID: [''],
    materiasID: [],nombre: nombre,periodoActual: '',usuarioFoto: '',usuarioID: '');
    guardarDatosUsuario( nuevo );

    return '';
  } on FirebaseAuthException catch (e) {
    if (e.code == 'email-already-in-use') {
      return 'La cuenta ya existe para ese correo electrónico.';
    }
  } catch (error) {
    return '$error';
  }
  return 'No se registro el Usuario';
}

Future<bool> iniciarSesion(String correo, String clave) async {
  try {
    await FirebaseAuth.instance.signInWithEmailAndPassword(
      email: correo,
      password: clave,
    );
    return true;
  } on FirebaseAuthException catch (e) {
    if (e.code == 'wrong-password') {
      return false;
    }
  } catch (e) {
    return false;
  }
  return false;
}
