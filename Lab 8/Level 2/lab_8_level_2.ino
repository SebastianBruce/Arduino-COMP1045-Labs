#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.

void setup()
{
  lcd.begin (16,2); //Initialize the LCD.
}

void loop(){
  
  //level 2
  //move to right on top 
  for(int i=0; i<8; i++) {
    lcd.clear();
    lcd.setCursor(i,0); //goto first column and first line (0,0)
    lcd.print("Sebastian"); //Print at cursor Location
    delay(500);
  }
  
  //move left on bottom row
  for(int i=8; i>0; i--) {
    lcd.clear();
    lcd.setCursor(i - 1,1); //goto first column and first line (0,0)
    lcd.print("Sebastian"); //Print at cursor Location
    delay(500);
  }
}