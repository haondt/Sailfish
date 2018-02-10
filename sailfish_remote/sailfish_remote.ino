int led = 2;
int c = 10;
int z = 11;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  pinMode(z,INPUT);
  digitalWrite(z,HIGH);
  pinMode(c,INPUT);
  digitalWrite(c,HIGH);
}
void loop(){
  delay(100);
  if(digitalRead(z)==1){
    Serial.println(1023);
  }
  else{
    Serial.println(analogRead(A0));
  }
}
