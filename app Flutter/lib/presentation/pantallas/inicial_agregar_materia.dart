import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/controladores/leer_escribir_materias.dart';
import 'package:mecha_app/modelos/Materia.dart';
import 'package:mecha_app/presentation/pantallas/base.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';

class PantallaAgregarMateria extends ConsumerWidget {
  const PantallaAgregarMateria({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final materiasElegidas = ref.watch(materiasSelecionada);
    final obtenerMaterias = ref.watch(materiasBasedeDatos);
    bool agregar= true;
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.secondary,
        title: Text('Agregar Materias', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
        actions: [Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){
             if(ref.watch(materiaAgregada) != null){
                ref.read(materiaAgregada.notifier).state = null;
              }
             showDialog(context: context, builder: (context) => Dialog(
              child: SizedBox(
                height: 300,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    const Padding(
                      padding:  EdgeInsets.all(8.0),
                      child:  Text('Introduce el nombre de la Materia'),
                    ),
                    const SizedBox(height: 10,),
                     EntradaTexto(entradaControlador: ref.watch(crearMateriaNombre), tipo: 'Materia'),
                     const SizedBox(height: 10,),
                     const Padding(
                      padding:  EdgeInsets.all(8.0),
                      child:  Text('Escribe el nombre del Porfesor'),
                    ),
                    const SizedBox(height: 10,),
                    EntradaTexto(entradaControlador: ref.watch(crearMateriaProfesor), tipo: 'Nombre'),
                    MaterialButton(
                      color: Theme.of(context).primaryColor,
                      onPressed: (){
                       Materia nueva = Materia(nombre: ref.watch(crearMateriaNombre).text, profesor: ref.watch(crearMateriaProfesor).text, descripcion: 'Agrega una descripción', integrantes: [ ], instituto: ref.read(instritutoSelecionado), periodo: ref.watch(periodoSelecionado));
                       agregarMateria(nueva);
                       ref.read(materiaAgregada.notifier).state = nueva;
                        Navigator.pop(context);
                    },
                    child: Text('Crear', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
                    )
                  ],
                ),
              ),
            ),);
         

          }, icon:const Icon(Icons.add_box_rounded, color: Colors.white,)),
        )]
       ),
      body: Column(children: [
         Expanded(
          child: obtenerMaterias.when(data:(data) {
            List<Materia> materias = data;
            if(ref.watch(materiaAgregada) != null && agregar ){
              data.add(ref.watch(materiaAgregada)!);
              agregar= false;
            }
            return 
                Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: GridView.builder(
                    gridDelegate:const SliverGridDelegateWithFixedCrossAxisCount(
                      crossAxisCount: 2,
                      crossAxisSpacing: 10.0,
                      mainAxisSpacing: 10.0,
                    ),
                    itemCount: materias.length, 
                    itemBuilder: (BuildContext context, int index) {
                      return GestureDetector(
                        onTap: (){
                          if(ref.watch(materiaAgregada) != null){
                            ref.read(materiaAgregada.notifier).state = null;
                          }

                          if(materiasElegidas.contains(materias[index])){
                            ref.read(materiasSelecionada.notifier).update((state) => state.where((materia) => materia != materias[index]).toList());
                          }else{
                            ref.read(materiasSelecionada.notifier).update((state) => [...state, materias[index]]);
                          }
                        },
                        child: Stack(
                          children: [
                            Container(
                              decoration: BoxDecoration(borderRadius: BorderRadius.circular(20), border: Border.all(width: 2, color: materiasElegidas.contains(materias[index]) ? Colors.black : Theme.of(context).colorScheme.secondary)),
                              child: Column(
                                children: [
                                  Container(
                                    height: 50,
                                    width: double.infinity,
                                    decoration: BoxDecoration(borderRadius:const BorderRadius.only(topLeft: Radius.circular(18),topRight: Radius.circular(18)), color: Theme.of(context).colorScheme.secondary),
                                    child: Text(materias[index].nombre,style: TextStyle(fontSize: 18, color: Theme.of(context).dialogBackgroundColor), textAlign: TextAlign.center,),
                                  ),
                                  SizedBox(
                                    height: 60,
                                    width: double.infinity,
                                    child: ListView.builder(
                                      scrollDirection: Axis.horizontal,
                                      itemCount: materias[index].integrantes.length,
                                      itemBuilder: (context, i) {
                                       return Padding(padding:const  EdgeInsets.all(8),
                                       child: materias[index].integrantes[i].imagen.isEmpty? 
                                        const Icon(Icons.person)
                                       :  ClipRRect(
                                        borderRadius: BorderRadius.circular(500),
                                        child: Image.network(materias[index].integrantes[i].imagen)));
                                    },),
                                  ),
                                  Expanded(child: Text(materias[index].descripcion, overflow: TextOverflow.ellipsis,)),
                                  Container(
                                    height: 50,
                                    width: double.infinity,
                                    decoration: BoxDecoration(borderRadius:const BorderRadius.only(bottomRight: Radius.circular(18),bottomLeft: Radius.circular(18)), color: Theme.of(context).colorScheme.secondary),
                                    child: Text(materias[index].profesor,style: TextStyle(fontSize: 18, color: Theme.of(context).dialogBackgroundColor), textAlign: TextAlign.center,),
                                  ),
                              ],),
                            ),
                            if(materiasElegidas.contains(materias[index]))
                            const Positioned(
                              top: 10,
                              right: 10,
                              child: Icon(Icons.check_box_rounded))
                          ],
                        ),
                      );
                    }
                  ),
                );
          },
          error: (error, stackTrace) => const Center(child: Text('Problemas de conexion'),),
          loading: () => Center(child: CircularProgressIndicator(color: Theme.of(context).colorScheme.secondary,),) ,
          )),
        MaterialButton(
          color: Theme.of(context).colorScheme.secondary,
          onPressed: materiasElegidas.isEmpty? null : (){
            Navigator.pushAndRemoveUntil(context,MaterialPageRoute(builder: (context) => const PantallaBase(),), (Route<dynamic> route) => false);
          },
          shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(50), 
          ),
          child: Text('Continuar', style: TextStyle(fontSize: 18,color: Theme.of(context).dialogBackgroundColor),),)
      ],),
    );
  }
}