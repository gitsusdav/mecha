import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/presentation/pantallas/configuracion_del_usuario.dart';
import 'package:mecha_app/presentation/pantallas/inicio_sesion.dart';
import 'package:mecha_app/presentation/pantallas/selecion_institucion.dart';
import 'package:mecha_app/presentation/pantallas/todas_las_materias.dart';
import 'package:mecha_app/controladores/iniciar_con_google.dart';

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
          GestureDetector(
            onTap: (){
              Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaConfiguracionDelUsuario(),));
            },
            child: Container(
              height: 100,
              width: 100,
              decoration: const BoxDecoration(shape: BoxShape.circle, color: Colors.amber),
            ),
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
                Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaSelecionInstitucion(),));
              },
              child:const ListTile(leading:  Icon(Icons.business_rounded,color: Colors.white, size: 40,),title:  Text('Cambiar de Instituto',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0 ,top:10, right: 10.0),
            child: MaterialButton(
              color: Theme.of(context).primaryColor,
              onPressed: (){
                Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaTodasLasMaterias(),));
              },
              child:const ListTile(leading:  Icon(Icons.auto_stories_rounded,color: Colors.white, size: 40,),title:  Text('Todas mis materias',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0, top:10, right: 10.0),
            child: MaterialButton(
            
              color: Theme.of(context).primaryColor,
              onPressed: (){
                
              },
              child:const ListTile(leading:  Icon(Icons.account_tree_rounded,color: Colors.white, size: 40,),title:  Text('Registro de periodos',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0, top:10, right: 10.0),
            child: MaterialButton(
            
              color: Theme.of(context).primaryColor,
              onPressed: (){
         
              },
              child:const ListTile(leading:  Icon(Icons.search,color: Colors.white, size: 40,),title:  Text('Buscar tema',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
          Padding(
            padding: const EdgeInsets.only(left:10.0, top:10, right: 10.0),
            child: MaterialButton(
            
              color: Theme.of(context).primaryColor,
              onPressed: (){
            
              },
              child:const ListTile(leading:  Icon(Icons.task,color: Colors.white, size: 40,),title:  Text('Todas mis evaluaciones',style: TextStyle(color:Colors.white, fontSize: 20),)),
            ),
          ),
        
          Padding(
            padding: const EdgeInsets.only(left: 10.0, top: 10),
            child: MaterialButton(
        color: Theme.of(context).primaryColor,
        onPressed: ()async {
          await cerrarSesion();
          if(context.mounted){
            Navigator.pushReplacement(context, MaterialPageRoute(builder: (context) => const PantallaInicioSesion(),));
          }
        },
        child: const Text('Cerrar Sesión',style:  TextStyle(color:Colors.white, fontSize: 20), )
          ),
        ),
        
             const SizedBox(height: 20)
            ]),
      ),);
  }
}
