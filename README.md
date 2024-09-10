# Smart Irrigation System

## Overview

The Smart Irrigation System is a project designed to automate the process of watering plants based on soil moisture levels. This system uses soil moisture sensors to monitor the moisture content of the soil and automatically activates a water pump to irrigate plants when needed. The system also provides a web interface for real-time monitoring and manual control.

## Features

- **Automatic Watering:** Activates the water pump when soil moisture falls below a specified threshold.
- **Real-time Monitoring:** Displays current soil moisture levels on a web interface.
- **Manual Control:** Allows users to manually toggle the water pump from the web interface.
- **Wi-Fi Connectivity:** Uses an ESP8266 module to connect to a Wi-Fi network and provide remote access.

## Components

- **Arduino Uno** or **ESP8266** (with built-in Wi-Fi)
- **Soil Moisture Sensor** (e.g., FC-28)
- **Water Pump**
- **Relay Module** (for controlling the water pump)
- **Jumper Wires**
- **Breadboard**

## Installation

1. **Hardware Setup:**
   - Connect the soil moisture sensor to the analog pin (e.g., A0) on the Arduino or ESP8266.
   - Connect the relay module to a digital pin (e.g., D1) for controlling the water pump.
   - Ensure proper power connections for the pump and relay.

2. **Software Setup:**
   - Clone the repository:
     ```bash
     git clone https://github.com/ber-zackii/smart-irrigation-system.git
     ```
   - Open the `smart-irrigation-system.ino` file in the Arduino IDE.
   - Update the Wi-Fi credentials in the code:
     ```cpp
     const char* ssid = "Your_SSID";
     const char* password = "Your_PASSWORD";
     ```
   - Upload the code to the Arduino or ESP8266 board.

3. **Access the Web Interface:**
   - Once the board is connected to Wi-Fi, find the IP address assigned to it.
   - Open a web browser and enter the IP address to access the web interface.

## Code

The main code for the Smart Irrigation System is located in the `smart-irrigation-system.ino` file. The code handles:

- Reading soil moisture levels from the sensor.
- Controlling the water pump based on moisture levels.
- Serving a web page for real-time monitoring and manual control.

## Usage

- **Real-Time Monitoring:** The web interface displays the current soil moisture level.
- **Manual Control:** Use the web interface to toggle the water pump on or off.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. If you have any suggestions or improvements, please let us know!

