# LED-Controller
 Audio-Responsive Neopixel LED Controller Complete Design Package

## Description
---
 This Github Repo stores the necessary code, technical drawings, and parts list needed to make a DIY Music-Reactive LED Controller. The key aspects of the design are the code, the 3D printed STL files and the GERBER custom PCB board. The main boards of the design are the Seeed XIAO RP2040 and the Arduino Nano 33 IoT. It is designed to work with WS2812B Leds (Neopixels) and is currently a work in progress. The code is written in C++ (Arduino code), and utilizes the Adafruit_Neopixel, DFRobot_LCD1602, and Fast_FFT libraries. The code also utilizes Mbed OS on the RP2040 to allow for multithreading.
 
 ## Master Chip
 ---
   The Master Chip controls the UI and all user interactions with the device. This includes a clickable joystick as well as an 2x16 LCD display. The code runs a menu system on the LCD that is navigateable using the joystick. From there, colors and patterns can be selected to be run on the lights. These commands are forwarded to the slave chip through serial communication.
   
 ## Useful Articles to Understand the Fast Fourier Transforms
 ---
  [Explains Hamming Function and Windowing](https://towardsdatascience.com/brief-introduction-of-hamming-and-hanning-function-as-the-preprocessing-of-discrete-fourier-8b87fe538bb7)

## Useful Articles to Undestand Multithreading
 ---
 [Multithreading on RP2040 using Mbed OS](https://www.digikey.no/no/maker/blogs/2022/how-to-write-multi-threaded-arduino-programs)

 ## Photos
 ---
 ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Isometric.PNG?raw=true)
 
 ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Isometric%20Closed.PNG?raw=true)
 
  ![alt text](https://github.com/JohnWom/LED-Controller/blob/main/Physicals/Photos/Top.PNG?raw=true)
