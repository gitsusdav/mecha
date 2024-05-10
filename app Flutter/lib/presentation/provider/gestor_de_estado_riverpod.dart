import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/configuraciones/tema_claro.dart';

final temaActual = StateProvider<ThemeData>((ref) {
  return TemaClaro.tema;
});

// Estados Pantalla Inicio Sesion
final entradaCorreo = StateProvider<TextEditingController>((ref) => TextEditingController());
final entradaClave = StateProvider<TextEditingController>((ref) => TextEditingController());
final entradaNombre = StateProvider<TextEditingController>((ref) => TextEditingController());
final esVisibleClave = StateProvider<bool>((ref) => false);

 