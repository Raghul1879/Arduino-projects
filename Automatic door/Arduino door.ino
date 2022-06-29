#include<math.h>
#include <Servo.h>

Servo servo;

float distance;
float duration;
int trigPin = 8;
int echoPin = 8;

void setup()
{
  Serial.begin(9600);
  servo.attach(7);
  servo.write(0);
}

void loop()
{
  float distance1 = ult();
  delay(1000);
  float distance2 = ult();
  float speed=0;
  speed = abs(distance1-distance2);
  Serial.println(speed);
  if(speed>10)
  {
    servo.write(90);
  }
}

float ult()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  return distance;
}