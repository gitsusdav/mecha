class Instituto {
  String nombre;
  String descripcion;
  String codigo;
  String logo;
  String color='000000';
  bool privado;
  int miembros;
  bool agregar = false;

  Instituto({
    required this.nombre,
    required this.descripcion,
    required this.codigo,
    required this.privado,
    required this.miembros,
    this.logo ='',
    this.color='000000',
    this.agregar =false
  });
  
  Instituto.fromMap(Map<String, dynamic> map)
      : nombre = map['nombre'],
        descripcion = map['descripcion'],
        codigo = map['codigo'],
        privado = map['privado'],
        logo = map['logo'],
        color = map['color'],
        miembros = map['miembros'];

  Map<String, dynamic> toMap() {
    return {
      'nombre': nombre,
      'descripcion': descripcion,
      'codigo': codigo,
      'privado': privado,
      'miembros': miembros,
      'logo':logo,
      'color':color
    };
  }
}