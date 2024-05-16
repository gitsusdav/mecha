import 'package:flutter/material.dart';

class PantallaDetalleApunte extends StatelessWidget {
  const PantallaDetalleApunte({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
      ),
    );
  }
}
