import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';

class MenuLateral extends ConsumerWidget {
  const MenuLateral({
    super.key, required this.size,
  });
  final Size size;

  @override
  Widget build(BuildContext context, WidgetRef ref) {
    return Container(height: size.height,width: size.width*0.75, 
      decoration:  BoxDecoration(
      borderRadius:const BorderRadius.only(topRight: Radius.circular(20),bottomRight: Radius.circular(20)), color: Theme.of(context).primaryColor),
      child: SingleChildScrollView(
        child: Column(
        
          children: [
        
          const SizedBox(height: 40),
          Container(
            height: 100,
            width: 100,
            decoration: const BoxDecoration(shape: BoxShape.circle, color: Colors.amber),
          ),
          const SizedBox(height: 20),
          const Text('Nombre del usuario', style: TextStyle(fontSize: 20, color: Colors.white),),
          const SizedBox(height: 20),
          const Divider(), 
          Padding(
            padding: const EdgeInsets.only(left:10.0 , right: 10.0),
            child: MaterialButton(
              color: Theme.of(context).primaryColor,
              onPressed: (){
                
              },
              child:const ListTile(leading:  Icon(Icons.poll_rounded,color: Colors.white, size: 40,),title:  Text('Todas tus materias',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0, top:10, right: 10.0),
            child: MaterialButton(
            
              color: Theme.of(context).primaryColor,
              onPressed: (){
                
              },
              child:const ListTile(leading:  Icon(Icons.chat,color: Colors.white, size: 40,),title:  Text('Historial de materias',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0, top:10, right: 10.0),
            child: MaterialButton(
            
              color: Theme.of(context).primaryColor,
              onPressed: (){
         
              },
              child:const ListTile(leading:  Icon(Icons.search,color: Colors.white, size: 40,),title:  Text('Buscar apuntes',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0, top:10, right: 10.0),
            child: MaterialButton(
            
              color: Theme.of(context).primaryColor,
              onPressed: (){
            
              },
              child:const ListTile(leading:  Icon(Icons.task,color: Colors.white, size: 40,),title:  Text('Todas tus evaluaciones',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
        
          Padding(
            padding: const EdgeInsets.only(left: 10.0, top: 10),
            child: MaterialButton(
        color: Theme.of(context).primaryColor,
        onPressed: () {
         
        },
        child: const Text('Cerrar Sesión',style:  TextStyle(color:Colors.white, fontSize: 20), )
          ),
        ),
        
             const SizedBox(height: 20)
            ]),
      ),);
  }
}
