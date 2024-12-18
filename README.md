# Emotion Monitoring System
## Introduction
The Emotion Monitoring System is a project that monitors physiological parameters to evaluate stress levels and emotional states in real-time. By analyzing different indicators such as heart rate, skin conductivity, and body temperature, the system helps users understand and manage their stress levels effectively. With an easy-to-read display and intuitive feedback mechanisms like colored LEDs and auditory alerts, the system delivers immediate results that are easy to interpret. Additionally, it leverages IoT technology to transmit data to an online dashboard, enabling users to track their stress trends over time and gain a deeper understanding of their emotional health.

## Overview
The project integrates multiple sensors to:

* Measure physiological parameters:
    - Heart rate and variability using the MAX30102 sensor.
    - Galvanic skin response (GSR) for stress detection.
    - Body temperature with the TMP102 sensor.
* Provide real-time feedback:
    - Visual feedback through RGB LED.
    - Auditory alerts using a buzzer.
* Send data to an IoT dashboard for remote monitoring and historical tracking

The system uses the Arduino Nano ESP32 microcontroller, which supports Wi-Fi communication and ensures efficient data transmission. The sensors are connected to appropriate GPIO pins on the microcontroller. By leveraging IoT, users can visualize their emotional health data remotely, identify trends, and take appropriate steps toward stress management.
  
### Block Diagram 
<img src="https://github.com/user-attachments/assets/c4a19aaf-9e48-4334-9094-0abcd0cac6c9" width="600" height="450">

## Hardware Design
### Bill Of Materials
| Component | Quantity | Description | Datasheet |
| --- | :---: | :---: | :---: |
| Arduino Nano ESP32 | 1 | Microcontroller with Wi-Fi | [Datasheet](https://docs-old.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf)
| Heart Rate Sensor - MAX30102 | 1 |For pulse measurement | [Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/MAX30102.pdf) |
| GSR Sensor | 1 |Measures skin conductivity | [Datasheet](https://www.farnell.com/datasheets/3759026.pdf)|
| Temperature Sensor - TMP102 | 1 |For body temperature readings| [Datasheet](https://www.ti.com/lit/ds/symlink/tmp102.pdf?ts=1734356719087) |
| LCD Display | 1 | For showing real-time data | - |
| RGB LED | 1 | Provides visual feedback based on stress levels | - |
| Buzzer | 1 | Alerts users of high stress levels | - |
| Resistors | 4 - 330 Ω each | For circuit stabilization | - |
| Wires and breadboard | - | For wiring all components together | - |

### Circuit Diagram 
<img src="https://github.com/user-attachments/assets/fca486da-ea98-4470-8e56-1a4b525e6009" width="600" height="450">

## Hardware Functionality
The project integrates multiple sensors, modules, and components to measure physiological parameters such as heart rate, body temperature, and skin conductivity, providing real-time feedback on stress levels and emotional states.
### 1. Microcontroller: Arduino Nano ESP32
<img src="https://github.com/user-attachments/assets/4b5fb4cf-60d7-4929-ae2c-e2e30b63d1f9" width="300" height="150">

* The Arduino Nano ESP32 is the core of the system. It is a compact microcontroller featuring an ESP32 processor that supports:
    - Wi-Fi and Bluetooth connectivity for IoT data transmission.
    - Multiple analog and digital GPIO pins for sensor and module connections.
* Key Specifications:
    - Operating Voltage: 3.3V
    - I/O Pins: 22 (Analog and Digital)
    - PWM Support: On most GPIO pins

### 2. TMP102 Temperature Sensor
<img src="https://github.com/user-attachments/assets/d08f4895-070a-4f12-87e1-95df33be7d49" width="200" height="200">

Body temperature can indicate stress or emotional changes, as temperature fluctuations often occur under stress.

* Communication Interface: I2C (2 pins: SCL and SDA)
* Pins used: 
    - VCC (Power): Connect to 3.3V → TMP102 operates on 3.3V logic.
    - GND (Ground): Connect to the GND rail → Provides a ground reference.
    - SCL (Clock): Connect to A4 (SCL) → The clock line for I2C communication.
    - SDA (Data): Connect to A5 (SDA) → The data line for I2C communication.

### 3. MAX30102 Heart Rate Sensor
<img src="https://github.com/user-attachments/assets/27ec97df-8d30-42e2-8600-d79090ebfa16" width="200" height="200">

Heart rate is a key indicator of stress levels, as it tends to increase under stressful conditions.

* Communication Interface: I2C (2 pins: SCL and SDA)
* Pins used: 
    - VIN (Power): Connect to 3.3V → MAX30102 operates on 3.3V logic.
    - GND (Ground): Connect to the GND rail → Provides a ground reference.
    - SCL (Clock): Connect to A4 (SCL) → The clock line for I2C communication.
    - SDA (Data): Connect to A5 (SDA) → The data line for I2C communication.

### 4. GSR Sensor
<img src="https://github.com/user-attachments/assets/002533e4-4ecd-45d3-abbc-f1875183a23a" width="200" height="200">

The GSR sensor outputs analog data corresponding to skin resistance, which is directly read by one of the analog pins. Skin conductivity is directly related to stress, making it a reliable indicator of emotional states.

* Communication Interface: Analog output
* Pins used: 
    - VCC (Power): Connect to 3.3V → GSR operates on 3.3V logic.
    - GND (Ground): Connect to the GND rail → Provides a ground reference.
    - Signal Pin: Connect to A0 (analog) → Reads analog values representing skin conductivity.

### 5. Audio and visual feedback
* RGB LED
    - Provides visual feedback on stress levels using different colors
    - Communication Interface: PWM 
    - Pins used:
       - Red Pin -> D9 Pin
       - Green Pin -> D8 Pin
       - Blue Pin -> D7 Pin

* Buzzer
    - Provides auditory alerts when stress levels exceed predefined thresholds
    - Communication Interface: PWM
    - Pins used:
       - Positive Pin -> D5 Pin
       - Negative Pin -> GND


## Software Design
**IDE**: Visual Studio Code, PlatformIO extension
* **Libraries**:
* **Main features**:
    - Reads heart rate, GSR, and temperature data using appropriate libraries and sensors
    - Calculates a stress index from sensor values
    - Uses RGB LED and a buzzer for feedback
    - Sends data to an IoT dashboard

### Workflow - TBD

## Final Results
_TBD_

## Conclusions
_TBD_

## Journal
* _30.11.2024_ - the choice of the project
* _03.12.2024_ - started the documentation
* _15.12.2024_ - made the block diagram
* _16.12.2024_ - soldering pins and started the circuit
* _17.12.2024_ - made the circuit and updated the documentation

## Resources
_TBD_
