/*
  TortuBot lite

  Copyright (c) 2025 CEAR INACAP.  All right reserved.
  License: GPL 3.0.

  This program comes with ABSOLUTELY NO WARRANTY.
  This is free software, and you are welcome to redistribute it
  under certain conditions.

  Created 7 Apr 2025
  by Cesar Fuenzalida Vergara (http://cefuve.com)
*/

#include <TortuBot_lite.h>

TortuBot Tortu;         // ¡Dale vida a tu robot poniéndole un nombre!

void setup(){
  Tortu.begin();        // Cargar configuración inicial
  Tortu.beep(20);       // Emitir pitido por 20 ms
  delay(1000);

  Tortu.moveForward();  // Mover el robot hacia adelante
  delay(500);
  Tortu.stop();    // Detener el robot
  delay(2000);

  Tortu.moveReverse();  // Mover el robot hacia atras
  delay(500);
  Tortu.stop();    // Detener el robot
  delay(2000);

  Tortu.setVelocity(100); // Establecer la velocidad al 100%

  Tortu.turnLeft();     // Girar el robot a la izquierda
  delay(500);
  Tortu.stop();    // Detener el robot
  delay(2000);

  Tortu.turnRight();    // Girar el robot a la derecha
  delay(500);
  Tortu.stop();    // Detener el robot
  delay(2000);
}

void loop(){

}