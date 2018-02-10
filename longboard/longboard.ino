#include <Servo.h>
Servo esc;
int b = 7;
int led = 13;
int spd = 0;
void setup(){
  pinMode(b,INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(b,HIGH);
  esc.attach(9);
  digitalWrite(led,HIGH);
  esc.writeMicroseconds(700);
  delay(2000);
  esc.writeMicroseconds(2000);
  delay(1000);
  esc.writeMicroseconds(700);
  delay(2000);
  digitalWrite(led,LOW);
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  Serial.begin(9600);
}

void loop(){
  Serial.println(spd);
  delay(100);
  if(analogRead(0)<=18){
    if(spd<200){
      spd+=10;
      esc.write(spd);
      delay(1000);
    }
  }
  else if(analogRead(A1)<20){
    while(analogRead(A1)<20){
      delay(100);
      esc.write(spd);
    }
  }
  else{
    if(spd>=10){
      spd-=10;
      esc.write(spd);
      delay(1000);
    }
  }
  

}
