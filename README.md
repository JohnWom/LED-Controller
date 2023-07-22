# LED-Controller
 Audio-Responsive Neopixel LED Controller

## Description
---
 This Github Repo stores the necessary code, technical drawings, and parts list needed to make a DIY Music-Reactive LED Controller. The key aspects of the design are the code, the 3D-printed STL files and the GERBER custom PCB board. The main boards of the design are the Seeed XIAO RP2040 and the Arduino Nano 33 IoT. It is designed to work with WS2812B Leds (Neopixels) and is currently a work in progress. The code is written in C++ and utilizes the Platform IO IDE tool to manage the development of the code. The general architecture follows the Controller-Responder pattern, where the Arduino Nano 33 IoT chip is used to gather user input, while the Seeeduino chip is the "workhorse" of the system and manages the LEDs and audio processing. 
 
 
 ## Controller Chip
 ---
   The Controller Chip controls the UI and all user interactions with the device. This includes a clickable joystick as well as a 2x16 LCD display. The code runs a menu system on the LCD that is navigatable using the joystick. From there, colors and patterns can be selected to be run on the lights. These commands are forwarded to the Responder chip through serial communication and a custom-designed communication protocol.
  
  
 ## Responder Chip
 ---
   The Responder Chip controls the LEDs and music recognition abilities. It intakes commands from the Controller chip and adjusts the system accordingly. System data is stored here, such as the number of LEDs, the current color, and the current selected pattern. 
   
   
 ## Photos
 ---
 ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Isometric.PNG?raw=true)
 
 ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Isometric%20Closed.PNG?raw=true)
 
  ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Top.PNG?raw=true)
