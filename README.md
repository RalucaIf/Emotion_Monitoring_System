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
    - Display of real-time data on an LCD screen.
* Send data to an IoT dashboard for remote monitoring and historical tracking
### Block Diagram 
<img src="https://github.com/user-attachments/assets/c4a19aaf-9e48-4334-9094-0abcd0cac6c9" width="500" height="400">

## Hardware Design
### Bill Of Materials
| Component | Quantity | Description | Datasheet |
| --- | :---: | :---: | :---: |
| Arduino Nano ESP32 | 1 | Microcontroller with Wi-Fi | [Datasheet](https://docs-old.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf)
| Heart Rate Sensor - MAX30102 | 1 |For pulse measurement | [Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/MAX30102.pdf) |
| GSR Sensor | 1 |Measures skin conductivity | [Datasheet](https://www.farnell.com/datasheets/3759026.pdf)|
| Temperature Sensor - TMP102 | 1 |For body temperature readings| [Datasheet](https://www.ti.com/lit/ds/symlink/tmp102.pdf?ts=1734356719087) |
| LCD Display | 1 | For showing real-time data | [Datasheet]()|
| RGB LED | 1 | Provides visual feedback based on stress levels | - |
| Buzzer | 1 | Alerts users of high stress levels | - |
| Resistors | - | For circuit stabilization | - |
| Wires and breadboard | - | For wiring all components together | - |

### Circuit Diagram - TBD

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
