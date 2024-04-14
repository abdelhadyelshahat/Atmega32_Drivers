# Atmega32 Driver Collection

This repository provides a collection of well-documented and easy-to-use drivers written in C for the Atmega32 microcontroller. 
It aims to simplify interacting with various peripherals and modules on the Atmega32, accelerating your embedded systems development.

## Supported Drivers
### MCAL Layer 
- Digital Input/Output (DIO): This driver facilitates reading and writing digital signals to the Atmega32's general-purpose I/O pins.
- Analog-to-Digital Converter (ADC): This driver allows you to configure and read analog voltage values from the Atmega32's built-in ADC.
- Timer/Counter (Timer/Counter0, ..., Timer/Counter2): This driver provides control over the Atmega32's timers and counters, enabling      functions like pulse-width modulation (PWM) generation and delay generation.
- Universal Asynchronous Receiver/Transmitter (UART):This driver enables serial communication with UART devices. It supports baud rate,   data format, and flow control configuration, and provides functions for transmitting/receiving characters and handling interrupts.
- Serial Peripheral Interface (SPI):This driver enables high-speed, full-duplex communication with SPI peripherals. It offers           
  configuration for clock, data order, and chip select, and functions for data transfer. 
- Two-Wire Interface (TWI, also known as I2C):This driver facilitates I2C communication with various sensors, displays, and real-time      clock modules.

  ### HAL Layer
- Keypad (KPD): This driver facilitates interaction with a keypad connected to the Atmega32. It might provide functions for scanning key 
  presses, debouncing (eliminating switch bounce), and retrieving the pressed key code.
- Liquid Crystal Display (LCD ): This driver enables controlling an LCD display connected to the Atmega32. It offer functions for 
  initializing the LCD, sending commands, and writing characters/data/strings to the display.
- EEPROM (Electrically Erasable Programmable Read-Only Memory): This driver allows you to read from and write to the Atmega32's internal   EEPROM or an external EEPROM chip. It might provide functions for byte/word writes, reads, and erase operations.
- Real-Time Clock (RTC) DS1307: This driver helps interact with an external DS1307 RTC module. It offer functionalities for 
  setting/getting time (date, hours, minutes, seconds).
- Fingerprint Sensor R503: This driver simplifies communication with the R503 fingerprint sensor module. the implemented functions are  enrollment, identification, and image capture.

## Thanks for Reading
