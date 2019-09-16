#include <SimpleTimer.h>
#define BUTTON 2
#define ALARM 8
#define LED 13

SimpleTimer timer;

int pState=LOW;
boolean booked=false;

void setup() {
  pinMode(BUTTON,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
 int state=digitalRead(BUTTON);

 if(pState==LOW&&state==HIGH){
  if(booked==false){
    booked=true;
    digitalWrite(LED,HIGH);
    timer.setTimeout(5000,beep); //특정시간뒤에
  }
 }
 pState=state;
 timer.run();
}
void beep(){
  booked=false;
  digitalWrite(LED,LOW);
  tone(8,1000,20);
  delay(100);
  tone(8,1000,20);
  delay(100);
  tone(8,1000,20);
}

