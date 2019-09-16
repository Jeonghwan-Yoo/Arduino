#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330

int pins[]={2,3,4};
int notes[]={NOTE_E4,NOTE_D4,NOTE_C4};
  
void setup() {
  for(int i=0;i<3;i++){
    pinMode(pins[i],INPUT);
  }
}

void loop() {
  for(int i=0;i<3;i++){
    if(digitalRead(pins[i])==HIGH){
      tone(8,notes[i],20);
    }
  }

}
