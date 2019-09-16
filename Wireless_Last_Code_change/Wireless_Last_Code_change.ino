#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int potCurrent=A0; //아날로그 청소기 인풋 전류 입력
const int potVoltage1=A1;  //아날로그 청소기 인풋 전압 입력
const int potVoltage=A2; //아날로그 배터리 전압 입력
int readVoltage1=0; //아날로그 값 저장 변수
int readVoltage=0; //아날로그 값 저장 변수
int readCurrent=0; //아날로그 값 저장 변수

double mVperAmp=0.185;
double Voltage=0; //계산된 전압 값
double Voltage1=0; //계산된 전압 값
double Current=0; //계산된 전류 값
double Power=0; //계산된 전력 값
double Level=0; //계산된 배터리 잔량 퍼센트 값
double r1=1002.0; //배터리 전압 디바이드 쓰기위한 작은 저항값
double r2=9990.0; //배터리 전압 디바이드 쓰기위한 큰 저항값
double r3=1013.0; //인풋 전압 디바이드 쓰기 위한 작은 저항값
double r4=9970.0; //인풋 전압 디바이드 쓰기 위한 큰 저항값

byte block[8] = { //빈 사각형
  B11111, B10001, B10001, B10001,
  B10001, B10001, B10001, B11111
};
byte block1[8] = { //꽉찬 사각형
  B11111, B11111, B11111, B11111,
  B11111, B11111, B11111, B11111
};

byte code2[8] = { //코 
  B11111, B00001, B11111, B00001,
  B00001, B00100, B00100, B11111
};
byte code3[8] = { // 드
  B11111, B10000, B10000, B10000,
  B11111, B00000, B00000, B11111
};
byte code4[8] = { // 제
  B11101, B01001, B01011, B01011,
  B01111, B01011, B10101, B10101
};
byte code5[8] = { // 로
  B11111, B00001, B11111, B10000,
  B11111, B00100, B00100, B11111
};

void setup()
{
  lcd.init(); //초기화
  lcd.createChar(1, block1);
  lcd.createChar(0, block);
  lcd.createChar(2, code2);
  lcd.createChar(3, code3);
  lcd.createChar(4, code4);
  lcd.createChar(5, code5);
  pinMode(potVoltage,INPUT); // 배터리 입력전압
  pinMode(potCurrent,INPUT); // 입력 전류
  pinMode(potVoltage1,INPUT); // 입력 전압
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
 
 }
void loop()
{
  readVoltage=analogRead(potVoltage); // 배터리 전압
  readCurrent=analogRead(potCurrent); // 청소기 인풋 전류
  readVoltage1=analogRead(potVoltage1); // 청소기 인풋 전압
  Voltage=((1+r2/r1)*5/1024*readVoltage); // 배터리 전압
  Voltage1=((1+r4/r3)*5/1024*readVoltage1); // 청소기 인풋 전압
  Current=((512-readCurrent)*5/1024.0/mVperAmp); // 청소기 인풋 전류
  Power=(Voltage1*Current); // 인풋 전압 곱 인풋 전류 = 전력
  Level=(Voltage - 8.0)/(15 - 8.0)*100; // 배터리 잔량의 퍼센트 값 

  lcd.setCursor(11,0);
  if (0<=Level&&Level<=100){
     lcd.print(Level,0);
  }   
  if (0>Level){
    lcd.print("0");
  }
  if (Level>100.0){
    lcd.print("100");
  }
  lcd.print("%");
  lcd.setCursor(0,0);
  lcd.print(char(2));
  lcd.print(char(3));
  lcd.print(char(4));
  lcd.print(char(5));
  Serial.print(Voltage,3); // 배터리 전압
  Serial.print("V");
  Serial.print("\t");
  Serial.print(Voltage1,3); // 인풋 전압
  Serial.print("V1");
  Serial.print("\t");
  Serial.print(Current,3); // 인풋 전류
  Serial.print("A");
  Serial.print("\t");
  Serial.print(Power,3); // 전력
  Serial.println("W");

   if(Current > 0.2 ){
    lcd.setCursor(0,1);
    lcd.print(Voltage1,1);
    lcd.print("V");
    lcd.setCursor(6,1);
    lcd.print(Current,1);
    lcd.print("A");
    lcd.setCursor(11,1);
    lcd.print(Power,1);
    lcd.print("W");
   }
  else if (Voltage1 > 9 ){
    lcd.setCursor(0,1);
    lcd.print("Charging...");
   }
    
  if(Level<20.0){ //한칸 충전
    lcd.setCursor(5,0);
    lcd.print(char(1));
    lcd.print(char(0));
    lcd.print(char(0));
    lcd.print(char(0));
    lcd.print(char(0));
  }
    
  else if(20.0<=Level&&Level<40.0){ //두칸 충전
    lcd.setCursor(5,0);
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(0));
    lcd.print(char(0));
    lcd.print(char(0));
  }
    
  else if(40.0<=Level&&Level<60.0){ //세칸 충전
    lcd.setCursor(6,0);
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(0));
    lcd.print(char(0));
  }

  else if(60.0<=Level&&Level<80.0){ //네칸 충전
    lcd.setCursor(6,0);
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(0));
  }

  else { //다섯칸 충전
    lcd.setCursor(6,0);
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(1));
    lcd.print(char(1));
  }    
    
    delay(1500); // 1.5초 딜레이 
    lcd.clear();
}
