import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/config/light_theme.dart';

final temaActual = StateProvider<ThemeData>((ref) {
  return LightTheme.temaClaro;
});