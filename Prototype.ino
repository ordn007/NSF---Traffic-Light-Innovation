#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

int red = 13;
int red1 = 1;
int red2 = 2;
int red3 = 3;
int red4 = 4;
int red5 = 5;
int red6 = 6;

int yellow = 12;
int green = 11;
int Turn = 0;

void setup() 
{
  lcd.backlight();
  lcd.init();

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
//-------- Write characters on the display ------------------
  // NOTE: Cursor Position: Lines and Characters start at 0  
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Time:");
  //delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Today's Date");
  //delay(1000);  
  lcd.setCursor(2,2);
  lcd.print("**Informations**");
  lcd.setCursor(15,3);
  //delay(1000);   
  lcd.print("T-LIG");
  //delay(2000);
  
  //changeLights();
  // green off, yellow off, red ON on for 7 seconds
  digitalWrite(red, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
  digitalWrite(red5, HIGH);
  digitalWrite(red6, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
digitalWrite(red, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
  digitalWrite(red5, HIGH);
  digitalWrite(red6, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
digitalWrite(red, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
  digitalWrite(red5, LOW);
  digitalWrite(red6, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
digitalWrite(red, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, LOW);
  digitalWrite(red5, LOW);
  digitalWrite(red6, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
digitalWrite(red, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(red5, LOW);
  digitalWrite(red6, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
digitalWrite(red, HIGH);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(red5, LOW);
  digitalWrite(red6, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
digitalWrite(red, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(red3, LOW);
  digitalWrite(red4, LOW);
  digitalWrite(red5, LOW);
  digitalWrite(red6, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);


  // turn off red, then turn green ON for 5 seconds
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(5000);

  // turn green off, then turn yellow ON for 2 seconds
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(2000);

}

/*void changeLights() {
  

}
*/
