#include <Servo.h>
const int buttonPin  = 2;
const int ledButton = 3; // for npn transistor
int buttonState = 0;  // variable to store the button state
Servo myservo;// create servo object to control a servo
Servo myservo1;

int pos = 0;    // variable to store the servo position
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(8);
  pinMode(buttonPin, INPUT);
  pinMode(ledButton, OUTPUT);
  myservo.write(pos);
  myservo1.write(pos);
}

void loop() {
  buttonState = digitalRead(buttonPin); //read button state
  if (buttonState == HIGH) { // button pressed?
    if (pos == 0) { // faceplate raised?
      digitalWrite(ledButton, LOW); // leds off
      for (pos = 0; pos < 150; pos += 1) { // raise face
        myservo.write(pos);
        myservo1.write(pos);
        delay(15);
        Serial.println(pos);
      }
    }
    else {
      for (pos = 150; pos > 0; pos -= 1) { // lower face
        myservo.write(pos);
        myservo1.write(pos);
        delay(15);
      }
      digitalWrite(ledButton, HIGH); // leds on
    }
  }
}
