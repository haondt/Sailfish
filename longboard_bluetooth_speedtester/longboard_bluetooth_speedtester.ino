#include <Servo.h>
#include <SoftwareSerial.h> //Serial Port for bluetooth module

SoftwareSerial mySerial(3,2);
Servo esc;  // create servo object to control a servo
int spd = 0;
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  esc.attach(9);
  startesc();// attaches the servo on pin 9 to the servo object
}

void loop() {
/*  if(Serial.available()){
    int i = Serial.parseInt();
    if(i>=0&&i<=180){
      spd=i;
    }
  }
  esc.write(spd);
  delay(100);
  */
  esc.write(0);
  delay(1000);
  esc.write(90);
  delay(1000);
  esc.write(180);
  delay(1000);
}

void startesc(){
  esc.write(0);
  delay(1000);
  esc.write(180);
  delay(1000);
  esc.write(0);
  delay(2000);
}

