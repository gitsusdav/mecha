import 'package:flutter/material.dart';

class PantallaHistorialPeriodo extends StatelessWidget {
  const PantallaHistorialPeriodo({super.key, required this.periodo});
  final String periodo;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).primaryColor,
        title: Text('Registro del Periodo', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
      ),
      body:  Column(
        children: [
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: const Text('Estas son las Materias que fueron registradas por los estudiantes para este periodo'),
          ),
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: GridView.builder(
                gridDelegate:const SliverGridDelegateWithFixedCrossAxisCount(
                  crossAxisCount: 2,
                  crossAxisSpacing: 10.0,
                  mainAxisSpacing: 10.0,
                ),
                itemCount: 10, // Cantidad de elementos en tu grid
                itemBuilder: (BuildContext context, int index) {
                  // Construye cada elemento del grid
                  return GestureDetector(
                    onTap: (){ // aqui va a Registro de Materia
                      //Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaDetalleInstitucion(institucion: 'Institución $index'),));
                    },
                    child: Container(
                      decoration: BoxDecoration(borderRadius: BorderRadius.circular(20),
                      border: Border.all(width: 2, color: Colors.green[100 * ((index+1 % 9) + 1)] ?? Colors.blue,)),
                      child: Center(
                        child: Text(
                          'Materia $index',
                          style: TextStyle(fontSize: 20.0),
                        ),
                      ),
                    ),
                  );
                },
              ),
            ),
          ),
        ],
      ),
    );
  }
}