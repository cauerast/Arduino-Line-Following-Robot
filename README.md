# Line Follower Robot with Obstacle Avoidance

> Autonomous robot built with Arduino, infrared, and ultrasonic sensors, designed to follow lines and avoid obstacles in real time.  
> Developed as an educational project focused on embedded systems, automation, and algorithmic control.

---

## Overview

This project implements a line-following robot capable of detecting and following a path based on surface contrast while avoiding obstacles using distance sensing.  
The goal is to demonstrate how sensor integration, PWM motor control, and decision-making logic can work together in small-scale robotics.

The source code is divided into modular scripts (`code1`, `code2`, etc.) for different functionalities such as movement, sensors, and logic flow.

---

## Features

- **Autonomous Navigation** — Follows black or white lines using IR sensors  
- **Obstacle Detection** — Stops or adjusts path upon detecting an obstacle  
- **PWM Motor Control** — Smooth and precise speed regulation  
- **Modular Logic** — Separate scripts for sensors, motors, and decisions  
- **Customizable Settings** — Adjust thresholds, speed, and distances  
- **Educational & Open Source** — Ideal for learning embedded programming and robotics  

---

## Hardware Components

| Component | Description |
|------------|-------------|
| **Arduino Uno / Mega** | Main microcontroller |
| **L298N H-Bridge** | Dual DC motor driver |
| **DC Motors (x2)** | Left and right wheel control |
| **Infrared Sensors (x2)** | Line tracking sensors |
| **HC-SR04 Ultrasonic Sensor** | Obstacle detection |
| **Power Supply (6–12V)** | Battery pack |
| **Chassis + Wiring** | Robot base and connections |

---

## Project Structure

```

📦 line-follower-robot
├── code1
├── code2
├── code3
├── docs/
│   ├── wiring_diagram.png
│   └── notes.md
├── README.md
└── .gitignore

````

Each code file represents a logical module of the robot, such as:
- **Sensor setup and calibration**
- **Motor control routines**
- **Main decision logic**
- **Obstacle avoidance algorithm**

---

## Setup & Execution

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/cauerast/line-follower-robot.git
cd line-follower-robot
````

### 2️⃣ Open in Arduino IDE

* Load each `.ino` or `.cpp` file (`code1`, `code2`, etc.)
* Select the correct Arduino board and COM port
* Upload to your device

### 3️⃣ Hardware Assembly

Use the wiring diagram in the `/docs` folder.
Ensure correct connections between sensors, motors, and the H-Bridge.

### 4️⃣ Run the Robot

Place the robot on a surface with a clear line (black over white or vice versa).
The system will automatically start following the line and respond to nearby obstacles.

---

## Configuration

You can modify:

* **Speed** (default PWM: 175)
* **Ultrasonic detection distance** (default: 175 mm)
* **Sensor threshold** based on track brightness

These values can be adjusted in the main script or through defined constants.

---

## Educational Context

Developed as part of a **university robotics and automation study**, this project aims to bridge theoretical learning and hands-on engineering practice through:

* Embedded systems programming
* Real-time control algorithms
* Sensor fusion and automation
* Hardware/software integration

---

## Author

**Cauê Silva Rasteiro**
Software Developer 
- [cauerast@gmail.com](mailto:cauerast@gmail.com)
- [github.com/cauerast](https://github.com/cauerast)
- [linkedin.com/in/cauerast](https://www.linkedin.com/in/cauerast/)

---

## 📜 License

This project is licensed under the **MIT License**.
You are free to use, modify, and distribute it for educational or research purposes.

---

> *An open-source robotics project combining logic, hardware, and automation for experimentation and learning.*

```
