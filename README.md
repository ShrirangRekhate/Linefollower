# Line Follower PCB Project

## Overview
This repository contains the design files and code for a line follower robot. The project uses a line-following sensor (RLS sensor), a TB6612FNG motor driver, and an Arduino Nano to control the robot's movements.

## Features
- **Line-Following Capability**: The robot can follow a predefined line path.
- **Arduino Nano Control**: Utilizes an Arduino Nano for processing sensor input and controlling the motor driver.
- **TB6612FNG Motor Driver**: Efficient motor driver for precise motor control.
- **Custom PCB Design**: Includes design files for a custom PCB to integrate all components neatly.

## Hardware Components
- **Arduino Nano**
- **RLS Line-Following Sensor**
- **TB6612FNG Motor Driver**
- **Motors and Wheels**
- **Power Supply (Battery)**
- **Custom PCB**

## Repository Contents
- `PCB/`: Contains PCB design files.
  - `lschematic.pdf`: Schematic diagram of the PCB.
  - `layers.pdf`: PCB layout diagram.
  - `gerber.zip`: Gerber files for PCB manufacturing.
- `Code/`: Contains the Arduino source code.
  - `line_follower.ino`: Main Arduino sketch for the line follower.
- `Docs/`: Additional documentation and resources.
  - `bill_of_materials.xlsx`: List of components required.

## Getting Started

### Prerequisites
- **Arduino IDE**: Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
- **PCB Manufacturing**: Use the provided Gerber files to manufacture the PCB.

### Installation
1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/linefollower-pcb.git
   ```
2. **Open the Arduino Sketch**:
   - Open `line_follower.ino` in the Arduino IDE.
3. **Upload the Code**:
   - Connect your Arduino Nano to your computer via USB.
   - Select the correct board and port in the Arduino IDE.
   - Click the upload button to upload the code to the Arduino Nano.

### Assembling the Robot
1. **Manufacture the PCB**:
   - Use the `gerber.zip` files to order the PCB.
2. **Solder Components**:
   - Solder the components onto the PCB.
3. **Connect Motors and Sensors**:
   - Connect the motors and the RLS line-following sensor to the PCB as per the schematic.
4. **Power Up**:
   - Connect a suitable battery to the PCB.

## Usage
1. Place the robot on a track with a clear line to follow.
2. Turn on the power.
3. The robot should start following the line automatically.

## Troubleshooting
- **Not Following the Line**:
  - Check sensor connections.
  - Ensure the line is clear and has good contrast with the background.
- **Motors Not Running**:
  - Verify motor connections.
  - Check the power supply.


## License
This project is licensed under the MIT License.

## Contact
For any questions or suggestions, please contact [shrirangrekhate27@gmail.com].

---
