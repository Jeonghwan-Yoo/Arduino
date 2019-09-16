#include <Servo.h>

Servo myservo;
int pos=0;

void setup() {
  myservo.attach(9);
}

void loop() {
 myservo.write(map(analogRead(A0),0,1024,0,120));
 delay(15);
  
}
