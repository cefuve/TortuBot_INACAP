/*
  TortuBot_INACAP.cpp - Main include file for robot functions
  Copyright (c) 2025 CEAR INACAP.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
  License: GPL 3.0.

  Author: César Fuenzalida Vergara (cefuve.com)
*/

#include "TortuBot_INACAP.h"

/**
 * @brief Constructor del TortuBot.
 * 
 * Inicializa los valores por defecto de las variables internas. 
 * La configuración de pines se hace con begin().
 */
TortuBot::TortuBot()
{
    _velocity = 0;
}


/**
 * @brief Inicializa los pines del TortuBot y configura los valores por defecto.
 * 
 * Este método debe llamarse en `setup()` antes de utilizar otras funciones del TortuBot.
 * Configura los sensores IR como entradas, los motores y el buzzer como salidas.
 * Además, establece una velocidad inicial de 20% por defecto.
 */
void TortuBot::begin()
{
    // IR Sensors
    pinMode(IR_L, INPUT);
    pinMode(IR_C, INPUT);
    pinMode(IR_R, INPUT);

    // Motors
    pinMode(M1_FW, OUTPUT);
    pinMode(M1_RV, OUTPUT);
    pinMode(M2_FW, OUTPUT);
    pinMode(M2_RV, OUTPUT);

    // Buzzer
    pinMode(BUZZER, OUTPUT);

    // Default velocity: 20%
    setVelocity(DEFAULT_SPEED);
}


/**
 * @brief Lee el valor de un sensor infrarrojo (IR).
 * 
 * Esta función permite leer el estado lógico (HIGH o LOW) del sensor IR
 * especificado, utilizado comúnmente para detección de línea u obstáculos.
 * 
 * @param sensor El sensor IR a leer. Puede ser:
 * - IR::LEFT
 * - IR::CENTER
 * - IR::RIGHT
 * 
 * @return true Si el sensor está activado (por ejemplo, detecta línea negra).
 * @return false Si el sensor no está activado.
 */
bool TortuBot::sensorRead(IR sensor)
{
    // IR_L 18
    // IR_C 19
    // IR_R 23

    switch(sensor)
    {
        case IR::LEFT:
            return digitalRead(IR_L);
        case IR::CENTER:
            return digitalRead(IR_C);
        case IR::RIGHT:
            return digitalRead(IR_R);
        default:
            return false;
    }
}


/**
 * @brief Establece la velocidad del TortuBot en porcentaje.
 * 
 * La velocidad se convierte de un rango de 0 a 100 (porcentaje) a un valor PWM de 0 a 255.
 * Valores fuera de rango se limitan automáticamente.
 * 
 * @param velocity Velocidad deseada en porcentaje (0 a 100).
 */
void TortuBot::setVelocity(uint8_t velocity)
{
    velocity = constrain(velocity, 0, 100);
    _velocity = map(velocity, 0, 100, 0, 255);
}


/**
 * @brief Mueve el TortuBot hacia adelante con la velocidad actual.
 * 
 * Utiliza los pines PWM de ambos motores para avanzar. 
 * Se asume que la velocidad ha sido previamente configurada con setVelocity().
 */
void TortuBot::moveForward()
{
    setMotor(M1_FW, M1_RV, _velocity);
    setMotor(M2_FW, M2_RV, _velocity);
}


/**
 * @brief Mueve el TortuBot hacia atrás con la velocidad actual.
 * 
 * Utiliza los pines PWM de ambos motores para retroceder.
 * Se asume que la velocidad ha sido previamente configurada con setVelocity().
 */
void TortuBot::moveReverse()
{
    setMotor(M1_FW, M1_RV, -_velocity);
    setMotor(M2_FW, M2_RV, -_velocity);
}


/**
 * @brief Gira el TortuBot hacia la izquierda.
 * 
 * El motor derecho avanza y el motor izquierdo retrocede, realizando un giro en el lugar.
 */
void TortuBot::turnLeft()
{
    setMotor(M1_FW, M1_RV, -_velocity);
    setMotor(M2_FW, M2_RV, _velocity);
}


/**
 * @brief Gira el TortuBot hacia la derecha.
 * 
 * El motor izquierdo avanza y el motor derecho retrocede, realizando un giro en el lugar.
 */
void TortuBot::turnRight()
{
    setMotor(M1_FW, M1_RV, _velocity);
    setMotor(M2_FW, M2_RV, -_velocity);
}


/**
 * @brief Detiene completamente el movimiento del TortuBot.
 */
void TortuBot::stop()
{
    setMotor(M1_FW, M1_RV, 0);
    setMotor(M2_FW, M2_RV, 0);
}


/**
 * @brief Configura la dirección y velocidad de un motor.
 * 
 * Si el valor de velocidad es positivo, el motor avanza.
 * Si es negativo, el motor retrocede.
 * Si es cero, el motor se detiene.
 * 
 * @param pin_fw Pin de avance (forward).
 * @param pin_rv Pin de retroceso (reverse).
 * @param speed Valor PWM (-255 a 255).
 */
void TortuBot::setMotor(int pin_fw, int pin_rv, int speed)
{
    if (speed > 0)
    {
        analogWrite(pin_fw, speed);
        analogWrite(pin_rv, 0);
    }
    else if (speed < 0)
    {
        analogWrite(pin_fw, 0);
        analogWrite(pin_rv, -speed);
    }
    else
    {
        analogWrite(pin_fw, 0);
        analogWrite(pin_rv, 0);
    }
}


/**
 * @brief Emite un pitido corto con el buzzer del TortuBot.
 * 
 * El buzzer se activa durante el tiempo especificado en milisegundos.
 * 
 * @param pulse Duración del beep en milisegundos (1 a 200 ms).
 */
void TortuBot::beep(uint8_t pulse)
{
    pulse = constrain(pulse, 1, 200);
    digitalWrite(BUZZER, HIGH);
    delay(pulse);
    digitalWrite(BUZZER, LOW);
}


/**
 * @brief Hace que el robot emita un sonido tipo R2-D2.
 * 
 * Esta función reproduce un conjunto de tonos que suenan como el famoso droide.
 * Ideal para alertas o para diversión.
 */
void TortuBot::sayR2D2()
{
    int beeps[] = {1933, 2156, 1863, 1505, 1816, 1933, 1729, 2291};

    for (int i = 0; i < 10; i++) {
        tone(BUZZER, 1050);
        delay(2);
    }

    delay(35);

    for (int i = 0; i < 8; i++) {
        tone(BUZZER, beeps[i]);
        
        for (int v = 0; v < 250; v += 10) {
            delay(1);
        }
        
        for (int v = 250; v > 0; v -= 10) {
            delay(1);
        }
        
        noTone(BUZZER);
        delay(25);
    }

    int f = 2466;
    while (f < 2825) {
        tone(BUZZER, f);
        f += 3;
        delay(1);
    }

    f = 2825;
    while (f > 2000) {
        tone(BUZZER, f);
        f -= 6;
        delay(1);
    }
    noTone(BUZZER);
    delay(35);

    for (int i = 0; i < 10; i++) {
        tone(BUZZER, 1050);
        delay(2);
        noTone(BUZZER);
        delay(4);
    }

    noTone(BUZZER);
}