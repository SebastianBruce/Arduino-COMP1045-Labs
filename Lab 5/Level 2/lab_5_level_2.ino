

int blueLedPin = 12 ; //The blue LED is connected pin 12 of the Arduino.
int redLedPin = 13;
int button1Pin = 2;
int button2Pin = 3; //The SW1 button is connect to pin 3 of the Arduino.

void setup() { //The Setup function runs once
pinMode(blueLedPin, OUTPUT); //Setup blue LED pin as an output pin.
pinMode(redLedPin, OUTPUT);
pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
}

void loop() { //The loop function runs forever.
  if (digitalRead(button2Pin) == HIGH) { //Check to see if button1 is pressed.
  	digitalWrite(blueLedPin, HIGH);//Turn on the blue LED.
  } else {
  	digitalWrite(blueLedPin, LOW); //Turn off the blue LED.
  }
  if (digitalRead(button1Pin) == HIGH) { //Check to see if button1 is pressed.
  	digitalWrite(redLedPin, HIGH);//Turn on the blue LED.
  } else {
  	digitalWrite(redLedPin, LOW); //Turn off the blue LED.
  }
}