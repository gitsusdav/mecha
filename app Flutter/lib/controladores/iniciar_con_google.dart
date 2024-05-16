import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:google_sign_in/google_sign_in.dart';
import 'package:mecha_app/presentation/pantallas/base.dart';
import 'package:mecha_app/utilidades/mostrar_mensaje.dart';

Future<bool> inciarConGoogle(BuildContext context) async{
   try{
    final GoogleSignInAccount? gUser =
          await GoogleSignIn().signIn();

      if (gUser == null) {
        //El usuerio canceló el inicio de sesión
        return false;
      }

      // Obtener la autenticación de Google
      final GoogleSignInAuthentication gAuth =
          await gUser.authentication;

      // Crear una credencial utilizando los tokens de acceso y de identificación de Google
      final credential = GoogleAuthProvider.credential(
          accessToken: gAuth.accessToken,
          idToken: gAuth.idToken);

      // Iniciar sesión en Firebase con la credencial
      final UserCredential userCredential = await FirebaseAuth
          .instance
          .signInWithCredential(credential);
      final User? user = userCredential.user;
     // final UserRegistro input = UserRegistro();
      // input.nombre = nombreController.text;
      // input.ciudad = ciudadController.text;
      // input.zona = zonaController.text;
      // input.marca = marcaController.text;

      // print('usuario logeado?: $user');
      if (user != null) {
        user.uid;
        // LocalStorage local = LocalStorage();
        // final bool isSave =
        //     await storeUserNameWithGoogle(user, input);

        //local.setNombre(nombreController.text);
        // local.setCiudad(ciudadController.text);
        // local.setZona(zonaController.text);
        // local.setMarca(marcaController.text);

        if (context.mounted) {
          Navigator.pushReplacement(
            context,
            MaterialPageRoute(
              builder: (context) => const PantallaBase(),
            ),
          );
          // Navigator.pop(context);
          // Navigator.pop(context);
        }
      } else {
        // print("Error al obtener usuario");
        if(context.mounted){
          mostrarMensaje(
              context, 'Algo salio mal, intenta de nuevo');
          Navigator.pop(context);
        }
      }
    } on FirebaseAuthException catch (error) {
      throw Exception(
          "Error durante el inicio de sesión con Google: $error");
    }
    
  return false;
}

Future<void> cerrarSesion() async {
  final FirebaseAuth auth = FirebaseAuth.instance;
  final GoogleSignIn googleSignIn = GoogleSignIn();
  await auth.signOut();
  
  try {
    await googleSignIn.disconnect();
    await googleSignIn.signOut();
  } catch (e) {
    return;
  }
}
