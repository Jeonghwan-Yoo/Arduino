#include <dht11.h>
#define DHT11PIN 2
dht11 DHT11;

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

}

void loop() {
  Serial.println();

  int chk=DHT11.read(DHT11PIN);

  Serial.print("Read sensor: ");
  switch(chk){
    case 0:Serial.println("OK"); break;
    case -1:Serial.println("Checksum error"); break;
    case -2:Serial.println("Time out error"); break;
    default:Serial.println("Unknown error"); break;
  }
  Serial.print("Humidity (%):");
  Serial.println(DHT11.humidity);

  Serial.print("Temperature (oC):");
  Serial.println(DHT11.temperature);

  delay(2000);

}
