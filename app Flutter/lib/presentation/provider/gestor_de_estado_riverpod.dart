import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:mecha_app/configuraciones/tema_claro.dart';
import 'package:mecha_app/controladores/leer_escribir_materias.dart';
import 'package:mecha_app/modelos/apunte_completo.dart';
import 'package:mecha_app/modelos/clase.dart';
import 'package:mecha_app/modelos/comentarios_completos.dart';
import 'package:mecha_app/modelos/materia_mecha.dart';

final temaActual = StateProvider<ThemeData>((ref) {
  return TemaClaro.tema;
});

// Estados Pantalla Inicio Sesion
final entradaCorreo = StateProvider<TextEditingController>((ref) => TextEditingController());
final entradaClave = StateProvider<TextEditingController>((ref) => TextEditingController());
final entradaNombre = StateProvider<TextEditingController>((ref) => TextEditingController());
final esVisibleClave = StateProvider<bool>((ref) => true);

final animacionInicio = StateProvider<bool>((ref) => false);
final animacionRegistro = StateProvider<bool>((ref) => false);
final animacionCargando = StateProvider<bool>((ref) => false);
final animacionAlerta = StateProvider<bool>((ref) => false);

final mostrarMensaje = StateProvider<String>((ref) => '');

// Estados Pantalla Base
final selectionTarjeta = StateProvider<String>((ref) => '');
final animacionTarjeta = StateProvider<bool>((ref) => false);
final contenidoTarjeta = StateProvider<Widget>((ref) => const SizedBox());

// Estados Pantalla Clase
final animacionTarjetaApunte = StateProvider<bool>((ref) => false);
final animacionComentariosApunte = StateProvider<bool>((ref) => false);

// Estados Pantalla Configuracion Inicial

final mostrarCrearInstituto = StateProvider<bool>((ref) => false); 
final crearInstitutoNombre = StateProvider<TextEditingController>((ref) => TextEditingController()); 

// Estados Inicio Crear Periodo

final instritutoSelecionado = StateProvider<String>((ref) => '');
final crearPeriodoNombre = StateProvider<TextEditingController>((ref) => TextEditingController()); 
final crearPeriodoFacultad = StateProvider<TextEditingController>((ref) => TextEditingController()); 

// Estados Inicio Agregar Materias

final periodoSelecionado = StateProvider<String>((ref) => '');
final materiasSelecionada = StateProvider<List<Materia>>((ref) => []);
final crearMateriaNombre = StateProvider<TextEditingController>((ref) => TextEditingController()); 
final crearMateriaProfesor = StateProvider<TextEditingController>((ref) => TextEditingController()); 
final materiasBasedeDatos = FutureProvider<List<Materia>>((ref) async {
  return await obtenerMateria(ref.watch(periodoSelecionado), ref.watch(instritutoSelecionado));
});

final materiaAgregada = StateProvider<Materia?>((ref) => null);

// Pantalla Base 

final clasesMaterias = StateProvider<List<Clase>>((ref) => []);

//para video 
final listaclases = StateProvider<List<String>>((ref) => ['15-05-2024\nMiercoles','20-05-2024\nLunes','22-05-2024\nMiercoles']);

final crearApunte = StateProvider<TextEditingController>((ref) => TextEditingController() );

final crearComentario = StateProvider<TextEditingController>((ref) => TextEditingController() );

final listaApuntes  = StateProvider<List<ApunteCompleto>>((ref) => [
ApunteCompleto(
  seguir: true,
  like: 10,
  dislike: 2,
  fecha: '16-05-2024',
  materia: 'Matemáticas Discretas',
  comentarios: [
    ComentariosCompletos(contenido: '¡Increíble explicación sobre la teoría de grafos! Me encantó cómo se aplicaron los conceptos en problemas del mundo real. ¡Definitivamente amplió mi comprensión de las estructuras discretas! 👏', dislike:0, like: 0, fotoUsuario: 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTzCdPHgK4ZaypnoGaHe5wXYaBIsQEmLTZ5hg&usqp=CAU', nombreUsuario: 'Lorena'),
    
  ],
  nombreUsuario: 'Pedro',
  fotoUsuario: 'https://p1.pxfuel.com/preview/914/252/853/young-man-profile-man-dream-boy.jpg',
  contenido: 'En la clase de hoy de Matemáticas Discretas, profundizamos en la teoría de grafos y sus aplicaciones en la informática. ¡Los conceptos fueron fascinantes!',
),ApunteCompleto(
  seguir: false,
  like: 20,
  dislike: 4,
    fecha: '16-05-2024',
  materia: 'Arquitectura de computadoras',
  comentarios: [
    ComentariosCompletos(contenido: 'Contenido 2', dislike:0, like: 0, fotoUsuario: 'url2', nombreUsuario: 'Usuario 2'),
  ],
  nombreUsuario: 'Andrea',
  fotoUsuario: 'url2',
  contenido: 'Qué emocionante fue la discusión sobre la arquitectura de computadoras en la materia de Arquitectura de Computadoras! ¡Aprendí mucho sobre el diseño de sistemas',
),ApunteCompleto(
  seguir: true,
  like: 30,
  dislike: 6,
    fecha: '16-05-2024',
  materia: 'Redes de Computadoras',
  comentarios: [
    ComentariosCompletos(contenido: 'Contenido 3', dislike:0, like: 0, fotoUsuario: 'url3', nombreUsuario: 'Usuario 3'),
  ],
  nombreUsuario: 'Toñito',
  fotoUsuario: 'url3',
  contenido: 'Hoy en la clase de Redes de Computadoras, aprendimos sobre protocolos de enrutamiento. ¡Es increíble cómo funciona la comunicación entre dispositivos en una red',
),ApunteCompleto(
  seguir: false,
  like: 40,
  dislike: 8,
    fecha: '16-05-2024',
  materia: 'Inteligencia Artificial',
  comentarios: [
    ComentariosCompletos(contenido: 'Contenido 4', dislike:0, like: 0, fotoUsuario: 'url4', nombreUsuario: 'Usuario 4'),
  ],
  nombreUsuario: 'Lucia',
  fotoUsuario: 'url4',
  contenido: 'En la clase de hoy de Inteligencia Artificial, discutimos sobre algoritmos de búsqueda heurística. ¡Es increíble cómo los agentes pueden tomar decisiones inteligentes',
),ApunteCompleto(
  seguir: true,
  like: 50,
  dislike: 10,
    fecha: '16-05-2024',
  materia: 'Seguridad Informática',
  comentarios: [
    ComentariosCompletos(contenido: 'Contenido 5', dislike:0, like: 0, fotoUsuario: 'url5', nombreUsuario: 'Usuario 5'),
  ],
  nombreUsuario: 'Julian',
  fotoUsuario: 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTjnDxL8BCQP3GFx1HVHTuKScg2i0SYyVBjzg&usqp=CAU',
  contenido: '¡En la clase de hoy de Seguridad Informática, aprendimos sobre técnicas de cifrado y criptografía! ¡La protección de la información es fundamental en el mundo digital!',
)

]); 

