//Sebastian Bruce
//Date: October 5 2023
//Description: control RGB LED with buttons and attachInterrupt

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int button1Pin = 2;
int button2Pin = 3; //The SW1 button is connect to pin 3 of the Arduino.
int count;// varible that controls the RGB LED

void setup() { //The Setup function runs once
pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(button1Pin), blink, RISING);
attachInterrupt(digitalPinToInterrupt(button2Pin), off, RISING);
}

void loop() { //The loop function runs forever.
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
  
void blink() {
  count = 1;
}

void off() {
  count = 0;
}