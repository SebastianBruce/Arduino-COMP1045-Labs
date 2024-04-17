//Sebastian Bruce
//Date: Sept 7 2023
//Description: Lab 3 - Control 2 LEDS in sequence with for loops

//Variables
int blueLED = 13;//LED Connected to port 13
int redLED = 12;//LED Connected to port 12

//input/output, runs once
void setup()
{
pinMode(blueLED, OUTPUT);
pinMode(redLED, OUTPUT);
}

//set up functions to pull in loop
void alternateLights()
{
  //for loop runs 5 times before passing
  for (int i = 0; i < 5; i++)//sets i to 0, checks its less than 5, adds 1
  {
  digitalWrite(blueLED, HIGH);//turn LED on
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(blueLED, LOW);//turn LED off
  digitalWrite(redLED, HIGH);//turn LED on
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(redLED, LOW);//turn LED off
  }
}

void flashBoth()
{
  //for loop runs 4 times before passing
  for (int i = 0; i < 4; i++)//sets i to 0, checks its less than 4, adds 1
  {
  digitalWrite(blueLED, HIGH);//turn LED on
  digitalWrite(redLED, HIGH);//turn LED on
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(blueLED, LOW);//turn LED off
  digitalWrite(redLED, LOW);//turn LED off
  delay(500); // Wait for 500 millisecond(s)
  }
}

//main loop, runs forevr
void loop()
{
  alternateLights();//pull function
  digitalWrite(blueLED, LOW);//Turns off remaining light
  delay(100);
  flashBoth();//pull function
  delay(5000);//end of loop
}