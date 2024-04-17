//Sebastian Bruce
//Date: November 23 2023
//Description: move motor with buttons and change light color

#include <Servo.h>

Servo myservo;
int val;
int button1 = 2; // Button 1 connected to digital pin 2
int button2 = 3; // Button 2 connected to digital pin 3
int RGBRedPin = 5;
int RGBGreenPin = 6;
int RGBBluePin = 7;

void setup()
{
  myservo.attach(4);
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(RGBRedPin, OUTPUT);
  pinMode(RGBGreenPin, OUTPUT);
  pinMode(RGBBluePin, OUTPUT);
}

void loop() {
  if (digitalRead(button1) == HIGH) {//when button1 is pressed add 25%
    val = val + 45;
  }else if (digitalRead(button2) == HIGH) {//when button2 is pressed subtract 25%
    val = val - 45;
  }
  myservo.write(val); //move motor based on button press
  color();
  delay(500);
  Serial.println(val);
  if(val > 180) {//if button is pressed while at max
    goDown();
  }else if(val < 0) {//if button is pressed while at min
    goUp();
  }
}

void goDown() {//moves the motor to min while cycling colors
  while(val > 0) {
    val = val - 45;
    myservo.write(val);
    color();
    delay(500);
  }
}

void goUp() {//moves the motor to max while cycling colors
  while(val < 180) {
    val = val + 45;
    myservo.write(val);
    color();
    delay(500);
  }
}

void color() {//sets color based on motor value
  if(val == 0) {
    digitalWrite(RGBRedPin, HIGH);
    digitalWrite(RGBGreenPin, LOW);
    digitalWrite(RGBBluePin, LOW);
  }
  else if(val == 45) {
    digitalWrite(RGBRedPin, LOW);
    digitalWrite(RGBGreenPin, HIGH);
    digitalWrite(RGBBluePin, LOW);
  }
  else if(val == 90) {
    digitalWrite(RGBRedPin, LOW);
    digitalWrite(RGBGreenPin, LOW);
    digitalWrite(RGBBluePin, HIGH);
  }
  else if(val == 135) {
    digitalWrite(RGBRedPin, LOW);
    digitalWrite(RGBGreenPin, HIGH);
    digitalWrite(RGBBluePin, HIGH);
  }
  else if(val == 180) {
    digitalWrite(RGBRedPin, HIGH);
    digitalWrite(RGBGreenPin, LOW);
    digitalWrite(RGBBluePin, HIGH);
  }
}