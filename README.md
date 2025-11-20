A low-cost Arduino-based robotic arm that automatically turns pages during scanning, built for fast and error-free digitization.

# Automated-Page-Turning-Robotic-Arm


The Automated Page-Turning Robotic Arm is a low-cost, Arduino-based automation system designed to streamline the digitization of examination papers. Traditional scanning requires a human operator to manually turn each page, which is slow, error-prone, and difficult to scale for large volumes of documents. This project solves that problem by introducing a fully automated, sensor-driven page-turning mechanism that works alongside any standard flatbed scanner.

At its core, the system uses an Arduino Uno, MG995 servo motor, and an LDR sensor to detect scan completion and trigger precise page-turning actions. A silicone-tipped arm carefully lifts and flips individual pages without causing tears, folds, or accidental multi-page turns. The design emphasizes accuracy, affordability, and ease of integration, making it suitable for educational institutions, administrative departments, and digitization labs with large scanning workloads.

This project demonstrates the integration of embedded systems, mechanical design, and automation, providing a scalable alternative to expensive commercial document feeders. The prototype achieves a page-turning accuracy of 98%, supports continuous scanning, and offers a strong foundation for future improvements such as computer vision, adaptive height adjustment, and machine learning-based movement optimization.

## 🛠️ Tech Stack

### **Hardware**
- Arduino Uno
- MG995 High-Torque Servo Motor
- LDR (Light Dependent Resistor) Sensor
- Regulated Power Supply (6V 5A + 9V)
- Silicone-Tipped Page Turner
- Flatbed Scanner

### **Software / Firmware**
- Arduino IDE
- Embedded C / Arduino C++
- PWM Motor Control
- Sensor-Based Interrupt Logic

### **Design & Documentation**
- Fritzing (optional for circuit diagrams)
- Autodesk Fusion / SolidWorks (optional for arm structure)
- MS Word / LaTeX (Project Report)


## Project Architecture Diagram

                    +---------------------------+
                    |       Flatbed Scanner     |
                    |  (Scanning Light Source)  |
                    +-------------+-------------+
                                  |
                                  | LDR Sensor detects
                                  | scan completion
                                  v
+-------------------+      +-------------------+
|  Power Supply     |      |   Arduino Uno     |
|  6V/5A (Servo)    |----->| (Control Logic)   |
|  9V (Controller)  |      |                   |
+----------+--------+      +---------+---------+
           |                         |
           | PWM Signals             | Sensor Input
           v                         v
 +---------+----------+     +--------+--------+
 |   MG995 Servo      |     |   LDR Module    |
 | (Arm + Gripper)    |     +-----------------+
 +---------+----------+
           |
           v
 +---------------------------+
 |  Page-Turning Mechanism   |
 | (Silicone-Tipped Arm)     |
 +---------------------------+

System Workflow:
1. Scanner ON → LDR detects light.
2. Scanner OFF → Arduino triggers servo.
3. Servo lifts & turns page.
4. System resets → next scan cycle.

## 🔧 Installation & Setup

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/<your-username>/page-turning-robotic-arm.git
cd page-turning-robotic-arm

2️⃣ Install Arduino Dependencies

Arduino IDE

Servo.h library (built-in)

Basic analog sensor read support

3️⃣ Upload Code to Arduino

Connect Arduino Uno via USB.

Open .ino file from the repository.

Select the correct COM port.

Upload the sketch.

4️⃣ Hardware Assembly

Connect MG995 servo to pin (e.g., D9).

Connect LDR sensor to analog pin (e.g., A0).

Provide separate power supplies:

6V 5A for servo motor

9V/USB for Arduino

Mount robotic arm beside scanner bed.

5️⃣ Run the System

Place the document stack on scanner.

Start scanning.

System automatically:

Detects scan completion via LDR

Turns the next page

Repeats the cycle
