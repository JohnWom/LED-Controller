# LED-Controller
 Audio-Responsive Neopixel LED Controller Complete Design Package

## Description
---
 This Github Repo stores the necessary code, technical drawings, and parts list needed to make a DIY Music-Reactive LED Controller. The key aspects of the design are the code, the 3D printed STL files and the GERBER custom PCB board. The main boards of the design are the Seeed XIAO RP2040 and the Arduino Nano 33 IoT. It is designed to work with WS2812B Leds (Neopixels) and is currently a work in progress. The code is written in C++ (Arduino code), and utilizes the Adafruit_Neopixel, DFRobot_LCD1602, and Fast_FFT libraries. The code also utilizes Mbed OS on the RP2040 to allow for multithreading.
 
 ## Master Chip
 ---
   The Master Chip controls the UI and all user interactions with the device. This includes a clickable joystick as well as an 2x16 LCD display. The code runs a menu system on the LCD that is navigateable using the joystick. From there, colors and patterns can be selected to be run on the lights. These commands are forwarded to the slave chip through serial communication.
  
  
 ## Slave Chip
 ---
   The Slave Chip controls the LED's and music recongition abilities. It intakes commands from the master chip and adjusts the system accordingling. It operates on two threads, with the main constantly checking its serial port for new commands, the spawned thread running the according pattern on the LED. It also operates all of the audio processing, should a pattern require it. 
   
   
 ## Photos
 ---
 ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Isometric.PNG?raw=true)
 
 ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Isometric%20Closed.PNG?raw=true)
 
  ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Top.PNG?raw=true)
