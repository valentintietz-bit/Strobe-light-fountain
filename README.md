# Stroboscopic Fountain Controller

## Overview

This project controls a **stroboscopic fountain effect** using an Arduino. The system uses **PWM to drive a pump** and creates a **stroboscopic LED effect** to give the illusion of water drops being frozen or moving in slow motion. A **potentiometer** allows the user to adjust the strobe frequency in real time.

Ideal for educational demonstrations of visual perception, wave mechanics, and stroboscopic effects in water.

---

## Features

* **Stroboscopic LED control** to simulate frozen water motion
* **PWM control of water pump**
* **Real-time frequency adjustment** using a potentiometer (25–100 Hz)
* Smooth and responsive strobe effect based on precise microsecond timing

---

## Hardware Requirements

* Arduino board (e.g. Uno, Nano)
* White LED (high brightness recommended)
* N-channel MOSFET or transistor (to drive the LED)
* Water pump (low voltage, e.g. 5V or 12V)
* Potentiometer (10kΩ typical)
* Power supply (for pump and Arduino)
* Resistors, wires, breadboard or PCB

---

## Pin Configuration

| Component                                   | Arduino Pin |
| ------------------------------------------- | ----------- |
| LED (via transistor)                        | 9           |
| Water Pump (via transistor or motor driver) | 3 (PWM)     |
| Potentiometer                               | A1          |

---

## How It Works

* The **potentiometer** sets the frequency of the LED strobe (between 25 Hz and 100 Hz).
* The **LED** flashes briefly (5% duty cycle) at the set frequency using microsecond-level timing.
* The **pump** is powered via PWM at 50% duty cycle (constant speed).
* The combination of LED flashes and flowing water creates a **stroboscopic visual effect** that simulates motion freeze.

---

## Code Summary

```cpp
// Read potentiometer value
int valPot = analogRead(pinPot);
// Map to frequency range
int freq = map(valPot, 0, 1023, 25, 100);
// Compute period and pulse width
period_us = 1000000UL / freq;
ton_us = period_us * 0.05;
```

The LED is turned **ON** briefly and **OFF** for the rest of the cycle, controlled precisely using `micros()`.

---

## Usage

1. Upload the code to your Arduino using the Arduino IDE.
2. Connect the hardware as described.
3. Power on the system.
4. Adjust the potentiometer to change the LED strobe frequency.
5. Observe the water appearing to freeze or move in slow motion under the LED strobe.

---

## Author

* **Valentin Tietz**

---

