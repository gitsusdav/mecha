import 'package:flutter/material.dart';

class PantallaActualizaciones extends StatelessWidget {
  const PantallaActualizaciones({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Actualizaciones', style: TextStyle(color: Colors.white),),
      leading: IconButton(
        icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
        onPressed: () {
          Navigator.pop(context);
        },
      )),
      body: Column(children: [
          Text('Estas son las notificaciones y eso...')
      ],),
    );
  }
}