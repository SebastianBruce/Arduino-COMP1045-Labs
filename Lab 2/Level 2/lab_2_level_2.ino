//Sebastian Bruce
//Date: September 14 2023
//Description: Level 2 code: Lightshow

int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
float totalWait;
int waitTime1 = 500; //Sets the amount of time to wait between color changes.
int waitTime2 = 700;
int waitTime3 = 700;


void setup() { //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
  //activate serial monitor
  Serial.begin(9600);
}

void loop() {
  //level 2 code
  for(int i = 0; i < 3; i++) { //cycle one
    digitalWrite(RGBRedPin, HIGH);
    delay(waitTime1);
    digitalWrite(RGBRedPin, LOW);
    digitalWrite(RGBBluePin, HIGH);
    delay(waitTime1);
    digitalWrite(RGBBluePin, LOW);
    digitalWrite(RGBGreenPin, HIGH);
    delay(waitTime1);
    digitalWrite(RGBGreenPin, LOW);
    totalWait = totalWait + waitTime1 * 3;
  }
  Serial.print(totalWait / 1000);
  Serial.println(" seconds have passed after cycle 1."); //print the amount of time past
  for(int i = 0; i < 3; i++) { //cycle two
    digitalWrite(RGBBluePin, HIGH);
    digitalWrite(RGBGreenPin, HIGH);
    delay(waitTime2);
    digitalWrite(RGBBluePin, LOW);
    digitalWrite(RGBRedPin, HIGH);
    delay(waitTime2);
    digitalWrite(RGBGreenPin, LOW);
    digitalWrite(RGBRedPin, LOW);
    totalWait = totalWait + waitTime2 * 2;
  }
  Serial.print(totalWait / 1000);
  Serial.println(" seconds have passed after cycle 2."); //print
  for(int i = 0; i < 3; i++) { //cycle three
    digitalWrite(RGBRedPin, HIGH);
    digitalWrite(RGBBluePin, HIGH);
    delay(waitTime3);
    digitalWrite(RGBRedPin, LOW);
    delay(waitTime3);
    digitalWrite(RGBGreenPin, HIGH);
    delay(waitTime3);
    digitalWrite(RGBBluePin, LOW);
    digitalWrite(RGBGreenPin, LOW);
    totalWait = totalWait + waitTime3 * 3;
  }
  Serial.print(totalWait / 1000);
  Serial.println(" seconds have passed after cycle 3.");
  delay(5000);
}
    
