//Shrek Github Test!!!
// KM NEWER test
//SP NEW TESSSTTT
// KM's first change


//SERVO WITH BUTTON TEST//---------------------------------------
#include <Servo.h>

Servo myservo;
const int buttonPin = 8;
int buttonState = 0;
int previousButtonState = 0;
bool servoPosition = false; // Track position: false = 0°, true = 90°

void setup() {
  pinMode(buttonPin, INPUT);
  myservo.attach(9);
  myservo.write(0); // Start at 0 degrees
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Check if button state has changed from LOW to HIGH (button press)
  if (buttonState == HIGH && previousButtonState == LOW) {
    Serial.println("Button pressed");

    // Toggle the servo position
    if (servoPosition) {
      myservo.write(0); // Move back to 0°
    } else {
      myservo.write(90); // Move to 90°
    }

    servoPosition = !servoPosition; // Flip the state
    delay(300); // Simple debounce delay
  }

  previousButtonState = buttonState; // Update the previous state
}
