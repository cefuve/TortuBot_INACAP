# TortuBot_lite

**Librería para controlar el robot educativo móvil TortuBot**, diseñada para el aprendizaje de programación y robótica en entornos Arduino.  

Esta librería permite controlar motores, sensores infrarrojos y emitir sonidos desde una placa Arduino compatible (ESP32 Devkit V1 principalmente).

---

## 🚀 Características principales

- Control simple de motores izquierdo y derecho.
- Lectura de sensores infrarrojos (IR) izquierdo, central y derecho.
- Reproducción de sonidos básicos (beep) y tono R2-D2.
- Funciones integradas de movimiento: avanzar, retroceder, girar y detenerse.
- Librería optimizada para educación: clara, compacta y fácil de usar.

---

## ⚙️ Funciones disponibles

### Inicialización
- `void begin();`  
  Inicia el robot configurando los pines necesarios.

### Sensores
- `bool sensorRead(IR sensor);`  
  Lee el estado del sensor IR. Parámetro: `'IR::LEFT'`, `'IR::CENTER'` o `'IR::RIGHT'` (izquierdo, central o derecho).  
  Retorna `true` si detecta línea negra.

### Movimiento
- `void moveForward();`  
  Mueve el robot hacia adelante.

- `void moveBackward();`  
  Mueve el robot hacia atrás.

- `void turnLeft();`  
  Gira el robot hacia la izquierda.

- `void turnRight();`  
  Gira el robot hacia la derecha.

- `void robotStop();`  
  Detiene todos los motores del robot.

### Sonido
- `void beep();`  
  Emite un beep corto por el buzzer.

- `void sayR2D2();`  
  Emite un sonido estilo "R2-D2" utilizando tonos aleatorios.

---

## ⚡ Ejemplo de uso

```cpp
#include <TortuBot_lite.h>

TortuBot Tortu;

void setup() {
  Tortu.begin();
  Tortu.beep(20);
}

void loop() {
  if ( Tortu.sensorRead(IR::CENTER) ) {
    Tortu.moveForward();
  } else {
    Tortu.stop();
  }
}
```
## Autor

- [César Fuenzalida Vergara](https://www.cefuve.com/)
