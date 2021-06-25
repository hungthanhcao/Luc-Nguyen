#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#define ECHOPIN 10 
#define TRIGPIN 11
int k = 1;
void setup()
{
 Serial.begin(9600);
 lcd.begin();
  lcd.print("DIST:");
  lcd.setCursor(8,1);
  lcd.print("CM");
 pinMode(ECHOPIN, INPUT);
 pinMode(TRIGPIN, OUTPUT);
 pinMode(12, OUTPUT);
} 
void loop()
{
 digitalWrite(TRIGPIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIGPIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIGPIN, LOW);
 float distance = pulseIn(ECHOPIN, HIGH);
 distance= distance/58;
 Serial.println(distance);
 delay(300);
 if(distance<6)
 {
 digitalWrite(12,HIGH);
 k++;
    if(k==3)
     {
      digitalWrite(12,LOW);
      k=1;
     }
 
 }
 //else
// {
//digitalWrite(12,LOW);
// }
      lcd.setCursor(3, 1);
      lcd.print(distance);
}
