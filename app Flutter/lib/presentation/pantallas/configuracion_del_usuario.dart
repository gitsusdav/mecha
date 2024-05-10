import 'package:flutter/material.dart';

class PantallaConfiguracionDelUsuario extends StatelessWidget {
  const PantallaConfiguracionDelUsuario({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Configuraciones', style: TextStyle(color: Colors.white),),
      leading: IconButton(
        icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
        onPressed: () {
          Navigator.pop(context);
        },
      )),
      body: Column(children: [
          Text('Elegir imagen, cambiar nombre, agregar descricion ... ya tu sabes')
      ],),
    );
  }
}