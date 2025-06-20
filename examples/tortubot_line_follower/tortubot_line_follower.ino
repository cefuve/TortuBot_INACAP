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

void setup() {
  Tortu.begin();        // Cargar configuración inicial
  Tortu.beep(20);       // Emitir pitido por 20 ms
}

void loop() {
  if ( Tortu.sensorRead(IR::CENTER) )       // Si detecta línea central, avanza
  {
    Tortu.moveForward();
  }
  else if ( Tortu.sensorRead(IR::LEFT) )    // Si detecta línea a la izquierda, gira a la izquierda
  {
    Tortu.turnLeft();
  }
  else if ( Tortu.sensorRead(IR::RIGHT) )   // Si detecta línea a la derecha, gira a la derecha
  {
    Tortu.turnRight();
  }
  else                                      // Si no detecta líneas, se detiene
  {
    Tortu.stop();
  }
}