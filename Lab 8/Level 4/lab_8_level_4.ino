//Sebastian Bruce
//Date: November 9 2023
//Description: answer questions and store answer

#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd(12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.
//stores questions
String questions[5] = {"Like Hockey?", "Like Red?", "Like Winter?", "Like Apples?", "Like Cola?"};
//stores answers
String answers[5] = {"", "", "", "", ""};
int ans[2] = {0, 0};
int button = 6;
int button1 = 7;
int yes; //store when yes is pressed
int no; //store when no is pressed

void setup()
{
  lcd.begin (16,2); //Initialize the LCD.
  pinMode(button, INPUT);
  pinMode(button1, INPUT);
  Serial.begin(9600);
}

void loop(){
  //level 4
  yes = 0;
  no = 0;
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print("Hit Any Button"); //Print at cursor Location
  lcd.setCursor(0,1); //goto first column and second line (0,1)
  lcd.print("To Start"); //Print at cursor Location
  delay(1000);
  while(digitalRead(button) == LOW && digitalRead(button1) == LOW){}
  questionAnswer(); //call main function
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (0,0)
  lcd.print("Yes: ");
  lcd.print(yes);
  lcd.setCursor(0,1);
  lcd.print("No: ");
  lcd.print(no);
  delay(1000);
  while(digitalRead(button) == LOW && digitalRead(button1) == LOW){}
}

void questionAnswer() { //asks questions and stores the answers
  for(int i=0; i<5; i++) {
    lcd.clear();
    lcd.setCursor(0,0); //goto first column and first line (0,0)
    lcd.print("Yes           No");
    lcd.setCursor(0,1);
    lcd.print(questions[i]);
    delay(1000);
    while(digitalRead(button) == LOW && digitalRead(button1) == LOW){}
    if (digitalRead(button) == HIGH) { //if yes is pressed, store yes
      answers[i] = "Yes";
      yes++;
      continue;
    }else if (digitalRead(button1) == HIGH) { //if no is pressed, store no
      answers[i] = "No";
      no++;
      continue;
    }
  }
}
