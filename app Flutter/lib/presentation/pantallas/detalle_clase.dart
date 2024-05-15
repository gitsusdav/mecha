import 'package:animate_do/animate_do.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/presentation/pantallas/historial_periodo.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/avatar_usuario.dart';
import 'package:mecha_app/presentation/widgets/tarjeta_completa.dart';

class PantallaDetalleClase extends ConsumerWidget {
  const PantallaDetalleClase({super.key, required this.clase});
  final String clase;
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final Size size = MediaQuery.of(context).size;
    final bool mostrarTarjeta = ref.watch(animacionTarjetaApunte);
    final bool mostrarComentarios = ref.watch(animacionComentariosApunte);
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.primary,
        title: Text('Clase', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),// Icons.manage_search_outlined assistant_photo_rounded
        actions: [Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){}, icon:const Icon(Icons.edit, color: Colors.white,)),
        )]
      ),
      body:  Stack(
        children: [
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: GestureDetector(
              onTap: (){
                FocusScope.of(context).requestFocus(FocusNode());
              },
              child: SingleChildScrollView(
                child: Column(children: [
                Container(
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(50),
                    border: Border.all(width: 2, color: Theme.of(context).colorScheme.primary)),
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Center(child: Text(clase,style: const TextStyle(fontSize: 20),)),
                  )),
                  const Align(
                      alignment: Alignment.centerLeft,
                      child:  Text('Compañeros con apuntes en esta clase')),
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
                    const Text('Tema:'),
                  Container(
                    
                      decoration: BoxDecoration(borderRadius: BorderRadius.circular(15),
                      color:const Color.fromARGB(255, 50, 96, 248),),
                      child: const Center(child: Text('Integrales', style: TextStyle(color: Colors.white, fontSize: 18), )),) ,
                  const SizedBox(height: 10),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceAround,
                    children: [
                      const Text('Apuntes',style: TextStyle(fontSize: 20),),
                      Container(
                        decoration: BoxDecoration(shape: BoxShape.circle,
                        border: Border.all(width: 2, color: Colors.black),
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
                         ]
                        ),
                        child: IconButton(
                          onPressed: (){}, icon: Icon(Icons.add_to_photos_rounded, color: Theme.of(context).colorScheme.primary)))
                    ],
                  ),
          const SizedBox(height: 10),
                  SizedBox(height: 280,
                      child:  ListView.builder(itemBuilder: (context, index) {
                        return GestureDetector(
                          onTap: (){
                            ref.read(animacionTarjetaApunte.notifier).state = true;
                          },
                          child: Padding(
                            padding: const EdgeInsets.all(8.0),
                            child: Container(height: 230,
                            decoration: BoxDecoration(
                              borderRadius: BorderRadius.circular(20),
                              border: Border.all(width: 2, color: Theme.of(context).colorScheme.onPrimary)),
                            child: Column(children: [
                              Padding(
                                padding: const EdgeInsets.all(8.0),
                                child: Row(
                                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                                  children: [
                                  const AvatarUsuario(imagen: 'imagen', color: Colors.blue,),
                                  const Text('Nombre Usuario'),
                                  BotonRedondo( radio: 50 ,hijo:  Icon(Icons.flag_outlined, color: Theme.of(context).colorScheme.primary,), )
                                ],),
                              ),
                              const Expanded(child: SingleChildScrollView(child: Text('Contenido'))),
                              Row(
                                  children: [
                                    Expanded(
                                      child: ClipRRect(
                                        borderRadius: BorderRadius.only(bottomLeft: Radius.circular(20)),
                                        child: MaterialButton(
                                          elevation: 0,
                                          height: 55,
                                          shape: const Border(
                                            top: BorderSide(
                            color: Colors.grey), // Borde gris en la parte superior
                                            right: BorderSide(
                            color: Colors.grey), // Borde gris en el lado derecho
                                          ),
                                          color: Colors.white,
                                          onPressed: null,
                                          child: Row(
                                            mainAxisAlignment: MainAxisAlignment.spaceAround,
                                            children: [
                                            BotonRedondo( radio: 40 ,hijo:  Icon(Icons.heart_broken_sharp, color: Theme.of(context).colorScheme.primary,), ),
                                            BotonRedondo( radio: 40 ,hijo:  Icon(Icons.favorite, color: Theme.of(context).colorScheme.primary,), )
                                          ],)
                                        ),
                                      ),
                                    ),
                                    Expanded(
                                      child: ClipRRect(
                                        borderRadius: const BorderRadius.only(bottomRight: Radius.circular(20)),
                                        child: MaterialButton(
                                          height: 55,
                                          elevation: 0,
                                          shape: const Border(
                                            top: BorderSide(color: Colors.grey),
                                          ),
                                          color: Colors.white,
                                          onPressed: () {
                                             ref.read(animacionComentariosApunte.notifier).state=true;
                                          },
                                          child: Row(
                                            mainAxisAlignment: MainAxisAlignment.spaceAround,
                                            children: [
                          
                          const Text(
                            'Comentarios',
                            style: TextStyle(color: Colors.black),
                            
                          ),
                          Icon(Icons.messenger_rounded),
                                            ],
                                          ),
                                        ),
                                      ),
                                    ),])
                            ],),
                            
                            ),
                          ),
                        );
                      },)
                ),
                  const Align(
                      alignment: Alignment.centerLeft,
                      child:  Text('Recursos')),
                ]),
              ),
            )
          ),
          ZoomIn(
            animate: mostrarTarjeta,
            child: TarjetaCompleta(contenido: Column(children: [ Text('Apunte')],), size: size, tituloTarjeta: 'Apunte', cerrar: ()=> (){
              ref.read(animacionTarjetaApunte.notifier).state = false;
            },),
          ),
          Positioned(
                left: 0,
                right: 0,
                bottom: 0,
                child: FadeInUpBig(
                  animate: mostrarComentarios,
                  child: Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 8.0),
                    child: Container(
                      height: size.height * 0.78,
                      width: double.infinity,
                      decoration: const BoxDecoration(
                          color: Colors.white,
                          borderRadius: BorderRadius.only(
                              topLeft: Radius.circular(20),
                              topRight: Radius.circular(20)),
                          boxShadow: [
                            BoxShadow(
                              color: Color.fromARGB(155, 118, 118, 118),
                              offset: Offset(-2, -2),
                              blurRadius: 8,
                              spreadRadius: 1,
                            )
                          ]),
                      child: Column( 
                        children: [
                           Row(
                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                            children: [
                              MaterialButton(
                                height: 60,
                                shape: const CircleBorder(),
                                onPressed: () {
                                  ref.read(animacionComentariosApunte.notifier).state=false;
                                  FocusScope.of(context).requestFocus(FocusNode());
                                },
                                child: const Icon(
                                  Icons.close_rounded,
                                  color: Colors.black,
                                ),
                              ),
                               Padding(
                                 padding: const EdgeInsets.only(right: 8.0),
                                 child: BotonRedondo( radio: 50 ,hijo:  Icon(Icons.flag_outlined, color: Theme.of(context).colorScheme.primary,), ),
                               )
                            ],
                          ),
                        ],
                      )
                      ),
                  )))
        ],
      ),
    );
  }
}

class BotonRedondo extends StatelessWidget {
  const BotonRedondo({
    super.key,required this.radio, required this.hijo,
  });
  final double radio;
  final Widget hijo;

  @override
  Widget build(BuildContext context) {
    return Container(height: radio, width: radio, 
      decoration: BoxDecoration(
      shape: BoxShape.circle,
      color: Colors.white,
      border: Border.all(
        color: const Color.fromARGB(255, 41, 27, 27),
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
    child: hijo,
    );
  }
}

