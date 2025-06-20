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
  Serial.begin(115200); // Iniciar comunicación serial
  Tortu.begin();        // Cargar configuración inicial
  Tortu.beep(20);       // Emitir pitido por 20 ms
}

void loop(){
  bool IR_left_value = Tortu.sensorRead(IR::LEFT);      // Leer sensor izquierdo y almacenar en variable
  bool IR_center_value = Tortu.sensorRead(IR::CENTER);  // Leer sensor central y almacenar en variable
  bool IR_right_value = Tortu.sensorRead(IR::RIGHT);    // Leer sensor derecho y almacenar en variable
  
  // Imprimir los valores de los sensores en el monitor serie
  Serial.print(IR_left_value);
  Serial.print(" | ");
  Serial.print(IR_center_value);
  Serial.print(" | ");
  Serial.println(IR_right_value);
}