import 'package:flutter/material.dart';

class TarjetaCompleta extends StatelessWidget {
  const TarjetaCompleta({
    super.key,
    required this.size,
    required this.tituloTarjeta, 
    required this.cerrar,
    required this.contenido,
  });

  final Size size;
  final String tituloTarjeta;
  final Function cerrar;
  final Widget contenido;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        height: size.height*0.8,
        width: size.width*0.8,
        decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(10),
        color: Colors.white,
        border: Border.all(
          color:  tituloTarjeta == 'Apunte' ? Theme.of(context).colorScheme.onPrimary : tituloTarjeta == 'Materia' ? Theme.of(context).colorScheme.secondary : Theme.of(context).colorScheme.primary  ,
          width: 2,
        ),
        boxShadow: const [
          BoxShadow(
            color: Color.fromARGB(255, 118, 118, 118),
            offset: Offset(1, 1),
            blurRadius: 4,
            spreadRadius: 1,
          ),
          BoxShadow(
            color: Color.fromARGB(255, 255, 255, 255),
            offset: Offset(-1, -1),
            blurRadius: 3,
            spreadRadius: 3,
          )
        ]),
        child: Column(children: [
          Container(
            decoration:  BoxDecoration(borderRadius: const BorderRadius.only(topLeft: Radius.circular(8), topRight: Radius.circular(8),), color: tituloTarjeta == 'Apunte' ? Theme.of(context).colorScheme.onPrimary : tituloTarjeta == 'Materia' ? Theme.of(context).colorScheme.secondary : Theme.of(context).colorScheme.primary  ,),
            child: Row(children: [
              IconButton(onPressed: cerrar(), icon: const Icon(Icons.close_rounded)),
              Text(tituloTarjeta,style: const TextStyle(color: Colors.white, fontSize: 20),)
            ],),
          ),
          Expanded(child: contenido)
        ],),
      ),
    );
  }
}