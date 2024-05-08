import 'dart:ffi';
import 'dart:io' show Platform;
import 'package:ffi/ffi.dart';

// typedef UsuarioConstructorC = Pointer Function();
// typedef UsuarioConstructorDart = Pointer Function();
// typedef AsignarNombreC = Void Function(Pointer usuario, Pointer<Utf8> nombre);
// typedef AsignarNombreDart = void Function(Pointer usuario, Pointer<Utf8> nombre);
// typedef ObtenerNombreC = Pointer<Utf8> Function(Pointer usuario);
// typedef ObtenerNombreDart = Pointer<Utf8> Function(Pointer usuario);
// Define el tipo de función de C.
typedef FuncinaFunc = Pointer<Utf8> Function(Pointer<Utf8>);
// Define el tipo de función de Dart.
typedef Funcina = Pointer<Utf8> Function(Pointer<Utf8>);

class Mecha {
  late final DynamicLibrary lib;

  late final Funcina funcina;
  // late final UsuarioConstructorDart createUsuario;
  // late final AsignarNombreDart asignarNombre;
  // late final ObtenerNombreDart obtenerNombre;

  Mecha() {
    lib = Platform.isAndroid
        ? DynamicLibrary.open('libmecha.so')
        : DynamicLibrary.process();

    // Busca la función 'funcina' en la biblioteca.
    funcina = lib
        .lookup<NativeFunction<FuncinaFunc>>('funcina')
        .asFunction<Funcina>();
    // Busca el constructor de Usuario en la biblioteca compartida.
    //   createUsuario = lib
    //       .lookup<NativeFunction<UsuarioConstructorC>>('Usuario')
    //       .asFunction<UsuarioConstructorDart>();

    //   // Busca el método asignarNombre en la biblioteca compartida.
    //   asignarNombre = lib
    //       .lookup<NativeFunction<AsignarNombreC>>('asignarNombre')
    //       .asFunction<AsignarNombreDart>();

    //   // Busca el método obtenerNombre en la biblioteca compartida.
    //   obtenerNombre = lib
    //       .lookup<NativeFunction<ObtenerNombreC>>('obtenerNombre')
    //       .asFunction<ObtenerNombreDart>();
    // }

    // void createUsuarioInstanceAndSetName(String nombre) {
    //   Pointer usuario = createUsuario();
    //   // Ahora puedes usar 'usuario' que es una instancia de la clase Usuario.

    //   // Asigna el nombre a la instancia de Usuario.

    //   asignarNombre(usuario, nombre.toNativeUtf8());

    //   // Obtiene el nombre de la instancia de Usuario.
    //   Pointer<Utf8> nombrePtr = obtenerNombre(usuario);
    //   String nombreObtenido = nombrePtr.cast<Utf8>().toDartString();
    //   print('El nombre del usuario es: $nombreObtenido');
  }
  String callFuncina(String entrada) {
    // Convierte la cadena de entrada a un puntero Utf8.
    final entradaPtr = entrada.toNativeUtf8();

    // Llama a la función 'funcina'.
    final resultPtr = funcina(entradaPtr);

    // Convierte el resultado a una cadena de Dart.
    final result = resultPtr.toDartString();
    print(result);
    // Libera la memoria.
    calloc.free(entradaPtr);
    calloc.free(resultPtr);

    return result;
  }
}
