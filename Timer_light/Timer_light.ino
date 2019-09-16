#include <SimpleTimer.h>
#define LED 13

SimpleTimer timer;
boolean ledOn=false;

void setup() {
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 timer.setInterval(1000,toggle);
 timer.setInterval(5000,notify);

}

void loop() {
  timer.run();
}
void toggle(){
  if(ledOn==true){
    digitalWrite(LED,LOW);
  } else{
    digitalWrite(LED,HIGH);
  }
  ledOn=!ledOn;
}
void notify(){
  Serial.print("Brightness:");
  Serial.println(analogRead(A0));
}

