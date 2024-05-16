// ignore_for_file: use_build_context_synchronously

import 'package:animate_do/animate_do.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/presentation/pantallas/base.dart';
import 'package:mecha_app/presentation/pantallas/recorrigo_nuevo_usuario.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/boton_primario.dart';
import 'package:mecha_app/presentation/widgets/cargando.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';
import 'package:mecha_app/controladores/iniciar_clave_correo.dart';
import 'package:mecha_app/controladores/iniciar_con_google.dart';

class PantallaInicioSesion extends ConsumerStatefulWidget {
  const PantallaInicioSesion({super.key});

  @override
  PantallaInicioSesionState createState() => PantallaInicioSesionState();
}

class PantallaInicioSesionState extends ConsumerState<PantallaInicioSesion> {

  @override
  Widget build(BuildContext context) {
    final Size size = MediaQuery.of(context).size;
    final TextEditingController entradaCorreoControlador =ref.watch(entradaCorreo);
    final TextEditingController entradaClaveControlador =ref.watch(entradaClave);
    final TextEditingController entradaNombreControlador =ref.watch(entradaNombre);
    final bool mostrarClave = ref.watch(esVisibleClave);
    return Scaffold(
      body: SingleChildScrollView(
        physics: const NeverScrollableScrollPhysics(),
        child: SizedBox(
          height: size.height,
          child: Stack(
            children: [
              Center(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: [
                    SizedBox(height: size.height * 0.10),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
        const Column(
          children: [
            Text('Bienvenido a',style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold)),
            Text('Mecha',style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold)),
          ],
        ),
                        SizedBox(
                          height: 80,
                          width: 80,
                          child: Image.asset('assets/mecha-logo.jpg'),
                        ),
                      ],
                    ),
        SizedBox(height: size.height * 0.13),
                    MaterialButton(
                      onPressed: () {
                       ref.read(animacionInicio.notifier).state=true;
                      },
                      color: Colors.white,
                      elevation: 5,
                      child: const Text('Iniciar Sesión'),
                    ),
        SizedBox(height: size.height * 0.05),
                    const Text('¿No estás registrado aún?'),
                    SizedBox(height: size.height * 0.001),
                    TextButton(
                        onPressed: () {
                          ref.read(animacionRegistro.notifier).state=true;
                        },
                        child: const Text('Regístrate aquí'))
                  ],
                ),
              ),
              Positioned(
                left: 0,
                right: 0,
                bottom: 0,
                child: FadeInUpBig(
                  animate: ref.watch(animacionInicio),
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
                        SizedBox(height: size.height * 0.015),
                        Row(
                          children: [
                            MaterialButton(
                              height: 60,
                              shape: const CircleBorder(),
                              onPressed: () {
                                ref.read(animacionInicio.notifier).state=false;
                                FocusScope.of(context).requestFocus(FocusNode());
                              },
                              child: const Icon(
                                Icons.close_rounded,
                                color: Colors.black,
                              ),
                            ),
                          ],
                        ),
                        SingleChildScrollView(
                          child: Column(
                            children: [
                              SizedBox(height: size.height * 0.020),
                              const Text('Iniciar Sesión',
                                  style: TextStyle(fontSize: 20)),
                              SizedBox(height: size.height * 0.040),
                              EntradaTexto(
                                entradaControlador: entradaCorreoControlador,
                                tipo: 'Correo'),
                              SizedBox(height: size.height * 0.030),
                              EntradaTexto(
                                entradaControlador: entradaClaveControlador,
                                tipo: 'Clave',
                                mostrarClave: mostrarClave,
                                mostrar: () => () { ref.read(esVisibleClave.notifier).update((state) => !state);}),
                              SizedBox(height: size.height * 0.040),
                              MaterialButton(
                                color: Colors.black,
                                splashColor: Colors.white,
                                onPressed: () async {
                                  ref.read(animacionCargando.notifier).state = true;
                                 bool completado = await iniciar( entradaCorreoControlador.text, entradaClaveControlador.text,ref,false,null);
                                  if(completado){
                                        Navigator.pushReplacement(context,MaterialPageRoute(builder: (context) => const PantallaBase(),));
                                  }else{
                                    showDialog(context: context, builder: (context) => Dialog(
                                      child: Padding(
                                        padding: const EdgeInsets.only(top: 40.0, bottom: 40, left: 20,right: 20),
                                        child: Text(ref.watch(mostrarMensaje), textAlign: TextAlign.center),
                                      ),
                                    ),);
                                    ref.read(animacionCargando.notifier).state = false;
                                  }
                                 
                                },
                                child: const Text(
                                  'Entrar',
                                  style: TextStyle(color: Colors.white),
                                ),
                              ),
                              SizedBox(height: size.height * 0.030),
                              Row(
                                mainAxisAlignment: MainAxisAlignment.center,
                                children: [
                                  Container(
                                    height: 1,
                                    width: 40,
                                    color:const Color.fromARGB(155, 61, 60, 60),
                                  ),
                                  const Text('tambien puedes iniciar con'),
                                  Container(
                                    height: 1,
                                    width: 40,
                                    color: const Color.fromARGB(155, 61, 60, 60),
                                  ),
                                ],
                              ),
                              SizedBox(height: size.height * 0.030),
                              BotonPrimario(
                                contenido:  Image.asset('assets/google_logo.png'),
                                sePreciona: () => () {
                                  inciarConGoogle(context);
                                  ref.read(animacionCargando.notifier).state=true;
                                }
                              ),
                              SizedBox(height: size.height * 0.050),
                              const Text('Al iniciar sesión, aceptas nuestros'),
                              SizedBox(height: size.height * 0.001),
                              TextButton(
                                  onPressed: () {},
                                  child: const Text('Términos y Condiciones'))
                            ],
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
              Positioned(
                left: 0,
                right: 0,
                bottom: 0,
                child: FadeInUpBig(
                  animate:  ref.watch(animacionRegistro),
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
                        SizedBox(height: size.height * 0.015),
                        Row(
                          children: [
                            MaterialButton(
                              height: 60,
                              shape: const CircleBorder(),
                              onPressed: () {
                                ref.read(animacionRegistro.notifier).state=false;
                                FocusScope.of(context).requestFocus(FocusNode());
                              },
                              child: const Icon(
                                Icons.close_rounded,
                                color: Colors.black,
                              ),
                            ),
                          ],
                        ),
                         Expanded(
                            child: GestureDetector(
                              onTap: (){
                               
                                FocusScope.of(context).requestFocus(FocusNode());
                              },
                              child: SingleChildScrollView(
                              child: Column(
                                children: [
                              const Text('Nuevo Usuario',
                                  style: TextStyle(fontSize: 20)),
                              SizedBox(height: size.height * 0.040),
                              EntradaTexto(
                                entradaControlador: entradaNombreControlador,
                                tipo: 'Nombre',
                              ),
                              SizedBox(height: size.height * 0.030),
                              EntradaTexto(
                                  entradaControlador: entradaCorreoControlador,
                                  tipo: 'Correo'),
                              SizedBox(height: size.height * 0.030),
                              EntradaTexto(
                                  entradaControlador: entradaClaveControlador,
                                  tipo: 'Clave',
                                  mostrarClave: mostrarClave,
                                  mostrar: () => () {
                                        ref.read(esVisibleClave.notifier).update((state) => !state);
                                      }),
                              SizedBox(height: size.height * 0.040),
                              MaterialButton(
                                color: Colors.black,
                                splashColor: Colors.white,
                                onPressed: ()async {
                                  ref.read(animacionCargando.notifier).state = true;
                                  bool completado = await iniciar(entradaCorreoControlador.text, entradaClaveControlador.text, ref,true, entradaNombreControlador.text );
                                  if(completado){
                                      Navigator.pushReplacement(context,MaterialPageRoute(builder: (context) => const PantallaRecorridoNuevoUsuario(),));
                                  }else{
                                    ref.read(animacionCargando.notifier).state = false;     
                                     showDialog(context: context, builder: (context) => Dialog(
                                      child: Padding(
                                          padding: const EdgeInsets.only(top: 40.0, bottom: 40, left: 20,right: 20),
                                        child: Text(ref.watch(mostrarMensaje), textAlign: TextAlign.center,),
                                      ),
                                    ),);
                                  }
                                },
                                child: const Text(
                                  'Registrar',
                                  style: TextStyle(color: Colors.white),
                                ),
                              ),
                              SizedBox(height: size.height * 0.030),
                              Row(
                                mainAxisAlignment: MainAxisAlignment.center,
                                children: [
                                  Container(
                                    height: 1,
                                    width: 40,
                                    color: const Color.fromARGB(155, 61, 60, 60),
                                  ),
                                  const Text('también puedes iniciar con'),
                                  Container(
                                    height: 1,
                                    width: 40,
                                    color: const Color.fromARGB(155, 61, 60, 60),
                                  ),
                                ],
                              ),
                              SizedBox(height: size.height * 0.030),
                              BotonPrimario(
                                contenido: Image.asset('assets/google_logo.png'),
                                sePreciona: () => () {
                                //  animacionCargando.forward();
                                  inciarConGoogle(context);
                                }
                              ),
                              SizedBox(height: size.height * 0.050),
                              const Text('Si te registras, aceptas nuestros'),
                              SizedBox(height: size.height * 0.001),
                              TextButton(
                                  onPressed: () {
                                
                                  },
                                  child: const Text('Términos y Condiciones')),
                              SizedBox(height: size.height * 0.2),    
                                ],
                              ),
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
              ZoomIn(
                animate: ref.watch(animacionCargando),
                child: const Cargando())
            ],
          ),
        ),
      ),
    );
  }

Future<bool> iniciar(String correo, String clave, WidgetRef ref, bool registro, String? nombre) async{
 if (!RegExp(r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
      .hasMatch(correo)) {
    ref.read(mostrarMensaje.notifier).state = 'No es un correo valido';
    ref.read(animacionCargando.notifier).state = false;
    return false;
  }
  if (clave.length < 6) {
    ref.read(mostrarMensaje.notifier).state = 'La clave debe ser mayor a 6 digitos 🧐';
    ref.read(animacionCargando.notifier).state = false;
    return false;
  }
  if(!registro){
    final yaInicio = await iniciarSesion(correo, clave);
    if (context.mounted && yaInicio) {
      Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaBase(),));
    } else {
      if (!yaInicio) {
        ref.read(mostrarMensaje.notifier).state = 'Usuario o clave incorrectos 🚿';
        ref.read(animacionCargando.notifier).state = false;
      }
    }
  }else{
    final registroCompleto = await registrarUsuario(correo, clave, nombre!);
    if(registroCompleto.isEmpty){
      return true;
    }
    ref.read(mostrarMensaje.notifier).state = registroCompleto;
    return false;
  }
  return false;
  }
}

