import 'package:flutter/material.dart';
import 'package:mecha_app/configuraciones/codigo_cpp.dart';
import 'package:mecha_app/presentation/widgets/menu_lateral.dart';

class PantallaBase extends StatelessWidget {
  const PantallaBase({super.key});

  @override
  Widget build(BuildContext context) {
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
          child: IconButton(onPressed: (){}, icon:const Icon(Icons.supervised_user_circle_rounded, color: Colors.white,)),
        )],
      ),
      drawer: Padding(
        padding: const EdgeInsets.symmetric(vertical: 40.0),
        child: MenuLateral(size: size,),
      ),
      body: Column(children: [
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
          return Padding(
            padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
            child: Container(
              height: 150,
              width: 150,
              decoration: BoxDecoration(borderRadius: BorderRadius.circular(15),
               color: const Color.fromARGB(255, 124, 193, 250),),
               ) ,
             
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
          return Padding(
            padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
            child: Container(
              height: 180,
              width: 180,
              decoration: BoxDecoration(borderRadius: BorderRadius.circular(15),
              border: Border.all(width: 2, color: const Color.fromARGB(255, 86, 182, 30)),
               color: Colors.white,),
               ) ,
             
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
          return Padding(
            padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
            child: Container(
              height: 70,
              width: 140,
              decoration: BoxDecoration(borderRadius: BorderRadius.circular(5),
              border: Border.all(width: 2, color: const Color.fromARGB(255, 126, 30, 182)),
               color: Colors.white,),
               ) ,
             
          );
        },),
        ),
      ],)
    );
  }
}
