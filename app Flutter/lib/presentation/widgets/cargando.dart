import 'package:flutter/material.dart';

class Cargando extends StatelessWidget {
  const Cargando({
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return  Container(
        decoration: BoxDecoration(borderRadius: BorderRadius.circular(20),
        color: const Color.fromARGB(105, 0, 0, 0),
        ),
        child: Align(
        alignment: Alignment.center,
        child: Container(
          width: 200,
          height: 200,
          decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.circular(20),
          ),
          child: const Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: [
              SizedBox(
                height: 20,
              ),
              CircularProgressIndicator(),
              SizedBox(
                height: 20,
              ),
            ],
          ),
        ),
      ),
    );
  }
}