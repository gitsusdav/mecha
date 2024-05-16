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
          child: SizedBox(
            width: 40,
            height:40,
              child: ClipRRect(
                borderRadius: BorderRadius.circular(500),
                child: Image.network(imagen,
                errorBuilder: (context, error, stackTrace) => const Icon(Icons.person, color:Colors.black),
                ) ),
            )
        ),
      ),
    ): 
    SizedBox(
        width: 40,
        height:40,
          child: ClipRRect(
            borderRadius: BorderRadius.circular(500),
            child: Image.network(imagen,
            errorBuilder: (context, error, stackTrace) => const Icon(Icons.person, color:Colors.black),
            ) ),
        )
    ;
  }
}