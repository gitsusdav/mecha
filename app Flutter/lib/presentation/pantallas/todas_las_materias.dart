import 'package:flutter/material.dart';
import 'package:mecha_app/presentation/pantallas/detalle_materia.dart';

class PantallaTodasLasMaterias extends StatelessWidget {
  const PantallaTodasLasMaterias({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.primaryContainer,
        title: Text('Materias', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
        actions: [Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){
            showDialog(context: context, builder: (context) => Dialog(child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: Column(children: [Text('Puedes agregar una materia para el periodo actual o puedes selecionar una de esta materias que otros compañeros estan cursando en este instituto en este perido')],),
            ),),);

          }, icon:const Icon(Icons.dashboard_customize_rounded, color: Colors.white,)),
        )]
      ),
      body:  Padding(
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
              onTap: (){
                Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaDetalleMateria(materia: 'Materia $index'),));
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
    );
  }
}