//Sebastian Bruce
//Date: September 21 2023
//Description: change color by using rotation dial

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data; //Variable for storing dial value
int speed; //Variable for storing speed for delay


void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  pinMode(rotationPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  data = analogRead(rotationPin); //Read the value from the light sensor and store it
  if(data >= 0 && data <= 164) { //red
    analogWrite(RGBRedPin, 255);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 0);
  }
  else if(data >= 164 && data <= 348) { //orange
    analogWrite(RGBRedPin, 255);
    analogWrite(RGBGreenPin, 165);
    analogWrite(RGBBluePin, 0);
  }
  else if(data >= 348 && data <= 511) { //yellow
    analogWrite(RGBRedPin, 255);
    analogWrite(RGBGreenPin, 255);
    analogWrite(RGBBluePin, 0);
  }
  else if(data >= 511 && data <= 647) { //green
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 255);
    analogWrite(RGBBluePin, 0);
  }
  else if(data >= 647 && data <= 859) { //blue
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 255);
  }
  else if(data >= 859 && data <= 1023) { //purple
    analogWrite(RGBRedPin, 128);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 128);
  }
}