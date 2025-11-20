📄 Automated Page-Turning Robotic Arm
<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/ead903b2-9328-4a35-a473-f056b731d563" />


⭐ Tagline

A low-cost Arduino-based robotic arm that automatically turns pages during scanning, built for fast and error-free digitization.

📘 Overview

The Automated Page-Turning Robotic Arm is designed to solve a real-world problem faced by educational institutions: manually turning each page during the digitization of examination papers.

This system uses an Arduino Uno, MG995 servo motor, and an LDR sensor to detect when a scan is complete and automatically turn the next page. The silicone-tipped arm ensures safe, single-page handling without tearing or double-turning.

This project provides a cost-effective, scalable, and high-accuracy alternative to expensive commercial automatic document feeders.

🧩 Features

✔️ Automatic page turning synchronized with scanner

✔️ High accuracy (98%) page handling

✔️ Gentle silicone-tipped grip to prevent damage

✔️ Low-cost and easy to build

✔️ Sensor-driven automation (LDR detects scanner light)

✔️ Modular Arduino-controlled design

✔️ Suitable for schools, universities, admin offices

🛠️ Tech Stack
Hardware

Arduino Uno

MG995 High-Torque Servo Motor

LDR (Light Dependent Resistor) Sensor

Regulated Power Supply (6V 5A + 9V)

Silicone-Tipped Arm

Flatbed Scanner

Software

Arduino IDE

Embedded C / Arduino C++

PWM Motor Control

Analog Sensor Input Processing

Tools

Fritzing (optional circuit diagram)

SolidWorks / Fusion 360 (optional mechanical design)

📐 System Architecture
<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/0512d745-6dd1-46a1-ac23-3f7a598ba486" />


Workflow

Scanner ON → LDR detects scanning light

Scanner OFF → Arduino triggers servo

Servo lifts & turns a page

System resets → waits for next scan cycle

⚙️ Installation & Setup
1️⃣ Clone the Repository
git clone https://github.com/<username>/page-turning-robotic-arm.git
cd page-turning-robotic-arm

2️⃣ Install Arduino IDE & Libraries

Install Arduino IDE

Ensure Servo.h library is available (built-in)

3️⃣ Upload the Code

Open the .ino file from this repo

Select your COM port

Upload the sketch to the Arduino Uno

4️⃣ Hardware Connections
Component	Arduino Pin
MG995 Servo	D9
LDR Sensor	A0
Ground	GND
Servo Power	External 6V 5A

⚠️ IMPORTANT:
Servo motors must NOT be powered from Arduino.
Use separate 6V 5A supply for stable torque.

5️⃣ Run the System

Place the document stack on the scanner

Start scanning

System will:

Detect scan completion


🔍 How It Works
LDR Sensor

Detects the scanner’s light to determine when a page has finished scanning.

Arduino Logic

Reads LDR values → triggers servo movement sequence.

Servo Mechanism

Approach → Grip → Lift → Turn → Reset
Simulates the natural motion of a human turning a page.

Silicone-Tipped End Effector

Ensures gentle page lifting with no slipping or double-page grabbing.

🚧 Limitations

Works best with up to 50–60 pages

Sensitive to humidity & static electricity

Requires manual alignment before starting

Does not yet correct errors automatically

🚀 Future Enhancements

🤖 Computer Vision for page detection

📏 Adaptive height sensing

🧠 Machine Learning for improved stability

📡 Wi-Fi/Bluetooth remote control

🗂️ Integration with Document Management Systems

🧑‍💻 Team Members

Durvesh Angal

Yash Parshetty

Amol Darkunde

Ayush Penkar

Rohit Sunka


