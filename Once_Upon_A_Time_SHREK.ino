#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int buttonPin1 = 7;
const int buttonPin2 = 5;
const int buttonPin3 = 8;
const int buttonPin4 = 6;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int previousButtonState1 = 0;
int previousButtonState2 = 0;
int previousButtonState3 = 0;
int previousButtonState4 = 0;

bool servo1Position = false;
bool servo2Position = false;
bool servo3Position = false;
bool servo4Position = false;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);

  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  if (buttonState1 == HIGH && previousButtonState1 == LOW) {
    if (servo1Position) {
      servo1.write(0);
    } else {
      servo1.write(90);
    }
    servo1Position = !servo1Position;
    delay(300);
  }

  if (buttonState2 == HIGH && previousButtonState2 == LOW) {
    Serial.println("Button 5 pressed - controlling Servo 2");
    if (servo2Position) {
      servo2.write(0);
    } else {
      servo2.write(90);
    }
    servo2Position = !servo2Position;
    delay(300);
  }

  if (buttonState3 == HIGH && previousButtonState3 == LOW) {
    if (servo3Position) {
      servo3.write(0);
    } else {
      servo3.write(90);
    }
    servo3Position = !servo3Position;
    delay(300);
  }

  if (buttonState4 == HIGH && previousButtonState4 == LOW) {
    Serial.println("Button 6 pressed - controlling Servo 4");
    if (servo4Position) {
      servo4.write(0);
    } else {
      servo4.write(90);
    }
    servo4Position = !servo4Position;
    delay(300);
  }

  previousButtonState1 = buttonState1;
  previousButtonState2 = buttonState2;
  previousButtonState3 = buttonState3;
  previousButtonState4 = buttonState4;
}
