#define TRIG 2
#define ECHO 3

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() {
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  long distance=pulseIn(ECHO,HIGH)/58.2;
  tone(8,1000,20);
  delay(100);
  tone(8,1000,20);
  delay(distance);

}
