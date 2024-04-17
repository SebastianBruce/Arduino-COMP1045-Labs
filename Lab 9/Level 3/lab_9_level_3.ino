//Sebastian Bruce
//Date: November 10 2023
//Description: use remote to navigate menus and control lights

#include <IRremote.h>
#define IR_RECEIVE_PIN 11
#define power 0
#define button1 16
#define button2 17
#define button3 18
#define button4 20

int count; //will be used for randomness later
bool blue = false; //will be used to toggle later
bool red = false; //will be used to toggle later
int value;
int RGBRedPin = 8;
int RGBGreenPin = 9;
int RGBBluePin = 10;
int blueLED = 12;
int redLED = 13;
bool powerOn = false; //used later to determine if program should run
bool menu1 = false; //used later to determine if menu1 should run
bool menu2 = false; //used later to determine if menu2 should run
bool menu3 = false; //used later to determine if menu3 should run

void setup() {
  Serial.begin(9600);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(RGBRedPin, OUTPUT);
  pinMode(RGBGreenPin, OUTPUT);
  pinMode(RGBBluePin, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN);
  //seed the randomness
  randomSeed(analogRead(0));
}

void loop() {
  value = 200; //sets value to a constant that is never used so it doesnt activate any if statements
  remoteValue(); //get value
  Serial.println("Press the power button to start");
  while(value != power) { //pauses program until power button is pressed
    remoteValue(); //get value
  }
  if(value == power) { //once power is pressed, this runs
    powerOn = true; 
    menu1 = true;
  }
  while(powerOn) { //when power is on, this runs
    if(menu1) { //when menu1 is active, this runs
      menu1text();
      firstMenu();
    }else if(menu2) { //when menu2 is active, this runs
      menu2text();
      secondMenu();
    }else if(menu3) { //when menu3 is active, this runs
      menu3text();
      thirdMenu();
    }else if(!powerOn) { //if power gets pressed again it stops the code
      break;
    }
  }
  
}

void remoteValue() { //get value from ir remote
  if (IrReceiver.decode()) {
      IrReceiver.resume();
      value = IrReceiver.decodedIRData.command;
    }
  
}

void menu1text() { //text for menu 1
  Serial.println("Menu 1 Options:");
  Serial.println("Press 1 to turn on blue LED");
  Serial.println("Press 2 to turn off blue LED");
  Serial.println("Press 3 to go to menu 2");
  Serial.println("Press 4 to go to menu 3");
}

void menu2text() { //text for menu 2
  Serial.println("Menu 2 Options:");
  Serial.println("Press 1 to turn on red LED");
  Serial.println("Press 2 to turn off red LED");
  Serial.println("Press 3 to go to menu 1");
  Serial.println("Press 4 to go to menu 3");
}

void menu3text() { //text for menu 3
  Serial.println("Menu 3 Options:");
  Serial.println("Press 1 to display a random color");
  Serial.println("Press 2 to toggle red and blue LED");
  Serial.println("Press 3 to go to menu 1");
  Serial.println("Press 4 to go to menu 2");
}

void firstMenu() {
  while(true) {
    value = 200; //sets value to a constant that is never used so it doesnt activate any if statements
    remoteValue(); //get value
    if(value == button1) { //if 1 is pressed, this runs
      blue = true;
      digitalWrite(blueLED, HIGH);
    }else if(value == button2) { //if 2 is pressed, this runs
      digitalWrite(blueLED, LOW);
      blue = false;
    }else if(value == button3) { //if 3 is pressed, this runs
      menu2 = true;
      menu1 = false;
      break;
    }else if(value == button4) { //if 4 is pressed, this runs
      menu3 = true;
      menu1 = false;
      break;
    }else if(value == power) { //if power is pressed, this runs
      powerOn = false;
      menu1 = false;
      break;
    }
    //if a different button is pressed, this runs
    else if(value != button1 && value != button2 && value != button3 && value != button4 && value != 200) {
      Serial.println("invalid input");
      continue;
    }
  }
}

void secondMenu() {
    while(true) {
    value = 200;
    remoteValue();
    if(value == button1) {
      red = true;
      digitalWrite(redLED, HIGH);
    }else if(value == button2) {
      digitalWrite(redLED, LOW);
      red = false;
    }else if(value == button3) {
      menu1 = true;
      menu2 = false;
      break;
    }else if(value == button4) {
      menu3 = true;
      menu2 = false;
      break;
    }else if(value == power) {
      powerOn = false;
      menu2 = false;
      break;
    }else if(value != button1 && value != button2 && value != button3 && value != button4 && value != 200) {
      Serial.println("invalid input");
      continue;
    }
  }
}

void thirdMenu() {
    while(true) {
    value = 200;
    remoteValue();
    if(value == button1) {
      count = random(1,4);
      color();
    }else if(value == button2) {
      blue = !blue;
      red = !red;
      digitalWrite(blueLED, blue);
      digitalWrite(redLED, red);
    }else if(value == button3) {
      menu1 = true;
      menu3 = false;
      break;
    }else if(value == button4) {
      menu2 = true;
      menu3 = false;
      break;
    }else if(value == power) {
      powerOn = false;
      menu3 = false;
      break;
    }else if(value != button1 && value != button2 && value != button3 && value != button4 && value != 200) {
      Serial.println("invalid input");
      continue;
    }
  }
}

void color() { //picks random color
  if(count == 1) {
    digitalWrite(RGBRedPin, HIGH);
    digitalWrite(RGBGreenPin, LOW);
    digitalWrite(RGBBluePin, LOW);
  }
  else if(count == 2) {
    digitalWrite(RGBRedPin, LOW);
    digitalWrite(RGBGreenPin, HIGH);
    digitalWrite(RGBBluePin, LOW);
  }
  else if(count == 3) {
    digitalWrite(RGBRedPin, LOW);
    digitalWrite(RGBGreenPin, LOW);
    digitalWrite(RGBBluePin, HIGH);
  }
}

    