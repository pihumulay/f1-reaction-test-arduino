# f1-reaction-test-arduino
This Arduino-based project simulates a Formula 1 race start light system and measures the user's reaction time using an ultrasonic sensor. Instead of pressing a button, the user waves a hand to start, and the system records the time taken to react after the lights go out. The reaction time is displayed on an LCD screen, and LEDs visually simulate the classic F1 five-light sequence.

✨ Features:
F1-style race start lights using LEDs
Hand wave detection using an ultrasonic sensor (no physical button needed)
False start detection
Real-time reaction time display on LCD
Fun, interactive project to test and improve reflexes

⚙️ Hardware Components:
Arduino Uno (or compatible board)
5 x LEDs (for starting lights)
Ultrasonic sensor (HC-SR04)
16x2 LCD (with I2C or without)
Resistors (for LEDs)
Breadboard & jumper wires
Power source or USB cable

🛠️ How It Works:
Start Sequence:
The five LEDs light up one by one (like F1 starting lights).
After a random delay, all lights turn off—signaling GO!.

Reaction Capture:
As soon as the lights go off, the user moves their hand.
The ultrasonic sensor detects the hand's movement.
The system calculates and displays the reaction time in milliseconds.

False Start Handling:
If the hand is moved before the lights go out, a "False Start" message is shown.
