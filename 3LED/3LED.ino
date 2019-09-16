#define RED 11
#define GREEN 10
#define BLUE 9

void setup() {
  randomSeed(analogRead(0));

}

void loop() {
  analogWrite(RED,random(255));
  analogWrite(GREEN,random(255));
  analogWrite(BLUE,random(255));
  delay(1000);
}
