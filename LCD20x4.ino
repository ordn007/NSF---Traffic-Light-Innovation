#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x20 for a 16 chars and 2 line display

// Source: http://www.electroschematics.com/10178/arduino-traffic-light-system/
int trafficLights1[] = {2,3,4,5};  // red, yellow, green, pedestrians led pins
int trafficLights2[] = {6,7,8,9}; // red, yellow, green, pedestrians led pins
int situations = 4;
int duration[] = {8000,3000,10000,3000}; // duration of each situation
long previousCars = 0;
long previousPeds = 0;
long interval = 300;  //blink interval for pedestrians
int ledState = LOW;
int state;
int i = 0;

void setup()
{

  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
  
  for(int i = 0; i < 4; i++) {
    pinMode(trafficLights1[i], OUTPUT);
    pinMode(trafficLights2[i], OUTPUT);
  }
  Serial.begin(9600);
}


void loop()
{ 
  unsigned long start, finished, elapsed;
  int start_bro = 1;
  unsigned long currentMillis = millis();   
  delay(200); // for debounce
  Serial.println("Started...");
  start_bro = 0;
   
  int h,m,s,ms;
  unsigned long over;
  elapsed=finished-start;
  h=int(elapsed/3600000);
  over=elapsed%3600000;
  m=int(over/60000);
  
  if(currentMillis - previousCars < duration[i]) {      
    situation(i); 
    currentMillis=millis();
    //displayResult();
    lcd.setCursor(0,0);
    lcd.print("mins: ");
    lcd.print(m);

    lcd.setCursor(0,1);
    lcd.print("Secs: ");
    lcd.print(currentMilli);
    delay(70);  
  } else { 
    previousCars = currentMillis; 
    if(i >= situations) {
      i = 0;
      } else {
      i++;
    }   
  }
}
 
void activateTrafficLight1(String lights, int pedestrians) 
{ 
  for(int x = 0; x < 3; x++) 
  {
    if(lights[x] == '0') state = LOW;
    if(lights[x] == '1') state = HIGH;
    digitalWrite(trafficLights1[x], state); 
  }
  if(pedestrians == 1) {
    blinkPed(trafficLights1[3]);
  } else {
    digitalWrite(trafficLights1[3], LOW);
  }
}
 
void activateTrafficLight2(String lights, int pedestrians)
{ 
  for(int x = 0; x < 3; x++)
  {
    if(lights[x] == '0') state = LOW;
    if(lights[x] == '1') state = HIGH;
    digitalWrite(trafficLights2[x], state);
  }
  if(pedestrians == 1) {
    blinkPed(trafficLights2[3]);
  } else {
    digitalWrite(trafficLights2[3], LOW);
  }
}
 
void situation(int i)
{
  switch(i){
    case 0: 
      activateTrafficLight1("100",1); // 100 means red ON, yellow OFF, green OFF
      activateTrafficLight2("001",0); // the second parameter is for pedestrians
      break;              // 1 is ON and 0 is OFF
    case 1: 
      activateTrafficLight1("110",0); // 110: red ON, yellow ON, green OFF
      activateTrafficLight2("010",0);
      break;  
    case 2: 
      activateTrafficLight1("001",0);
      activateTrafficLight2("100",1);
      break;
    case 3: 
      activateTrafficLight1("010",0);
      activateTrafficLight2("110",0);
      break;  
  }
}
 
void blinkPed(int ped) {
  unsigned long currentMillis = millis();
  if(currentMillis - previousPeds > interval) {   
    previousPeds = currentMillis;   
    if (ledState == LOW)
    ledState = HIGH;
    else
    ledState = LOW;
    digitalWrite(ped, ledState);
  } 
}
