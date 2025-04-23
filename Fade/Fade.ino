/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

int brightness1 = 0;
int brightness2 = 0;
int brightness3 = 0;

int fadeAmount1 = 5;
int fadeAmount2 = 5;
int fadeAmount3 = 5;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

const int fadeDelay = 30;
const int delayOffset1 = 0;     // Start immediately
const int delayOffset2 = 1000;  // Start 1 second later
const int delayOffset3 = 2000;  // Start 2 seconds later

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // LED 1
  if (currentMillis >= delayOffset1 && currentMillis - previousMillis1 >= fadeDelay) {
    brightness1 += fadeAmount1;
    if (brightness1 <= 0 || brightness1 >= 255) {
      fadeAmount1 = -fadeAmount1;
    }
    analogWrite(led1, brightness1);
    previousMillis1 = currentMillis;
  }

  // LED 2
  if (currentMillis >= delayOffset2 && currentMillis - previousMillis2 >= fadeDelay) {
    brightness2 += fadeAmount2;
    if (brightness2 <= 0 || brightness2 >= 255) {
      fadeAmount2 = -fadeAmount2;
    }
    analogWrite(led2, brightness2);
    previousMillis2 = currentMillis;
  }

  // LED 3
  if (currentMillis >= delayOffset3 && currentMillis - previousMillis3 >= fadeDelay) {
    brightness3 += fadeAmount3;
    if (brightness3 <= 0 || brightness3 >= 255) {
      fadeAmount3 = -fadeAmount3;
    }
    analogWrite(led3, brightness3);
    previousMillis3 = currentMillis;
  }
}

