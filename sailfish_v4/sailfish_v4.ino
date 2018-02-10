#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
Servo esc;
int spd = 1000;
int i = 0;
int maxAccel = 20  ;
void setup(){
  esc.attach(5);
  esc.writeMicroseconds(2000);
  delay(3000);
  esc.writeMicroseconds(1000);
  delay(2000);
  mySerial.begin(9600);
  Serial.begin(9600);
}
void loop(){
  Serial.println(spd);
  esc.writeMicroseconds(spd);
  if(mySerial.available()){
    i=mySerial.parseInt();
    if(i<=500 && spd < 2000){
      spd+=map(i,500,0,1,maxAccel);
      if(spd>2000){spd=2000;}
    }
    else if(i>=520 && spd>=1000){
      spd-=map(1023-i,520,0,1,maxAccel);
      if(spd<1000){spd=1000;}
    }
  }
} 


