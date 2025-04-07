/*
  TortuBot INACAP

  Copyright (c) 2025 CEAR INACAP.  All right reserved.
  License: GPL 3.0.

  This program comes with ABSOLUTELY NO WARRANTY.
  This is free software, and you are welcome to redistribute it
  under certain conditions.

  Created 7 Apr 2025
  by Cesar Fuenzalida Vergara (http://cefuve.com)

  Para el control mediante el bluetooth de un telefóno celular.
  Aplicación: BT Robot Controller
  Desarrollador: Tinker Twins
*/

#include <TortuBot_INACAP.h>
#include "BluetoothSerial.h"

TortuBot Tortu;                             // ¡Dale vida a tu robot poniéndole un nombre!
BluetoothSerial bt;                         // Creamos un objeto de la librería bluetooth, llamado bt

void setup(){
  Serial.begin(115200);                     // Iniciamos la comunicación serial con la placa ESP32
  bt.begin("Tortuneitor");                  // Iniciamos la red bluetooth con su respectivo nombre
  
  Tortu.begin();                            // Cargar configuración inicial
  Tortu.beep(20);                           // Emitir pitido por 20 ms
}

void loop(){
  if(bt.available() > 0){                   // Verificamos si recibimos datos por bluetooth
    char command = bt.read();               // Leemos un carácter y lo almacenamos en la variable command

    switch(command){                        // Condicionamos la variable command
      // Instrucciones si la variable es "w"
      case 'w': Tortu.setVelocity(100);     // Establecemos la velocidad al 100%
                Tortu.moveForward();        // Movemos el robot hacia adelante
                Serial.println("avanzar");  // Imprimimos en el monitor serie
                break;
      // Instrucciones si la variable es "s"
      case 's': Tortu.setVelocity(80);      // Establecemos la velocidad al 80%
                Tortu.moveReverse();        // Movemos el robot hacia atrás
                Serial.println("retroceder"); // Imprimimos en el monitor serie
                break;
      // Instrucciones si la variable es "a"
      case 'a': Tortu.setVelocity(50);      // Establecemos la velocidad al 50%
                Tortu.turnLeft();           // Giramos el robot hacia la izquierda
                Serial.println("girar izquierda");  // Imprimimos en el monitor serie
                break;
      // Instrucciones si la variable es "d"
      case 'd': Tortu.setVelocity(50);      // Establecemos la velocidad al 50%
                Tortu.turnRight();          // Giramos el robot hacia la derecha
                Serial.println("girar derecha");  // Imprimimos en el monitor serie
                break;
      // Instrucciones si la variable es "x"
      case 'x': Tortu.stop();               // Detenemos el robot
                Serial.println("detener");  // Imprimimos en el monitor serie
                break;
    }
  }

  delay(1);
}