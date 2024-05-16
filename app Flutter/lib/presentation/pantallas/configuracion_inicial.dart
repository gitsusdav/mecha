import 'package:animate_do/animate_do.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/controladores/leer_escribir_institutos.dart';
import 'package:mecha_app/modelos/instituto.dart';
import 'package:mecha_app/presentation/pantallas/inicial_eleguir_periodo.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';

class PantallaConfiguracionInicial extends ConsumerWidget {
  const PantallaConfiguracionInicial({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    precacheImage(const NetworkImage('https://firebasestorage.googleapis.com/v0/b/mecha-b7681.appspot.com/o/harval.jpg?alt=media&token=d31a9914-c68a-44ec-8dcb-faa64caef664'), context);
    precacheImage(const NetworkImage('https://firebasestorage.googleapis.com/v0/b/mecha-b7681.appspot.com/o/logo_ula.jpg?alt=media&token=401e2573-8cfa-4f32-9169-1a43e081914e'), context);
    return Scaffold(
      appBar: AppBar(title: const Center(child: Text('Elige o Crea tu Instituto',style: TextStyle(color: Colors.white),)),),
      body: 
        Stack(
          children: [
            FutureBuilder(
            future: obtenerInstitutos(),
            builder: (context, snapshot) {
              if(snapshot.hasData){
              List<Instituto> enBaseDeDatos = snapshot.data?? [];
              return Padding(
                padding: const EdgeInsets.all(8.0),
                child: GridView.builder(
                    gridDelegate:const SliverGridDelegateWithFixedCrossAxisCount(
                      crossAxisCount: 2,
                      crossAxisSpacing: 10.0,
                      mainAxisSpacing: 10.0,
                    ),
                    itemCount: enBaseDeDatos.length, 
                    itemBuilder: (BuildContext context, int index) {
                      return enBaseDeDatos[index].agregar ?
                        const CrearInstituto()
                        : GestureDetector(
                        onTap: (){
                          if(enBaseDeDatos[index].privado){
                            showDialog(context: context, builder: (context) => Dialog(
                              child: SizedBox(
                                height: 300,
                                child: Column(
                                  mainAxisAlignment: MainAxisAlignment.center,
                                  children: [
                                    const Padding(
                                      padding:  EdgeInsets.all(8.0),
                                      child:  Text('Este Instutito es privado, por lo tanto para unirte deber agregar el codigo el invitacion'),
                                    ),
                                    const SizedBox(height: 10,),
                                    EntradaTexto(entradaControlador: TextEditingController(), tipo: 'Codigo'),
                                    MaterialButton(
                                      color: Theme.of(context).primaryColor,
                                      onPressed: (){
                                        showDialog(context: context, builder: (context) =>  Dialog(
                                        child: SizedBox(
                                          height: 400,
                                          child: Padding(
                                            padding: const EdgeInsets.all(8.0),
                                            child: Center(child: Text('Codigo Incorrecto', style: TextStyle(fontSize: 18, color: Theme.of(context).indicatorColor),)),
                                          ),
                                        )));
                                    },
                                    child: Text('Continuar', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
                                    )
                                  ],
                                ),
                              ),
                            ),);
                            return;
                          }
                          ref.read(instritutoSelecionado.notifier).state= enBaseDeDatos[index].codigo;
                          asignarInstitutoUsuario(FirebaseAuth.instance.currentUser!.uid,enBaseDeDatos[index].codigo);
                          Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaEleguirPeriodo(),));
                        },
                        child: Container(
                          decoration: BoxDecoration(borderRadius: BorderRadius.circular(20),
                          border: Border.all(width: 2, color: Color(int.parse(enBaseDeDatos[index].color)))),
                          child: Center(
                            child: Column(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: [
                                SizedBox(
                                  height: 90,
                                  width: 90,
                                  child: enBaseDeDatos[index].logo.isEmpty ? Icon(Icons.business_rounded, color: Theme.of(context).indicatorColor,) : Image.network(enBaseDeDatos[index].logo),
                                ),
                                Text(
                                  enBaseDeDatos[index].nombre,
                                  style: TextStyle(fontSize: 20.0, color: Theme.of(context).indicatorColor),
                                ),
                              ],
                            ),
                          ),
                        ),
                      );
                    },
                  ),
              );
              }
              return Center(child: CircularProgressIndicator(color: Theme.of(context).primaryColor,),);
            }
          ),

            ZoomIn(
              animate: ref.watch(mostrarCrearInstituto),
              child: GestureDetector(
                onTap: (){
                  FocusScope.of(context).requestFocus(FocusNode());
                  ref.read(mostrarCrearInstituto.notifier).state = false;
                },
                child: Container(
                  color: const Color.fromARGB(57, 0, 0, 0),
                  child: Center(
                    child: Padding(
                      padding: const EdgeInsets.all(12.0),
                      child: Container(
                        padding:const EdgeInsets.all(6),
                        height: 300,
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
                              offset: Offset(3, 3),
                              blurRadius: 2,
                              spreadRadius: 1,
                            ),
                          
                          ]),
                        child: Column(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                          Text('Nombre del Instituto', style: TextStyle(color: Theme.of(context).indicatorColor),),
                          EntradaTexto(entradaControlador:  ref.watch(crearInstitutoNombre), tipo: 'Nombre'),
                          MaterialButton(
                            color: Theme.of(context).primaryColor,
                            onPressed: () async{
                              if( ref.watch(crearInstitutoNombre).text.isEmpty){
                                showDialog(context: context, builder: (context) => const Dialog(
                                  child:  Text('Escribe el nombre del Instituto que vas agregar'),
                                ),);
                                return;
                              }          
                              Instituto nuevo = Instituto(codigo: ref.watch(crearInstitutoNombre).text, descripcion: '', miembros: 1,nombre: ref.watch(crearInstitutoNombre).text, privado: false );
                              await agregarInstituto(nuevo);
                              ref.read(mostrarCrearInstituto.notifier).state = false;          
                            },
                            child: Text('Crear',style: TextStyle(color: Theme.of(context).secondaryHeaderColor) ,),),
                      
                        ],),  
                      ),
                    ),
                  ),
                ),
              ))
          ],
        )
    );
  }
  void asignarInstitutoUsuario(String usuarioID,String instituto){
    final referenciaRealTime = FirebaseDatabase.instance.ref().child('usuarios').child(usuarioID);
    referenciaRealTime.update({
      'instituto':instituto
    });
  }
}

class CrearInstituto extends ConsumerWidget {
  const CrearInstituto({
    super.key,
  });

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return GestureDetector(
     onTap: (){
       // agregar 
       ref.read(mostrarCrearInstituto.notifier).state = true;
     },
      child: Container(
        decoration: BoxDecoration(borderRadius: BorderRadius.circular(20),
       border: Border.all(width: 2, color: Theme.of(context).cardColor)),
       child: Center(
         child: Icon(Icons.add_circle_outline_rounded, color: Theme.of(context).indicatorColor, size: 30,)
       ),
      ),
    );
  }
}