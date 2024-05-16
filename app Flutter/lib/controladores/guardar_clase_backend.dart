import 'package:cloud_firestore/cloud_firestore.dart';

void guardarClase( String idMateria){
   CollectionReference subjects = FirebaseFirestore.instance.collection('materia');

  subjects
      .doc(idMateria)
      .update({
        'clases': FieldValue.arrayUnion([
          {
            'fecha': Timestamp.fromDate(DateTime.now()),
            'apuntes': [
              {
                'nombre': 'Nombre del apunte',
                'usuario': 'Nombre del usuario',
                'comentarios': [
                  // Aquí puedes agregar los comentarios
                ],
              },
            ],
          },
        ]),
      })
      .then((value) => print("Clase añadida"));
}