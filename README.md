
# 🧭 Robô Seguidor de Linha com Desvio de Obstáculos

> Open-source autonomous robot designed to follow lines and avoid obstacles using **Arduino**, **infrared sensors**, and **ultrasonic distance measurement**.  
> The system applies basic robotics principles such as sensor fusion, PWM motor control, and obstacle detection logic.



## 📘 Overview

This project consists of a **line-following robot** capable of navigating predefined paths based on visual contrast (black/white) and autonomously stopping or rerouting when obstacles are detected.  
It was developed for educational and experimental purposes, focusing on **embedded systems**, **automation**, and **algorithmic control**.

The codebase is modular and well-organized, divided into logical sections for **motor control**, **sensor handling**, and **decision-making routines**.



## ⚙️ Key Features

- **Autonomous Line Tracking** — Follows black or white lines using infrared sensors  
- **Obstacle Avoidance** — Detects and stops when an obstacle is near using an ultrasonic sensor  
- **PWM Motor Control** — Smooth acceleration and directional precision  
- **Modular Firmware** — Organized code structure with separated logic for movement and sensors  
- **Adjustable Sensitivity** — Easily tune speed, detection range, and threshold values  
- **Open Source & Extensible** — Built for experimentation and future robotics extensions  



## 🧠 Hardware Components

| Component | Description |
|------------|-------------|
| **Arduino Uno / Mega** | Main microcontroller |
| **L298N H-Bridge** | Motor driver for two DC motors |
| **2x DC Motors** | Left and right traction motors |
| **2x Infrared Sensors** | Line detection (black/white) |
| **HC-SR04 Ultrasonic Sensor** | Obstacle detection |
| **Power Supply** | 6–12V battery pack |
| **Jumpers & Chassis** | Wiring and structure |

---

## 🧩 Project Structure



📦 line-follower-robot
├── firmware/
│   ├── line_follower_basic/
│   ├── line_follower_advanced/
│   └── obstacle_avoidance/
├── docs/
│   ├── wiring_diagram.png
│   ├── component_list.md
│   └── flowchart.md
├── LICENSE
├── README.md
└── .gitignore

````



## 🚀 Setup & Usage

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/cauerast/line-follower-robot.git
cd line-follower-robot
````

### 2️⃣ Open the Project in Arduino IDE

* Navigate to `firmware/line_follower_basic/`
* Select your Arduino board and COM port
* Upload the code to your board

### 3️⃣ Assemble the Circuit

Follow the wiring diagram in the `/docs` folder.
Make sure to correctly connect the **L298N module** to the motor and the **infrared sensors** to the analog pins defined in the firmware.

### 4️⃣ Run the Robot

Place the robot on a track with a **black line over a white surface** (or vice versa).
The robot will automatically start following the line and stop when an obstacle is detected.

---

## 🧰 Configuration

You can customize:

* **Speed** via PWM value (default: 175)
* **Detection distance** for the ultrasonic sensor (default: 175 mm)
* **Sensor polarity** depending on line color (black or white)

These values are defined in the `config.h` or directly in the main Arduino sketch.



## 🔬 Experiments & Extensions

You can extend this project by integrating:

* **Bluetooth/Wi-Fi modules** for remote control
* **PID control** for smoother and more accurate movement
* **OLED display** for telemetry visualization
* **MQTT or REST API** for IoT-based data monitoring

---

## 🧩 Educational Context

This project was created as part of a **university robotics and automation study**, with a focus on applying theoretical knowledge in:

* Embedded systems programming
* Algorithmic control logic
* Sensor integration
* Real-time response systems



## 🧠 Author

**Cauê Silva Rasteiro**
Software Developer & Automation Enthusiast
📧 [cauerast@gmail.com](mailto:cauerast@gmail.com)
🔗 [github.com/cauerast](https://github.com/cauerast) | [linkedin.com/in/cauerast](https://www.linkedin.com/in/cauerast/)



## 📜 License

This project is licensed under the **MIT License**.
You are free to use, modify, and distribute it for educational or research purposes.



> *Developed as an academic open-source robotics project to inspire hands-on learning in automation, control systems, and AI-driven embedded applications.*

```

Deseja que eu adicione uma seção final tipo **“Performance & Testing”** (como em repositórios da Intel ou OpenVINO) com resultados de testes e sugestões de benchmarks (velocidade, precisão, curva, resposta a obstáculos)? Isso deixaria seu README com um tom ainda mais profissional e completo.
```
