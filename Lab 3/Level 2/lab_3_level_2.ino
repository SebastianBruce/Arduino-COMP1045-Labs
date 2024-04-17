//Sebastian Bruce
//Date: September 21 2023
//Description: change color cycle speed by using rotation dial

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
  speed = 1023 - data;
  Serial.print("Rotation value =");
  Serial.println(data); //Print the data to the serial port.
  digitalWrite(RGBRedPin, HIGH); //Turn on light
  delay(speed); //Delay based on dial
  digitalWrite(RGBRedPin, LOW);
  digitalWrite(RGBBluePin, HIGH);
  delay(speed);
  digitalWrite(RGBBluePin, LOW);
  digitalWrite(RGBGreenPin, HIGH);
  delay(speed);
  digitalWrite(RGBGreenPin, LOW);
  
}