import 'package:flutter/material.dart';

class AvatarUsuario extends StatelessWidget {
  const AvatarUsuario({
    super.key, required this.imagen, this.color
  });
  final String imagen;
  final Color? color;
  @override
  Widget build(BuildContext context) {
    return color != null ?  Container(
      decoration: BoxDecoration(border: Border.all(width: 4, color: color!),shape: BoxShape.circle,
        color: Colors.white 
      ),
      child: Padding(
        padding: const EdgeInsets.all(4.0),
        child: Center(
          child: Container(
            width: 50,
            height: 50,
              decoration: const BoxDecoration(
              shape: BoxShape.circle,
            color:Color.fromARGB(255, 31, 46, 177),),
          ),
        ),
      ),
    ): 
    Container(
          width: 50,
          height: 50,
            decoration: const BoxDecoration(
            shape: BoxShape.circle,
          color:Color.fromARGB(255, 31, 46, 177),),
        )
    ;
  }
}