int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5; //This is the number of milliseconds that it will take between steps
int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int button1 = 2;//The button is connect to pin 2 of the Arduino.
int red;
int green;
int blue;
int data;
int count = 1;

void setup() { //The Setup function runs once.
pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
pinMode(rotationPin,INPUT); //Setup rotationPin pin as an input pin.
pinMode(button1, INPUT); //Setup button1 pin as an input pin.
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(button1), lockBrightness, RISING);

}

void loop() { //The loop function runs forever.
data = analogRead(rotationPin); //Read the value from the light sensor and store it
data = map(data,0,1023,0,255); //map the data value to brightness
setBrightness();
Serial.print("Red:");
Serial.print(red);
Serial.print(", Green:");
Serial.print(green);
Serial.print(", Blue:");
Serial.println(blue);
}

void setBrightness() {
  if(count == 1) {
    analogWrite(RGBRedPin, data);
    red = data;
  }else if(count == 2) {
    analogWrite(RGBGreenPin, data);
    green = data;
  }else if(count == 3) {
    analogWrite(RGBBluePin, data);
    blue = data;
  }
}

void lockBrightness() {
  count++;
  if(count > 3) {
    count = 1;
  }
  Serial.println(count);
  delay(500);
}



