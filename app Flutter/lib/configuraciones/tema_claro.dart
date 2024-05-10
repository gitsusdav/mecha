import 'package:flutter/material.dart';

class TemaClaro {
  static const Color primary =  Color.fromARGB(255, 35, 105, 228);
  static final ThemeData tema = ThemeData(

    colorScheme: ColorScheme.fromSwatch(
      
    ).copyWith(
      primary: Colors.purple,
      secondary: const Color.fromARGB(255, 45, 117, 47), // Materia
      tertiary: const Color.fromARGB(255, 250, 124, 40), // Periodo
      inversePrimary: const Color.fromARGB(255, 45, 117, 47), // Materia
      primaryContainer: const Color.fromARGB(255, 45, 117, 47), // Materia
      onPrimary : const Color.fromARGB(255, 40, 133, 170), // Materia
      tertiaryContainer:  const Color.fromARGB(255, 45, 117, 47), // Materia
    ),
    primaryColor: primary,
    canvasColor:const Color.fromARGB(255, 45, 117, 47), // Materia
    secondaryHeaderColor: const Color.fromARGB(255, 255, 255, 255),
    indicatorColor: Colors.black,
    iconTheme: const IconThemeData(color: Colors.white),
    bottomNavigationBarTheme: const BottomNavigationBarThemeData(
        backgroundColor: Colors.blue, unselectedItemColor: Colors.white),
    scaffoldBackgroundColor: Colors.white,
    appBarTheme: const AppBarTheme(
      color: Colors.blue,
      
    ),
    textTheme: const TextTheme(
      bodyLarge: TextStyle(color: Colors.black),
      bodyMedium: TextStyle(color: Colors.black),
    ),
    textButtonTheme: TextButtonThemeData(
      style: TextButton.styleFrom(
        foregroundColor: primary,
        surfaceTintColor: primary,
      ),
    ),
  );
}
