#include <IRremote.h> // thư viện hỗ trợ IR remote

const int receiverPin = 8; // chân digital 8 dùng để đọc tín hiệu
IRrecv irrecv(receiverPin); 
decode_results results;

const int led1 = 7;
const int led2 = 6; 
const int led3 = 5; 
/* trạng thái của các LEDs*/
boolean stateled1 = false;
boolean stateled2 = false;
boolean stateled3 = false;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void translateIR()
{
  switch(results.value)
  {
    case 0xFF30CF:  stateled1 = !stateled1; 
                digitalWrite(led1, stateled1); 
                break;
    case 0xFF18E7: stateled2 = !stateled2; 
                digitalWrite(led2, stateled2); 
                break;
    case 0xFF7A85: stateled3 = !stateled3; 
                digitalWrite(led3, stateled3);  
                break;
    case 0xFF38C7: stateled1 = stateled2 = stateled3 = false;
                digitalWrite(led1, 0);
                digitalWrite(led2, 0);
                digitalWrite(led3, 0);
  }
}
void loop()
{
  if (irrecv.decode(&results)) // nếu nhận được tín hiệu
  {
    translateIR();
    Serial.println(results.value, HEX);
    delay(200);
    irrecv.resume(); // nhận giá trị tiếp theo
  }
}
