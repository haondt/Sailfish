#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
Servo esc;
int hall = 6;
int spd = 0;
int i = 0;
int maxAccel = 2;
int maxspd =130;
int minspd = 55;
void setup(){
  esc.attach(5);
  esc.writeMicroseconds(700);
  delay(2000);
  esc.writeMicroseconds(2000);
  delay(1000);
  esc.writeMicroseconds(700);
  delay(2000);
  mySerial.begin(9600);
  pinMode(6,INPUT);
  digitalWrite(6,HIGH);
  Serial.begin(9600);
}
void loop(){
  if(mySerial.available()){
    i = mySerial.parseInt();
    if(i<=500){
      if(spd<minspd){spd=minspd;}
      spd+=map(i,500,0,1,maxAccel);
      if(spd>maxspd){spd=maxspd;}
    }
    else if(i>=520){
      spd-=map(1023-i,520,0,1,maxAccel);
      if(spd<minspd){spd=0;}
    }
    esc.write(spd);
    Serial.println(spd);
  }
} 


