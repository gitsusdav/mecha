import 'package:flutter/material.dart';
import 'package:flutter_swiper_view/flutter_swiper_view.dart';
import 'package:mecha_app/presentation/pantallas/configuracion_inicial.dart';

class PantallaRecorridoNuevoUsuario extends StatelessWidget {
  const PantallaRecorridoNuevoUsuario({super.key});
  static List<Widget> tarjetasRecorido= [
    Padding(
      padding: const EdgeInsets.all(8.0),
      child: Container(
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
              blurRadius: 2,
              spreadRadius: 1,
            ),
            BoxShadow(
              color: Color.fromARGB(255, 255, 255, 255),
              offset: Offset(-1, -1),
              blurRadius: 3,
              spreadRadius: 1,
            )
          ]),
        child: const Center(
          child:  Padding(
            padding: EdgeInsets.all(8.0),
            child: Text('Comparte tus apuntes de clases con tus compañeros y con las futuras generaciones de estudiantes', style: TextStyle(fontSize: 20), textAlign: TextAlign.center,),
          ),
        )),
    ),
    Padding(
      padding: const EdgeInsets.all(8.0),
      child: Container(
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
              blurRadius: 2,
              spreadRadius: 1,
            ),
            BoxShadow(
              color: Color.fromARGB(255, 255, 255, 255),
              offset: Offset(-1, -1),
              blurRadius: 3,
              spreadRadius: 1,
            )
          ]),
        child:  const Center(child: Text('Comparte tus apuntes de clases con tus compañeros y con las futuras generaciones de estudiantes', style: TextStyle(fontSize: 20), textAlign: TextAlign.center,))),
    ),
  ];
  @override
  Widget build(BuildContext context) {
    final Size size = MediaQuery.of(context).size;
    return Scaffold(
      appBar: AppBar(title: const Center(child: Text('Conoce lo que es Mecha',style: TextStyle(color: Colors.white), )),),
      body: Center(
        child: Column(children: [
          SizedBox(height: size.height*0.05,),
          SizedBox(
            height: size.width*0.5,
            width: size.width*0.5,
            child: Image.asset('assets/mecha-explicacion.jpg'),
          ),
           SizedBox(height: size.height*0.05,),
             SizedBox(
              height: size.height * 0.34,
              width: size.width*0.8,
               child: Swiper(
                  autoplay: true,
                  autoplayDelay: 2800,
                  curve: Curves.easeInQuart,
                  duration: 800,
                  itemBuilder: (BuildContext context, int index) {
                    return tarjetasRecorido[index];
                  },
                  itemCount: 2,
                  itemWidth: 300.0,
                  layout: SwiperLayout.STACK,
                ),
             ),
           MaterialButton(
            color: Theme.of(context).primaryColor,
            onPressed: (){
              Navigator.pushReplacement(context, MaterialPageRoute(builder: (context) => const PantallaConfiguracionInicial() ,));
           },
           child: const Text('Continuar', style: TextStyle(color: Colors.white),),)
        ],),
      ),
    );
  }
}