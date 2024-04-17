//Sebastian Bruce
//Date: November 2 2023
//Description: choose from list

#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.
String words1[5] = {"one", "two", "three", "four", "five"};
String words2[5] = {"red", "orange", "yellow", "green", "blue"};
String words3[5] = {"yes", "no", "maybe", "always", "never"};
int ans[2] = {0, 0};
int button = 6;
int choice1 = 0;
int choice2 = 0;
int choice3 = 0;

void setup()
{
  lcd.begin (16,2); //Initialize the LCD.
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  //level 3
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print("Welcome, click"); //Print at cursor Location
  lcd.setCursor(0,1); //goto first column and second line (0,1)
  lcd.print("button"); //Print at cursor Location
  delay(500);
  while(digitalRead(button) == LOW){}
  firstWords();
  secondWords();
  thirdWords();
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print(words1[choice1]); //Print at cursor Location
  lcd.print(", ");
  lcd.print(words2[choice2]); //Print at cursor Location
  lcd.print(",");
  lcd.setCursor(0,1);
  lcd.print(words3[choice3]); //Print at cursor Location
  delay(1000);
  while(digitalRead(button) == LOW){}
}

void firstWords() {
  for(int i=0; i<5; i++) {
    lcd.clear();
    lcd.setCursor(0,0); //goto first column and first line (0,0)
    lcd.print(words1[i]); //Print at cursor Location
    delay(1000);
    if (digitalRead(button) == HIGH) {
      choice1 = i;
      break;
    }
    if(i==4) {i = -1;}
  }
}

void secondWords() {
  for(int i=0; i<5; i++) {
    lcd.clear();
    lcd.setCursor(0,0); //goto first column and first line (0,0)
    lcd.print(words2[i]); //Print at cursor Location
    delay(1000);
    if (digitalRead(button) == HIGH) {
      choice2 = i;
      break;
    }
    if(i==4) {i = -1;}
  }
}

void thirdWords() {
  for(int i=0; i<5; i++) {
    lcd.clear();
    lcd.setCursor(0,0); //goto first column and first line (0,0)
    lcd.print(words3[i]); //Print at cursor Location
    delay(1000);
    if (digitalRead(button) == HIGH) {
      choice3 = i;
      break;
    }
    if(i==4) {i = -1;}
  }
}