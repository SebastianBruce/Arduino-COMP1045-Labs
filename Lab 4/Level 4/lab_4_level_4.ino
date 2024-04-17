//Sebastian Bruce
//Date: Oct 4 2023
//Description: Lab 4 Level 4 - display binary

//Variables
int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.
int yellowLED = 10;//LED Connected to port 10
int greenLED = 11;//LED Connected to port 11
int redLED = 12;//LED Connected to port 12
int blueLED = 13;//LED Connected to port 13
int data2;
int binaryNum[4];

//input/output, runs once
void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

//main loop, runs forevr
void loop() {
  data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
  data = map(data,6,679,0,15); //map the data value to 0-15
  Serial.print("Light value =");
  Serial.println(data); //Print the data to the serial port.
  
  if(data == 1) {//repeating code that turns on lights based off data number
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if(data == 2) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if(data == 3) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if(data == 4) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else if(data == 5) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else if(data == 6) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else if(data == 7) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else if(data == 8) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 9) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 10) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 11) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 12) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 13) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 14) {
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, HIGH);
  }
  else if(data == 15) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, HIGH);
  }
  delay(1000);
}