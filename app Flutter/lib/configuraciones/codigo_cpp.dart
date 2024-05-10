import 'dart:ffi';
import 'dart:io' show Platform;
import 'package:ffi/ffi.dart';

typedef FuncinaFunc = Pointer<Utf8> Function(Pointer<Utf8>);
typedef Funcina = Pointer<Utf8> Function(Pointer<Utf8>);

class Mecha {
  late final DynamicLibrary lib;

  late final Funcina funcina;

  Mecha() {
    lib = Platform.isAndroid
        ? DynamicLibrary.open('libmecha.so')
        : DynamicLibrary.process();

    funcina = lib
        .lookup<NativeFunction<FuncinaFunc>>('funcina')
        .asFunction<Funcina>();
   
  }
  String callFuncina(String entrada) {

    final entradaPtr = entrada.toNativeUtf8();

    final resultPtr = funcina(entradaPtr);

    final result = resultPtr.toDartString();
    print(result);

    calloc.free(entradaPtr);
    calloc.free(resultPtr);

    return result;
  }
}
