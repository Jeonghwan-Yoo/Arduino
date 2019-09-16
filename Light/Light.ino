void setup() {
  Serial.begin(9600);

}

void loop() {
  int cds=analogRead(A0);
  Serial.println(cds);
  analogWrite(9,map(analogRead(A0),0,1023,0,255));
  delay(1000);
}
