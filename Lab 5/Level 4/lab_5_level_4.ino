//Sebastian Bruce
//Date: October 12 2023
//Description: control all LEDs with buttons and attachInterrupt

int redLED = 12;//The red LED is connected pin 9 of the Arduino.
int greenLED = 13;//The green LED is connected pin 9 of the Arduino.
int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int button1Pin = 2;//The SW2 button is connect to pin 2 of the Arduino.
int button2Pin = 3; //The SW1 button is connect to pin 3 of the Arduino.
int count;//variable that controls the RGB LED
int countRG;//variable that controls red and green LED

void setup() { //The Setup function runs once
pinMode(redLED, OUTPUT); //Setup red LED pin as an output pin.
pinMode(greenLED, OUTPUT); //Setup green LED pin as an output pin.
pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(button1Pin), swapRG, FALLING);
attachInterrupt(digitalPinToInterrupt(button1Pin), swapRG, FALLING);
attachInterrupt(digitalPinToInterrupt(button2Pin), blink, FALLING);
attachInterrupt(digitalPinToInterrupt(button2Pin), blink, FALLING);
}

void loop() { //The loop function runs forever.
  redGreen();
  RGB();
}

void swapRG() {//swaps between red and green LED (and turns off RGB LED if red turns on)
  if(countRG == 0) {
    countRG = 1;
  }else if(countRG == 1) {
    countRG = 0;
    count = 0;
  }
}

void redGreen() {//controls red and green LED
  if(countRG == 0) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }else if(countRG == 1) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
}

void blink() {//turns RGB led on/off
  if(countRG == 1) {
    if(count == 0) {
      count = 1;
    }else if(count > 0) {
      count = 0;
    }
  }
}

void RGB() {//controls the RGB led
  if(count > 0) {
    count++;
    if(count == 4) {
      count = 1;
    }
  }
  Serial.println(count);
  delay(500);
  if(count == 1) { //red
    analogWrite(RGBRedPin, 255);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 0);
  } else if(count == 2) { //green
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 255);
    analogWrite(RGBBluePin, 0);
  } else if(count == 3) { //blue
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 255);
  } else { //off
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 0);
  }
}
