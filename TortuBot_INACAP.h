/*
  TortuBot_INACAP.h - Main include file for pin definitions
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

#ifndef TortuBot_h
#define TortuBot_h

#include <Arduino.h>

//IR sensors pins
#define IR_L 18
#define IR_C 19
#define IR_R 23

// Motor direction control pins
#define M1_FW 32
#define M1_RV 27
#define M2_FW 25
#define M2_RV 26

#define BUZZER 2

static const uint8_t DEFAULT_SPEED = 20;

enum class IR {
    LEFT,
    CENTER,
    RIGHT
};

/**
 * @brief Clase principal para controlar el robot TortuBot.
 */
class TortuBot
{
  public:
    // Constructor
    TortuBot();

    // Public Methods
    void begin();
    void beep(uint8_t pulse);
    void sayR2D2();
    bool sensorRead(IR sensor);
    void setVelocity(uint8_t velocity);
    void moveForward();
    void moveReverse();
    void turnLeft();
    void turnRight();
    void stop();

  private:
    // Private Variables
    int _velocity;
    void setMotor(int pin_fw, int pin_rv, int speed);
};

#endif