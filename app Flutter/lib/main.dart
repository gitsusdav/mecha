import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/presentation/provider/riverpod_provider.dart';
import 'package:mecha_app/presentation/screens/home_screen.dart';

void main() {
  runApp(const ProviderScope(child:  MyApp()));
}

class MyApp extends ConsumerWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Mecha',
      theme: ref.watch(temaActual),
      home: const HomeScreen()
    );
  }
}
