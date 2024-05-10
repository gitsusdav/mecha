import 'package:animate_do/animate_do.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/presentation/pantallas/base.dart';
import 'package:mecha_app/presentation/pantallas/recorrigo_nuevo_usuario.dart';
import 'package:mecha_app/presentation/provider/gestor_de_estado_riverpod.dart';
import 'package:mecha_app/presentation/widgets/boton_primario.dart';
import 'package:mecha_app/presentation/widgets/cargando.dart';
import 'package:mecha_app/presentation/widgets/entrada_texto.dart';
import 'package:mecha_app/utilidades/iniciar_clave_correo.dart';
import 'package:mecha_app/utilidades/iniciar_con_google.dart';

class PantallaInicioSesion extends ConsumerStatefulWidget {
  const PantallaInicioSesion({super.key});

  @override
  PantallaInicioSesionState createState() => PantallaInicioSesionState();
}

class PantallaInicioSesionState extends ConsumerState<PantallaInicioSesion> {
  late AnimationController animacionInicio;
  late AnimationController animacionRegistro;
  late AnimationController animacionCargando;

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
                        animacionInicio.reset();
                        animacionInicio.forward();
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
                          animacionRegistro.reset();
                          animacionRegistro.forward();
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
                  animate: false,
                  manualTrigger: true,
                  controller: (animacionControl) {
                    animacionInicio = animacionControl;
                  },
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
                                animacionInicio.reverse();
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
                                  Navigator.pushReplacement(context,MaterialPageRoute(builder: (context) => const PantallaRecorridoNuevoUsuario(),));
                                // await iniciar( entradaCorreoControlador.text, entradaClaveControlador.text);
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
                                  animacionCargando.forward();
                                  inciarConGoogle(context);
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
                  animate: false,
                  manualTrigger: true,
                  controller: (animacionControl) {
                    animacionRegistro = animacionControl;
                  },
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
                                animacionRegistro.reverse();
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
                                onPressed: () {},
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
                                  animacionCargando.forward();
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
                animate: false,
                manualTrigger: true,
                controller: (controller) {
                  animacionCargando = controller;
                },
                child: GestureDetector(
                  onTap: (){
                    animacionCargando.reset();
                  },
                  child: const Cargando()))
            ],
          ),
        ),
      ),
    );
  }

Future iniciar(String correo, String clave) async{
 if (!RegExp(r"^[a-zA-Z0-9.a-zA-Z0-9.!#$%&'*+-/=?^_`{|}~]+@[a-zA-Z0-9]+\.[a-zA-Z]+")
      .hasMatch(correo)) {
    // ref.read(showMensaje.notifier).state =
    //     'No es un correo valido';
    // controllerAnim.showMensaje.reset();
    // controllerAnim.showMensaje.forward();
    return;
  }
  if (clave.length < 6) {
    // ref.read(showMensaje.notifier).state =
    //     'La clave debe ser mayor a 6 digitos 🧐';
    // controllerAnim.showMensaje.reset();
    // controllerAnim.showMensaje.forward();
    return;
  }
  // controllerAnim.showalerta.reset(); // cargando
  // controllerAnim.showalerta.forward(); 
  final yaInicio = await iniciarSesion(correo, clave);
  if (context.mounted && yaInicio) {
    Navigator.push(context, MaterialPageRoute(builder: (context) => const PantallaBase(),));
  } else {
    if (!yaInicio) {
    //   controllerAnim.showalerta.reverse();
    //   ref.read(showMensaje.notifier).state =
    //       'Usuario o clave incorrectos 🚿';
    //   controllerAnim.showMensaje.reset();
    //   controllerAnim.showMensaje.forward();
    // } else {
    //   controllerAnim.showalerta.reverse();
    //   ref.read(showMensaje.notifier).state =
    //       'Sucedió un error, Intenta de nuevo 😉';
    //   controllerAnim.showMensaje.reset();
    //   controllerAnim.showMensaje.forward();
    }
  }
  }
}

