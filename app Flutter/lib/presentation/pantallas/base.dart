import 'package:animate_do/animate_do.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/configuraciones/codigo_cpp.dart';
import 'package:mecha_app/controladores/guardar_usuario_backend.dart';
import 'package:mecha_app/controladores/leer_escribir_materias.dart';
import 'package:mecha_app/controladores/leer_guardar_apuntes_c.dart';
import 'package:mecha_app/controladores/leer_guardar_clases.dart';
import 'package:mecha_app/modelos/apunte.dart';
import 'package:mecha_app/modelos/apunte_completo.dart';
import 'package:mecha_app/modelos/clase.dart';
import 'package:mecha_app/modelos/comentario.dart';
import 'package:mecha_app/modelos/comentarios_completos.dart';
import 'package:mecha_app/modelos/integrante.dart';
import 'package:mecha_app/modelos/materia_mecha.dart';
import 'package:mecha_app/modelos/usuario.dart';
import 'package:mecha_app/presentation/pantallas/actualizaciones.dart';
import 'package:mecha_app/presentation/pantallas/detalle_clase.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/avatar_usuario.dart';
import 'package:mecha_app/presentation/widgets/menu_lateral.dart';
import 'package:mecha_app/presentation/widgets/tarjeta_completa.dart';
import 'package:shimmer/shimmer.dart';

class PantallaBase extends ConsumerWidget {
  const PantallaBase({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final bool mostrarTarjeta = ref.watch(animacionTarjeta);
    final String tituloTarjeta = ref.watch(selectionTarjeta);
    final Widget contenido = ref.watch(contenidoTarjeta);
    final Size size =MediaQuery.of(context).size;
    final  materiasInicio = ref.watch(materiasSelecionada);
    final clasesProcimas = ref.watch(listaclases);
    final totalApuntes = ref.watch(listaApuntes);
      Mecha mecha = Mecha();
      mecha.callFuncina('FUNCIONA desde Flutter =D');
    return Scaffold(
      appBar: AppBar(
        leading: Builder(
        builder: (BuildContext context) {
            return IconButton(
              icon: Icon(Icons.menu_rounded, color: Theme.of(context).secondaryHeaderColor),
              onPressed: () {
                Scaffold.of(context).openDrawer();
              },
            );
          },
        ),
        actions: [ Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){
            Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaActualizaciones(),));
          }, icon:const Icon(Icons.supervised_user_circle_rounded, color: Colors.white,)),
        )],
      ),
      drawer: Padding(
        padding: const EdgeInsets.symmetric(vertical: 40.0),
        child: MenuLateral(size: size,),
      ),

      body: Stack(
        children: [
          Column(children: [
            const SizedBox(height: 5),
            const Align(
              alignment: Alignment.centerLeft,
              child:  Padding(
                padding: EdgeInsets.only(left: 8.0),
                child: Text('Mis apuntes relevantes:', style: TextStyle(fontSize: 18),),
              ),
            ),
            const SizedBox(height: 5),
            SizedBox(height: 160,
            child: ListView.builder(
              itemCount: totalApuntes.length,
              scrollDirection: Axis.horizontal,
              itemBuilder: (context, index) {
              return PreApunteTarjeta( 
                contenido: totalApuntes[index].contenido,
                materia: totalApuntes[index].materia,
                fotoUsuario: totalApuntes[index].fotoUsuario,
                fecha:totalApuntes[index].fecha,
                sePreciona: ()=> (){
                  ref.read(contenidoTarjeta.notifier).state = 
                  ApuntesTarjeta(
                    ind:index,
                    comentarios: totalApuntes[index].comentarios ,
                    dislike: totalApuntes[index].dislike,
                    like: totalApuntes[index].like,
                    materia: totalApuntes[index].materia,
                    contenido: totalApuntes[index].contenido,
                  );
               /*    
                  Column(children: [
                    MaterialButton(onPressed: (){
                     
Usuario usuario = Usuario(
  nombre: 'Nombre del usuario',
  usuarioID: 'ID del usuario',
  usuarioFoto: 'URL de la foto del usuario',
  apuntesPropiosID: ['ID del apunte 1', 'ID del apunte 2'],
  apuntesSeguidosID: ['ID del apunte 3', 'ID del apunte 4'],
  periodoActual: 'Periodo actual',
  institucionesID: ['ID de la institución 1', 'ID de la institución 2'],
  materiasID: ['ID de la materia 1', 'ID de la materia 2'],
);

Comentario comentario = Comentario(
  apunteID: 'ID del apunte',
  usuarioNombre: 'Nombre del usuario',
  usuarioFoto: 'URL de la foto del usuario',
  usuarioID: 'ID del usuario',
  contenido: 'Contenido del comentario',
  like: 0,
  dislike: 0,
  fecha: DateTime.now(),
);

Apunte apunte = Apunte(
  creador: usuario,
  fecha: DateTime.now(),
  contenido: 'Contenido del apunte',
  imagenes: ['URL de la imagen 1', 'URL de la imagen 2'],
  comentarios: [comentario],
  claseID: 'ID de la clase',
  like: 0,
  dislike: 0,
  popularidad: 0,
);

Clase clase = Clase(
  fecha: 'Fecha de la clase',
  apuntes: [apunte],
  participantes: ['ID del participante 1', 'ID del participante 2'],
  materiaID: 'ID de la materia',
  recursos: ['URL del recurso 1', 'URL del recurso 2'],
  tema: 'Tema de la clase',
);
Clase claseadd = Clase(
  fecha: 'Fecha de la clase',
  apuntes: [apunte,apunte],
  participantes: ['ID del participante 1', 'ID del participante 2'],
  materiaID: 'ID de la materia',
  recursos: ['URL del recurso 1', 'URL del recurso 2'],
  tema: 'Tema de la clase',
);
Materia materia = Materia(
  nombre: 'Nombre de la materia',
  profesor: 'Nombre del profesor',
  descripcion: 'Descripción de la materia',
  instituto: ref.watch(instritutoSelecionado),
  periodo: ref.watch(periodoSelecionado),
  clases: [clase],
  integrantes: [Integrante(nombre: 'ELias', imagen: 'url', id: 'idfirebase usuario')],
);

//agregarMateria(materia);
//agregarClase('4mFvb6n487dBdQburz7P',claseadd);
escribirClase(claseadd);
//guardarDatosUsuario(usuario);

                    },
                    child: Text('Agregar Clase y Apunte a Materia'),),
                   MaterialButton(onPressed: ()async{
                     Materia completa = await obtenerMateriaPorID('cYfsdg44qoeghAa8qwEO');
                     print(completa.clases[0].apuntes[0].comentarios[0].apunteID);
                   },
                   child: Text('Materia'),)
                  ],);*/
                  ref.read(selectionTarjeta.notifier).state='Apunte';
                  ref.read(animacionTarjeta.notifier).state = true; },
                );
            },),
            ),
            const SizedBox(height: 5),
            const Align(
              alignment: Alignment.centerLeft,
              child:  Padding(
                padding: EdgeInsets.only(left: 8.0),
                child: Text('Periodo activo:', style: TextStyle(fontSize: 18),),
              ),
            ),
            const SizedBox(height: 5),
            SizedBox(
              height: 40,
              child: Center(
                child: ListView.builder(
                  shrinkWrap: true, 
                  scrollDirection: Axis.horizontal,
                  itemCount: 1,
                  itemBuilder: (context, index) {
                  return Padding(
                    padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
                    child: Container(
                      width: 80,
                      
                      decoration: BoxDecoration(borderRadius: BorderRadius.circular(50),
                      color:const Color.fromARGB(255, 248, 162, 50),),
                      child: const Center(child: Text('A 2024', style: TextStyle(color: Colors.white, fontSize: 18), )),) ,
                    
                  );
                },),
              ),
              ),
              const SizedBox(height: 5),
              const Align(
              alignment: Alignment.centerLeft,
              child:  Padding(
                padding: EdgeInsets.only(left: 8.0),
                child: Text('Materias en curso:', style: TextStyle(fontSize: 18),),
              ),
            ),
            const SizedBox(height: 5),
            SizedBox(height: 190,
            child: StreamBuilder(
              stream:  FirebaseDatabase.instance.ref().child('usuarios').child(FirebaseAuth.instance.currentUser!.uid).child('materiasID').onValue,
              builder: (context, snapshot) {
                if(snapshot.hasData){
                
                 Map map = snapshot.data!.snapshot.value as Map;
                List<String> ids = map.values.toList().cast<String>();
                
                return ListView.builder(
                  itemCount: ids.length,
                  scrollDirection: Axis.horizontal,
                  itemBuilder: (context, index) {
                  return FutureBuilder(
                    future: FirebaseFirestore.instance.collection('materia').doc(ids[index]).get(),
                    builder: (context, snapshot) {
                      if(snapshot.hasData){
                        Materia materia = Materia(clases: [],descripcion: '',instituto: '',integrantes: [],nombre: '',periodo: '',profesor: '',id: '');
                       if(snapshot.data!.data() != null){
                      
                      Map<String, dynamic> data = snapshot.data!.data() as Map<String, dynamic>;
                          materia = Materia.fromMap(data);
                          // ref.read(clasesMaterias.notifier).update((state) => [ ...materia.clases, ...state]);
                      }
                      return GestureDetector(
                        onTap: (){
                          ref.read(selectionTarjeta.notifier).state='Materia';
                          ref.read(animacionTarjeta.notifier).state = true;
                          ref.read(contenidoTarjeta.notifier).state=MateriaTarjeta(materia: materia);
                        },
                        child: Padding(
                          padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
                          child: SizedBox(
                            width: 180,
                            height: 180,
                            child: PreTarjetaMateria(materia:materia))
                           
                        ),
                      );
                      }
                      return Padding(
                        padding: const EdgeInsets.all(8.0),
                        child: ClipRRect(
                            borderRadius: BorderRadius.circular(20),
                            child: Shimmer.fromColors(
                              baseColor:const Color.fromARGB(255, 204, 248, 204),
                              highlightColor: Colors.grey[100]!,
                              child: Container(
                                width: 180.0,
                                height: 180.0,
                                color: Colors.white,
                              ),
                            ),
                          ),
                      );
                    }
                  );
                },);
                }
                return Row(
                      mainAxisAlignment: MainAxisAlignment.spaceAround,
                      children: [
                        ClipRRect(
                          borderRadius: BorderRadius.circular(20),
                          child: Shimmer.fromColors(
                            baseColor:const Color.fromARGB(255, 204, 248, 204),
                            highlightColor: Colors.grey[100]!,
                            child: Container(
                              width: 150.0,
                              height: 150.0,
                              color: Colors.white,
                            ),
                          ),
                        ),
                        ClipRRect(
                          borderRadius: BorderRadius.circular(20),
                          child: Shimmer.fromColors(
                            baseColor:const Color.fromARGB(255, 204, 248, 204),
                            highlightColor: Colors.grey[100]!,
                            child: Container(
                              width: 150.0,
                              height: 150.0,
                              color: Colors.white,
                            ),
                          ),
                        ),
                      ],
                    );
              }
            ),
            ),
            const SizedBox(height: 5),
              const Align(
              alignment: Alignment.centerLeft,
              child:  Padding(
                padding: EdgeInsets.only(left: 8.0),
                child: Text('Clases recientes:', style: TextStyle(fontSize: 18),),
              ),
            ),
            const SizedBox(height: 5),
            SizedBox(height: 80,
            child: FutureBuilder(
              future: null,
              builder: (context, snapshot) {
                return ListView.builder(
                  itemCount: clasesProcimas.length,
                  scrollDirection: Axis.horizontal,
                  itemBuilder: (context, index) {
                  return GestureDetector(
                    onTap: (){
                      ref.read(selectionTarjeta.notifier).state='Clase';
                      ref.read(animacionTarjeta.notifier).state = true;
                 ref.read(contenidoTarjeta.notifier).state= TarjetaClase( nombreClase :'clase', nombreMateria: 'materia',);
                    },
                    child: Padding(
                      padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
                      child: Container(
                        height: 50,
                        width: 140,
                        decoration: BoxDecoration(borderRadius: BorderRadius.circular(50),
                        border: Border.all(width: 2, color: const Color.fromARGB(255, 126, 30, 182)),
                         color: const Color.fromARGB(255, 126, 30, 182),),
                         child: Center(child: Text(clasesProcimas[index], textAlign: TextAlign.center, style:const TextStyle(color:Colors.white, fontSize: 18))),
                         ) ,
                       
                    ),
                  );
                },);
              }
            ),
            ),
          ],),
          ZoomIn(
            animate: mostrarTarjeta,
            child: TarjetaCompleta(contenido: contenido, size: size, tituloTarjeta: tituloTarjeta, cerrar: ()=> (){
              ref.read(animacionTarjeta.notifier).state = false;
            },),
          )
        ],
      ),
      resizeToAvoidBottomInset: false,
    );
  }
}

class TarjetaClase extends ConsumerWidget {
  const TarjetaClase({
    super.key,
    required this.nombreClase,
    required this.nombreMateria
  });
final String nombreClase;
final String nombreMateria;
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final controladorNuevoApunte =ref.watch(crearApunte);
    return Column(children: [
      Container(
        decoration: BoxDecoration(borderRadius: BorderRadius.circular(20), border: Border.all(width: 2, color:Colors.green)),
         child: Center(child: Text(nombreMateria, style:const TextStyle(fontSize: 20)))),
     Text(nombreClase, style:const TextStyle(fontSize: 20)),
     const SizedBox(height: 20),
     const Text('Crea un Apunte para esta Clase'),
     Row(
      mainAxisAlignment: MainAxisAlignment.end,
       children: [
         MaterialButton(
          color:Colors.black,
          onPressed:()async{
           ApunteCompleto nuevo = ApunteCompleto(comentarios: [],contenido: controladorNuevoApunte.text,dislike: 0,fecha: '',fotoUsuario: '',like: 0,materia:nombreMateria,nombreUsuario: 'usuario', seguir: false );
         
          await agregarApunte(nuevo);
          ref.read(listaApuntes.notifier).update((state) => [nuevo, ...state]);
           ref.read(animacionTarjeta.notifier).state = false;
         },
         child:const Text('Crear Apunte', style: TextStyle( color:Colors.white)),),
         const SizedBox(width: 10,)
       ],
     ),
    Expanded(
      child: TextField(
        controller: controladorNuevoApunte,
        maxLines: null, // Permite un número ilimitado de líneas.
        textAlignVertical: TextAlignVertical.top, // Alinea el texto en la parte superior.
        decoration: InputDecoration(
        hintText: 'Escribe aquí...',
        ),
      ),
    ),
    
    ],);
  }
}

class ApuntesTarjeta extends ConsumerWidget {
  const ApuntesTarjeta(  {super.key, required this.materia,required this.contenido,required this.like,required this.dislike,required this.comentarios, required this.ind,});
  final String materia;
  final String contenido;
  final int like;
  final int dislike;
  final int ind;
  final List<ComentariosCompletos> comentarios; 
  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final comentarioControlador = ref.watch(crearComentario);
   // final apuntes = ref.watch(listaApuntes);
    return Column(children: [
     Padding(
       padding: const EdgeInsets.all(8.0),
       child: Row(
         children: [
        //  BotonRedondo( radio: 50 ,hijo:  Icon(Icons.flag_outlined, color: Theme.of(context).colorScheme.primary,), ),
          const SizedBox(width: 5,),
          Text(materia, style: const TextStyle(fontSize: 20), overflow: TextOverflow.ellipsis,)
         ],
       ),
     ),
      Expanded(child: Text(contenido)),
       Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          GestureDetector(
            onTap:(){
              showDialog(context: context, builder:(context) => Dialog(
                child: Column(children: [
                  const Text('Escribe el comentario que deseas agregar'),
                  const SizedBox( height :10),
                  SizedBox(height: 50,
                  child: TextField(
                    controller: comentarioControlador
                  )
                   ),
                    MaterialButton(
                      color:Colors.black,
                      onPressed:(){
                     ComentariosCompletos nuevoComentario = ComentariosCompletos(contenido: comentarioControlador.text, dislike: 0,fotoUsuario: '',like: 0,nombreUsuario: '');
                      ref.read(listaApuntes.notifier).update((state) {
                       state[ind].comentarios.add(nuevoComentario);
                        return [...state];
                      });
                      Navigator.pop(context);
                      //ref.read(animacionTarjeta.notifier).state = false;
                    },
                    child:const Text('Crear Comentario', style: TextStyle( color:Colors.white)),),
                ],),
              ),);
            },
            child: const BotonRedondo(hijo: Icon(Icons.add, color: Colors.black),radio: 30,)),
          const SizedBox(width: 10,),
          const Text('Comentarios ', style:  TextStyle(fontSize: 20)),
          const SizedBox(width: 10,),
          const Icon(Icons.messenger, color: Colors.black,)
        ],
      ),
      SizedBox(
        height: 250,
        child: ListView.builder(
          itemCount: comentarios.length,
          itemBuilder: (context, index) {
          return Padding(
            padding: const EdgeInsets.all(8.0),
            child: CajaComentario(
              indexx: ind,
              i: index,
              like: comentarios[index].like, 
              dislike: comentarios[index].dislike,
              fotoUsuario:comentarios[index].fotoUsuario,
              nombreUsuario:comentarios[index].nombreUsuario,
              contenido:comentarios[index].contenido
              ),
          );
        },)),
      Padding(
        padding: const EdgeInsets.all(8.0),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: [
           Column(
             children: [
              Text('$like'),
               BotonRedondo( radio: 40 ,hijo:  Icon(Icons.heart_broken_sharp, color: Theme.of(context).colorScheme.primary,), ),
             ],
           ),
            Column(
              children: [
                Text('$dislike'),
                BotonRedondo( radio: 40 ,hijo:  Icon(Icons.favorite, color: Theme.of(context).colorScheme.primary,), ),
              ],
            )
        ] ),
      )
    ],);
  }
}

class CajaComentario extends ConsumerWidget {
  const CajaComentario({
    super.key,
    required this.like,
    required this.dislike,
    required this.fotoUsuario,
    required this.nombreUsuario,
    required this.contenido,
    required this.indexx,
    required this.i,
  });

  final int like;
  final int dislike;
  final int indexx;
  final int i;
  final String fotoUsuario;
  final String nombreUsuario;
  final String contenido;

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Container(
      height: 150,
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
      child: Column(children: [
         Padding(
           padding: const EdgeInsets.all(8.0),
           child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
              Column(
                children: [
           GestureDetector(
            onTap: (){
              ref.read(listaApuntes.notifier).update((state) {
                 state[indexx].comentarios[i].dislike=state[indexx].comentarios[i].dislike+1;
                return [...state];
              } );
              
            },
            child: BotonRedondo(  radio: 30 ,hijo:  Icon(Icons.heart_broken_sharp, color: Theme.of(context).colorScheme.primary,), )),
                         Text('$like')
                        ],
                      ),
                       AvatarUsuario(imagen: fotoUsuario),
            const SizedBox(width: 5,),
            Text(nombreUsuario),
                       Column(
                         children: [
            BotonRedondo( radio: 30 ,hijo:  Icon(Icons.favorite, color: Theme.of(context).colorScheme.primary,), ),
            Text('$dislike'),
                         ],
                       )
                   ] ),
         ),
        Expanded(child: SingleChildScrollView(child: Text(contenido)))
      ],),
    );
  }
}

class PreTarjetaMateria extends StatelessWidget {
  const PreTarjetaMateria({
    super.key,
     this.materia,
     this.materiasInicio,
     this.index
  });

  final Materia? materia;
  final int? index;
  final List? materiasInicio;
  @override
  Widget build(BuildContext context) {
    
    return Stack(
            children: [
              Container(
                decoration: BoxDecoration(borderRadius: BorderRadius.circular(20), border: Border.all(width: 2, color:  Theme.of(context).colorScheme.secondary)),
                child: Column(
                  children: [
                    Container(
                      height: 50,
                      width: double.infinity,
                      decoration: BoxDecoration(borderRadius:const BorderRadius.only(topLeft: Radius.circular(18),topRight: Radius.circular(18)), color: Theme.of(context).colorScheme.secondary),
                      child: Padding(
                        padding: const EdgeInsets.all(2.0),
                        child: Text(materia!.nombre,style: TextStyle(fontSize: 18, color: Theme.of(context).dialogBackgroundColor), textAlign: TextAlign.center,),
                      ),
                    ),
                   
                    Expanded(child: Padding(
                      padding: const EdgeInsets.all(4.0),
                      child: Text(materia!.descripcion, maxLines: 3 , overflow: TextOverflow.ellipsis,),
                    )),
                    Container(
                      height: 50,
                      width: double.infinity,
                      decoration: BoxDecoration(borderRadius:const BorderRadius.only(bottomRight: Radius.circular(18),bottomLeft: Radius.circular(18)), color: Theme.of(context).colorScheme.secondary),
                      child: Text(materia!.profesor,style: TextStyle(fontSize: 18, color: Theme.of(context).dialogBackgroundColor), textAlign: TextAlign.center,),
                    ),
                ],),
              ),
            ],
          );
  }
}

class MateriaTarjeta extends StatelessWidget {
  const MateriaTarjeta({
    super.key,
    required this.materia,
  });

  final Materia materia;
  @override
  Widget build(BuildContext context) {
    return Column(children: [
      const Text('Compañeros de Clases', style: TextStyle(fontSize: 18)),
       SizedBox(
          height: 60,
          width: double.infinity,
          child: ListView.builder(
            scrollDirection: Axis.horizontal,
            itemCount: materia.integrantes.length,
            itemBuilder: (context, i) {
              return Padding(padding:const  EdgeInsets.all(8),
              child: materia.integrantes[i].imagen.isEmpty? 
              const Icon(Icons.person)
              :  ClipRRect(
              borderRadius: BorderRadius.circular(500),
              child: Image.network(materia.integrantes[i].imagen,
              errorBuilder: (context, error, stackTrace) => const Icon(Icons.person, color:Colors.black),
              ),
              ));
          },),
        ),
        const Text('Clases', style: TextStyle(fontSize: 18)),
        Expanded(
          
          child: ListView.builder(
            scrollDirection: Axis.vertical,
            itemCount: materia.clases.length,
            itemBuilder: (context, i) {
              return Padding(padding:const  EdgeInsets.all(8),
              child: Container(
                width: 140,
                height: 30,
                decoration: BoxDecoration(borderRadius: BorderRadius.circular(50), color:Colors.purple),
                child: Center(child: Text( materia.clases[i].fecha, textAlign: TextAlign.center, style: const TextStyle(color: Colors.white, fontSize: 16))),
              ) );
          },),
           
        ),
        const Text('Recursos', style: TextStyle(fontSize: 18),),
         SizedBox(
          height: 150,
          width: double.infinity,
          child: ListView.builder(
            scrollDirection: Axis.horizontal,
            itemBuilder: (context, index) {
            return Padding(
              padding: const EdgeInsets.all(8.0),
              child: Container(
                width: 150,
                height: 150,
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(20),
                  border: Border.all(width: 2, color: Colors.black)
                  ),
                child: Center(child:Icon(Icons.safety_check, color: Colors.black))
              ),
            );
          },)
         )
    ],);
  }
}


class PreApunteTarjeta extends StatelessWidget {
  const PreApunteTarjeta({
    super.key,
    required this.sePreciona, required this.materia, required this.fotoUsuario, required this.fecha, required this.contenido,
  });

  final Function sePreciona;
  final String materia;
  final String fotoUsuario;
  final String fecha;
  final String contenido;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: sePreciona(),
      child: Padding(
        padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
        child: Container(
          height: 150,
          width: 150,
          decoration: BoxDecoration(borderRadius: BorderRadius.circular(15),
           color: const Color.fromARGB(255, 124, 193, 250),),
           child: Column(children: [
              Padding(
                padding: const EdgeInsets.all(2.0),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceAround,
                  children: [
                    SizedBox(
                      width:100, child: Text(materia,maxLines: 2 , overflow: TextOverflow.ellipsis)),
                     SizedBox(
                      width: 40,
                      height:40,
                       child: ClipRRect(
                          borderRadius: BorderRadius.circular(500),
                          child: Image.network(fotoUsuario,
                          errorBuilder: (context, error, stackTrace) => const Icon(Icons.person, color:Colors.black),
                          ) ),
                     )
                  ],
                ),
              ),
              Text(fecha),
              Padding(
                padding: const EdgeInsets.all(2.0),
                child: Expanded(child: Text(contenido, maxLines: 3, overflow: TextOverflow.ellipsis,),),
              ),
              // Padding(
              //   padding: const EdgeInsets.all(8.0),
              //   child: SizedBox(
              //     height: 50,
              //     width: 140,
              //     child: ListView.builder(
              //       itemCount: 10,
              //       scrollDirection: Axis.horizontal,
              //       itemBuilder: (context, index) {
              //       return Padding(
              //         padding: const EdgeInsets.all(2.0),
              //         child: Container(
              //           height: 50,
              //           width:50,
              //         decoration: BoxDecoration(
              //                 borderRadius: BorderRadius.circular(10),
              //                 color: Colors.white,
              //                 border: Border.all(
              //                         color: const Color.fromARGB(255, 61, 60, 60),
              //                         width: 2,
              //                 ),
              //               ),
              //                 child:  Image.network(fotoUsuario,
              //                         errorBuilder: (context, error, stackTrace) => const Icon(Icons.notes_rounded, color:Colors.black),
              //         )),
              //       );
              //     },),
              //   ),
              // )
           ],)

           ) ,  
      ),
    );
  }
}
