#include<SoftwareSerial.h>
SoftwareSerial bsc(10,11);
const int trigPin = 8;
const int echoPin = 7;
int smoke=9;

long duration;
int distance;
void distance_read();
void setup() {
  bsc.begin(9600);
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
pinMode(echoPin, INPUT);
  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
   pinMode(9,INPUT);
     pinMode(6,OUTPUT);
 pinMode(13,OUTPUT);  
  Serial.begin(9600);
 
}

char x;
void loop() 
{
  int smokesensor=digitalRead(9);
  Serial.println(smokesensor);
 if(smokesensor==0){
   digitalWrite(6 ,LOW);
    bsc.println("SMOKE IS DETECTED!!!.. PLEASE ELERT");
     bsc.println("ROBOT STOPPED");
    digitalWrite(4,LOW);
  digitalWrite(5,LOW);
   digitalWrite(12,LOW);
  digitalWrite(13,LOW);
    
 }
 else{
   digitalWrite(6 ,HIGH);
   // bsc.println("SMOKE IS NOT DETECTED!!!");
  
 }
  int y;
   y=digitalRead(2);
   if(x=='l'){
    bsc.println("lights ON");
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
    
  }
    if(y!=0){
    digitalWrite(3 ,HIGH);
     }
  else{
    digitalWrite(3 , LOW);
  }

distance_read();
if(bsc.available() > 0) 
{
   x = bsc.read();
    if(x=='l'){
    bsc.println("lights ON");
    digitalWrite(3,HIGH);
    delay(3000);
  }
    if(x=='o'){
    bsc.println("lights OFF");
    digitalWrite(3,LOW);
  }
 

   if(x=='s'){
    bsc.println("ROBOT STOPPED");
    digitalWrite(4,LOW);
  digitalWrite(5,LOW);
   digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
  if(x=='f'){
    bsc.println("ROBOT MOVING FRONT");
    digitalWrite(4,LOW);
     digitalWrite(5,HIGH);
      digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  }
  if(x=='r'){
    bsc.println("ROBOT MOVING BACK");
    
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
     digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  }
   if(x=='p'){
    bsc.println("ROBOT MOVING left");
    
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
     digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(200);
    digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(200);
   bsc.println("ROBOT MOVING FRONT");
    digitalWrite(4,LOW);
     digitalWrite(5,HIGH);
      digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  }
   if(x=='q'){
    bsc.println("ROBOT MOVING right");
    
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
     digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(200);
    digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
   delay(200);
   bsc.println("ROBOT MOVING FRONT");
    digitalWrite(4,LOW);
     digitalWrite(5,HIGH);
      digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  
  }
  
}
  
  
 if(distance<=50)
 {
  bsc.println("Obstacle detected...!!...ROBOT STOPPED");
    
    digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
  delay(1000);
 
}

void distance_read()
{
   digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= (duration/2)*0.034;

if(distance>=0 && distance<500){
    Serial.println("Distance: ");
Serial.println(distance);
bsc.println(distance);
  }  
}
  

