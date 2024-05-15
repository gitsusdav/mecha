import 'package:animate_do/animate_do.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/configuraciones/codigo_cpp.dart';
import 'package:mecha_app/presentation/dibujables/barra_de_navegacion.dart';
import 'package:mecha_app/presentation/pantallas/actualizaciones.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/menu_lateral.dart';
import 'package:mecha_app/presentation/widgets/tarjeta_completa.dart';

class PantallaBase extends ConsumerWidget {
  const PantallaBase({super.key});

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    final bool mostrarTarjeta = ref.watch(animacionTarjeta);
    final String tituloTarjeta = ref.watch(selectionTarjeta);
    final Widget contenido = ref.watch(contenidoTarjeta);
    final Size size =MediaQuery.of(context).size;
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
              scrollDirection: Axis.horizontal,
              itemBuilder: (context, index) {
              return ApunteTarjeta( 
                sePreciona: ()=> (){
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
            child: ListView.builder(
              scrollDirection: Axis.horizontal,
              itemBuilder: (context, index) {
              return GestureDetector(
                onTap: (){
                  ref.read(selectionTarjeta.notifier).state='Materia';
                  ref.read(animacionTarjeta.notifier).state = true;
                  ref.read(contenidoTarjeta.notifier).state= Column(children: [Text('Nombre de la materia'),
                    Text('ayuden xD')
                  ],);
                },
                child: Padding(
                  padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
                  child: Container(
                    height: 180,
                    width: 180,
                    decoration: BoxDecoration(borderRadius: BorderRadius.circular(15),
                    border: Border.all(width: 2, color: const Color.fromARGB(255, 86, 182, 30)),
                     color: Colors.white,),
                     child: Column(children: [
                      Container(
                        width: double.infinity,
                        decoration: BoxDecoration(borderRadius: BorderRadius.only(topLeft: Radius.circular(13), topRight: Radius.circular(13)), color: Theme.of(context).colorScheme.secondary ),
                        child: Text('Nombre de la materia \n en dos lineas', style: TextStyle(color: Colors.white), textAlign: TextAlign.center,))
                     ],),
                     ) ,
                   
                ),
              );
            },),
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
            child: ListView.builder(
              scrollDirection: Axis.horizontal,
              itemBuilder: (context, index) {
              return GestureDetector(
                onTap: (){
                  ref.read(selectionTarjeta.notifier).state='Clase';
                 ref.read(animacionTarjeta.notifier).state = true;
                },
                child: Padding(
                  padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
                  child: Container(
                    height: 50,
                    width: 140,
                    decoration: BoxDecoration(borderRadius: BorderRadius.circular(50),
                    border: Border.all(width: 2, color: const Color.fromARGB(255, 126, 30, 182)),
                     color: Colors.white,),
                     ) ,
                   
                ),
              );
            },),
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
     floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
      floatingActionButton: Stack(
        children: [
          Positioned(
            left: 0,
            right: 0,
            bottom: 0,
            child: SizedBox(
              height: 85,
              width: double.infinity,
              child: CustomPaint(
                  size: Size.infinite, painter: BarraNavegacion(color: Theme.of(context).secondaryHeaderColor)),
            ),
          ),
          Positioned(
            bottom: 50,
            left: size.width / 2 - 29,
            child: GestureDetector(
              onTap: (){
                print('Crean apunte');
              },
              child: Container(
                    height: 60.0,
                    width: 58.0,
                    decoration: const BoxDecoration(
                        shape: BoxShape.circle, color: Colors.blue),
                    child: const Center(
                      child: Icon(
                              Icons.note_add,
                              size: 40,
                              color: Colors.white,
                            )
                          
                    ),
                  ),
            ),
          ),
        ],
      ),
    );
  }
}


class ApunteTarjeta extends StatelessWidget {
  const ApunteTarjeta({
    super.key,
    required this.sePreciona,
  });

  final Function sePreciona;

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
           ) ,  
      ),
    );
  }
}
