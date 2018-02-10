#include <Servo.h> //Treating the esc as a servo
#include <SoftwareSerial.h> //Serial Port for bluetooth module

SoftwareSerial mySerial(3,2); //Connecting to the tx and rx pins of the bluetooth module
Servo esc; // creating the esc
int spd = 90; // "speed" value sent to esc
void setup(){
  esc.attach(9); // esc signal pin on pin 9
  esc.write(0);
  delay(1000);
  esc.write(180);
  delay(1000);
  esc.write(0);
  delay(1000);
  esc.write(90);
  delay(1000);
  mySerial.begin(9600); // open serial connection with bluetooth module 
}

void loop(){
  esc.write(spd); // important to constantly tell the esc the current speed so it doesnt engage the safety shutoff
  delay(100); // avoids overloading the esc with too many commands to quickly
  
  if (mySerial.available()){ // when we receive information over serial
    
    char i = mySerial.read(); //find out which letter the serial sends (A= faster, B= slower, C= stop)
    if(i=='A'){ // "faster"
      if(spd>=90 && spd<=170){ // if the board is over speed twenty, and below the max speed, i.e board is already moving,
        spd+=10; //accelerate
        esc.write(spd);
        delay(100); // give board time to accelerate
      }
      else if(spd<=89){ //if speed is below 20, i.e board is either stopped or barely going fast enough to move under load
        spd=90; // speed all the way up to twenty
        esc.write(spd);
        delay(500); // give suffiecient time to reach speed from standstill
      }
    }
    else if(i=='B'){ // "slow down" 
      if(spd>=100){ // if board is going over thirty, i.e 10+ above minimum speed
        spd-=10; // slow down by 10
        esc.write(spd);
        delay(100); // give time for decceleration
      }
      else{ // if the board is going speed 19 or below, i.e some speed less than minimum speed, which it shouldn't, stop
        spd=90;
        esc.write(spd);
      }
    }
    else if(i=='C'){ // emergency stop/deadman switch
      for(int i=spd;i-=1;i>=90){ // gradual slow down to a stop (the "fast stop")
        spd=i;
        esc.write(spd);
        delay(25); // can be adjusted for a quicker stop
      }
    }
  }
}
