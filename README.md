# simple_webserver_Esp32S3
Implement a webserver using the Xiao Esp32S3.

# ESP32-S3 Web Server

This repository contains code for a simple web server running on an ESP32-S3 microcontroller. 

## Description

The code is written in C++ using the Arduino IDE and utilizes the ESP32 core library. It creates a web server that allows a user to enter text on a web page, which is then sent to the ESP32-S3 and printed to the Serial Monitor. 

## Installation

1. Clone or download the repository to your local machine.
2. Open the `esp32s3-webserver.ino` file in the Arduino IDE.
3. Connect your ESP32-S3 board to your computer using a USB cable.
4. Select the appropriate board and port in the Arduino IDE.
5. Upload the code to the ESP32-S3 board.

## Usage

1. After uploading the code to the ESP32-S3, open the Serial Monitor in the Arduino IDE to view the board's IP address.
2. Enter the IP address in a web browser to access the web server.
3. Enter text in the provided input field and click "Send" to send the text to the ESP32-S3.
4. View the Serial Monitor in the Arduino IDE to see the text that was received by the ESP32-S3.

## Contributing

Feel free to submit pull requests or issues with any improvements or fixes to the code.
