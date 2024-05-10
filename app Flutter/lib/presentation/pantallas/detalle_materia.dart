import 'package:flutter/material.dart';
import 'package:mecha_app/presentation/pantallas/detalle_clase.dart';
import 'package:mecha_app/presentation/pantallas/historial_periodo.dart';
import 'package:mecha_app/presentation/widgets/avatar_usuario.dart';
import 'package:mecha_app/presentation/widgets/boton_primario.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';

class PantallaDetalleMateria extends StatelessWidget {
  const PantallaDetalleMateria({super.key, required this.materia});
  final String materia;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.secondary,
        title: Text('Materia', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),// Icons.manage_search_outlined
        actions: [Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){
            
          }, icon:const Icon(Icons.edit, color: Colors.white,)),
        )]
      ),
      body:  Padding(
        padding: const EdgeInsets.all(8.0),
        child: GestureDetector(
          onTap: (){
            FocusScope.of(context).requestFocus(FocusNode());
          },
          child: SingleChildScrollView(
            child: Column(children: [
            Container(
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(10),
                border: Border.all(width: 2, color: Colors.green)),
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: Center(child: Text(materia,style: const TextStyle(fontSize: 20),)),
              )),
              const Align(
                  alignment: Alignment.centerLeft,
                  child:  Text('Compañeros')),
            SizedBox(
              height: 80,
              child: Center(
                child: ListView.builder(
                  shrinkWrap: true, 
                  scrollDirection: Axis.horizontal,
                  itemCount: 35,
                  itemBuilder: (context, index) {
                  return GestureDetector(
                    onTap: (){
                      Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaHistorialPeriodo(periodo: 'A 20${index+23-4}',),));
                    },
                    child: const Padding(
                      padding: EdgeInsets.all(8.0),
                      child: AvatarUsuario( imagen: 'url'),
                    )
                  );
                },),)),
                const Text('Profesor(s)'),
              Container(
                
                  decoration: BoxDecoration(borderRadius: BorderRadius.circular(15),
                  color:const Color.fromARGB(255, 50, 96, 248),),
                  child: const Center(child: Text('Nombre del Profesor', style: TextStyle(color: Colors.white, fontSize: 18), )),) ,
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  const Text('Moderador(s)'),
                  const SizedBox(width: 5,),
                  SizedBox(
                    width: 200,
                    height: 80,
                    child: ListView.builder(
                    scrollDirection: Axis.horizontal,
                    itemCount: 35,
                    itemBuilder: (context, index) {
                    return GestureDetector(
                      onTap: (){
                        Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaHistorialPeriodo(periodo: 'A 20${index+23-4}',),));
                      },
                      child: const Padding(
                        padding: EdgeInsets.all(8.0),
                        child: AvatarUsuario( imagen: 'url'),
                      )
                    );
                                    }
                    ),
                  )
                ],
              ),
              const Align(
                  alignment: Alignment.centerLeft,
                  child:  Text('Clases')),
              SizedBox(height: 200,
                  child:  GridView.builder(
                  gridDelegate:const SliverGridDelegateWithFixedCrossAxisCount(
                    crossAxisCount: 3,
                    crossAxisSpacing: 10.0,
                    mainAxisSpacing: 10.0,
                    childAspectRatio: 2.9
                  ),
                  itemCount: 10, // Cantidad de elementos en tu grid
                  itemBuilder: (BuildContext context, int index) {
                    // Construye cada elemento del grid
                    return GestureDetector(
                      onTap: (){
                        Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaDetalleClase(clase: '${index+5}-05-2024'),));
                      },
                      child: Container(
                        decoration: BoxDecoration(borderRadius: BorderRadius.circular(20),
                        color: index < 2 ? Colors.purple: null,
                        border: Border.all(width: 2, color: Colors.purple[100 * ((index+1 % 9) + 1)] ?? Colors.blue,)),
                        child: Center(
                          child: Text(
                            '${index+5}-05-2024',
                            style: TextStyle(fontSize: 20.0, color:index < 2 ? Colors.white: Colors.black ),
                          ),
                        ),
                      ),
                    );
                  },
                ),
          
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                EntradaTexto(entradaControlador: TextEditingController(), tipo: 'Buscar apunte'),
                const SizedBox(width: 5),
                BotonPrimario(contenido: Icon(Icons.search, color: Theme.of(context).primaryColor,), sePreciona:(){} )
              ],
            ),
            const SizedBox(height: 20,),
             const Align(
                  alignment: Alignment.centerLeft,
                  child:  Text('Información personal en la institución')),
            const Align(
                  alignment: Alignment.centerLeft,
                  child:  Text('Agrega información sobre la institución')),
            ]),
          ),
        )
      ),
    );
  }
}

