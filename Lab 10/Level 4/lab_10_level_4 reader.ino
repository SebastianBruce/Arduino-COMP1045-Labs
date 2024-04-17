//Reciever
#include <Wire.h>
int blueLED = 12;
int x;

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(blueLED, OUTPUT);
}

void loop()
{
  if(x == 1) {
    //blink 3 times
    for(int i = 0; i < 3; i++) {
      digitalWrite(blueLED, HIGH);
      delay(500);
      digitalWrite(blueLED, LOW);
      delay(500);
    }
    x = 0;
  }else {
    digitalWrite(blueLED, LOW);
  }
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}