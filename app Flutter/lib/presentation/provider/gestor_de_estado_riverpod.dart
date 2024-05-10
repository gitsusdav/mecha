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

final animacionInicio = StateProvider<bool>((ref) => false);
final animacionRegistro = StateProvider<bool>((ref) => false);
final animacionCargando = StateProvider<bool>((ref) => false);

// Estados Pantalla Base
final selectionTarjeta = StateProvider<String>((ref) => '');
final animacionTarjeta = StateProvider<bool>((ref) => false);
final contenidoTarjeta = StateProvider<Widget>((ref) => const SizedBox());

// Estados Pantalla Clase
final animacionTarjetaApunte = StateProvider<bool>((ref) => false);
final animacionComentariosApunte = StateProvider<bool>((ref) => false);