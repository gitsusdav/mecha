class Instituto {
  String nombre;
  String descripcion;
  String codigo;
  bool privado;
  int miembros;

  Instituto({
    required this.nombre,
    required this.descripcion,
    required this.codigo,
    required this.privado,
    required this.miembros,
  });
  
  Instituto.fromMap(Map<String, dynamic> map)
      : nombre = map['nombre'],
        descripcion = map['descripcion'],
        codigo = map['codigo'],
        privado = map['privado'],
        miembros = map['miembros'];

  Map<String, dynamic> toMap() {
    return {
      'nombre': nombre,
      'descripcion': descripcion,
      'codigo': codigo,
      'privado': privado,
      'miembros': miembros,
    };
  }
}