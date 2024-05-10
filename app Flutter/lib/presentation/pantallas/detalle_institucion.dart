import 'package:flutter/material.dart';
import 'package:mecha_app/presentation/pantallas/historial_periodo.dart';
import 'package:mecha_app/presentation/widgets/boton_primario.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';

class PantallaDetalleInstitucion extends StatelessWidget {
  const PantallaDetalleInstitucion({super.key, required this.institucion});
  final String institucion;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.tertiary,
        title: Text('Sobre $institucion', style: TextStyle(color: Theme.of(context).secondaryHeaderColor),),
        leading: IconButton(
          icon: Icon(Icons.arrow_back_ios_new_rounded, color: Theme.of(context).secondaryHeaderColor ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),// Icons.manage_search_outlined assignment_add backup_sharp 
        actions: [Padding(
          padding: const EdgeInsets.only(right: 8.0),
          child: IconButton(onPressed: (){}, icon:const Icon(Icons.manage_search_outlined, color: Colors.white,)),
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
            const Align(
              alignment: Alignment.centerLeft,
              child:  Text('Periodos pasados registrados en Mecha')),
            SizedBox(
              height: 40,
              child: Center(
                child: ListView.builder(
                  shrinkWrap: true, 
                  scrollDirection: Axis.horizontal,
                  itemCount: 5,
                  itemBuilder: (context, index) {
                  return GestureDetector(
                    onTap: (){
                      Navigator.push(context, MaterialPageRoute(builder: (context) => PantallaHistorialPeriodo(periodo: 'A 20${index+23-4}',),));
                    },
                    child: Padding(
                      padding: const EdgeInsets.only(left: 8.0, top: 8, bottom: 8),
                      child: Container(
                        width: 80,
                        
                        decoration: BoxDecoration(borderRadius: BorderRadius.circular(50),
                        color:const Color.fromARGB(255, 177, 114, 31),),
                        child:  Center(child: Text('A 20${index+23-4}', style:const TextStyle(color: Colors.white, fontSize: 18), )),) ,
                      
                    ),
                  );
                },),)),
                const Text('Tu periodo en curso actual'),
              Container(
                  width: 80,
                  decoration: BoxDecoration(borderRadius: BorderRadius.circular(50),
                  color:const Color.fromARGB(255, 248, 162, 50),),
                  child: const Center(child: Text('A 2024', style: TextStyle(color: Colors.white, fontSize: 18), )),) ,
              const Text('Tus materias en curso actual'),
              SizedBox(height: 190,
                child: Row(
                  children: [
                Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: BotonPrimario(contenido: Icon(Icons.add_circle_outline_rounded, color: Theme.of(context).primaryColor,), sePreciona: (){}),
                ),
                Expanded(
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
              ],
            ),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                EntradaTexto(entradaControlador: TextEditingController(), tipo: 'Buscar tema'),
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