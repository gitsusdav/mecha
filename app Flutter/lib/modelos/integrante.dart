class Integrante{
  String nombre='';
  String imagen = '';
  String id='';

  Integrante({
    required this.nombre,
    required this.imagen,
    required this.id,
  });

  Integrante.fromMap(Map<String, dynamic> map)
      : nombre = map['nombre'],
        imagen = map['imagen'],
        id = map['id'];

  Map<String, dynamic> toMap() {
    return {
      'nombre': nombre,
      'imagen': imagen,
      'id': id,
    };
  }
  @override
  bool operator ==(Object other) {
    if (identical(this, other)) return true;

    return other is Integrante &&
        other.nombre == nombre &&
        other.imagen == imagen &&
        other.id == id;
  }
  @override
  int get hashCode {
    return nombre.hashCode ^
        imagen.hashCode ^
        id.hashCode;
  } 
  
}