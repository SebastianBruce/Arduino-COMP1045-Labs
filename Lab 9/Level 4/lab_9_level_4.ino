//Sebastian Bruce
//Date: November 16 2023
//Description: Calculator 
//gets first input number and displays it
//gets operant and displays it
//gets second number and displays it
//does equation and displays it

#include <IRremote.h>
#include <LiquidCrystal.h>
#define IR_RECEIVE_PIN 11
#define power 0
#define clearScreen 2
#define buttonPlus 1
#define buttonMinus 9
#define buttonMultiply 5
#define buttonDevide 13
#define button0 12
#define button1 16
#define button2 17
#define button3 18
#define button4 20
#define button5 21
#define button6 22
#define button7 24
#define button8 25
#define button9 26

int count; //will be used for randomness later
LiquidCrystal lcd(13,12,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.
int value;
int firstNumber;
int secondNumber;
int convertedValue;
float finalValue;
char convertedOperant;
char operant;

bool powerOn = false; //used later to determine if program should run


void setup() {
  Serial.begin(9600);
  lcd.begin (16,2); //Initialize the LCD.
  IrReceiver.begin(IR_RECEIVE_PIN);
  //seed the randomness
  randomSeed(analogRead(0));
}

void loop() {
  value = 200; //sets value to a constant that is never used so it doesnt activate any if statements
  remoteValue(); //get value
  Serial.println("Press the power button to start");
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print("OFF"`); //Print at cursor Location
  while(value != power) { //pauses program until power button is pressed
    remoteValue(); //get value
  }
  if(value == power) { //once power is pressed, this runs
    powerOn = true; 
    lcd.clear();
  }
  while(powerOn) { //when power is on, this runs
    firstDescription();
    firstValue();
    secondDescription();
    operantValue();
    thirdDescription();
    secondValue();
    math();
    finalDescription();
    while(value != clearScreen && value != power) { //pauses program until clear button is pressed
      remoteValue(); //get value
      if(value == power) {
        lcd.clear();
        powerOn = false;
        break;
      }else if(value == clearScreen) {
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (0,0)
        continue;
      }
    }
  }
}

void remoteValue() { //get value from ir remote
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    value = IrReceiver.decodedIRData.command;
    //Serial.println(value);
    }
}

void firstDescription() { //print description
  Serial.println("Hit a number button to enter the first number");
}

void firstValue() { //gets first value and converts it to the number and displays that number
  while(true) {
    value = 200;
    remoteValue(); //get value
    if(value == button1 || value == button2 || value == button3 || value == button4 || value == button5 || value == button6 || value == button7 || value == button8 || value == button9) {
      convertValue();
      firstNumber = convertedValue;
      lcd.setCursor(0,0); //goto first column and first line (0,0)
      lcd.print(firstNumber); //Print at cursor Location
      break;
    }else if(value != button1 && value != button2 && value != button3 && value != button4 && value != button5 && value != button6 && value != button7 && value != button8 && value != button9 && value != 200) {
      Serial.println("invalid input");
      continue;
    }
  }
}

void secondDescription() { //print description
  Serial.println("Now pick an operant:");
  Serial.println("'VOL+' for Addition");
  Serial.println("'VOL-' for Subtraction");
  Serial.println("'Play/Pause' for Multiplication");
  Serial.println("'EQ' for Devision");
}

void operantValue() { //gets operant value and converts to that operant and displays it
  while(true) {
    value = 200;
    remoteValue(); //get value
    if(value == buttonPlus || value == buttonMinus || value == buttonMultiply || value == buttonDevide) {
      convertValue();
      operant = convertedOperant;
      lcd.print(operant); //Print at cursor Location
      break;
    }else if(value != buttonPlus && value != buttonMinus && value != buttonMultiply && value != buttonDevide && value != 200) {
      Serial.println("invalid input");
      continue;
    }
  }
}

void thirdDescription() { //print description
  Serial.println("Hit a number button to enter the second number");
}

void secondValue() { //gets second value and converts to number and displays that number
  while(true) {
    value = 200;
    remoteValue(); //get value
    if(value == button1 || value == button2 || value == button3 || value == button4 || value == button5 || value == button6 || value == button7 || value == button8 || value == button9) {
      convertValue();
      secondNumber = convertedValue;
      lcd.print(secondNumber); //Print at cursor Location
      break;
    }else if(value != button1 && value != button2 && value != button3 && value != button4 && value != button5 && value != button6 && value != button7 && value != button8 && value != button9 && value != 200) {
      Serial.println("invalid input");
      continue;
    }
  }
}

void math() {
  if(operant == '+') {
    finalValue = firstNumber + secondNumber;
  }else if(operant == '-') {
    finalValue = firstNumber - secondNumber;
  }else if(operant == '*') {
    finalValue = firstNumber * secondNumber;
  }else if(operant == '/') {
    finalValue = static_cast<float>(firstNumber) / secondNumber;
  }
  lcd.setCursor(0,1); //goto first column and first line (0,0)
  lcd.print(finalValue); //Print at cursor Location
}

void finalDescription() { //print description
  Serial.println("Would you like to do another equation or stop?");
  Serial.println("Press FUNC/STOP to clear and continue");
  Serial.println("Press the power button to end.");
}
    
  

void convertValue() {
  if(value == button0) {
    convertedValue = 0;
  }else if(value == button1) {
    convertedValue = 1;
  }else if(value == button2) {
    convertedValue = 2;
  }else if(value == button3) {
    convertedValue = 3;
  }else if(value == button4) {
    convertedValue = 4;
  }else if(value == button5) {
    convertedValue = 5;
  }else if(value == button6) {
    convertedValue = 6;
  }else if(value == button7) {
    convertedValue = 7;
  }else if(value == button8) {
    convertedValue = 8;
  }else if(value == button9) {
    convertedValue = 9;
  }else if(value == buttonPlus) {
    convertedOperant = '+';
  }else if(value == buttonMinus) {
    convertedOperant = '-';
  }else if(value == buttonMultiply) {
    convertedOperant = '*';
  }else if(value == buttonDevide) {
    convertedOperant = '/';
  }
}
