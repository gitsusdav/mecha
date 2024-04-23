import 'package:flutter/material.dart';

class LightTheme {
  static final ThemeData temaClaro = ThemeData(
    primaryColor: const Color.fromARGB(255, 10, 38, 88),
    secondaryHeaderColor: Colors.red,
    indicatorColor: Colors.black,
    bottomNavigationBarTheme: const BottomNavigationBarThemeData(
        backgroundColor: Colors.blue, unselectedItemColor: Colors.white),
    scaffoldBackgroundColor: Colors.white,
    appBarTheme: const AppBarTheme(
      color: Colors.blue,
    ),
    textTheme: const TextTheme(
      bodyLarge: TextStyle(color: Colors.white),
      bodyMedium: TextStyle(color: Colors.white),
    ),
  );
}
