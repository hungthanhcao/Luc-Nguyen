
#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;               
SoftwareSerial mySerial(rxPin, txPin);

int ac=4;
int light=5;
int fan=6;
int tv=7;
String data;

void setup() 
{
   Serial.begin(9600);
   mySerial.begin(9600);
   
   pinMode(ac, OUTPUT);
   pinMode(light, OUTPUT);
   pinMode(fan, OUTPUT);
   pinMode(tv, OUTPUT);
 
   digitalWrite(ac, LOW);
   digitalWrite(light, LOW);
   digitalWrite(fan, LOW);
   digitalWrite(tv, LOW);
}

void loop() 
{
    int i=0;
    char ch=0;
    data="";
    while(1)
    { 
      while(mySerial.available()<=0);
      ch = mySerial.read();
      if(ch=='#')
      break;
      data+=ch;
    }
   Serial.println(data);
    
    if(data=="*bật đèn phòng ngủ")
    { 
      digitalWrite(ac,HIGH);
      Serial.println("ac on");
    }
    else if(data=="*Tắt đèn phòng ngủ")
    {
      digitalWrite(ac,LOW);
      Serial.println("ac off");
    }
    else if(data=="*Turn on Light")
    {
      digitalWrite(light,HIGH);
      Serial.println("light on");
    }
    else if(data=="*Turn off light")
    {
      digitalWrite(light,LOW);
      Serial.println("light off");
    }
    else if(data=="*bật quạt")
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan on");
    }
    else if(data=="*tắt quạt")
    {
      digitalWrite(fan,LOW);
      Serial.println("fan off");
    }
    else if(data=="*Turn On TV")
    {
      digitalWrite(tv,HIGH);
      Serial.println("tv on");
    }
    else if(data=="*Turn off TV")
    {
      digitalWrite(tv,LOW);
      Serial.println("tv off");
    }
    else if(data=="*Bật tất cả đèn")
    {
      digitalWrite(ac,HIGH);
      digitalWrite(light,HIGH);
      digitalWrite(fan,HIGH);
      digitalWrite(tv,HIGH);
      Serial.println("all on");
    }
    else if(data=="*Tắt tất cả đèn")
    {
      digitalWrite(ac,LOW);
      digitalWrite(light,LOW);
      digitalWrite(fan,LOW);
      digitalWrite(tv,LOW);
      Serial.println("all off");
    
    }
    
}
