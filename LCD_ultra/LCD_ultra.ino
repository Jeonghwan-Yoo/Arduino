#include <LiquidCrystal.h>
#define TRIG 8
#define ECHO 9

LiquidCrystal lcd(12,11,2,3,4,5);

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  lcd.begin(16,2);

}

void loop() {
 digitalWrite(TRIG,LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG,HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG,LOW);

 long distance=pulseIn(ECHO,HIGH)/58.2;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(distance);
 lcd.print("cm");
 delay(200);
}
