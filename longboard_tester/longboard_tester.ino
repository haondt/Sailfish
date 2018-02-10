#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
Servo esc;
int hall = 6;
int spd = 0;
void setup(){
  esc.attach(5);
  esc.writeMicroseconds(700);
  delay(2000);
  esc.writeMicroseconds(2000);
  delay(1000);
  esc.writeMicroseconds(700);
  delay(2000);
  mySerial.begin(9600);
}

void loop(){
  esc.write(spd);
  if (mySerial.available()){
    spd = mySerial.parseInt();
    mySerial.println(spd);
  }
}



