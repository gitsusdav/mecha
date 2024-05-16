import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/controladores/leer_escribir_periodos.dart';
import 'package:mecha_app/modelos/periodo.dart';
import 'package:mecha_app/presentation/pantallas/inicial_agregar_materia.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';

class PantallaEleguirPeriodo extends ConsumerWidget {
  const PantallaEleguirPeriodo({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.tertiary,
        title: Text('Periodos en curso', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),// Icons.manage_search_outlined assignment_add backup_sharp 
        actions: [Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){
            showDialog(context: context, builder: (context) => Dialog(
              child: SizedBox(
                height: 300,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    const Padding(
                      padding:  EdgeInsets.all(8.0),
                      child:  Text('Introduce el nombre de la facultad o del nucleo'),
                    ),
                    const SizedBox(height: 10,),
                     EntradaTexto(entradaControlador: ref.watch(crearPeriodoFacultad), tipo: 'Facultad'),
                     const SizedBox(height: 10,),
                     const Padding(
                      padding:  EdgeInsets.all(8.0),
                      child:  Text('Escribe el nombre del Periodo'),
                    ),
                    const SizedBox(height: 10,),
                    EntradaTexto(entradaControlador: ref.watch(crearPeriodoNombre), tipo: 'Nombre'),
                    MaterialButton(
                      color: Theme.of(context).primaryColor,
                      onPressed: (){
                        agregarPeriodo(Periodo(codigo:'${ref.watch(crearPeriodoNombre).text}${ref.watch(crearPeriodoFacultad).text}' ,instituto: ref.watch(instritutoSelecionado),facultad: ref.watch(crearPeriodoFacultad).text, nombre:ref.watch(crearPeriodoNombre).text, enCurso: true ));
                        
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
        Text('Estos son los periodos habilitados en este momento dentro del Instituto, Elige en el que estas o crea el tuyo personal', style: TextStyle(fontSize: 18, color: Theme.of(context).indicatorColor), textAlign: TextAlign.center,),
        Expanded(
          child: StreamBuilder(
            stream: obtenerPeriodo(ref.watch(instritutoSelecionado)),
            builder: (context, snapshot) {
              if(snapshot.hasData){
                List<Periodo> periodosEnCuros = snapshot.data!;
                return Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: GridView.builder(
                    gridDelegate:const SliverGridDelegateWithFixedCrossAxisCount(
                      crossAxisCount: 2,
                      crossAxisSpacing: 10.0,
                      mainAxisSpacing: 10.0,
                      childAspectRatio: 2.4
                    ),
                    itemCount: periodosEnCuros.length, 
                    itemBuilder: (BuildContext context, int index) {
                      return GestureDetector(
                        onTap: (){
                          ref.read(periodoSelecionado.notifier).state= periodosEnCuros[index].codigo;
                          agsinarPeridoUsuario( FirebaseAuth.instance.currentUser!.uid,periodosEnCuros[index].codigo);
                          Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaAgregarMateria(),));
                        },
                        child: Container(
                          decoration: BoxDecoration(borderRadius: BorderRadius.circular(20), border: Border.all(width: 2, color: Theme.of(context).colorScheme.tertiary)),
                          child: Column(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: [
                            Text(periodosEnCuros[index].facultad, style: TextStyle(fontSize: 18, color: Theme.of(context).indicatorColor),),
                            Text(periodosEnCuros[index].nombre, style: TextStyle(fontSize: 18, color: Theme.of(context).indicatorColor)),
                          ],),
                        ),
                      );
                    }
                  ),
                );
              }
              return Center(child: CircularProgressIndicator(color: Theme.of(context).colorScheme.tertiary,),);
            }
          ),
        )
      ],),
    );
  }
  void agsinarPeridoUsuario(String usuarioID, String periodoCodigo){
    final referenciaRealTime = FirebaseDatabase.instance.ref().child('usuarios').child(usuarioID);
    referenciaRealTime.update({
      'peridoActual':periodoCodigo
    });
  }
}