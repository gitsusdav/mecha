import 'package:flutter/material.dart';

class EntradaTexto extends StatelessWidget {
  const EntradaTexto(
      {super.key, required this.entradaControlador, required this.tipo,
      this.mostrarClave =false, this.mostrar,
      });
  final TextEditingController entradaControlador;
  final String tipo;
  final bool mostrarClave;
  final Function? mostrar;
  @override
  Widget build(BuildContext context) {
    return Container(
        width: 250,
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
        child: Row(
          children: [
            const SizedBox(
              width: 20,
            ),
            SizedBox(
              width: tipo == 'Clave' ? 170 : 200,
              child: TextFormField(
                controller: entradaControlador,
                  autocorrect: false,
                  maxLines: 1,
                  obscureText: mostrarClave,
                  keyboardType: tipo == 'Correo' ? TextInputType.emailAddress : tipo == 'Clave' ? TextInputType.visiblePassword : TextInputType.name,
                  decoration: InputDecoration(
                      border: InputBorder.none,
                      focusedBorder: InputBorder.none,
                      hintText: tipo),
                  style: const TextStyle(
                    overflow: TextOverflow.ellipsis,
                    color: Color.fromARGB(255, 0, 0, 0),
                    fontSize: 18,
                  )),
            ),
            if(tipo == 'Clave')
            SizedBox(
                width: 40,
                child: IconButton(
                  splashRadius: 20,
                  icon: mostrarClave? const Icon(Icons.remove_red_eye_sharp) : const Icon(Icons.visibility_off) ,
                  onPressed: mostrar!(),
                )),
            const SizedBox(
              width: 10,
            ),
          ],
        ));
  }
}
