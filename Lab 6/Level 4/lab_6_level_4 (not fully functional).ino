int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int fadeDelay = 5; //This is the number of milliseconds that it will take between steps
int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int button1 = 2;//The button is connect to pin 2 of the Arduino.
int input; // for incoming serial data
int previousInput = -1;
int red;
int green;
int blue;
int data;
int count;
bool goodValue;

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
  if(count == 0) {
    Serial.println("Please input: R,G,B");
  }
  while(Serial.available()==0){}
  input = Serial.read();
  validateInput();
  if(goodValue == true) {
    if(count == 0) {
      lockBrightness();
    }
    setBrightness();
  }

/*Serial.print("Red:");
Serial.print(red);
Serial.print(", Green:");
Serial.print(green);
Serial.print(", Blue:");
Serial.println(blue);*/
}

void validateInput() {
  if ((input == 82 || input == 71 || input == 66) && input != previousInput) {
    Serial.println("Valid input.");
    previousInput = input;
    goodValue = true;
  } else {
    if (input == previousInput) {
      Serial.println("You've already entered that value. Enter a different one.");
      count = 0;
      goodValue = false;
    } else {
      Serial.println("Invalid input.");
      count = 0;
      goodValue = false;
    }
  }
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
  if(input == 82) {(count = 1);}
  else if(input == 71) {(count = 2);}
  else if(input == 66) {(count = 3);}
  Serial.println(count);
  delay(500);
}



