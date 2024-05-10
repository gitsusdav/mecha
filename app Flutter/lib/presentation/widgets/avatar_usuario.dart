import 'package:flutter/material.dart';

class AvatarUsuario extends StatelessWidget {
  const AvatarUsuario({
    super.key, required this.imagen,
  });
  final String imagen;
  @override
  Widget build(BuildContext context) {
    return Container(
      width: 50,
      height: 50,
        decoration: const BoxDecoration(
        shape: BoxShape.circle,
      color:Color.fromARGB(255, 31, 46, 177),),
    );
  }
}