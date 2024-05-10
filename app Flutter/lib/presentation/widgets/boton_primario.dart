import 'package:flutter/material.dart';

class BotonPrimario extends StatelessWidget {
  const BotonPrimario({
    super.key,
    required this.contenido, required this.sePreciona,
  });
  final Widget contenido;
  final Function sePreciona;
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 50,
      width: 50,
      decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(10),
          color: Colors.white,
          border: Border.all(
            color: const Color.fromARGB(255, 61, 60, 60),
            width: 2,
          ),
          boxShadow: const [
            BoxShadow(
              color: Color.fromARGB(255, 118, 118, 118),
              offset: Offset(1, 1),
              blurRadius: 2,
              spreadRadius: 1,
            ),
            BoxShadow(
              color: Color.fromARGB(255, 255, 255, 255),
              offset: Offset(-1, -1),
              blurRadius: 3,
              spreadRadius: 1,
            )
          ]),
      child: GestureDetector(
        onTap: sePreciona(),
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Center(child: contenido),
        ),
      ),
    );
  }
}
