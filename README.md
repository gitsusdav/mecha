# Mecha

Mecha es una aplicación donde tus notas de clases se convierten en tesoros históricos compartidos a las siguientes generaciones.

## Descripción

Mecha es una aplicación desarrollada en C++ para ayudar a los estudiantes universitarios a organizar y gestionar sus notas de manera eficiente en diversas materias. La aplicación permite ordenar las notas por fechas, relevancia y complementarlas con las notas de los compañeros de clase.

## Características Principales

Gestión de Materias: 
Los usuarios pueden crear y gestionar diferentes materias que estén cursando en el semestre actual. Cada materia tiene su conjunto de clases que se crean a lo largo del tiempo.
Gestión de Clases: Dentro de cada materia, los usuarios pueden añadir y gestionar cada clase realizada en un día concreto.

## Apuntes Públicos:

Los usuarios pueden compartir apuntes públicamente dentro de la aplicación para cada clase, facilitando el intercambio de conocimientos entre compañeros.
Historial de Calificaciones: La aplicación registra el historial de calificaciones de los usuarios, permitiéndoles acceder fácilmente a notas anteriores y realizar un seguimiento de su progreso académico a lo largo del tiempo.

Mecha está diseñada para optimizar la experiencia de los estudiantes universitarios en la gestión de sus notas y fomentar el intercambio de conocimientos entre pares. ¡Descárgala y transforma tus notas en tesoros históricos!

## Desarrollo en Figma

 [Pizarra](https://www.figma.com/file/oMsfZWNp5UkkZlvhE2dHSD/Figma-to-React-Component-(Community)?type=design&node-id=0%3A1&mode=design&t=7sLeo3oZNHaYe9m7-1)

## Compilar

El proyecto tiene como dependencia la librería openssl/sha se debe instalar Openssl para ubuntu.

`sudo apt-get install libssl-dev`

Compilas el proyecto desde la raíz con el comando, debes tener preinstalado el comando make, clang y c++ en la versión 17

`make`

El ejecutable se encuentra en la carpeta desde la raíz main/bin/Mecha o también puedes ejecutar para compilar y ejecutar

`make go`

## Licencia

Este código es público bajo la licencia BSD (Berkeley Software Distribution) 