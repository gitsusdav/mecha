class Usuario {

  String nombre='';
  String usuarioID='';
  String usuarioFoto='';
  List<String> apuntesPropiosID=[];
  List<String>  apuntesSeguidosID=[];
  String periodoActual='';
  List<String> institucionesID= [];
  List<String> materiasID=[];

Usuario({
    required this.nombre,
    required this.usuarioID,
    required this.usuarioFoto,
    required this.apuntesPropiosID,
    required this.apuntesSeguidosID,
    required this.periodoActual,
    required this.institucionesID,
    required this.materiasID,
  });

  Usuario.fromMap(Map<String, dynamic> map)
      : nombre = map['nombre'],
        usuarioID = map['usuarioID'],
        usuarioFoto = map['usuarioFoto'],
        apuntesPropiosID = (map['apuntesPropiosID'] as List).map((item) => item as String).toList(),
        apuntesSeguidosID = (map['apuntesSeguidosID'] as List).map((item) => item as String).toList(),
        periodoActual = map['periodoActual'],
        institucionesID = (map['institucionesID'] as List).map((item) => item as String).toList(),
        materiasID = (map['materiasID'] as List).map((item) => item as String).toList();

  Map<String, dynamic> toMap() {
    return {
      'nombre': nombre,
      'usuarioID': usuarioID,
      'usuarioFoto': usuarioFoto,
      'apuntesPropiosID': apuntesPropiosID.asMap(),
      'apuntesSeguidosID': apuntesSeguidosID.asMap(),
      'periodoActual': periodoActual,
      'institucionesID': institucionesID.asMap(),
      'materiasID': materiasID.asMap(),
    };
  }
}