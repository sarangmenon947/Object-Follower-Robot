# Object Follower Robot

An Arduino-based autonomous robot that **follows an object** in front of it using two IR sensors. The robot detects the presence and position of a nearby object and steers itself to track it in real time.

---

## How It Works

Two IR sensors are mounted on the **front** of the robot, facing forward. When an object is close enough, it reflects the IR signal back to the sensor (reads `LOW`). When no object is detected, the sensor reads `HIGH`.

By comparing both sensor readings, the robot determines where the object is and moves toward it:

---

## Movement Logic

| Left Sensor | Right Sensor | Condition                        | Action          |
|-------------|--------------|----------------------------------|-----------------|
| HIGH        | HIGH         | No object detected on either side | Stop          |
| LOW         | HIGH         | Object detected on left only      | Turn Left     |
| HIGH        | LOW          | Object detected on right only     | Turn Right    |
| LOW         | LOW          | Object detected on both sides     | Move Forward  |

> Sensors return `LOW` when an object is **detected** and `HIGH` when the path is **clear**.

---

## Pin Configuration

| Pin | Role                         |
|-----|------------------------------|
| 2   | Left IR sensor (INPUT)       |
| 3   | Right IR sensor (INPUT)      |
| 13  | Left motor — forward (IN1)   |
| 12  | Left motor — reverse (IN2)   |
| 11  | Right motor — forward (IN3)  |
| 10  | Right motor — reverse (IN4)  |

---

## Components Required

| Component                   | Quantity |
|-----------------------------|----------|
| Arduino Uno (or compatible) | 1        |
| IR Sensor Module            | 2        |
| DC Gear Motor               | 2        |
| Motor Driver (L298N/L293D)  | 1        |
| Robot Chassis               | 1        |
| Wheels                      | 2        |
| Caster Wheel                | 1        |
| Li-ion / 9V Battery         | 1        |
| Jumper Wires                | As needed|

---

## Circuit Overview

```
  Arduino
  ┌─────────────────┐
  │ D2  ──── Left IR Sensor (OUT)
  │ D3  ──── Right IR Sensor (OUT)
  │ D13 ──── Motor Driver IN1 (Left Motor +)
  │ D12 ──── Motor Driver IN2 (Left Motor -)
  │ D11 ──── Motor Driver IN3 (Right Motor +)
  │ D10 ──── Motor Driver IN4 (Right Motor -)
  │ 5V  ──── IR Sensor VCC
  │ GND ──── Common Ground
  └─────────────────┘
```

---

## Project Structure

```
object-following-robot/
├── object_following.ino  
└── README.md
```

---

## How to Upload

1. Open `object_follower.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
2. Select your board: **Tools → Board → Arduino Uno**.
3. Select the correct port: **Tools → Port → COMx** (Windows) or `/dev/ttyUSBx` (Linux/macOS).
4. Click **Upload** (→).
5. Power the robot and place your hand or an object in front of the sensors — it will follow.

---

## Setup Tips

- **Sensor range:** IR obstacle sensors typically detect objects at **2–30 cm**. Adjust the onboard potentiometer to set the desired following distance.
- **Sensor alignment:** Mount both sensors at the **same height and angle**, pointing straight ahead, spaced about 5–8 cm apart.
- **Object type:** Works best with **light-coloured, opaque objects** (your hand, a box, a white surface). Dark or transparent objects may not reflect IR well.
- **Lighting:** Avoid strong direct sunlight — it can saturate IR sensors and cause false readings.
- **Power:** Use a dedicated battery pack for motors to prevent voltage drops affecting the Arduino.
