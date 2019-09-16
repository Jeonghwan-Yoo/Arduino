void setup() {
  
}

void loop() {
  tone(8,map(analogRead(A0),0,1023,31,4978),20);
  delay(500);
}
