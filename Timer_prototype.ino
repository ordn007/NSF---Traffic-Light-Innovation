/**
 * @Author Orden Aitchedji
 */

unsigned long start, finished, elapsed;
int start_bro = 1;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x20 for a 16 chars and 2 line display
 
void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}
 
void displayResult()
{
  int h,m,s,ms;
  unsigned long over;
  elapsed=finished-start;
  h=int(elapsed/3600000);
  over=elapsed%3600000;
  m=int(over/60000);
  if (m < 10) {
    lcd.setCursor(7,3);
    lcd.print(" ");
  }
  over=over%60000;
  s=int(over/1000);
  if (s < 10) {
    lcd.setCursor(10,2);
    lcd.print(" ");
  }
  ms=over%1000;
  /*
  Serial.print("Raw elapsed time: ");
  Serial.println(elapsed);
  Serial.print("Elapsed time: ");
  Serial.print(h,0);
  Serial.print("h ");
  Serial.print(m,0);
  Serial.print("m ");
  Serial.print(s,0);
  Serial.print("s ");
  Serial.print(ms,0);
  Serial.println("ms");
  Serial.println();
  */
  lcd.setCursor(0,0);
  lcd.print("hours: ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("mins: ");
  lcd.print(m);
  lcd.setCursor(0,2);
  lcd.print("seconds: ");
  lcd.print(s);
  lcd.setCursor(0,3);
  lcd.print("millis: ");
  lcd.print(ms);
  
}
 
void loop()
{
  if (start_bro==1)
  {
    start=millis();
    delay(200); // for debounce
    Serial.println("Started...");
    start_bro = 0;
  }
  
  if (1==HIGH)
  {
    finished=millis();
    displayResult();
    delay(70);
  }
}
