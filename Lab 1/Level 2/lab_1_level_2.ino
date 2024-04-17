//Sebastian Bruce
//Date: Sept 7 2023
//Description: Lab 2 - Display morse code with LED

//Variables
int blueLED = 13;//LED Connected to port 13

//level 2 variables
int dotTime = 200;
int dashTime = 600;
int spaceBetween = 200;
int spaceLetter = 600;
int spaceWord = 1400;

//input/output, runs once
void setup()
{
pinMode(blueLED, OUTPUT);
}

//set functions to pull in loop
void dot()
{
  digitalWrite(blueLED, HIGH);//turn LED on
  delay(dotTime);
  digitalWrite(blueLED, LOW);//turn LED off
}

void dash()
{
  digitalWrite(blueLED, HIGH);//turn LED on
  delay(dashTime);
  digitalWrite(blueLED, LOW);//turn LED off
}
//main loop, runs forever
void loop()
{
  //FUN
  // F
  dot();
  delay(spaceBetween);
  dot();
  delay(spaceBetween);
  dash();
  delay(spaceBetween);
  dot();
  delay(spaceLetter);

  //U
  dot();
  delay(spaceBetween);
  dot();
  delay(spaceBetween);
  dash();
  delay(spaceLetter);

  //N
  dash();
  delay(spaceBetween);
  dot();
  delay(spaceWord);

  //BAT
  //B
  dash();
  delay(spaceBetween);
  dot();
  delay(spaceBetween);
  dot();
  delay(spaceBetween);
  dot();
  delay(spaceLetter);

  //A
  dot();
  delay(spaceBetween);
  dash();
  delay(spaceLetter);

  //T
  dash();
  delay(spaceWord);

  delay(5000);//end of loop
}
