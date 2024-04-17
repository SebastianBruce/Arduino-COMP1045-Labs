//Sebastian Bruce
//Date: Sept 28 2023
//Description: Lab 4 Level 3 - control LEDS from photoresistor

//Variables
int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data = 0; //This will store the data from the sensor.
int greenLED = 11;//LED Connected to port 11
int redLED = 12;//LED Connected to port 12
int blueLED = 13;//LED Connected to port 13

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
  data = map(data,6,679,0,100); //map the data value to a percentage
  Serial.print("Light value =");
  Serial.println(data); //Print the data to the serial port.
  delay(1000); //Wait 1 second (1000mS) before running again.
  
  if(data >= 50) { //turn on red
    digitalWrite(redLED, HIGH);
  }
  else { //turn off red
    digitalWrite(redLED, LOW); 
  }
  if(data >= 30 && data <= 60) { //turn on blue
    digitalWrite(blueLED, HIGH);
  }
  else { //turn off blue
    digitalWrite(blueLED, LOW);
  }
  if(data <= 33) { //turn on green and blink slow
    digitalWrite(greenLED, HIGH);
    delay(1000);
    digitalWrite(greenLED, LOW);
  }
  else if(data >= 66) { //turn on green and blink fast
    digitalWrite(greenLED, HIGH);
    delay(50);
    digitalWrite(greenLED, LOW);
  }
  else { //turn off green
    digitalWrite(greenLED, LOW);
  }
}