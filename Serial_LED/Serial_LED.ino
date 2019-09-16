#define LED 13
void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 if(Serial.available()){
  if(Serial.read()=='a'){
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
  }
 }
}
