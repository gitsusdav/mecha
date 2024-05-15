import 'package:flutter/material.dart';

class BarraNavegacion extends CustomPainter {

  final Color color;
  BarraNavegacion({ required this.color});
  @override
  void paint(Canvas canvas, Size size) {
    int diameter = 85;
    double topSpace = 2;
    double startCurve = (size.width - diameter) / 2; // donde comienza la curba

    double endCurve = startCurve + diameter - 2; // donde termina la curba
    double xValueInset = diameter * 0.06;
    double yValueOffset = (diameter / 3) * 6.2 / 3.0;
    Path path = Path();
    Paint paint = Paint();
    final Color shadowColor = Colors.black.withOpacity(0.25);
    Path shadowPath = Path();
    Paint shadowPaint = Paint();

    Offset shadowfirstendPoint = Offset(endCurve - topSpace, 0.0);
    Offset shadowcontrolPoint1 =
        Offset(startCurve + xValueInset + topSpace, yValueOffset);
    Offset shadowcontrolPoint2 =
        Offset((diameter - xValueInset) + startCurve - topSpace, yValueOffset);

    shadowPath.lineTo(startCurve + topSpace, 0.0);
    shadowPath.cubicTo(
        shadowcontrolPoint1.dx,
        shadowcontrolPoint1.dy,
        shadowcontrolPoint2.dx,
        shadowcontrolPoint2.dy,
        shadowfirstendPoint.dx,
        shadowfirstendPoint.dy);
    shadowPath.lineTo(size.width, 0.0);
    shadowPath.lineTo(size.width, size.height);
    shadowPath.lineTo(0.0, size.height);
    shadowPath.close();

    shadowPaint.color = shadowColor;
    canvas.drawPath(shadowPath, shadowPaint);

    Offset firstendPoint = Offset(endCurve, topSpace);
    Offset controlPoint1 =
        Offset(startCurve + xValueInset, yValueOffset + topSpace);
    Offset controlPoint2 =
        Offset((diameter - xValueInset) + startCurve, yValueOffset + topSpace);

    path.moveTo(0.0, topSpace);
    path.lineTo(startCurve, topSpace);
    path.cubicTo(controlPoint1.dx, controlPoint1.dy, controlPoint2.dx,
        controlPoint2.dy, firstendPoint.dx, firstendPoint.dy);
    path.lineTo(size.width, topSpace);
    path.lineTo(size.width, size.height);
    path.lineTo(0.0, size.height);
    path.close();
    paint.color = color;
    canvas.drawPath(path, paint);
  }

  @override
  bool shouldRepaint(BarraNavegacion oldDelegate) => oldDelegate != this;
}