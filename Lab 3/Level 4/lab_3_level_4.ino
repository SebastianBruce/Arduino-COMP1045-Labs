//Sebastian Bruce
//Date: September 21 2023
//Description: change color by typing R, G, or B

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int incomingByte = 0; // for incoming serial data


void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  pinMode(rotationPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(1000); 
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
  if(incomingByte == 82) { //red
    analogWrite(RGBRedPin, 255);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 0);
  }
  else if(incomingByte == 71) { //green
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 255);
    analogWrite(RGBBluePin, 0);
  }
  else if(incomingByte == 66) { //blue
    analogWrite(RGBRedPin, 0);
    analogWrite(RGBGreenPin, 0);
    analogWrite(RGBBluePin, 255);
  }
}