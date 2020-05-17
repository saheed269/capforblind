#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);
int anglepin=11;
int trig1=22; // this pin work as the output of the two trig pin of the two sensor
int echo1=23;
int echo2=33;
int trig2=32;
int soundpin=10;
int trigpin3=41;
int echopin3=40;
int echo4=28;
int trig4=29;
int trig5=51; 
int echo5=50;

 void setup()
 {
   Serial.begin (9600);
   Wire.begin();
  mpu6050.begin();
  //mpu6050.calcGyroOffsets(true);
   pinMode(trig2,OUTPUT);
   pinMode(echo2, INPUT);
   pinMode(trig1, OUTPUT);
   pinMode(echo1, INPUT);
   pinMode(trigpin3, OUTPUT);
   pinMode(echopin3, INPUT);
   pinMode(trig4, OUTPUT);
   pinMode(echo4, INPUT);
  pinMode(trig5, OUTPUT);
   pinMode(echo5, INPUT);
    
   pinMode(soundpin,OUTPUT);
   pinMode(anglepin,OUTPUT);
   
 }
 void loop()
{
   float duration1, distance1, duration2, distance2,duration3,distance3,duration4, distance4,duration5,distance5;
//sonar 4
mpu6050.update();
if((mpu6050.getAngleY()>=0)&&(mpu6050.getAngleY()<=17))
    {
    digitalWrite(anglepin,LOW);
  digitalWrite(trig4,LOW); 
  delayMicroseconds(2);
  digitalWrite(trig4, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig4, LOW); //trig:10 microsecond TTL pulse
  
  duration4 = pulseIn(echo4, HIGH);

  //sonar 1
  digitalWrite(trig1,LOW); 
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig1, LOW); //trig:10 microsecond TTL pulse
  
  duration1 = pulseIn(echo1, HIGH);

  //sonar 2
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig2,LOW);
  
  duration2 = pulseIn(echo2, HIGH);
//sonar 3
  digitalWrite(trigpin3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin3,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin3,LOW);
  
  duration3 = pulseIn(echopin3, HIGH);

//sonar 5
  digitalWrite(trig5,LOW);
  delayMicroseconds(2);
  digitalWrite(trig5,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig5,LOW);//
  
  duration5 = pulseIn(echo5, HIGH);

  //distance calculation
  distance1 = duration1/2/29.1;
  distance2 = duration2/2/29.1;
  distance3 = duration3/2/29.1;
  distance4 = duration4/2/29.1;
  distance5 = duration5/2/29.1;
  if(distance2<=10||distance3<=10||distance4<=10)
  {
    digitalWrite(soundpin,HIGH);
  }
  else
  {
    digitalWrite(soundpin,LOW);
  }

  //Serial.print(distance1);
   Serial.print(',');

   Serial.print(distance2);
   Serial.print(',');
   Serial.print(distance3);
   Serial.print(',');
   Serial.print(distance4);
   Serial.print(',');
  // Serial.print(distance4);
   //Serial.print(',');

   Serial.println(',');
    }

   else
   {
    digitalWrite(soundpin,LOW);
    digitalWrite(anglepin,HIGH);
   } 
    Serial.print("\tangleY : ");
  Serial.println(mpu6050.getAngleY());

  

   Serial.println(',');
  
  delay(20);
}
