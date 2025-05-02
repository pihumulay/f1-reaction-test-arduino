#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to 0x3F if needed

const int leds[] = {2, 3, 4, 5, 6}; // 5 LED pins
const int trigPin = 9;
const int echoPin = 10;

unsigned long startTime = 0;
bool falseStart = false;

void setup() {
  // Set up LEDs
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  // Set up ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up LCD
  lcd.init();              // Correct method for I2C LCD
  lcd.backlight();         // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("F1 Reaction Test");
  delay(2000);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Get Ready...");
  delay(1000);
  falseStart = false;

  // Countdown with LEDs
  for (int i = 0; i < 5; i++) {
    if (handDetected()) {
      falseStart = true;
      break;
    }
    digitalWrite(leds[i], HIGH);
    delay(1000);
  }

  // Turn off LEDs
  for (int i = 0; i < 5; i++) digitalWrite(leds[i], LOW);

  if (falseStart) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("False Start!");
    delay(3000);
    return;
  }

  // Start timer
  startTime = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GO!");

  // Wait for hand detection
  while (!handDetected());

  unsigned long reactionTime = millis() - startTime;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reaction Time:");
  lcd.setCursor(0, 1);
  lcd.print(reactionTime);
  lcd.print(" ms");

  delay(4000); // Display result for 4 seconds
}

bool handDetected() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  return (distance > 0 && distance < 15); // Hand within 15 cm
}
