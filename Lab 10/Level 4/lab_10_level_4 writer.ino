//Sebastian Bruce
//Date: November 23 2023
//Description: lab 10 level 4

//Writer
#include <Wire.h>
int button = 2;

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(button, INPUT);
}

byte x = 0;

void loop()
{
  if(digitalRead(button)==HIGH) {
    if(x == 0) {
      x = 1;
    }else {
      x=0;
    }
    Wire.beginTransmission(4); // transmit to device #4
    Wire.write("x is ");        // sends five bytes
    Wire.write(x);              // sends one byte  
    Wire.endTransmission();    // stop transmitting
  }
  
  delay(500);
}